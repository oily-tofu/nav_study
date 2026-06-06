#!/usr/bin/env python3

import math

import rclpy
from rclpy.node import Node

from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped

import tf2_ros


class PathFollower(Node):

    def __init__(self):

        super().__init__("path_follower")

        self.declare_parameter(
            "lookahead_distance",
            0.5
        )

        self.lookahead_distance = (
            self.get_parameter(
                "lookahead_distance"
            ).value
        )

        self.path_sub = self.create_subscription(
            Path,
            "/path",
            self.path_callback,
            10
        )

        self.goal_pub = self.create_publisher(
            PoseStamped,
            "/goal_pose",
            10
        )

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(
            self.tf_buffer,
            self
        )

        self.timer = self.create_timer(
            0.1,
            self.control_loop
        )

        self.path_points = []

        # 最近点索引（只允许向前搜索）
        self.closest_index = 0

    def path_callback(self, msg):

        if len(msg.poses) < 2:
            self.get_logger().warn(
                "Path too short"
            )
            return

        self.path_points = msg.poses

        self.closest_index = 0

        self.get_logger().info(
            f"Receive Path: {len(self.path_points)} points"
        )

    def get_robot_pose(self):

        try:

            transform = self.tf_buffer.lookup_transform(
                "map",
                "base_link",
                rclpy.time.Time()
            )

            x = transform.transform.translation.x
            y = transform.transform.translation.y

            return x, y

        except Exception:

            return None

    def find_closest_point(self, robot_x, robot_y):

        best_index = self.closest_index
        best_distance = float("inf")

        for i in range(
            self.closest_index,
            len(self.path_points)
        ):

            px = self.path_points[i].pose.position.x
            py = self.path_points[i].pose.position.y

            d = math.hypot(
                px - robot_x,
                py - robot_y
            )

            if d < best_distance:

                best_distance = d
                best_index = i

            # 提前结束搜索
            elif d > best_distance + 1.0:
                break

        self.closest_index = best_index

        return best_index

    def find_lookahead_point(self, closest_index):

        accumulated_distance = 0.0

        goal_index = closest_index

        while goal_index < len(self.path_points) - 1:

            p1 = self.path_points[goal_index].pose.position
            p2 = self.path_points[goal_index + 1].pose.position

            segment_length = math.hypot(
                p2.x - p1.x,
                p2.y - p1.y
            )

            accumulated_distance += segment_length

            goal_index += 1

            if accumulated_distance >= self.lookahead_distance:
                break

        return goal_index

    def publish_goal(self, goal_index):

        goal = PoseStamped()

        goal.header.frame_id = "map"
        goal.header.stamp = (
            self.get_clock().now().to_msg()
        )

        goal.pose = (
            self.path_points[goal_index].pose
        )

        self.goal_pub.publish(goal)

        self.get_logger().info(
            f"Closest={self.closest_index} "
            f"Goal={goal_index} "
            f"x={goal.pose.position.x:.2f} "
            f"y={goal.pose.position.y:.2f}"
        )

    def control_loop(self):

        if len(self.path_points) == 0:
            return

        robot_pose = self.get_robot_pose()

        if robot_pose is None:
            return

        robot_x, robot_y = robot_pose

        # 1. 找最近点
        closest_index = self.find_closest_point(
            robot_x,
            robot_y
        )

        # 2. 找前方lookahead点
        goal_index = self.find_lookahead_point(
            closest_index
        )

        # 3. 发布目标
        self.publish_goal(
            goal_index
        )

        # 4. 到达终点检测
        if goal_index >= len(self.path_points) - 1:

            goal_x = (
                self.path_points[-1]
                .pose.position.x
            )

            goal_y = (
                self.path_points[-1]
                .pose.position.y
            )

            distance_to_end = math.hypot(
                goal_x - robot_x,
                goal_y - robot_y
            )

            if distance_to_end < 0.15:

                self.get_logger().info(
                    "Path Finished"
                )

                self.path_points = []

    def destroy_node(self):

        self.get_logger().info(
            "PathFollower Shutdown"
        )

        super().destroy_node()


def main(args=None):

    rclpy.init(args=args)

    node = PathFollower()

    try:

        rclpy.spin(node)

    except KeyboardInterrupt:

        pass

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()
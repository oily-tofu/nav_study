#!/usr/bin/env python3

import math

import rclpy
from rclpy.node import Node

from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped


class PathFollower(Node):

    def __init__(self):
        super().__init__("path_follower")

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

        self.timer = self.create_timer(
            0.8,
            self.publish_next_goal
        )

        self.path_points = []
        self.current_index = 0
        self.path_length = 0.0

    def path_callback(self, msg):

        if len(msg.poses) < 2:
            return

        self.path_points = msg.poses
        self.current_index = 0

        self.path_length = self.calculate_path_length(
            self.path_points
        )

        self.get_logger().info(
            f"Receive Path: {len(self.path_points)} points"
        )

        self.get_logger().info(
            f"Path Length = {self.path_length:.2f} m"
        )

    def calculate_path_length(self, poses):

        total = 0.0

        for i in range(len(poses) - 1):

            p1 = poses[i].pose.position
            p2 = poses[i + 1].pose.position

            dx = p2.x - p1.x
            dy = p2.y - p1.y

            total += math.sqrt(dx * dx + dy * dy)

        return total

    def publish_next_goal(self):

        if len(self.path_points) == 0:
            return

        if self.current_index >= len(self.path_points):

            self.get_logger().info(
                "Path Finished"
            )

            return

        goal = self.path_points[self.current_index]

        goal.header.stamp = (
            self.get_clock().now().to_msg()
        )

        self.goal_pub.publish(goal)

        self.get_logger().info(
            f"Publish Goal [{self.current_index}] "
            f"({goal.pose.position.x:.2f}, "
            f"{goal.pose.position.y:.2f})"
        )

        self.current_index += 1


def main(args=None):

    rclpy.init(args=args)

    node = PathFollower()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()
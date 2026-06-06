#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import numpy as np

from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped


class PathPublisher(Node):

    def __init__(self):
        super().__init__("path_publisher")

        self.path_pub = self.create_publisher(
            Path,
            "/path",
            10
        )

        self.path_points = self.create_custom_path()

        self.get_logger().info(
            f"Generate {len(self.path_points)} path points"
        )

    def create_custom_path(self):

        waypoints = [
            (0.0, 0.0),
            (1.0, 0.0),
            (2.0, -1.0),
            (3.0, 0.0),
            (4.0, 0.5),
            (4.0, 2.0),
            (3.0, 3.0),
            (1.0, 2.0),
            (0.0, 0.0),
        ]

        return self.generate_polyline(
            waypoints,
            step=0.05
        )

    def generate_polyline(self, points, step=0.05):

        full_path = []

        for i in range(len(points) - 1):

            start = np.array(points[i])
            end = np.array(points[i + 1])

            dist = np.linalg.norm(end - start)

            num = max(2, int(dist / step))

            t_values = np.linspace(0.0, 1.0, num)

            if i > 0:
                t_values = t_values[1:]

            for t in t_values:
                pt = start + t * (end - start)
                full_path.append(pt)

        return np.array(full_path)

    def publish_path(self):

        path_msg = Path()

        path_msg.header.stamp = (
            self.get_clock().now().to_msg()
        )

        path_msg.header.frame_id = "map"

        for pt in self.path_points:

            pose = PoseStamped()

            pose.header.frame_id = "map"

            pose.pose.position.x = float(pt[0])
            pose.pose.position.y = float(pt[1])
            pose.pose.position.z = 0.0

            pose.pose.orientation.w = 1.0

            path_msg.poses.append(pose)

        self.path_pub.publish(path_msg)

        self.get_logger().info(
            f"Publish Path ({len(path_msg.poses)} points)"
        )


def main(args=None):

    rclpy.init(args=args)

    node = PathPublisher()
    node.publish_path()

    # rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()
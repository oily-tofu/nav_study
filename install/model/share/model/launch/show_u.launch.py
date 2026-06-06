#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from launch import LaunchDescription

from launch_ros.actions import Node

from ament_index_python.packages import get_package_share_directory

import os


def generate_launch_description():

    # 获取功能包路径
    pkg_path = get_package_share_directory('model')

    # URDF 文件路径
    urdf_path = os.path.join(
        pkg_path,
        'urdf',
        'omni_u.urdf'
    )

    return LaunchDescription([

        # joint_state_publisher_gui
        # 提供关节滑块

        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui'
        ),

        # robot_state_publisher
        # 发布 TF

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            arguments=[urdf_path]
        ),

        # RViz2

        Node(
            package='rviz2',
            executable='rviz2',
            output='screen',
            arguments=['-d', '/home/tofu/catkin_ws/src/model/rviz/show.rviz']
        )

    ])


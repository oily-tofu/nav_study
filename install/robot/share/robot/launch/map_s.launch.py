from launch import LaunchDescription
from launch_ros.actions import Node
import os
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():

    map_saver = Node(
        package='nav2_map_server',
        executable='map_saver_cli',
        name='map_saver',
        output='screen',
        arguments=[
            '-f',
            "/home/tofu/catkin_ws/src/robot/map/map"
        ]
    )

    return LaunchDescription([
        map_saver
    ])
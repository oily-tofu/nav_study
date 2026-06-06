# map_publisher_launch.py
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # 地图文件路径（你的已有地图）
    map_file = os.path.join(
        get_package_share_directory('py_test'),  # 替换为你的包名
        'maps',
        'map.yaml'  # 你的地图文件
    )
    
    # 地图服务器节点（专门用于发布地图）
    map_server_node = Node(
        package='nav2_map_server',
        executable='map_server',
        name='map_server',
        parameters=[{
            'yaml_filename': map_file,
            'use_sim_time': True  # 仿真环境需要
        }],
        output='screen'
    )
    
    # 生命周期管理器（自动启动 map_server）
    lifecycle_node = Node(
        package='nav2_lifecycle_manager',
        executable='lifecycle_manager',
        name='lifecycle_manager_map',
        parameters=[{
            'use_sim_time': True,
            'autostart': True,
            'node_names': ['map_server']
        }],
        output='screen'
    )
    
    return LaunchDescription([
        map_server_node,
        lifecycle_node
    ])
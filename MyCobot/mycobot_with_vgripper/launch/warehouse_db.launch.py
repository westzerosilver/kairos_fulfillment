from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_warehouse_db_launch


def generate_launch_description():
    moveit_config = MoveItConfigsBuilder("mycobot_320", package_name="mycobot_with_vgripper").to_moveit_configs()
    return generate_warehouse_db_launch(moveit_config)

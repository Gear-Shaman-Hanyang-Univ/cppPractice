import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class SLAMNode(Node):
    def __init__(self):
        super().__init__("slam_node")
        self.subscription = self.create_subscription(
            String, "lidar_data", self.listener_callback, 10
        )
        self.get_logger().info("SLAM Node has started")

    def listener_callback(self, msg):
        self.get_logger().info(f"Received LiDAR data: {msg.data}")


def main(args=None):
    rclpy.init(args=args)
    node = SLAMNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

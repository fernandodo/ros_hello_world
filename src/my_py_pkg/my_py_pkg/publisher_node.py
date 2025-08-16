#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64


class NumberPublisherNode(Node):
    def __init__(self):
        super().__init__("number_publisher")
        self.get_logger().info("Number publisher has been started")
        self.counter_ = 0
        self.timer_ = self.create_timer(1.0, self.timer_callback)
        self.publisher_ = self.create_publisher(Int64, "number", 10)
    
    def timer_callback(self):
        self.counter_ += 1
        self.get_logger().info("Publishing: " + str(self.counter_))
        msg = Int64()
        msg.data = self.counter_
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()

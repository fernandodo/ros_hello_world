#include "rclcpp/rclcpp.hpp"

class MyCustomNode : public rclcpp::Node {
public:
  MyCustomNode() : Node("my_node_name"), counter_(0) {
    RCLCPP_INFO(this->get_logger(), "Hello ROS2");
    timer_ =
        this->create_wall_timer(std::chrono::seconds(1),
                                std::bind(&MyCustomNode::timer_callback, this));
  }

private:
  int counter_;
  rclcpp::TimerBase::SharedPtr timer_;

  void timer_callback() {
    RCLCPP_INFO(this->get_logger(), "Hello ROS2: %d", counter_++);
  }
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MyCustomNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
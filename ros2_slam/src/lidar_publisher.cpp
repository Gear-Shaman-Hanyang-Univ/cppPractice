#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "lidar.hpp"
#include <sstream>

class LiDARPublisher : public rclcpp::Node {
public:
    LiDARPublisher() : Node("lidar_publisher"), lidar(5.0), robotPosition(0, 0){
        publisher_ = this -> create_publisher<std_msg::msg::String>("lidar_data", 10);
        // timer_ : 1초마다 publishData 를 호출하도록 설정된 타이머
        timer_ = this -> create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&LiDARPublisher::publishData, this)
        );
        RCLCPP_INFO(this->get_logger(), "LiDAR Publisher started");
    }

private:
    void publishData() {
        std::vector<Point> obstacles = {{3,3},{7,8},{6,2}};
        auto detections = lidar.scan(obstacles, robotPosition);

        std_msgs::msg::String msg;
        std::ostringstream oss;
        for (const auto& point : detections) {
            oss << "(" << point.x << ", " << point.y << ") ";
        }
        msg.data = oss.str();
        publisher_->publish(msg);

        RCLCPP_INFO(this->get_logger(), "Published: %s", msg.data.c_str());
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    LiDAR lidar;
    Point robotPosition;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LiDARPublisher>());
    rclcpp::shutdown();l
    return 0;
}
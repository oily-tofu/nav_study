#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <thread>
#include <termios.h> 
#include <unistd.h>
#include <atomic>

class PubCmd : public rclcpp::Node
{
public:
    PubCmd(const std::string &name) : Node(name)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        // timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&PubCmd::timer_callback, this));

        keyboard_thread_ = std::thread(&PubCmd::keyboardLoop, this);

        RCLCPP_INFO(this->get_logger(),"w: forward");
        RCLCPP_INFO(this->get_logger(),"s: backward");
        RCLCPP_INFO(this->get_logger(),"a: turn left");
        RCLCPP_INFO(this->get_logger(),"d: turn right");
        RCLCPP_INFO(this->get_logger(),"x: stop");
        RCLCPP_INFO(this->get_logger(),"q: quit");
    }

    ~PubCmd()
    {
        running_ = false;
        if (keyboard_thread_.joinable())
        {
            keyboard_thread_.join();
        }
    }
    

private:

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::thread keyboard_thread_;
    std::atomic<bool> running_{true};

    // void timer_callback()
    // {
    //     auto message = geometry_msgs::msg::Twist();
    //     message.linear.x = 1.0;
    //     message.linear.y = 0;
    //     message.angular.z = 0.5;
    //     RCLCPP_INFO(this->get_logger(), "Publishing: linear.x=%f, linear.y=%f, angular.z=%f", message.linear.x, message.linear.y, message.angular.z);
    //     publisher_->publish(message);
    // }

    char getch()
    {
        struct termios oldt;
        struct termios newt;

        tcgetattr(STDIN_FILENO, &oldt);

        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);

        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        char c = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return c;
    }

    void publishCmd(double vx, double wz)
    {
        geometry_msgs::msg::Twist msg;

        msg.linear.x = vx;
        msg.angular.z = wz;

        publisher_->publish(msg);

        RCLCPP_INFO(this->get_logger(),
                    "linear=%.2f angular=%.2f",
                    vx,
                    wz);
    }

    void keyboardLoop()
    {
        while (running_)
        {
            char key = getch();

            switch (key)
            {
                case 'w':
                    publishCmd(1.0, 0.0);
                    break;

                case 's':
                    publishCmd(-1.0, 0.0);
                    break;

                case 'a':
                    publishCmd(0.0, 1.0);
                    break;

                case 'd':
                    publishCmd(0.0, -1.0);
                    break;

                case 'x':
                    publishCmd(0.0, 0.0);
                    break;

                case 'q':
                    rclcpp::shutdown();
                    return;
            }
        }
    }

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PubCmd>("pub_cmd"));
    rclcpp::shutdown();
    return 0;
}
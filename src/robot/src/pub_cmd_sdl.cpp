#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include <SDL2/SDL.h>

class TeleopSDL : public rclcpp::Node
{
public:
    TeleopSDL() : Node("teleop_sdl")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            RCLCPP_ERROR(this->get_logger(), "SDL Init Failed");
            rclcpp::shutdown();
            return;
        }

        window_ = SDL_CreateWindow(
            "ROS2 Teleop",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            400,
            200,
            SDL_WINDOW_SHOWN);

        timer_ = this->create_wall_timer(std::chrono::milliseconds(50),std::bind(&TeleopSDL::update, this));

        RCLCPP_INFO(this->get_logger(), "Focus SDL window then use WASD");
    }

    ~TeleopSDL()
    {
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }

private:

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    SDL_Window *window_{nullptr};

    void update()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                rclcpp::shutdown();
                return;
            }
        }

        const Uint8 *state = SDL_GetKeyboardState(nullptr);

        double linear = 0.0;
        double angular = 0.0;

        if (state[SDL_SCANCODE_W])
            linear += 0.7;

        if (state[SDL_SCANCODE_S])
            linear -= 0.7;

        if (state[SDL_SCANCODE_A])
            angular += 0.7;

        if (state[SDL_SCANCODE_D])
            angular -= 0.7;

        geometry_msgs::msg::Twist msg;
        msg.linear.x = linear;
        msg.angular.z = angular;

        publisher_->publish(msg);

        RCLCPP_INFO_THROTTLE(
            this->get_logger(),
            *this->get_clock(),
            500,
            "linear=%.1f angular=%.1f",
            linear,
            angular);
    }

    
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TeleopSDL>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
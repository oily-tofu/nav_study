#include <memory>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "c_test/action/atest.hpp"

class AtestActionClient : public rclcpp::Node
{
public:
    using Atest = c_test::action::Atest;
    using GoalHandleAtest =
        rclcpp_action::ClientGoalHandle<Atest>;

    AtestActionClient()
    : Node("atest_action_client")
    {
        client_ =
            rclcpp_action::create_client<Atest>(
                this,
                "atest");

        timer_ =
            this->create_wall_timer(
                std::chrono::seconds(1),
                std::bind(
                    &AtestActionClient::send_goal,
                    this));
    }

private:
    rclcpp_action::Client<Atest>::SharedPtr client_;

    rclcpp::TimerBase::SharedPtr timer_;

    void send_goal()
    {
        timer_->cancel();

        if (!client_->wait_for_action_server())
        {
            RCLCPP_ERROR(
                this->get_logger(),
                "Action Server Not Available");

            return;
        }

        auto goal_msg = Atest::Goal();

        goal_msg.order = 10;

        RCLCPP_INFO(
            this->get_logger(),
            "Send Goal");

        auto options =
            rclcpp_action::Client<Atest>::SendGoalOptions();

        options.goal_response_callback =
            std::bind(
                &AtestActionClient::goal_response_callback,
                this,
                std::placeholders::_1);

        options.feedback_callback =
            std::bind(
                &AtestActionClient::feedback_callback,
                this,
                std::placeholders::_1,
                std::placeholders::_2);

        options.result_callback =
            std::bind(
                &AtestActionClient::result_callback,
                this,
                std::placeholders::_1);

        client_->async_send_goal(
            goal_msg,
            options);
    }

    void goal_response_callback(
        const GoalHandleAtest::SharedPtr & goal_handle)
    {
        if (!goal_handle)
        {
            RCLCPP_ERROR(
                this->get_logger(),
                "Goal Rejected");
        }
        else
        {
            RCLCPP_INFO(
                this->get_logger(),
                "Goal Accepted");
        }
    }

    void feedback_callback(
        GoalHandleAtest::SharedPtr,
        const std::shared_ptr<
            const Atest::Feedback> feedback)
    {
        std::stringstream ss;

        ss << "Feedback: ";

        for (auto value :
             feedback->partial_sequence)
        {
            ss << value << " ";
        }

        RCLCPP_INFO(
            this->get_logger(),
            "%s",
            ss.str().c_str());
    }

    void result_callback(
        const GoalHandleAtest::WrappedResult & result)
    {
        std::stringstream ss;

        ss << "Result: ";

        for (auto value :
             result.result->sequence)
        {
            ss << value << " ";
        }

        RCLCPP_INFO(
            this->get_logger(),
            "%s",
            ss.str().c_str());

        rclcpp::shutdown();
    }
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<AtestActionClient>();

    rclcpp::spin(node);

    return 0;
}
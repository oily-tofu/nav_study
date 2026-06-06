#include <functional>
#include <memory>
#include <thread>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "c_test/action/atest.hpp"


//
class AtestActionServer : public rclcpp::Node
{
public:
    using Atest = c_test::action::Atest;
    using GoalHandleAtest = rclcpp_action::ServerGoalHandle<Atest>;

    explicit AtestActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions()): Node("atest_action_server", options)
    {
        using namespace std::placeholders;

        action_server_ =
            rclcpp_action::create_server<Atest>(
                this,
                "atest",
                std::bind(&AtestActionServer::handle_goal,this,_1,_2),
                std::bind(&AtestActionServer::handle_cancel,this,_1),
                std::bind(&AtestActionServer::handle_accepted,this,_1));

        RCLCPP_INFO(this->get_logger(),"Atest Action Server Started");
    }

private:
    rclcpp_action::Server<Atest>::SharedPtr action_server_;

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const Atest::Goal> goal)
    {
        (void)uuid;

        RCLCPP_INFO(
            this->get_logger(),
            "Receive Goal, order=%d",
            goal->order);

        if (goal->order < 1)
        {
            RCLCPP_WARN(
                this->get_logger(),
                "Reject Goal");
            return rclcpp_action::GoalResponse::REJECT;
        }

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleAtest> goal_handle)
    {
        (void)goal_handle;

        RCLCPP_INFO(
            this->get_logger(),
            "Receive Cancel Request");

        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(
        const std::shared_ptr<GoalHandleAtest> goal_handle)
    {
        std::thread(
            [this, goal_handle]()
            {
                execute(goal_handle);
            })
            .detach();
    }

    void execute(
        const std::shared_ptr<GoalHandleAtest> goal_handle)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "Start Execute");

        rclcpp::Rate loop_rate(1);

        const auto goal = goal_handle->get_goal();

        auto feedback =
            std::make_shared<Atest::Feedback>();

        auto result =
            std::make_shared<Atest::Result>();

        auto & sequence =
            feedback->partial_sequence;

        sequence.push_back(0);

        goal_handle->publish_feedback(feedback);

        if (goal->order > 1)
        {
            sequence.push_back(1);

            goal_handle->publish_feedback(feedback);
        }

        for (int i = 2; i < goal->order; ++i)
        {
            if (goal_handle->is_canceling())
            {
                result->sequence = sequence;

                goal_handle->canceled(result);

                RCLCPP_INFO(
                    this->get_logger(),
                    "Goal Canceled");

                return;
            }

            int next =
                sequence[i - 1] +
                sequence[i - 2];

            sequence.push_back(next);

            goal_handle->publish_feedback(feedback);

            RCLCPP_INFO(
                this->get_logger(),
                "Feedback Size=%ld",
                sequence.size());

            loop_rate.sleep();
        }

        result->sequence = sequence;

        goal_handle->succeed(result);

        RCLCPP_INFO(
            this->get_logger(),
            "Goal Succeeded");
    }
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<AtestActionServer>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
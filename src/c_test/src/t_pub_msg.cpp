#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"
#include "c_test/msg/novel.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

/*
    创建一个类节点，名字叫做SingleDogNode,继承自Node.
*/
class SingleDogNode : public rclcpp::Node
{

public:
    // 构造函数,有一个参数为节点名称
    SingleDogNode(std::string name) : Node(name)
    {
        // 打印一句自我介绍
        RCLCPP_INFO(this->get_logger(), "大家好，我是单身狗%s.", name.c_str());
         // 创建一个订阅者来订阅李四写的小说，通过名字sexy_girl
        sub_novel = this->create_subscription<c_test::msg::Novel>
            ("sexy_girl", 
            10,
            std::bind(&SingleDogNode::topic_callback, this, _1));
    }

private:
    // 声明一个订阅者（成员变量）,用于订阅小说
    rclcpp::Subscription<c_test::msg::Novel>::SharedPtr sub_novel;

    // 收到话题数据的回调函数
    void topic_callback(const c_test::msg::Novel::SharedPtr msg)
    {
        int a = msg->a; 
        int b = msg->b; 
        std::string c = msg->c;
        RCLCPP_INFO(this->get_logger(), "朕已阅：'%d---%d---%s'", a, b, c.c_str());
    };

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*产生一个Wang2的节点*/
    auto node = std::make_shared<SingleDogNode>("wang2");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from c_test:action/Atest.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__ACTION__DETAIL__ATEST__BUILDER_HPP_
#define C_TEST__ACTION__DETAIL__ATEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "c_test/action/detail/atest__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_Goal_order
{
public:
  Init_Atest_Goal_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::c_test::action::Atest_Goal order(::c_test::action::Atest_Goal::_order_type arg)
  {
    msg_.order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_Goal>()
{
  return c_test::action::builder::Init_Atest_Goal_order();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_Result_sequence
{
public:
  Init_Atest_Result_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::c_test::action::Atest_Result sequence(::c_test::action::Atest_Result::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_Result>()
{
  return c_test::action::builder::Init_Atest_Result_sequence();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_Feedback_partial_sequence
{
public:
  Init_Atest_Feedback_partial_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::c_test::action::Atest_Feedback partial_sequence(::c_test::action::Atest_Feedback::_partial_sequence_type arg)
  {
    msg_.partial_sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_Feedback>()
{
  return c_test::action::builder::Init_Atest_Feedback_partial_sequence();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_SendGoal_Request_goal
{
public:
  explicit Init_Atest_SendGoal_Request_goal(::c_test::action::Atest_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::c_test::action::Atest_SendGoal_Request goal(::c_test::action::Atest_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_SendGoal_Request msg_;
};

class Init_Atest_SendGoal_Request_goal_id
{
public:
  Init_Atest_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Atest_SendGoal_Request_goal goal_id(::c_test::action::Atest_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Atest_SendGoal_Request_goal(msg_);
  }

private:
  ::c_test::action::Atest_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_SendGoal_Request>()
{
  return c_test::action::builder::Init_Atest_SendGoal_Request_goal_id();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_SendGoal_Response_stamp
{
public:
  explicit Init_Atest_SendGoal_Response_stamp(::c_test::action::Atest_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::c_test::action::Atest_SendGoal_Response stamp(::c_test::action::Atest_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_SendGoal_Response msg_;
};

class Init_Atest_SendGoal_Response_accepted
{
public:
  Init_Atest_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Atest_SendGoal_Response_stamp accepted(::c_test::action::Atest_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Atest_SendGoal_Response_stamp(msg_);
  }

private:
  ::c_test::action::Atest_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_SendGoal_Response>()
{
  return c_test::action::builder::Init_Atest_SendGoal_Response_accepted();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_GetResult_Request_goal_id
{
public:
  Init_Atest_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::c_test::action::Atest_GetResult_Request goal_id(::c_test::action::Atest_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_GetResult_Request>()
{
  return c_test::action::builder::Init_Atest_GetResult_Request_goal_id();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_GetResult_Response_result
{
public:
  explicit Init_Atest_GetResult_Response_result(::c_test::action::Atest_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::c_test::action::Atest_GetResult_Response result(::c_test::action::Atest_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_GetResult_Response msg_;
};

class Init_Atest_GetResult_Response_status
{
public:
  Init_Atest_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Atest_GetResult_Response_result status(::c_test::action::Atest_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Atest_GetResult_Response_result(msg_);
  }

private:
  ::c_test::action::Atest_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_GetResult_Response>()
{
  return c_test::action::builder::Init_Atest_GetResult_Response_status();
}

}  // namespace c_test


namespace c_test
{

namespace action
{

namespace builder
{

class Init_Atest_FeedbackMessage_feedback
{
public:
  explicit Init_Atest_FeedbackMessage_feedback(::c_test::action::Atest_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::c_test::action::Atest_FeedbackMessage feedback(::c_test::action::Atest_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::action::Atest_FeedbackMessage msg_;
};

class Init_Atest_FeedbackMessage_goal_id
{
public:
  Init_Atest_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Atest_FeedbackMessage_feedback goal_id(::c_test::action::Atest_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Atest_FeedbackMessage_feedback(msg_);
  }

private:
  ::c_test::action::Atest_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::action::Atest_FeedbackMessage>()
{
  return c_test::action::builder::Init_Atest_FeedbackMessage_goal_id();
}

}  // namespace c_test

#endif  // C_TEST__ACTION__DETAIL__ATEST__BUILDER_HPP_

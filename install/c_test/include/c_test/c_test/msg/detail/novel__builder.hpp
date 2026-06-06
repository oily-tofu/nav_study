// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from c_test:msg/Novel.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__MSG__DETAIL__NOVEL__BUILDER_HPP_
#define C_TEST__MSG__DETAIL__NOVEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "c_test/msg/detail/novel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace c_test
{

namespace msg
{

namespace builder
{

class Init_Novel_c
{
public:
  explicit Init_Novel_c(::c_test::msg::Novel & msg)
  : msg_(msg)
  {}
  ::c_test::msg::Novel c(::c_test::msg::Novel::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::c_test::msg::Novel msg_;
};

class Init_Novel_b
{
public:
  explicit Init_Novel_b(::c_test::msg::Novel & msg)
  : msg_(msg)
  {}
  Init_Novel_c b(::c_test::msg::Novel::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_Novel_c(msg_);
  }

private:
  ::c_test::msg::Novel msg_;
};

class Init_Novel_a
{
public:
  Init_Novel_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Novel_b a(::c_test::msg::Novel::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_Novel_b(msg_);
  }

private:
  ::c_test::msg::Novel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::c_test::msg::Novel>()
{
  return c_test::msg::builder::Init_Novel_a();
}

}  // namespace c_test

#endif  // C_TEST__MSG__DETAIL__NOVEL__BUILDER_HPP_

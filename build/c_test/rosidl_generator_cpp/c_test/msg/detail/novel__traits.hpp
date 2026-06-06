// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from c_test:msg/Novel.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__MSG__DETAIL__NOVEL__TRAITS_HPP_
#define C_TEST__MSG__DETAIL__NOVEL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "c_test/msg/detail/novel__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace c_test
{

namespace msg
{

inline void to_flow_style_yaml(
  const Novel & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: c
  {
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Novel & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Novel & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace c_test

namespace rosidl_generator_traits
{

[[deprecated("use c_test::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const c_test::msg::Novel & msg,
  std::ostream & out, size_t indentation = 0)
{
  c_test::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use c_test::msg::to_yaml() instead")]]
inline std::string to_yaml(const c_test::msg::Novel & msg)
{
  return c_test::msg::to_yaml(msg);
}

template<>
inline const char * data_type<c_test::msg::Novel>()
{
  return "c_test::msg::Novel";
}

template<>
inline const char * name<c_test::msg::Novel>()
{
  return "c_test/msg/Novel";
}

template<>
struct has_fixed_size<c_test::msg::Novel>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<c_test::msg::Novel>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<c_test::msg::Novel>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // C_TEST__MSG__DETAIL__NOVEL__TRAITS_HPP_

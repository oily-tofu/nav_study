// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from c_test:msg/Novel.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__MSG__DETAIL__NOVEL__STRUCT_HPP_
#define C_TEST__MSG__DETAIL__NOVEL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__c_test__msg__Novel __attribute__((deprecated))
#else
# define DEPRECATED__c_test__msg__Novel __declspec(deprecated)
#endif

namespace c_test
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Novel_
{
  using Type = Novel_<ContainerAllocator>;

  explicit Novel_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0l;
      this->b = 0l;
      this->c = "";
    }
  }

  explicit Novel_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : c(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0l;
      this->b = 0l;
      this->c = "";
    }
  }

  // field types and members
  using _a_type =
    int32_t;
  _a_type a;
  using _b_type =
    int32_t;
  _b_type b;
  using _c_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _c_type c;

  // setters for named parameter idiom
  Type & set__a(
    const int32_t & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const int32_t & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__c(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->c = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    c_test::msg::Novel_<ContainerAllocator> *;
  using ConstRawPtr =
    const c_test::msg::Novel_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<c_test::msg::Novel_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<c_test::msg::Novel_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      c_test::msg::Novel_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<c_test::msg::Novel_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      c_test::msg::Novel_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<c_test::msg::Novel_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<c_test::msg::Novel_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<c_test::msg::Novel_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__c_test__msg__Novel
    std::shared_ptr<c_test::msg::Novel_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__c_test__msg__Novel
    std::shared_ptr<c_test::msg::Novel_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Novel_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->c != other.c) {
      return false;
    }
    return true;
  }
  bool operator!=(const Novel_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Novel_

// alias to use template instance with default allocator
using Novel =
  c_test::msg::Novel_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace c_test

#endif  // C_TEST__MSG__DETAIL__NOVEL__STRUCT_HPP_

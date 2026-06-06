// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from c_test:msg/Novel.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__MSG__DETAIL__NOVEL__STRUCT_H_
#define C_TEST__MSG__DETAIL__NOVEL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'c'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Novel in the package c_test.
typedef struct c_test__msg__Novel
{
  int32_t a;
  int32_t b;
  rosidl_runtime_c__String c;
} c_test__msg__Novel;

// Struct for a sequence of c_test__msg__Novel.
typedef struct c_test__msg__Novel__Sequence
{
  c_test__msg__Novel * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__msg__Novel__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // C_TEST__MSG__DETAIL__NOVEL__STRUCT_H_

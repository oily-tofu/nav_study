// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from c_test:action/Atest.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__ACTION__DETAIL__ATEST__STRUCT_H_
#define C_TEST__ACTION__DETAIL__ATEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_Goal
{
  /// 客户端 → 服务端：发送的目标
  int32_t order;
} c_test__action__Atest_Goal;

// Struct for a sequence of c_test__action__Atest_Goal.
typedef struct c_test__action__Atest_Goal__Sequence
{
  c_test__action__Atest_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'sequence'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_Result
{
  /// 服务端 → 客户端：最终结果
  rosidl_runtime_c__int32__Sequence sequence;
} c_test__action__Atest_Result;

// Struct for a sequence of c_test__action__Atest_Result.
typedef struct c_test__action__Atest_Result__Sequence
{
  c_test__action__Atest_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'partial_sequence'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_Feedback
{
  /// 服务端 → 客户端：中间反馈
  rosidl_runtime_c__int32__Sequence partial_sequence;
} c_test__action__Atest_Feedback;

// Struct for a sequence of c_test__action__Atest_Feedback.
typedef struct c_test__action__Atest_Feedback__Sequence
{
  c_test__action__Atest_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "c_test/action/detail/atest__struct.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  c_test__action__Atest_Goal goal;
} c_test__action__Atest_SendGoal_Request;

// Struct for a sequence of c_test__action__Atest_SendGoal_Request.
typedef struct c_test__action__Atest_SendGoal_Request__Sequence
{
  c_test__action__Atest_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} c_test__action__Atest_SendGoal_Response;

// Struct for a sequence of c_test__action__Atest_SendGoal_Response.
typedef struct c_test__action__Atest_SendGoal_Response__Sequence
{
  c_test__action__Atest_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} c_test__action__Atest_GetResult_Request;

// Struct for a sequence of c_test__action__Atest_GetResult_Request.
typedef struct c_test__action__Atest_GetResult_Request__Sequence
{
  c_test__action__Atest_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "c_test/action/detail/atest__struct.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_GetResult_Response
{
  int8_t status;
  c_test__action__Atest_Result result;
} c_test__action__Atest_GetResult_Response;

// Struct for a sequence of c_test__action__Atest_GetResult_Response.
typedef struct c_test__action__Atest_GetResult_Response__Sequence
{
  c_test__action__Atest_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "c_test/action/detail/atest__struct.h"

/// Struct defined in action/Atest in the package c_test.
typedef struct c_test__action__Atest_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  c_test__action__Atest_Feedback feedback;
} c_test__action__Atest_FeedbackMessage;

// Struct for a sequence of c_test__action__Atest_FeedbackMessage.
typedef struct c_test__action__Atest_FeedbackMessage__Sequence
{
  c_test__action__Atest_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} c_test__action__Atest_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // C_TEST__ACTION__DETAIL__ATEST__STRUCT_H_

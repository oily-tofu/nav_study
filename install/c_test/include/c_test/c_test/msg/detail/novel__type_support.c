// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from c_test:msg/Novel.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "c_test/msg/detail/novel__rosidl_typesupport_introspection_c.h"
#include "c_test/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "c_test/msg/detail/novel__functions.h"
#include "c_test/msg/detail/novel__struct.h"


// Include directives for member types
// Member `c`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  c_test__msg__Novel__init(message_memory);
}

void c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_fini_function(void * message_memory)
{
  c_test__msg__Novel__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_member_array[3] = {
  {
    "a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_test__msg__Novel, a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_test__msg__Novel, b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "c",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(c_test__msg__Novel, c),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_members = {
  "c_test__msg",  // message namespace
  "Novel",  // message name
  3,  // number of fields
  sizeof(c_test__msg__Novel),
  c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_member_array,  // message members
  c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_init_function,  // function to initialize message memory (memory has to be allocated)
  c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_type_support_handle = {
  0,
  &c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_c_test
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, c_test, msg, Novel)() {
  if (!c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_type_support_handle.typesupport_identifier) {
    c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &c_test__msg__Novel__rosidl_typesupport_introspection_c__Novel_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

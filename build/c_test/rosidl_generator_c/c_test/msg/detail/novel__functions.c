// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from c_test:msg/Novel.idl
// generated code does not contain a copyright notice
#include "c_test/msg/detail/novel__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `c`
#include "rosidl_runtime_c/string_functions.h"

bool
c_test__msg__Novel__init(c_test__msg__Novel * msg)
{
  if (!msg) {
    return false;
  }
  // a
  // b
  // c
  if (!rosidl_runtime_c__String__init(&msg->c)) {
    c_test__msg__Novel__fini(msg);
    return false;
  }
  return true;
}

void
c_test__msg__Novel__fini(c_test__msg__Novel * msg)
{
  if (!msg) {
    return;
  }
  // a
  // b
  // c
  rosidl_runtime_c__String__fini(&msg->c);
}

bool
c_test__msg__Novel__are_equal(const c_test__msg__Novel * lhs, const c_test__msg__Novel * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  // c
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->c), &(rhs->c)))
  {
    return false;
  }
  return true;
}

bool
c_test__msg__Novel__copy(
  const c_test__msg__Novel * input,
  c_test__msg__Novel * output)
{
  if (!input || !output) {
    return false;
  }
  // a
  output->a = input->a;
  // b
  output->b = input->b;
  // c
  if (!rosidl_runtime_c__String__copy(
      &(input->c), &(output->c)))
  {
    return false;
  }
  return true;
}

c_test__msg__Novel *
c_test__msg__Novel__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c_test__msg__Novel * msg = (c_test__msg__Novel *)allocator.allocate(sizeof(c_test__msg__Novel), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(c_test__msg__Novel));
  bool success = c_test__msg__Novel__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
c_test__msg__Novel__destroy(c_test__msg__Novel * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    c_test__msg__Novel__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
c_test__msg__Novel__Sequence__init(c_test__msg__Novel__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c_test__msg__Novel * data = NULL;

  if (size) {
    data = (c_test__msg__Novel *)allocator.zero_allocate(size, sizeof(c_test__msg__Novel), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = c_test__msg__Novel__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        c_test__msg__Novel__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
c_test__msg__Novel__Sequence__fini(c_test__msg__Novel__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      c_test__msg__Novel__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

c_test__msg__Novel__Sequence *
c_test__msg__Novel__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c_test__msg__Novel__Sequence * array = (c_test__msg__Novel__Sequence *)allocator.allocate(sizeof(c_test__msg__Novel__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = c_test__msg__Novel__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
c_test__msg__Novel__Sequence__destroy(c_test__msg__Novel__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    c_test__msg__Novel__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
c_test__msg__Novel__Sequence__are_equal(const c_test__msg__Novel__Sequence * lhs, const c_test__msg__Novel__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!c_test__msg__Novel__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
c_test__msg__Novel__Sequence__copy(
  const c_test__msg__Novel__Sequence * input,
  c_test__msg__Novel__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(c_test__msg__Novel);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    c_test__msg__Novel * data =
      (c_test__msg__Novel *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!c_test__msg__Novel__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          c_test__msg__Novel__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!c_test__msg__Novel__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

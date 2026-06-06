// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from c_test:action/Atest.idl
// generated code does not contain a copyright notice

#ifndef C_TEST__ACTION__DETAIL__ATEST__FUNCTIONS_H_
#define C_TEST__ACTION__DETAIL__ATEST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "c_test/msg/rosidl_generator_c__visibility_control.h"

#include "c_test/action/detail/atest__struct.h"

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_Goal
 * )) before or use
 * c_test__action__Atest_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Goal__init(c_test__action__Atest_Goal * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Goal__fini(c_test__action__Atest_Goal * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_Goal *
c_test__action__Atest_Goal__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Goal__destroy(c_test__action__Atest_Goal * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Goal__are_equal(const c_test__action__Atest_Goal * lhs, const c_test__action__Atest_Goal * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Goal__copy(
  const c_test__action__Atest_Goal * input,
  c_test__action__Atest_Goal * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Goal__Sequence__init(c_test__action__Atest_Goal__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Goal__Sequence__fini(c_test__action__Atest_Goal__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_Goal__Sequence *
c_test__action__Atest_Goal__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Goal__Sequence__destroy(c_test__action__Atest_Goal__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Goal__Sequence__are_equal(const c_test__action__Atest_Goal__Sequence * lhs, const c_test__action__Atest_Goal__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Goal__Sequence__copy(
  const c_test__action__Atest_Goal__Sequence * input,
  c_test__action__Atest_Goal__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_Result
 * )) before or use
 * c_test__action__Atest_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Result__init(c_test__action__Atest_Result * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Result__fini(c_test__action__Atest_Result * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_Result *
c_test__action__Atest_Result__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Result__destroy(c_test__action__Atest_Result * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Result__are_equal(const c_test__action__Atest_Result * lhs, const c_test__action__Atest_Result * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Result__copy(
  const c_test__action__Atest_Result * input,
  c_test__action__Atest_Result * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Result__Sequence__init(c_test__action__Atest_Result__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Result__Sequence__fini(c_test__action__Atest_Result__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_Result__Sequence *
c_test__action__Atest_Result__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Result__Sequence__destroy(c_test__action__Atest_Result__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Result__Sequence__are_equal(const c_test__action__Atest_Result__Sequence * lhs, const c_test__action__Atest_Result__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Result__Sequence__copy(
  const c_test__action__Atest_Result__Sequence * input,
  c_test__action__Atest_Result__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_Feedback
 * )) before or use
 * c_test__action__Atest_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Feedback__init(c_test__action__Atest_Feedback * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Feedback__fini(c_test__action__Atest_Feedback * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_Feedback *
c_test__action__Atest_Feedback__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Feedback__destroy(c_test__action__Atest_Feedback * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Feedback__are_equal(const c_test__action__Atest_Feedback * lhs, const c_test__action__Atest_Feedback * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Feedback__copy(
  const c_test__action__Atest_Feedback * input,
  c_test__action__Atest_Feedback * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Feedback__Sequence__init(c_test__action__Atest_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Feedback__Sequence__fini(c_test__action__Atest_Feedback__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_Feedback__Sequence *
c_test__action__Atest_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_Feedback__Sequence__destroy(c_test__action__Atest_Feedback__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Feedback__Sequence__are_equal(const c_test__action__Atest_Feedback__Sequence * lhs, const c_test__action__Atest_Feedback__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_Feedback__Sequence__copy(
  const c_test__action__Atest_Feedback__Sequence * input,
  c_test__action__Atest_Feedback__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_SendGoal_Request
 * )) before or use
 * c_test__action__Atest_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Request__init(c_test__action__Atest_SendGoal_Request * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Request__fini(c_test__action__Atest_SendGoal_Request * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_SendGoal_Request *
c_test__action__Atest_SendGoal_Request__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Request__destroy(c_test__action__Atest_SendGoal_Request * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Request__are_equal(const c_test__action__Atest_SendGoal_Request * lhs, const c_test__action__Atest_SendGoal_Request * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Request__copy(
  const c_test__action__Atest_SendGoal_Request * input,
  c_test__action__Atest_SendGoal_Request * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Request__Sequence__init(c_test__action__Atest_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Request__Sequence__fini(c_test__action__Atest_SendGoal_Request__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_SendGoal_Request__Sequence *
c_test__action__Atest_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Request__Sequence__destroy(c_test__action__Atest_SendGoal_Request__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Request__Sequence__are_equal(const c_test__action__Atest_SendGoal_Request__Sequence * lhs, const c_test__action__Atest_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Request__Sequence__copy(
  const c_test__action__Atest_SendGoal_Request__Sequence * input,
  c_test__action__Atest_SendGoal_Request__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_SendGoal_Response
 * )) before or use
 * c_test__action__Atest_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Response__init(c_test__action__Atest_SendGoal_Response * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Response__fini(c_test__action__Atest_SendGoal_Response * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_SendGoal_Response *
c_test__action__Atest_SendGoal_Response__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Response__destroy(c_test__action__Atest_SendGoal_Response * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Response__are_equal(const c_test__action__Atest_SendGoal_Response * lhs, const c_test__action__Atest_SendGoal_Response * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Response__copy(
  const c_test__action__Atest_SendGoal_Response * input,
  c_test__action__Atest_SendGoal_Response * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Response__Sequence__init(c_test__action__Atest_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Response__Sequence__fini(c_test__action__Atest_SendGoal_Response__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_SendGoal_Response__Sequence *
c_test__action__Atest_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_SendGoal_Response__Sequence__destroy(c_test__action__Atest_SendGoal_Response__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Response__Sequence__are_equal(const c_test__action__Atest_SendGoal_Response__Sequence * lhs, const c_test__action__Atest_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_SendGoal_Response__Sequence__copy(
  const c_test__action__Atest_SendGoal_Response__Sequence * input,
  c_test__action__Atest_SendGoal_Response__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_GetResult_Request
 * )) before or use
 * c_test__action__Atest_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Request__init(c_test__action__Atest_GetResult_Request * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Request__fini(c_test__action__Atest_GetResult_Request * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_GetResult_Request *
c_test__action__Atest_GetResult_Request__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Request__destroy(c_test__action__Atest_GetResult_Request * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Request__are_equal(const c_test__action__Atest_GetResult_Request * lhs, const c_test__action__Atest_GetResult_Request * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Request__copy(
  const c_test__action__Atest_GetResult_Request * input,
  c_test__action__Atest_GetResult_Request * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Request__Sequence__init(c_test__action__Atest_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Request__Sequence__fini(c_test__action__Atest_GetResult_Request__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_GetResult_Request__Sequence *
c_test__action__Atest_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Request__Sequence__destroy(c_test__action__Atest_GetResult_Request__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Request__Sequence__are_equal(const c_test__action__Atest_GetResult_Request__Sequence * lhs, const c_test__action__Atest_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Request__Sequence__copy(
  const c_test__action__Atest_GetResult_Request__Sequence * input,
  c_test__action__Atest_GetResult_Request__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_GetResult_Response
 * )) before or use
 * c_test__action__Atest_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Response__init(c_test__action__Atest_GetResult_Response * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Response__fini(c_test__action__Atest_GetResult_Response * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_GetResult_Response *
c_test__action__Atest_GetResult_Response__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Response__destroy(c_test__action__Atest_GetResult_Response * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Response__are_equal(const c_test__action__Atest_GetResult_Response * lhs, const c_test__action__Atest_GetResult_Response * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Response__copy(
  const c_test__action__Atest_GetResult_Response * input,
  c_test__action__Atest_GetResult_Response * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Response__Sequence__init(c_test__action__Atest_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Response__Sequence__fini(c_test__action__Atest_GetResult_Response__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_GetResult_Response__Sequence *
c_test__action__Atest_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_GetResult_Response__Sequence__destroy(c_test__action__Atest_GetResult_Response__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Response__Sequence__are_equal(const c_test__action__Atest_GetResult_Response__Sequence * lhs, const c_test__action__Atest_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_GetResult_Response__Sequence__copy(
  const c_test__action__Atest_GetResult_Response__Sequence * input,
  c_test__action__Atest_GetResult_Response__Sequence * output);

/// Initialize action/Atest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * c_test__action__Atest_FeedbackMessage
 * )) before or use
 * c_test__action__Atest_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_FeedbackMessage__init(c_test__action__Atest_FeedbackMessage * msg);

/// Finalize action/Atest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_FeedbackMessage__fini(c_test__action__Atest_FeedbackMessage * msg);

/// Create action/Atest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * c_test__action__Atest_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_FeedbackMessage *
c_test__action__Atest_FeedbackMessage__create();

/// Destroy action/Atest message.
/**
 * It calls
 * c_test__action__Atest_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_FeedbackMessage__destroy(c_test__action__Atest_FeedbackMessage * msg);

/// Check for action/Atest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_FeedbackMessage__are_equal(const c_test__action__Atest_FeedbackMessage * lhs, const c_test__action__Atest_FeedbackMessage * rhs);

/// Copy a action/Atest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_FeedbackMessage__copy(
  const c_test__action__Atest_FeedbackMessage * input,
  c_test__action__Atest_FeedbackMessage * output);

/// Initialize array of action/Atest messages.
/**
 * It allocates the memory for the number of elements and calls
 * c_test__action__Atest_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_FeedbackMessage__Sequence__init(c_test__action__Atest_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_FeedbackMessage__Sequence__fini(c_test__action__Atest_FeedbackMessage__Sequence * array);

/// Create array of action/Atest messages.
/**
 * It allocates the memory for the array and calls
 * c_test__action__Atest_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
c_test__action__Atest_FeedbackMessage__Sequence *
c_test__action__Atest_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Atest messages.
/**
 * It calls
 * c_test__action__Atest_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
void
c_test__action__Atest_FeedbackMessage__Sequence__destroy(c_test__action__Atest_FeedbackMessage__Sequence * array);

/// Check for action/Atest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_FeedbackMessage__Sequence__are_equal(const c_test__action__Atest_FeedbackMessage__Sequence * lhs, const c_test__action__Atest_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Atest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_c_test
bool
c_test__action__Atest_FeedbackMessage__Sequence__copy(
  const c_test__action__Atest_FeedbackMessage__Sequence * input,
  c_test__action__Atest_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // C_TEST__ACTION__DETAIL__ATEST__FUNCTIONS_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_interfaces:action/StateACT.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__STRUCT_H_
#define MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_Goal
{
  bool trigger;
  int8_t target;
} mycobot_interfaces__action__StateACT_Goal;

// Struct for a sequence of mycobot_interfaces__action__StateACT_Goal.
typedef struct mycobot_interfaces__action__StateACT_Goal__Sequence
{
  mycobot_interfaces__action__StateACT_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_Result
{
  bool endflag;
  int8_t result;
} mycobot_interfaces__action__StateACT_Result;

// Struct for a sequence of mycobot_interfaces__action__StateACT_Result.
typedef struct mycobot_interfaces__action__StateACT_Result__Sequence
{
  mycobot_interfaces__action__StateACT_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_Feedback
{
  int8_t state;
} mycobot_interfaces__action__StateACT_Feedback;

// Struct for a sequence of mycobot_interfaces__action__StateACT_Feedback.
typedef struct mycobot_interfaces__action__StateACT_Feedback__Sequence
{
  mycobot_interfaces__action__StateACT_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "mycobot_interfaces/action/detail/state_act__struct.h"

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  mycobot_interfaces__action__StateACT_Goal goal;
} mycobot_interfaces__action__StateACT_SendGoal_Request;

// Struct for a sequence of mycobot_interfaces__action__StateACT_SendGoal_Request.
typedef struct mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence
{
  mycobot_interfaces__action__StateACT_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} mycobot_interfaces__action__StateACT_SendGoal_Response;

// Struct for a sequence of mycobot_interfaces__action__StateACT_SendGoal_Response.
typedef struct mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence
{
  mycobot_interfaces__action__StateACT_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} mycobot_interfaces__action__StateACT_GetResult_Request;

// Struct for a sequence of mycobot_interfaces__action__StateACT_GetResult_Request.
typedef struct mycobot_interfaces__action__StateACT_GetResult_Request__Sequence
{
  mycobot_interfaces__action__StateACT_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_GetResult_Response
{
  int8_t status;
  mycobot_interfaces__action__StateACT_Result result;
} mycobot_interfaces__action__StateACT_GetResult_Response;

// Struct for a sequence of mycobot_interfaces__action__StateACT_GetResult_Response.
typedef struct mycobot_interfaces__action__StateACT_GetResult_Response__Sequence
{
  mycobot_interfaces__action__StateACT_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"

/// Struct defined in action/StateACT in the package mycobot_interfaces.
typedef struct mycobot_interfaces__action__StateACT_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  mycobot_interfaces__action__StateACT_Feedback feedback;
} mycobot_interfaces__action__StateACT_FeedbackMessage;

// Struct for a sequence of mycobot_interfaces__action__StateACT_FeedbackMessage.
typedef struct mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence
{
  mycobot_interfaces__action__StateACT_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__STRUCT_H_

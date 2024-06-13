// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_interfaces:srv/DetectionRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__STRUCT_H_
#define MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DetectionRQ in the package mycobot_interfaces.
typedef struct mycobot_interfaces__srv__DetectionRQ_Request
{
  bool trigger;
} mycobot_interfaces__srv__DetectionRQ_Request;

// Struct for a sequence of mycobot_interfaces__srv__DetectionRQ_Request.
typedef struct mycobot_interfaces__srv__DetectionRQ_Request__Sequence
{
  mycobot_interfaces__srv__DetectionRQ_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__srv__DetectionRQ_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "vision_msgs/msg/detail/detection2_d_array__struct.h"

/// Struct defined in srv/DetectionRQ in the package mycobot_interfaces.
typedef struct mycobot_interfaces__srv__DetectionRQ_Response
{
  vision_msgs__msg__Detection2DArray result;
} mycobot_interfaces__srv__DetectionRQ_Response;

// Struct for a sequence of mycobot_interfaces__srv__DetectionRQ_Response.
typedef struct mycobot_interfaces__srv__DetectionRQ_Response__Sequence
{
  mycobot_interfaces__srv__DetectionRQ_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_interfaces__srv__DetectionRQ_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__STRUCT_H_

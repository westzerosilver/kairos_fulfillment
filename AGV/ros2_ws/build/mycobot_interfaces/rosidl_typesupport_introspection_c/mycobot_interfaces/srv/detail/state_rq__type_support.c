// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mycobot_interfaces:srv/StateRQ.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mycobot_interfaces/srv/detail/state_rq__rosidl_typesupport_introspection_c.h"
#include "mycobot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mycobot_interfaces/srv/detail/state_rq__functions.h"
#include "mycobot_interfaces/srv/detail/state_rq__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mycobot_interfaces__srv__StateRQ_Request__init(message_memory);
}

void mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_fini_function(void * message_memory)
{
  mycobot_interfaces__srv__StateRQ_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_member_array[2] = {
  {
    "trigger",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mycobot_interfaces__srv__StateRQ_Request, trigger),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mycobot_interfaces__srv__StateRQ_Request, target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_members = {
  "mycobot_interfaces__srv",  // message namespace
  "StateRQ_Request",  // message name
  2,  // number of fields
  sizeof(mycobot_interfaces__srv__StateRQ_Request),
  mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_member_array,  // message members
  mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_type_support_handle = {
  0,
  &mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ_Request)() {
  if (!mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_type_support_handle.typesupport_identifier) {
    mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mycobot_interfaces__srv__StateRQ_Request__rosidl_typesupport_introspection_c__StateRQ_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "mycobot_interfaces/srv/detail/state_rq__rosidl_typesupport_introspection_c.h"
// already included above
// #include "mycobot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "mycobot_interfaces/srv/detail/state_rq__functions.h"
// already included above
// #include "mycobot_interfaces/srv/detail/state_rq__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mycobot_interfaces__srv__StateRQ_Response__init(message_memory);
}

void mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_fini_function(void * message_memory)
{
  mycobot_interfaces__srv__StateRQ_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_member_array[2] = {
  {
    "endflag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mycobot_interfaces__srv__StateRQ_Response, endflag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mycobot_interfaces__srv__StateRQ_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_members = {
  "mycobot_interfaces__srv",  // message namespace
  "StateRQ_Response",  // message name
  2,  // number of fields
  sizeof(mycobot_interfaces__srv__StateRQ_Response),
  mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_member_array,  // message members
  mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_type_support_handle = {
  0,
  &mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ_Response)() {
  if (!mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_type_support_handle.typesupport_identifier) {
    mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mycobot_interfaces__srv__StateRQ_Response__rosidl_typesupport_introspection_c__StateRQ_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "mycobot_interfaces/srv/detail/state_rq__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_members = {
  "mycobot_interfaces__srv",  // service namespace
  "StateRQ",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_Request_message_type_support_handle,
  NULL  // response message
  // mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_Response_message_type_support_handle
};

static rosidl_service_type_support_t mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_type_support_handle = {
  0,
  &mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mycobot_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ)() {
  if (!mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_type_support_handle.typesupport_identifier) {
    mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, srv, StateRQ_Response)()->data;
  }

  return &mycobot_interfaces__srv__detail__state_rq__rosidl_typesupport_introspection_c__StateRQ_service_type_support_handle;
}

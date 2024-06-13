// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from mycobot_interfaces:action/StateACT.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "mycobot_interfaces/action/detail/state_act__struct.h"
#include "mycobot_interfaces/action/detail/state_act__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_Goal_type_support_ids_t;

static const _StateACT_Goal_type_support_ids_t _StateACT_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_Goal_type_support_symbol_names_t _StateACT_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_Goal)),
  }
};

typedef struct _StateACT_Goal_type_support_data_t
{
  void * data[2];
} _StateACT_Goal_type_support_data_t;

static _StateACT_Goal_type_support_data_t _StateACT_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_Goal_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_Goal)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_Result_type_support_ids_t;

static const _StateACT_Result_type_support_ids_t _StateACT_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_Result_type_support_symbol_names_t _StateACT_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_Result)),
  }
};

typedef struct _StateACT_Result_type_support_data_t
{
  void * data[2];
} _StateACT_Result_type_support_data_t;

static _StateACT_Result_type_support_data_t _StateACT_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_Result_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_Result_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_Result_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_Result)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_Feedback_type_support_ids_t;

static const _StateACT_Feedback_type_support_ids_t _StateACT_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_Feedback_type_support_symbol_names_t _StateACT_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_Feedback)),
  }
};

typedef struct _StateACT_Feedback_type_support_data_t
{
  void * data[2];
} _StateACT_Feedback_type_support_data_t;

static _StateACT_Feedback_type_support_data_t _StateACT_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_Feedback_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_Feedback)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_SendGoal_Request_type_support_ids_t;

static const _StateACT_SendGoal_Request_type_support_ids_t _StateACT_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_SendGoal_Request_type_support_symbol_names_t _StateACT_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_SendGoal_Request)),
  }
};

typedef struct _StateACT_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _StateACT_SendGoal_Request_type_support_data_t;

static _StateACT_SendGoal_Request_type_support_data_t _StateACT_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_SendGoal_Request_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_SendGoal_Request)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_SendGoal_Response_type_support_ids_t;

static const _StateACT_SendGoal_Response_type_support_ids_t _StateACT_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_SendGoal_Response_type_support_symbol_names_t _StateACT_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_SendGoal_Response)),
  }
};

typedef struct _StateACT_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _StateACT_SendGoal_Response_type_support_data_t;

static _StateACT_SendGoal_Response_type_support_data_t _StateACT_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_SendGoal_Response_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_SendGoal_Response)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_SendGoal_type_support_ids_t;

static const _StateACT_SendGoal_type_support_ids_t _StateACT_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_SendGoal_type_support_symbol_names_t _StateACT_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_SendGoal)),
  }
};

typedef struct _StateACT_SendGoal_type_support_data_t
{
  void * data[2];
} _StateACT_SendGoal_type_support_data_t;

static _StateACT_SendGoal_type_support_data_t _StateACT_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_SendGoal_service_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_StateACT_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_StateACT_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t StateACT_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_SendGoal)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_GetResult_Request_type_support_ids_t;

static const _StateACT_GetResult_Request_type_support_ids_t _StateACT_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_GetResult_Request_type_support_symbol_names_t _StateACT_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_GetResult_Request)),
  }
};

typedef struct _StateACT_GetResult_Request_type_support_data_t
{
  void * data[2];
} _StateACT_GetResult_Request_type_support_data_t;

static _StateACT_GetResult_Request_type_support_data_t _StateACT_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_GetResult_Request_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_GetResult_Request)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_GetResult_Response_type_support_ids_t;

static const _StateACT_GetResult_Response_type_support_ids_t _StateACT_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_GetResult_Response_type_support_symbol_names_t _StateACT_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_GetResult_Response)),
  }
};

typedef struct _StateACT_GetResult_Response_type_support_data_t
{
  void * data[2];
} _StateACT_GetResult_Response_type_support_data_t;

static _StateACT_GetResult_Response_type_support_data_t _StateACT_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_GetResult_Response_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_GetResult_Response)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_GetResult_type_support_ids_t;

static const _StateACT_GetResult_type_support_ids_t _StateACT_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_GetResult_type_support_symbol_names_t _StateACT_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_GetResult)),
  }
};

typedef struct _StateACT_GetResult_type_support_data_t
{
  void * data[2];
} _StateACT_GetResult_type_support_data_t;

static _StateACT_GetResult_type_support_data_t _StateACT_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_GetResult_service_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_StateACT_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_StateACT_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t StateACT_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_GetResult)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mycobot_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _StateACT_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _StateACT_FeedbackMessage_type_support_ids_t;

static const _StateACT_FeedbackMessage_type_support_ids_t _StateACT_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _StateACT_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _StateACT_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _StateACT_FeedbackMessage_type_support_symbol_names_t _StateACT_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mycobot_interfaces, action, StateACT_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mycobot_interfaces, action, StateACT_FeedbackMessage)),
  }
};

typedef struct _StateACT_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _StateACT_FeedbackMessage_type_support_data_t;

static _StateACT_FeedbackMessage_type_support_data_t _StateACT_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _StateACT_FeedbackMessage_message_typesupport_map = {
  2,
  "mycobot_interfaces",
  &_StateACT_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_StateACT_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_StateACT_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t StateACT_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_StateACT_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mycobot_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mycobot_interfaces, action, StateACT_FeedbackMessage)() {
  return &::mycobot_interfaces::action::rosidl_typesupport_c::StateACT_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "mycobot_interfaces/action/state_act.h"
// already included above
// #include "mycobot_interfaces/action/detail/state_act__type_support.h"

static rosidl_action_type_support_t _mycobot_interfaces__action__StateACT__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, mycobot_interfaces, action, StateACT)()
{
  // Thread-safe by always writing the same values to the static struct
  _mycobot_interfaces__action__StateACT__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, mycobot_interfaces, action, StateACT_SendGoal)();
  _mycobot_interfaces__action__StateACT__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, mycobot_interfaces, action, StateACT_GetResult)();
  _mycobot_interfaces__action__StateACT__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _mycobot_interfaces__action__StateACT__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, mycobot_interfaces, action, StateACT_FeedbackMessage)();
  _mycobot_interfaces__action__StateACT__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_mycobot_interfaces__action__StateACT__typesupport_c;
}

#ifdef __cplusplus
}
#endif

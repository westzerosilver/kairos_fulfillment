// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mycobot_interfaces:srv/DetectionRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__TRAITS_HPP_
#define MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mycobot_interfaces/srv/detail/detection_rq__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mycobot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectionRQ_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: trigger
  {
    out << "trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionRQ_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: trigger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionRQ_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mycobot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mycobot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mycobot_interfaces::srv::DetectionRQ_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_interfaces::srv::DetectionRQ_Request & msg)
{
  return mycobot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_interfaces::srv::DetectionRQ_Request>()
{
  return "mycobot_interfaces::srv::DetectionRQ_Request";
}

template<>
inline const char * name<mycobot_interfaces::srv::DetectionRQ_Request>()
{
  return "mycobot_interfaces/srv/DetectionRQ_Request";
}

template<>
struct has_fixed_size<mycobot_interfaces::srv::DetectionRQ_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mycobot_interfaces::srv::DetectionRQ_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mycobot_interfaces::srv::DetectionRQ_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "vision_msgs/msg/detail/detection2_d_array__traits.hpp"

namespace mycobot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DetectionRQ_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectionRQ_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectionRQ_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mycobot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mycobot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mycobot_interfaces::srv::DetectionRQ_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_interfaces::srv::DetectionRQ_Response & msg)
{
  return mycobot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_interfaces::srv::DetectionRQ_Response>()
{
  return "mycobot_interfaces::srv::DetectionRQ_Response";
}

template<>
inline const char * name<mycobot_interfaces::srv::DetectionRQ_Response>()
{
  return "mycobot_interfaces/srv/DetectionRQ_Response";
}

template<>
struct has_fixed_size<mycobot_interfaces::srv::DetectionRQ_Response>
  : std::integral_constant<bool, has_fixed_size<vision_msgs::msg::Detection2DArray>::value> {};

template<>
struct has_bounded_size<mycobot_interfaces::srv::DetectionRQ_Response>
  : std::integral_constant<bool, has_bounded_size<vision_msgs::msg::Detection2DArray>::value> {};

template<>
struct is_message<mycobot_interfaces::srv::DetectionRQ_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mycobot_interfaces::srv::DetectionRQ>()
{
  return "mycobot_interfaces::srv::DetectionRQ";
}

template<>
inline const char * name<mycobot_interfaces::srv::DetectionRQ>()
{
  return "mycobot_interfaces/srv/DetectionRQ";
}

template<>
struct has_fixed_size<mycobot_interfaces::srv::DetectionRQ>
  : std::integral_constant<
    bool,
    has_fixed_size<mycobot_interfaces::srv::DetectionRQ_Request>::value &&
    has_fixed_size<mycobot_interfaces::srv::DetectionRQ_Response>::value
  >
{
};

template<>
struct has_bounded_size<mycobot_interfaces::srv::DetectionRQ>
  : std::integral_constant<
    bool,
    has_bounded_size<mycobot_interfaces::srv::DetectionRQ_Request>::value &&
    has_bounded_size<mycobot_interfaces::srv::DetectionRQ_Response>::value
  >
{
};

template<>
struct is_service<mycobot_interfaces::srv::DetectionRQ>
  : std::true_type
{
};

template<>
struct is_service_request<mycobot_interfaces::srv::DetectionRQ_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mycobot_interfaces::srv::DetectionRQ_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__TRAITS_HPP_

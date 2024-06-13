// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mycobot_interfaces:srv/StateRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__TRAITS_HPP_
#define MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mycobot_interfaces/srv/detail/state_rq__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mycobot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StateRQ_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: trigger
  {
    out << "trigger: ";
    rosidl_generator_traits::value_to_yaml(msg.trigger, out);
    out << ", ";
  }

  // member: target
  {
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StateRQ_Request & msg,
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

  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StateRQ_Request & msg, bool use_flow_style = false)
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
  const mycobot_interfaces::srv::StateRQ_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_interfaces::srv::StateRQ_Request & msg)
{
  return mycobot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_interfaces::srv::StateRQ_Request>()
{
  return "mycobot_interfaces::srv::StateRQ_Request";
}

template<>
inline const char * name<mycobot_interfaces::srv::StateRQ_Request>()
{
  return "mycobot_interfaces/srv/StateRQ_Request";
}

template<>
struct has_fixed_size<mycobot_interfaces::srv::StateRQ_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mycobot_interfaces::srv::StateRQ_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mycobot_interfaces::srv::StateRQ_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mycobot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StateRQ_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: endflag
  {
    out << "endflag: ";
    rosidl_generator_traits::value_to_yaml(msg.endflag, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StateRQ_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: endflag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "endflag: ";
    rosidl_generator_traits::value_to_yaml(msg.endflag, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StateRQ_Response & msg, bool use_flow_style = false)
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
  const mycobot_interfaces::srv::StateRQ_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_interfaces::srv::StateRQ_Response & msg)
{
  return mycobot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_interfaces::srv::StateRQ_Response>()
{
  return "mycobot_interfaces::srv::StateRQ_Response";
}

template<>
inline const char * name<mycobot_interfaces::srv::StateRQ_Response>()
{
  return "mycobot_interfaces/srv/StateRQ_Response";
}

template<>
struct has_fixed_size<mycobot_interfaces::srv::StateRQ_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mycobot_interfaces::srv::StateRQ_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mycobot_interfaces::srv::StateRQ_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mycobot_interfaces::srv::StateRQ>()
{
  return "mycobot_interfaces::srv::StateRQ";
}

template<>
inline const char * name<mycobot_interfaces::srv::StateRQ>()
{
  return "mycobot_interfaces/srv/StateRQ";
}

template<>
struct has_fixed_size<mycobot_interfaces::srv::StateRQ>
  : std::integral_constant<
    bool,
    has_fixed_size<mycobot_interfaces::srv::StateRQ_Request>::value &&
    has_fixed_size<mycobot_interfaces::srv::StateRQ_Response>::value
  >
{
};

template<>
struct has_bounded_size<mycobot_interfaces::srv::StateRQ>
  : std::integral_constant<
    bool,
    has_bounded_size<mycobot_interfaces::srv::StateRQ_Request>::value &&
    has_bounded_size<mycobot_interfaces::srv::StateRQ_Response>::value
  >
{
};

template<>
struct is_service<mycobot_interfaces::srv::StateRQ>
  : std::true_type
{
};

template<>
struct is_service_request<mycobot_interfaces::srv::StateRQ_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mycobot_interfaces::srv::StateRQ_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__TRAITS_HPP_

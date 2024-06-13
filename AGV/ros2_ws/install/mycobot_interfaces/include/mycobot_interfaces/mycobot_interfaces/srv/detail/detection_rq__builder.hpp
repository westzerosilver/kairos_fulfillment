// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mycobot_interfaces:srv/DetectionRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__BUILDER_HPP_
#define MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mycobot_interfaces/srv/detail/detection_rq__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mycobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionRQ_Request_trigger
{
public:
  Init_DetectionRQ_Request_trigger()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mycobot_interfaces::srv::DetectionRQ_Request trigger(::mycobot_interfaces::srv::DetectionRQ_Request::_trigger_type arg)
  {
    msg_.trigger = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::srv::DetectionRQ_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::srv::DetectionRQ_Request>()
{
  return mycobot_interfaces::srv::builder::Init_DetectionRQ_Request_trigger();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_DetectionRQ_Response_result
{
public:
  Init_DetectionRQ_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mycobot_interfaces::srv::DetectionRQ_Response result(::mycobot_interfaces::srv::DetectionRQ_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::srv::DetectionRQ_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::srv::DetectionRQ_Response>()
{
  return mycobot_interfaces::srv::builder::Init_DetectionRQ_Response_result();
}

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__BUILDER_HPP_

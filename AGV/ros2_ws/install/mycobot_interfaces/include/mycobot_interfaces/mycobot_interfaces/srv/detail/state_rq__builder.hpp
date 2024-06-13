// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mycobot_interfaces:srv/StateRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__BUILDER_HPP_
#define MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mycobot_interfaces/srv/detail/state_rq__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mycobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_StateRQ_Request_target
{
public:
  explicit Init_StateRQ_Request_target(::mycobot_interfaces::srv::StateRQ_Request & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::srv::StateRQ_Request target(::mycobot_interfaces::srv::StateRQ_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::srv::StateRQ_Request msg_;
};

class Init_StateRQ_Request_trigger
{
public:
  Init_StateRQ_Request_trigger()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateRQ_Request_target trigger(::mycobot_interfaces::srv::StateRQ_Request::_trigger_type arg)
  {
    msg_.trigger = std::move(arg);
    return Init_StateRQ_Request_target(msg_);
  }

private:
  ::mycobot_interfaces::srv::StateRQ_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::srv::StateRQ_Request>()
{
  return mycobot_interfaces::srv::builder::Init_StateRQ_Request_trigger();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace srv
{

namespace builder
{

class Init_StateRQ_Response_result
{
public:
  explicit Init_StateRQ_Response_result(::mycobot_interfaces::srv::StateRQ_Response & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::srv::StateRQ_Response result(::mycobot_interfaces::srv::StateRQ_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::srv::StateRQ_Response msg_;
};

class Init_StateRQ_Response_endflag
{
public:
  Init_StateRQ_Response_endflag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateRQ_Response_result endflag(::mycobot_interfaces::srv::StateRQ_Response::_endflag_type arg)
  {
    msg_.endflag = std::move(arg);
    return Init_StateRQ_Response_result(msg_);
  }

private:
  ::mycobot_interfaces::srv::StateRQ_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::srv::StateRQ_Response>()
{
  return mycobot_interfaces::srv::builder::Init_StateRQ_Response_endflag();
}

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__BUILDER_HPP_

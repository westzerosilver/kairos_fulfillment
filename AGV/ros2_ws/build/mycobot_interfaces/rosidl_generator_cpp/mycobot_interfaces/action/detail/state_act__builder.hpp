// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mycobot_interfaces:action/StateACT.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__BUILDER_HPP_
#define MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mycobot_interfaces/action/detail/state_act__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_Goal_target
{
public:
  explicit Init_StateACT_Goal_target(::mycobot_interfaces::action::StateACT_Goal & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::action::StateACT_Goal target(::mycobot_interfaces::action::StateACT_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_Goal msg_;
};

class Init_StateACT_Goal_trigger
{
public:
  Init_StateACT_Goal_trigger()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateACT_Goal_target trigger(::mycobot_interfaces::action::StateACT_Goal::_trigger_type arg)
  {
    msg_.trigger = std::move(arg);
    return Init_StateACT_Goal_target(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_Goal>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_Goal_trigger();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_Result_result
{
public:
  explicit Init_StateACT_Result_result(::mycobot_interfaces::action::StateACT_Result & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::action::StateACT_Result result(::mycobot_interfaces::action::StateACT_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_Result msg_;
};

class Init_StateACT_Result_endflag
{
public:
  Init_StateACT_Result_endflag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateACT_Result_result endflag(::mycobot_interfaces::action::StateACT_Result::_endflag_type arg)
  {
    msg_.endflag = std::move(arg);
    return Init_StateACT_Result_result(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_Result>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_Result_endflag();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_Feedback_state
{
public:
  Init_StateACT_Feedback_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mycobot_interfaces::action::StateACT_Feedback state(::mycobot_interfaces::action::StateACT_Feedback::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_Feedback>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_Feedback_state();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_SendGoal_Request_goal
{
public:
  explicit Init_StateACT_SendGoal_Request_goal(::mycobot_interfaces::action::StateACT_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::action::StateACT_SendGoal_Request goal(::mycobot_interfaces::action::StateACT_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_SendGoal_Request msg_;
};

class Init_StateACT_SendGoal_Request_goal_id
{
public:
  Init_StateACT_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateACT_SendGoal_Request_goal goal_id(::mycobot_interfaces::action::StateACT_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_StateACT_SendGoal_Request_goal(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_SendGoal_Request>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_SendGoal_Request_goal_id();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_SendGoal_Response_stamp
{
public:
  explicit Init_StateACT_SendGoal_Response_stamp(::mycobot_interfaces::action::StateACT_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::action::StateACT_SendGoal_Response stamp(::mycobot_interfaces::action::StateACT_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_SendGoal_Response msg_;
};

class Init_StateACT_SendGoal_Response_accepted
{
public:
  Init_StateACT_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateACT_SendGoal_Response_stamp accepted(::mycobot_interfaces::action::StateACT_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_StateACT_SendGoal_Response_stamp(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_SendGoal_Response>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_SendGoal_Response_accepted();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_GetResult_Request_goal_id
{
public:
  Init_StateACT_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mycobot_interfaces::action::StateACT_GetResult_Request goal_id(::mycobot_interfaces::action::StateACT_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_GetResult_Request>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_GetResult_Request_goal_id();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_GetResult_Response_result
{
public:
  explicit Init_StateACT_GetResult_Response_result(::mycobot_interfaces::action::StateACT_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::action::StateACT_GetResult_Response result(::mycobot_interfaces::action::StateACT_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_GetResult_Response msg_;
};

class Init_StateACT_GetResult_Response_status
{
public:
  Init_StateACT_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateACT_GetResult_Response_result status(::mycobot_interfaces::action::StateACT_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_StateACT_GetResult_Response_result(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_GetResult_Response>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_GetResult_Response_status();
}

}  // namespace mycobot_interfaces


namespace mycobot_interfaces
{

namespace action
{

namespace builder
{

class Init_StateACT_FeedbackMessage_feedback
{
public:
  explicit Init_StateACT_FeedbackMessage_feedback(::mycobot_interfaces::action::StateACT_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::mycobot_interfaces::action::StateACT_FeedbackMessage feedback(::mycobot_interfaces::action::StateACT_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_FeedbackMessage msg_;
};

class Init_StateACT_FeedbackMessage_goal_id
{
public:
  Init_StateACT_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateACT_FeedbackMessage_feedback goal_id(::mycobot_interfaces::action::StateACT_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_StateACT_FeedbackMessage_feedback(msg_);
  }

private:
  ::mycobot_interfaces::action::StateACT_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_interfaces::action::StateACT_FeedbackMessage>()
{
  return mycobot_interfaces::action::builder::Init_StateACT_FeedbackMessage_goal_id();
}

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__BUILDER_HPP_

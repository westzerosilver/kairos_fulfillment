// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mycobot_interfaces:action/StateACT.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__STRUCT_HPP_
#define MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_Goal __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_Goal __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_Goal_
{
  using Type = StateACT_Goal_<ContainerAllocator>;

  explicit StateACT_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
      this->target = 0;
    }
  }

  explicit StateACT_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
      this->target = 0;
    }
  }

  // field types and members
  using _trigger_type =
    bool;
  _trigger_type trigger;
  using _target_type =
    int8_t;
  _target_type target;

  // setters for named parameter idiom
  Type & set__trigger(
    const bool & _arg)
  {
    this->trigger = _arg;
    return *this;
  }
  Type & set__target(
    const int8_t & _arg)
  {
    this->target = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_Goal
    std::shared_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_Goal
    std::shared_ptr<mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_Goal_ & other) const
  {
    if (this->trigger != other.trigger) {
      return false;
    }
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_Goal_

// alias to use template instance with default allocator
using StateACT_Goal =
  mycobot_interfaces::action::StateACT_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces


#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_Result __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_Result __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_Result_
{
  using Type = StateACT_Result_<ContainerAllocator>;

  explicit StateACT_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->endflag = false;
      this->result = 0;
    }
  }

  explicit StateACT_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->endflag = false;
      this->result = 0;
    }
  }

  // field types and members
  using _endflag_type =
    bool;
  _endflag_type endflag;
  using _result_type =
    int8_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__endflag(
    const bool & _arg)
  {
    this->endflag = _arg;
    return *this;
  }
  Type & set__result(
    const int8_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_Result
    std::shared_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_Result
    std::shared_ptr<mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_Result_ & other) const
  {
    if (this->endflag != other.endflag) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_Result_

// alias to use template instance with default allocator
using StateACT_Result =
  mycobot_interfaces::action::StateACT_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces


#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_Feedback __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_Feedback_
{
  using Type = StateACT_Feedback_<ContainerAllocator>;

  explicit StateACT_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  explicit StateACT_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  // field types and members
  using _state_type =
    int8_t;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const int8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_Feedback
    std::shared_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_Feedback
    std::shared_ptr<mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_Feedback_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_Feedback_

// alias to use template instance with default allocator
using StateACT_Feedback =
  mycobot_interfaces::action::StateACT_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "mycobot_interfaces/action/detail/state_act__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Request __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_SendGoal_Request_
{
  using Type = StateACT_SendGoal_Request_<ContainerAllocator>;

  explicit StateACT_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit StateACT_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const mycobot_interfaces::action::StateACT_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Request
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Request
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_SendGoal_Request_

// alias to use template instance with default allocator
using StateACT_SendGoal_Request =
  mycobot_interfaces::action::StateACT_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Response __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_SendGoal_Response_
{
  using Type = StateACT_SendGoal_Response_<ContainerAllocator>;

  explicit StateACT_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit StateACT_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Response
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_SendGoal_Response
    std::shared_ptr<mycobot_interfaces::action::StateACT_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_SendGoal_Response_

// alias to use template instance with default allocator
using StateACT_SendGoal_Response =
  mycobot_interfaces::action::StateACT_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces

namespace mycobot_interfaces
{

namespace action
{

struct StateACT_SendGoal
{
  using Request = mycobot_interfaces::action::StateACT_SendGoal_Request;
  using Response = mycobot_interfaces::action::StateACT_SendGoal_Response;
};

}  // namespace action

}  // namespace mycobot_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Request __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_GetResult_Request_
{
  using Type = StateACT_GetResult_Request_<ContainerAllocator>;

  explicit StateACT_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit StateACT_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Request
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Request
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_GetResult_Request_

// alias to use template instance with default allocator
using StateACT_GetResult_Request =
  mycobot_interfaces::action::StateACT_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Response __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_GetResult_Response_
{
  using Type = StateACT_GetResult_Response_<ContainerAllocator>;

  explicit StateACT_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit StateACT_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    mycobot_interfaces::action::StateACT_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const mycobot_interfaces::action::StateACT_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Response
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_GetResult_Response
    std::shared_ptr<mycobot_interfaces::action::StateACT_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_GetResult_Response_

// alias to use template instance with default allocator
using StateACT_GetResult_Response =
  mycobot_interfaces::action::StateACT_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces

namespace mycobot_interfaces
{

namespace action
{

struct StateACT_GetResult
{
  using Request = mycobot_interfaces::action::StateACT_GetResult_Request;
  using Response = mycobot_interfaces::action::StateACT_GetResult_Response;
};

}  // namespace action

}  // namespace mycobot_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "mycobot_interfaces/action/detail/state_act__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__action__StateACT_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__action__StateACT_FeedbackMessage __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct StateACT_FeedbackMessage_
{
  using Type = StateACT_FeedbackMessage_<ContainerAllocator>;

  explicit StateACT_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit StateACT_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const mycobot_interfaces::action::StateACT_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_FeedbackMessage
    std::shared_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__action__StateACT_FeedbackMessage
    std::shared_ptr<mycobot_interfaces::action::StateACT_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateACT_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateACT_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateACT_FeedbackMessage_

// alias to use template instance with default allocator
using StateACT_FeedbackMessage =
  mycobot_interfaces::action::StateACT_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace mycobot_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace mycobot_interfaces
{

namespace action
{

struct StateACT
{
  /// The goal message defined in the action definition.
  using Goal = mycobot_interfaces::action::StateACT_Goal;
  /// The result message defined in the action definition.
  using Result = mycobot_interfaces::action::StateACT_Result;
  /// The feedback message defined in the action definition.
  using Feedback = mycobot_interfaces::action::StateACT_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = mycobot_interfaces::action::StateACT_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = mycobot_interfaces::action::StateACT_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = mycobot_interfaces::action::StateACT_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct StateACT StateACT;

}  // namespace action

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__ACTION__DETAIL__STATE_ACT__STRUCT_HPP_

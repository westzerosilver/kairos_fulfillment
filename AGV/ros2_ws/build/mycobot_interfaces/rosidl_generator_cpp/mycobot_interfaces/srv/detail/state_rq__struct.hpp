// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mycobot_interfaces:srv/StateRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__STRUCT_HPP_
#define MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__srv__StateRQ_Request __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__srv__StateRQ_Request __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StateRQ_Request_
{
  using Type = StateRQ_Request_<ContainerAllocator>;

  explicit StateRQ_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
      this->target = 0;
    }
  }

  explicit StateRQ_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__srv__StateRQ_Request
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__srv__StateRQ_Request
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateRQ_Request_ & other) const
  {
    if (this->trigger != other.trigger) {
      return false;
    }
    if (this->target != other.target) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateRQ_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateRQ_Request_

// alias to use template instance with default allocator
using StateRQ_Request =
  mycobot_interfaces::srv::StateRQ_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mycobot_interfaces


#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__srv__StateRQ_Response __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__srv__StateRQ_Response __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StateRQ_Response_
{
  using Type = StateRQ_Response_<ContainerAllocator>;

  explicit StateRQ_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->endflag = false;
      this->result = 0;
    }
  }

  explicit StateRQ_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__srv__StateRQ_Response
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__srv__StateRQ_Response
    std::shared_ptr<mycobot_interfaces::srv::StateRQ_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateRQ_Response_ & other) const
  {
    if (this->endflag != other.endflag) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateRQ_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateRQ_Response_

// alias to use template instance with default allocator
using StateRQ_Response =
  mycobot_interfaces::srv::StateRQ_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mycobot_interfaces

namespace mycobot_interfaces
{

namespace srv
{

struct StateRQ
{
  using Request = mycobot_interfaces::srv::StateRQ_Request;
  using Response = mycobot_interfaces::srv::StateRQ_Response;
};

}  // namespace srv

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__STATE_RQ__STRUCT_HPP_

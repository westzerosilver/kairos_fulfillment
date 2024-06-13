// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mycobot_interfaces:srv/DetectionRQ.idl
// generated code does not contain a copyright notice

#ifndef MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__STRUCT_HPP_
#define MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Request __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Request __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectionRQ_Request_
{
  using Type = DetectionRQ_Request_<ContainerAllocator>;

  explicit DetectionRQ_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
    }
  }

  explicit DetectionRQ_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trigger = false;
    }
  }

  // field types and members
  using _trigger_type =
    bool;
  _trigger_type trigger;

  // setters for named parameter idiom
  Type & set__trigger(
    const bool & _arg)
  {
    this->trigger = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Request
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Request
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionRQ_Request_ & other) const
  {
    if (this->trigger != other.trigger) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionRQ_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionRQ_Request_

// alias to use template instance with default allocator
using DetectionRQ_Request =
  mycobot_interfaces::srv::DetectionRQ_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mycobot_interfaces


// Include directives for member types
// Member 'result'
#include "vision_msgs/msg/detail/detection2_d_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Response __attribute__((deprecated))
#else
# define DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Response __declspec(deprecated)
#endif

namespace mycobot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectionRQ_Response_
{
  using Type = DetectionRQ_Response_<ContainerAllocator>;

  explicit DetectionRQ_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    (void)_init;
  }

  explicit DetectionRQ_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _result_type =
    vision_msgs::msg::Detection2DArray_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const vision_msgs::msg::Detection2DArray_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Response
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mycobot_interfaces__srv__DetectionRQ_Response
    std::shared_ptr<mycobot_interfaces::srv::DetectionRQ_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectionRQ_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectionRQ_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectionRQ_Response_

// alias to use template instance with default allocator
using DetectionRQ_Response =
  mycobot_interfaces::srv::DetectionRQ_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mycobot_interfaces

namespace mycobot_interfaces
{

namespace srv
{

struct DetectionRQ
{
  using Request = mycobot_interfaces::srv::DetectionRQ_Request;
  using Response = mycobot_interfaces::srv::DetectionRQ_Response;
};

}  // namespace srv

}  // namespace mycobot_interfaces

#endif  // MYCOBOT_INTERFACES__SRV__DETAIL__DETECTION_RQ__STRUCT_HPP_

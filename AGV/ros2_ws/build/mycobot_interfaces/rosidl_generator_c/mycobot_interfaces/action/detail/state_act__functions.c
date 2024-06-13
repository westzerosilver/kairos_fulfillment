// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mycobot_interfaces:action/StateACT.idl
// generated code does not contain a copyright notice
#include "mycobot_interfaces/action/detail/state_act__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mycobot_interfaces__action__StateACT_Goal__init(mycobot_interfaces__action__StateACT_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // trigger
  // target
  return true;
}

void
mycobot_interfaces__action__StateACT_Goal__fini(mycobot_interfaces__action__StateACT_Goal * msg)
{
  if (!msg) {
    return;
  }
  // trigger
  // target
}

bool
mycobot_interfaces__action__StateACT_Goal__are_equal(const mycobot_interfaces__action__StateACT_Goal * lhs, const mycobot_interfaces__action__StateACT_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // trigger
  if (lhs->trigger != rhs->trigger) {
    return false;
  }
  // target
  if (lhs->target != rhs->target) {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_Goal__copy(
  const mycobot_interfaces__action__StateACT_Goal * input,
  mycobot_interfaces__action__StateACT_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // trigger
  output->trigger = input->trigger;
  // target
  output->target = input->target;
  return true;
}

mycobot_interfaces__action__StateACT_Goal *
mycobot_interfaces__action__StateACT_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Goal * msg = (mycobot_interfaces__action__StateACT_Goal *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_Goal));
  bool success = mycobot_interfaces__action__StateACT_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_Goal__destroy(mycobot_interfaces__action__StateACT_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_Goal__Sequence__init(mycobot_interfaces__action__StateACT_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Goal * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_Goal *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_Goal__Sequence__fini(mycobot_interfaces__action__StateACT_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_Goal__Sequence *
mycobot_interfaces__action__StateACT_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Goal__Sequence * array = (mycobot_interfaces__action__StateACT_Goal__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_Goal__Sequence__destroy(mycobot_interfaces__action__StateACT_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_Goal__Sequence__are_equal(const mycobot_interfaces__action__StateACT_Goal__Sequence * lhs, const mycobot_interfaces__action__StateACT_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_Goal__Sequence__copy(
  const mycobot_interfaces__action__StateACT_Goal__Sequence * input,
  mycobot_interfaces__action__StateACT_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_Goal * data =
      (mycobot_interfaces__action__StateACT_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mycobot_interfaces__action__StateACT_Result__init(mycobot_interfaces__action__StateACT_Result * msg)
{
  if (!msg) {
    return false;
  }
  // endflag
  // result
  return true;
}

void
mycobot_interfaces__action__StateACT_Result__fini(mycobot_interfaces__action__StateACT_Result * msg)
{
  if (!msg) {
    return;
  }
  // endflag
  // result
}

bool
mycobot_interfaces__action__StateACT_Result__are_equal(const mycobot_interfaces__action__StateACT_Result * lhs, const mycobot_interfaces__action__StateACT_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // endflag
  if (lhs->endflag != rhs->endflag) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_Result__copy(
  const mycobot_interfaces__action__StateACT_Result * input,
  mycobot_interfaces__action__StateACT_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // endflag
  output->endflag = input->endflag;
  // result
  output->result = input->result;
  return true;
}

mycobot_interfaces__action__StateACT_Result *
mycobot_interfaces__action__StateACT_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Result * msg = (mycobot_interfaces__action__StateACT_Result *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_Result));
  bool success = mycobot_interfaces__action__StateACT_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_Result__destroy(mycobot_interfaces__action__StateACT_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_Result__Sequence__init(mycobot_interfaces__action__StateACT_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Result * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_Result *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_Result__Sequence__fini(mycobot_interfaces__action__StateACT_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_Result__Sequence *
mycobot_interfaces__action__StateACT_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Result__Sequence * array = (mycobot_interfaces__action__StateACT_Result__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_Result__Sequence__destroy(mycobot_interfaces__action__StateACT_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_Result__Sequence__are_equal(const mycobot_interfaces__action__StateACT_Result__Sequence * lhs, const mycobot_interfaces__action__StateACT_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_Result__Sequence__copy(
  const mycobot_interfaces__action__StateACT_Result__Sequence * input,
  mycobot_interfaces__action__StateACT_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_Result * data =
      (mycobot_interfaces__action__StateACT_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mycobot_interfaces__action__StateACT_Feedback__init(mycobot_interfaces__action__StateACT_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // state
  return true;
}

void
mycobot_interfaces__action__StateACT_Feedback__fini(mycobot_interfaces__action__StateACT_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // state
}

bool
mycobot_interfaces__action__StateACT_Feedback__are_equal(const mycobot_interfaces__action__StateACT_Feedback * lhs, const mycobot_interfaces__action__StateACT_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_Feedback__copy(
  const mycobot_interfaces__action__StateACT_Feedback * input,
  mycobot_interfaces__action__StateACT_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  return true;
}

mycobot_interfaces__action__StateACT_Feedback *
mycobot_interfaces__action__StateACT_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Feedback * msg = (mycobot_interfaces__action__StateACT_Feedback *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_Feedback));
  bool success = mycobot_interfaces__action__StateACT_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_Feedback__destroy(mycobot_interfaces__action__StateACT_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_Feedback__Sequence__init(mycobot_interfaces__action__StateACT_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Feedback * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_Feedback *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_Feedback__Sequence__fini(mycobot_interfaces__action__StateACT_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_Feedback__Sequence *
mycobot_interfaces__action__StateACT_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_Feedback__Sequence * array = (mycobot_interfaces__action__StateACT_Feedback__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_Feedback__Sequence__destroy(mycobot_interfaces__action__StateACT_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_Feedback__Sequence__are_equal(const mycobot_interfaces__action__StateACT_Feedback__Sequence * lhs, const mycobot_interfaces__action__StateACT_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_Feedback__Sequence__copy(
  const mycobot_interfaces__action__StateACT_Feedback__Sequence * input,
  mycobot_interfaces__action__StateACT_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_Feedback * data =
      (mycobot_interfaces__action__StateACT_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "mycobot_interfaces/action/detail/state_act__functions.h"

bool
mycobot_interfaces__action__StateACT_SendGoal_Request__init(mycobot_interfaces__action__StateACT_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mycobot_interfaces__action__StateACT_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!mycobot_interfaces__action__StateACT_Goal__init(&msg->goal)) {
    mycobot_interfaces__action__StateACT_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Request__fini(mycobot_interfaces__action__StateACT_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  mycobot_interfaces__action__StateACT_Goal__fini(&msg->goal);
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Request__are_equal(const mycobot_interfaces__action__StateACT_SendGoal_Request * lhs, const mycobot_interfaces__action__StateACT_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!mycobot_interfaces__action__StateACT_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Request__copy(
  const mycobot_interfaces__action__StateACT_SendGoal_Request * input,
  mycobot_interfaces__action__StateACT_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!mycobot_interfaces__action__StateACT_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

mycobot_interfaces__action__StateACT_SendGoal_Request *
mycobot_interfaces__action__StateACT_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_SendGoal_Request * msg = (mycobot_interfaces__action__StateACT_SendGoal_Request *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_SendGoal_Request));
  bool success = mycobot_interfaces__action__StateACT_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Request__destroy(mycobot_interfaces__action__StateACT_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__init(mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_SendGoal_Request * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_SendGoal_Request *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__fini(mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence *
mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * array = (mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__destroy(mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__are_equal(const mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * lhs, const mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence__copy(
  const mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * input,
  mycobot_interfaces__action__StateACT_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_SendGoal_Request * data =
      (mycobot_interfaces__action__StateACT_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
mycobot_interfaces__action__StateACT_SendGoal_Response__init(mycobot_interfaces__action__StateACT_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    mycobot_interfaces__action__StateACT_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Response__fini(mycobot_interfaces__action__StateACT_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Response__are_equal(const mycobot_interfaces__action__StateACT_SendGoal_Response * lhs, const mycobot_interfaces__action__StateACT_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Response__copy(
  const mycobot_interfaces__action__StateACT_SendGoal_Response * input,
  mycobot_interfaces__action__StateACT_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

mycobot_interfaces__action__StateACT_SendGoal_Response *
mycobot_interfaces__action__StateACT_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_SendGoal_Response * msg = (mycobot_interfaces__action__StateACT_SendGoal_Response *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_SendGoal_Response));
  bool success = mycobot_interfaces__action__StateACT_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Response__destroy(mycobot_interfaces__action__StateACT_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__init(mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_SendGoal_Response * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_SendGoal_Response *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__fini(mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence *
mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * array = (mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__destroy(mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__are_equal(const mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * lhs, const mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence__copy(
  const mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * input,
  mycobot_interfaces__action__StateACT_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_SendGoal_Response * data =
      (mycobot_interfaces__action__StateACT_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
mycobot_interfaces__action__StateACT_GetResult_Request__init(mycobot_interfaces__action__StateACT_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mycobot_interfaces__action__StateACT_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
mycobot_interfaces__action__StateACT_GetResult_Request__fini(mycobot_interfaces__action__StateACT_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
mycobot_interfaces__action__StateACT_GetResult_Request__are_equal(const mycobot_interfaces__action__StateACT_GetResult_Request * lhs, const mycobot_interfaces__action__StateACT_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_GetResult_Request__copy(
  const mycobot_interfaces__action__StateACT_GetResult_Request * input,
  mycobot_interfaces__action__StateACT_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

mycobot_interfaces__action__StateACT_GetResult_Request *
mycobot_interfaces__action__StateACT_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_GetResult_Request * msg = (mycobot_interfaces__action__StateACT_GetResult_Request *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_GetResult_Request));
  bool success = mycobot_interfaces__action__StateACT_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_GetResult_Request__destroy(mycobot_interfaces__action__StateACT_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__init(mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_GetResult_Request * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_GetResult_Request *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__fini(mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_GetResult_Request__Sequence *
mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * array = (mycobot_interfaces__action__StateACT_GetResult_Request__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__destroy(mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__are_equal(const mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * lhs, const mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_GetResult_Request__Sequence__copy(
  const mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * input,
  mycobot_interfaces__action__StateACT_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_GetResult_Request * data =
      (mycobot_interfaces__action__StateACT_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "mycobot_interfaces/action/detail/state_act__functions.h"

bool
mycobot_interfaces__action__StateACT_GetResult_Response__init(mycobot_interfaces__action__StateACT_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!mycobot_interfaces__action__StateACT_Result__init(&msg->result)) {
    mycobot_interfaces__action__StateACT_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
mycobot_interfaces__action__StateACT_GetResult_Response__fini(mycobot_interfaces__action__StateACT_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  mycobot_interfaces__action__StateACT_Result__fini(&msg->result);
}

bool
mycobot_interfaces__action__StateACT_GetResult_Response__are_equal(const mycobot_interfaces__action__StateACT_GetResult_Response * lhs, const mycobot_interfaces__action__StateACT_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!mycobot_interfaces__action__StateACT_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_GetResult_Response__copy(
  const mycobot_interfaces__action__StateACT_GetResult_Response * input,
  mycobot_interfaces__action__StateACT_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!mycobot_interfaces__action__StateACT_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

mycobot_interfaces__action__StateACT_GetResult_Response *
mycobot_interfaces__action__StateACT_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_GetResult_Response * msg = (mycobot_interfaces__action__StateACT_GetResult_Response *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_GetResult_Response));
  bool success = mycobot_interfaces__action__StateACT_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_GetResult_Response__destroy(mycobot_interfaces__action__StateACT_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__init(mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_GetResult_Response * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_GetResult_Response *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__fini(mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_GetResult_Response__Sequence *
mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * array = (mycobot_interfaces__action__StateACT_GetResult_Response__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__destroy(mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__are_equal(const mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * lhs, const mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_GetResult_Response__Sequence__copy(
  const mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * input,
  mycobot_interfaces__action__StateACT_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_GetResult_Response * data =
      (mycobot_interfaces__action__StateACT_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "mycobot_interfaces/action/detail/state_act__functions.h"

bool
mycobot_interfaces__action__StateACT_FeedbackMessage__init(mycobot_interfaces__action__StateACT_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mycobot_interfaces__action__StateACT_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!mycobot_interfaces__action__StateACT_Feedback__init(&msg->feedback)) {
    mycobot_interfaces__action__StateACT_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
mycobot_interfaces__action__StateACT_FeedbackMessage__fini(mycobot_interfaces__action__StateACT_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  mycobot_interfaces__action__StateACT_Feedback__fini(&msg->feedback);
}

bool
mycobot_interfaces__action__StateACT_FeedbackMessage__are_equal(const mycobot_interfaces__action__StateACT_FeedbackMessage * lhs, const mycobot_interfaces__action__StateACT_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mycobot_interfaces__action__StateACT_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_FeedbackMessage__copy(
  const mycobot_interfaces__action__StateACT_FeedbackMessage * input,
  mycobot_interfaces__action__StateACT_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mycobot_interfaces__action__StateACT_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

mycobot_interfaces__action__StateACT_FeedbackMessage *
mycobot_interfaces__action__StateACT_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_FeedbackMessage * msg = (mycobot_interfaces__action__StateACT_FeedbackMessage *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_interfaces__action__StateACT_FeedbackMessage));
  bool success = mycobot_interfaces__action__StateACT_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_interfaces__action__StateACT_FeedbackMessage__destroy(mycobot_interfaces__action__StateACT_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_interfaces__action__StateACT_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__init(mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_FeedbackMessage * data = NULL;

  if (size) {
    data = (mycobot_interfaces__action__StateACT_FeedbackMessage *)allocator.zero_allocate(size, sizeof(mycobot_interfaces__action__StateACT_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_interfaces__action__StateACT_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_interfaces__action__StateACT_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__fini(mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mycobot_interfaces__action__StateACT_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence *
mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * array = (mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence *)allocator.allocate(sizeof(mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__destroy(mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__are_equal(const mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * lhs, const mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence__copy(
  const mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * input,
  mycobot_interfaces__action__StateACT_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_interfaces__action__StateACT_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_interfaces__action__StateACT_FeedbackMessage * data =
      (mycobot_interfaces__action__StateACT_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_interfaces__action__StateACT_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_interfaces__action__StateACT_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_interfaces__action__StateACT_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

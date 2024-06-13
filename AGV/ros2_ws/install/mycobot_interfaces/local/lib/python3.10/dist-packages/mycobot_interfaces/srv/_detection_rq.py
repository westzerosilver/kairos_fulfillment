# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mycobot_interfaces:srv/DetectionRQ.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectionRQ_Request(type):
    """Metaclass of message 'DetectionRQ_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mycobot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mycobot_interfaces.srv.DetectionRQ_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detection_rq__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detection_rq__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detection_rq__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detection_rq__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detection_rq__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectionRQ_Request(metaclass=Metaclass_DetectionRQ_Request):
    """Message class 'DetectionRQ_Request'."""

    __slots__ = [
        '_trigger',
    ]

    _fields_and_field_types = {
        'trigger': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.trigger = kwargs.get('trigger', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.trigger != other.trigger:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def trigger(self):
        """Message field 'trigger'."""
        return self._trigger

    @trigger.setter
    def trigger(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'trigger' field must be of type 'bool'"
        self._trigger = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DetectionRQ_Response(type):
    """Metaclass of message 'DetectionRQ_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mycobot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mycobot_interfaces.srv.DetectionRQ_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detection_rq__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detection_rq__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detection_rq__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detection_rq__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detection_rq__response

            from vision_msgs.msg import Detection2DArray
            if Detection2DArray.__class__._TYPE_SUPPORT is None:
                Detection2DArray.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectionRQ_Response(metaclass=Metaclass_DetectionRQ_Response):
    """Message class 'DetectionRQ_Response'."""

    __slots__ = [
        '_result',
    ]

    _fields_and_field_types = {
        'result': 'vision_msgs/Detection2DArray',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['vision_msgs', 'msg'], 'Detection2DArray'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from vision_msgs.msg import Detection2DArray
        self.result = kwargs.get('result', Detection2DArray())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from vision_msgs.msg import Detection2DArray
            assert \
                isinstance(value, Detection2DArray), \
                "The 'result' field must be a sub message of type 'Detection2DArray'"
        self._result = value


class Metaclass_DetectionRQ(type):
    """Metaclass of service 'DetectionRQ'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mycobot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mycobot_interfaces.srv.DetectionRQ')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__detection_rq

            from mycobot_interfaces.srv import _detection_rq
            if _detection_rq.Metaclass_DetectionRQ_Request._TYPE_SUPPORT is None:
                _detection_rq.Metaclass_DetectionRQ_Request.__import_type_support__()
            if _detection_rq.Metaclass_DetectionRQ_Response._TYPE_SUPPORT is None:
                _detection_rq.Metaclass_DetectionRQ_Response.__import_type_support__()


class DetectionRQ(metaclass=Metaclass_DetectionRQ):
    from mycobot_interfaces.srv._detection_rq import DetectionRQ_Request as Request
    from mycobot_interfaces.srv._detection_rq import DetectionRQ_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')

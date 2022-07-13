// Generated by gencpp from file robot_localization/SetUTMZoneRequest.msg
// DO NOT EDIT!


#ifndef ROBOT_LOCALIZATION_MESSAGE_SETUTMZONEREQUEST_H
#define ROBOT_LOCALIZATION_MESSAGE_SETUTMZONEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robot_localization
{
template <class ContainerAllocator>
struct SetUTMZoneRequest_
{
  typedef SetUTMZoneRequest_<ContainerAllocator> Type;

  SetUTMZoneRequest_()
    : utm_zone()  {
    }
  SetUTMZoneRequest_(const ContainerAllocator& _alloc)
    : utm_zone(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _utm_zone_type;
  _utm_zone_type utm_zone;





  typedef boost::shared_ptr< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetUTMZoneRequest_

typedef ::robot_localization::SetUTMZoneRequest_<std::allocator<void> > SetUTMZoneRequest;

typedef boost::shared_ptr< ::robot_localization::SetUTMZoneRequest > SetUTMZoneRequestPtr;
typedef boost::shared_ptr< ::robot_localization::SetUTMZoneRequest const> SetUTMZoneRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robot_localization

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsMessage': True, 'IsFixedSize': False, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/melodic/share/geographic_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/melodic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsMessage< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "893fd74d45efde020666acda18d3cccc";
  }

  static const char* value(const ::robot_localization::SetUTMZoneRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x893fd74d45efde02ULL;
  static const uint64_t static_value2 = 0x0666acda18d3ccccULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_localization/SetUTMZoneRequest";
  }

  static const char* value(const ::robot_localization::SetUTMZoneRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"\n"
"string utm_zone\n"
;
  }

  static const char* value(const ::robot_localization::SetUTMZoneRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.utm_zone);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetUTMZoneRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_localization::SetUTMZoneRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_localization::SetUTMZoneRequest_<ContainerAllocator>& v)
  {
    s << indent << "utm_zone: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.utm_zone);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_LOCALIZATION_MESSAGE_SETUTMZONEREQUEST_H

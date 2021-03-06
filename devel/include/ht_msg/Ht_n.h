// Generated by gencpp from file ht_msg/Ht_n.msg
// DO NOT EDIT!


#ifndef HT_MSG_MESSAGE_HT_N_H
#define HT_MSG_MESSAGE_HT_N_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ht_msg
{
template <class ContainerAllocator>
struct Ht_n_
{
  typedef Ht_n_<ContainerAllocator> Type;

  Ht_n_()
    : glasses_people(0)
    , longhair_people(0)
    , sum_people(0)  {
    }
  Ht_n_(const ContainerAllocator& _alloc)
    : glasses_people(0)
    , longhair_people(0)
    , sum_people(0)  {
  (void)_alloc;
    }



   typedef uint8_t _glasses_people_type;
  _glasses_people_type glasses_people;

   typedef uint8_t _longhair_people_type;
  _longhair_people_type longhair_people;

   typedef uint8_t _sum_people_type;
  _sum_people_type sum_people;





  typedef boost::shared_ptr< ::ht_msg::Ht_n_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ht_msg::Ht_n_<ContainerAllocator> const> ConstPtr;

}; // struct Ht_n_

typedef ::ht_msg::Ht_n_<std::allocator<void> > Ht_n;

typedef boost::shared_ptr< ::ht_msg::Ht_n > Ht_nPtr;
typedef boost::shared_ptr< ::ht_msg::Ht_n const> Ht_nConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ht_msg::Ht_n_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ht_msg::Ht_n_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ht_msg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsMessage': True, 'IsFixedSize': True, 'HasHeader': False}
// {'ht_msg': ['/home/ucar/ROS_xunfei/ucar_ws/src/ht_msg/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsMessage< ::ht_msg::Ht_n_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ht_msg::Ht_n_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ht_msg::Ht_n_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ht_msg::Ht_n_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ht_msg::Ht_n_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ht_msg::Ht_n_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ht_msg::Ht_n_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0c743cff3054fd55978a5fd3eccc3803";
  }

  static const char* value(const ::ht_msg::Ht_n_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0c743cff3054fd55ULL;
  static const uint64_t static_value2 = 0x978a5fd3eccc3803ULL;
};

template<class ContainerAllocator>
struct DataType< ::ht_msg::Ht_n_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ht_msg/Ht_n";
  }

  static const char* value(const ::ht_msg::Ht_n_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ht_msg::Ht_n_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 glasses_people\n"
"uint8 longhair_people\n"
"uint8 sum_people\n"
;
  }

  static const char* value(const ::ht_msg::Ht_n_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ht_msg::Ht_n_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.glasses_people);
      stream.next(m.longhair_people);
      stream.next(m.sum_people);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Ht_n_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ht_msg::Ht_n_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ht_msg::Ht_n_<ContainerAllocator>& v)
  {
    s << indent << "glasses_people: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.glasses_people);
    s << indent << "longhair_people: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.longhair_people);
    s << indent << "sum_people: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sum_people);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HT_MSG_MESSAGE_HT_N_H

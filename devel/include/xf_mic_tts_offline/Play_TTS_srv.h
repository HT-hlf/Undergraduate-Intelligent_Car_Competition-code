// Generated by gencpp from file xf_mic_tts_offline/Play_TTS_srv.msg
// DO NOT EDIT!


#ifndef XF_MIC_TTS_OFFLINE_MESSAGE_PLAY_TTS_SRV_H
#define XF_MIC_TTS_OFFLINE_MESSAGE_PLAY_TTS_SRV_H

#include <ros/service_traits.h>


#include <xf_mic_tts_offline/Play_TTS_srvRequest.h>
#include <xf_mic_tts_offline/Play_TTS_srvResponse.h>


namespace xf_mic_tts_offline
{

struct Play_TTS_srv
{

typedef Play_TTS_srvRequest Request;
typedef Play_TTS_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Play_TTS_srv
} // namespace xf_mic_tts_offline


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::xf_mic_tts_offline::Play_TTS_srv > {
  static const char* value()
  {
    return "a69a11dcb98f2002f416b83cdd55c128";
  }

  static const char* value(const ::xf_mic_tts_offline::Play_TTS_srv&) { return value(); }
};

template<>
struct DataType< ::xf_mic_tts_offline::Play_TTS_srv > {
  static const char* value()
  {
    return "xf_mic_tts_offline/Play_TTS_srv";
  }

  static const char* value(const ::xf_mic_tts_offline::Play_TTS_srv&) { return value(); }
};


// service_traits::MD5Sum< ::xf_mic_tts_offline::Play_TTS_srvRequest> should match 
// service_traits::MD5Sum< ::xf_mic_tts_offline::Play_TTS_srv > 
template<>
struct MD5Sum< ::xf_mic_tts_offline::Play_TTS_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::xf_mic_tts_offline::Play_TTS_srv >::value();
  }
  static const char* value(const ::xf_mic_tts_offline::Play_TTS_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::xf_mic_tts_offline::Play_TTS_srvRequest> should match 
// service_traits::DataType< ::xf_mic_tts_offline::Play_TTS_srv > 
template<>
struct DataType< ::xf_mic_tts_offline::Play_TTS_srvRequest>
{
  static const char* value()
  {
    return DataType< ::xf_mic_tts_offline::Play_TTS_srv >::value();
  }
  static const char* value(const ::xf_mic_tts_offline::Play_TTS_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::xf_mic_tts_offline::Play_TTS_srvResponse> should match 
// service_traits::MD5Sum< ::xf_mic_tts_offline::Play_TTS_srv > 
template<>
struct MD5Sum< ::xf_mic_tts_offline::Play_TTS_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::xf_mic_tts_offline::Play_TTS_srv >::value();
  }
  static const char* value(const ::xf_mic_tts_offline::Play_TTS_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::xf_mic_tts_offline::Play_TTS_srvResponse> should match 
// service_traits::DataType< ::xf_mic_tts_offline::Play_TTS_srv > 
template<>
struct DataType< ::xf_mic_tts_offline::Play_TTS_srvResponse>
{
  static const char* value()
  {
    return DataType< ::xf_mic_tts_offline::Play_TTS_srv >::value();
  }
  static const char* value(const ::xf_mic_tts_offline::Play_TTS_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // XF_MIC_TTS_OFFLINE_MESSAGE_PLAY_TTS_SRV_H

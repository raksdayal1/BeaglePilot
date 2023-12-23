#pragma once
// MESSAGE OAIRE_RFSENSOR_TRACE PACKING

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE 11042


typedef struct __mavlink_oaire_rfsensor_trace_t {
 float frequency[1000]; /*<  Frequency Array*/
 float trace[1000]; /*<  Trace Data*/
} mavlink_oaire_rfsensor_trace_t;

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN 8000
#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN 8000
#define MAVLINK_MSG_ID_11042_LEN 8000
#define MAVLINK_MSG_ID_11042_MIN_LEN 8000

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC 83
#define MAVLINK_MSG_ID_11042_CRC 83

#define MAVLINK_MSG_OAIRE_RFSENSOR_TRACE_FIELD_FREQUENCY_LEN 1000
#define MAVLINK_MSG_OAIRE_RFSENSOR_TRACE_FIELD_TRACE_LEN 1000

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OAIRE_RFSENSOR_TRACE { \
    11042, \
    "OAIRE_RFSENSOR_TRACE", \
    2, \
    {  { "frequency", NULL, MAVLINK_TYPE_FLOAT, 1000, 0, offsetof(mavlink_oaire_rfsensor_trace_t, frequency) }, \
         { "trace", NULL, MAVLINK_TYPE_FLOAT, 1000, 4000, offsetof(mavlink_oaire_rfsensor_trace_t, trace) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OAIRE_RFSENSOR_TRACE { \
    "OAIRE_RFSENSOR_TRACE", \
    2, \
    {  { "frequency", NULL, MAVLINK_TYPE_FLOAT, 1000, 0, offsetof(mavlink_oaire_rfsensor_trace_t, frequency) }, \
         { "trace", NULL, MAVLINK_TYPE_FLOAT, 1000, 4000, offsetof(mavlink_oaire_rfsensor_trace_t, trace) }, \
         } \
}
#endif

/**
 * @brief Pack a oaire_rfsensor_trace message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param frequency  Frequency Array
 * @param trace  Trace Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_trace_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const float *frequency, const float *trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN];

    _mav_put_float_array(buf, 0, frequency, 1000);
    _mav_put_float_array(buf, 4000, trace, 1000);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN);
#else
    mavlink_oaire_rfsensor_trace_t packet;

    mav_array_memcpy(packet.frequency, frequency, sizeof(float)*1000);
    mav_array_memcpy(packet.trace, trace, sizeof(float)*1000);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
}

/**
 * @brief Pack a oaire_rfsensor_trace message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param frequency  Frequency Array
 * @param trace  Trace Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_trace_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const float *frequency,const float *trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN];

    _mav_put_float_array(buf, 0, frequency, 1000);
    _mav_put_float_array(buf, 4000, trace, 1000);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN);
#else
    mavlink_oaire_rfsensor_trace_t packet;

    mav_array_memcpy(packet.frequency, frequency, sizeof(float)*1000);
    mav_array_memcpy(packet.trace, trace, sizeof(float)*1000);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
}

/**
 * @brief Encode a oaire_rfsensor_trace struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param oaire_rfsensor_trace C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_trace_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_oaire_rfsensor_trace_t* oaire_rfsensor_trace)
{
    return mavlink_msg_oaire_rfsensor_trace_pack(system_id, component_id, msg, oaire_rfsensor_trace->frequency, oaire_rfsensor_trace->trace);
}

/**
 * @brief Encode a oaire_rfsensor_trace struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param oaire_rfsensor_trace C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_trace_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_oaire_rfsensor_trace_t* oaire_rfsensor_trace)
{
    return mavlink_msg_oaire_rfsensor_trace_pack_chan(system_id, component_id, chan, msg, oaire_rfsensor_trace->frequency, oaire_rfsensor_trace->trace);
}

/**
 * @brief Send a oaire_rfsensor_trace message
 * @param chan MAVLink channel to send the message
 *
 * @param frequency  Frequency Array
 * @param trace  Trace Data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_oaire_rfsensor_trace_send(mavlink_channel_t chan, const float *frequency, const float *trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN];

    _mav_put_float_array(buf, 0, frequency, 1000);
    _mav_put_float_array(buf, 4000, trace, 1000);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE, buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
#else
    mavlink_oaire_rfsensor_trace_t packet;

    mav_array_memcpy(packet.frequency, frequency, sizeof(float)*1000);
    mav_array_memcpy(packet.trace, trace, sizeof(float)*1000);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE, (const char *)&packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
#endif
}

/**
 * @brief Send a oaire_rfsensor_trace message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_oaire_rfsensor_trace_send_struct(mavlink_channel_t chan, const mavlink_oaire_rfsensor_trace_t* oaire_rfsensor_trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_oaire_rfsensor_trace_send(chan, oaire_rfsensor_trace->frequency, oaire_rfsensor_trace->trace);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE, (const char *)oaire_rfsensor_trace, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
#endif
}

#if MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_oaire_rfsensor_trace_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *frequency, const float *trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_float_array(buf, 0, frequency, 1000);
    _mav_put_float_array(buf, 4000, trace, 1000);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE, buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
#else
    mavlink_oaire_rfsensor_trace_t *packet = (mavlink_oaire_rfsensor_trace_t *)msgbuf;

    mav_array_memcpy(packet->frequency, frequency, sizeof(float)*1000);
    mav_array_memcpy(packet->trace, trace, sizeof(float)*1000);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE, (const char *)packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_CRC);
#endif
}
#endif

#endif

// MESSAGE OAIRE_RFSENSOR_TRACE UNPACKING


/**
 * @brief Get field frequency from oaire_rfsensor_trace message
 *
 * @return  Frequency Array
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_trace_get_frequency(const mavlink_message_t* msg, float *frequency)
{
    return _MAV_RETURN_float_array(msg, frequency, 1000,  0);
}

/**
 * @brief Get field trace from oaire_rfsensor_trace message
 *
 * @return  Trace Data
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_trace_get_trace(const mavlink_message_t* msg, float *trace)
{
    return _MAV_RETURN_float_array(msg, trace, 1000,  4000);
}

/**
 * @brief Decode a oaire_rfsensor_trace message into a struct
 *
 * @param msg The message to decode
 * @param oaire_rfsensor_trace C-struct to decode the message contents into
 */
static inline void mavlink_msg_oaire_rfsensor_trace_decode(const mavlink_message_t* msg, mavlink_oaire_rfsensor_trace_t* oaire_rfsensor_trace)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_oaire_rfsensor_trace_get_frequency(msg, oaire_rfsensor_trace->frequency);
    mavlink_msg_oaire_rfsensor_trace_get_trace(msg, oaire_rfsensor_trace->trace);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN? msg->len : MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN;
        memset(oaire_rfsensor_trace, 0, MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_LEN);
    memcpy(oaire_rfsensor_trace, _MAV_PAYLOAD(msg), len);
#endif
}

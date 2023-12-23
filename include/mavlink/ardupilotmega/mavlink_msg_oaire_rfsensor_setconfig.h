#pragma once
// MESSAGE OAIRE_RFSENSOR_SETCONFIG PACKING

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG 11040


typedef struct __mavlink_oaire_rfsensor_setconfig_t {
 float center_frq; /*< [Hz] Center Frequency to set on RFSensor*/
 float span; /*< [Hz] Span of the frequency*/
 int16_t no_points; /*<  No of points*/
 int8_t continuous; /*<  Bool value indicating continuous of single sweep*/
 int8_t start_stop; /*<  Bool value to set sensor from idle to active state*/
} mavlink_oaire_rfsensor_setconfig_t;

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN 12
#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN 12
#define MAVLINK_MSG_ID_11040_LEN 12
#define MAVLINK_MSG_ID_11040_MIN_LEN 12

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC 141
#define MAVLINK_MSG_ID_11040_CRC 141



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OAIRE_RFSENSOR_SETCONFIG { \
    11040, \
    "OAIRE_RFSENSOR_SETCONFIG", \
    5, \
    {  { "center_frq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_oaire_rfsensor_setconfig_t, center_frq) }, \
         { "span", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_oaire_rfsensor_setconfig_t, span) }, \
         { "no_points", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_oaire_rfsensor_setconfig_t, no_points) }, \
         { "continuous", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_oaire_rfsensor_setconfig_t, continuous) }, \
         { "start_stop", NULL, MAVLINK_TYPE_INT8_T, 0, 11, offsetof(mavlink_oaire_rfsensor_setconfig_t, start_stop) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OAIRE_RFSENSOR_SETCONFIG { \
    "OAIRE_RFSENSOR_SETCONFIG", \
    5, \
    {  { "center_frq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_oaire_rfsensor_setconfig_t, center_frq) }, \
         { "span", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_oaire_rfsensor_setconfig_t, span) }, \
         { "no_points", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_oaire_rfsensor_setconfig_t, no_points) }, \
         { "continuous", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_oaire_rfsensor_setconfig_t, continuous) }, \
         { "start_stop", NULL, MAVLINK_TYPE_INT8_T, 0, 11, offsetof(mavlink_oaire_rfsensor_setconfig_t, start_stop) }, \
         } \
}
#endif

/**
 * @brief Pack a oaire_rfsensor_setconfig message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param center_frq [Hz] Center Frequency to set on RFSensor
 * @param span [Hz] Span of the frequency
 * @param no_points  No of points
 * @param continuous  Bool value indicating continuous of single sweep
 * @param start_stop  Bool value to set sensor from idle to active state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_setconfig_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float center_frq, float span, int16_t no_points, int8_t continuous, int8_t start_stop)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN];
    _mav_put_float(buf, 0, center_frq);
    _mav_put_float(buf, 4, span);
    _mav_put_int16_t(buf, 8, no_points);
    _mav_put_int8_t(buf, 10, continuous);
    _mav_put_int8_t(buf, 11, start_stop);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN);
#else
    mavlink_oaire_rfsensor_setconfig_t packet;
    packet.center_frq = center_frq;
    packet.span = span;
    packet.no_points = no_points;
    packet.continuous = continuous;
    packet.start_stop = start_stop;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
}

/**
 * @brief Pack a oaire_rfsensor_setconfig message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param center_frq [Hz] Center Frequency to set on RFSensor
 * @param span [Hz] Span of the frequency
 * @param no_points  No of points
 * @param continuous  Bool value indicating continuous of single sweep
 * @param start_stop  Bool value to set sensor from idle to active state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_setconfig_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float center_frq,float span,int16_t no_points,int8_t continuous,int8_t start_stop)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN];
    _mav_put_float(buf, 0, center_frq);
    _mav_put_float(buf, 4, span);
    _mav_put_int16_t(buf, 8, no_points);
    _mav_put_int8_t(buf, 10, continuous);
    _mav_put_int8_t(buf, 11, start_stop);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN);
#else
    mavlink_oaire_rfsensor_setconfig_t packet;
    packet.center_frq = center_frq;
    packet.span = span;
    packet.no_points = no_points;
    packet.continuous = continuous;
    packet.start_stop = start_stop;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
}

/**
 * @brief Encode a oaire_rfsensor_setconfig struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param oaire_rfsensor_setconfig C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_setconfig_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_oaire_rfsensor_setconfig_t* oaire_rfsensor_setconfig)
{
    return mavlink_msg_oaire_rfsensor_setconfig_pack(system_id, component_id, msg, oaire_rfsensor_setconfig->center_frq, oaire_rfsensor_setconfig->span, oaire_rfsensor_setconfig->no_points, oaire_rfsensor_setconfig->continuous, oaire_rfsensor_setconfig->start_stop);
}

/**
 * @brief Encode a oaire_rfsensor_setconfig struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param oaire_rfsensor_setconfig C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_setconfig_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_oaire_rfsensor_setconfig_t* oaire_rfsensor_setconfig)
{
    return mavlink_msg_oaire_rfsensor_setconfig_pack_chan(system_id, component_id, chan, msg, oaire_rfsensor_setconfig->center_frq, oaire_rfsensor_setconfig->span, oaire_rfsensor_setconfig->no_points, oaire_rfsensor_setconfig->continuous, oaire_rfsensor_setconfig->start_stop);
}

/**
 * @brief Send a oaire_rfsensor_setconfig message
 * @param chan MAVLink channel to send the message
 *
 * @param center_frq [Hz] Center Frequency to set on RFSensor
 * @param span [Hz] Span of the frequency
 * @param no_points  No of points
 * @param continuous  Bool value indicating continuous of single sweep
 * @param start_stop  Bool value to set sensor from idle to active state
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_oaire_rfsensor_setconfig_send(mavlink_channel_t chan, float center_frq, float span, int16_t no_points, int8_t continuous, int8_t start_stop)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN];
    _mav_put_float(buf, 0, center_frq);
    _mav_put_float(buf, 4, span);
    _mav_put_int16_t(buf, 8, no_points);
    _mav_put_int8_t(buf, 10, continuous);
    _mav_put_int8_t(buf, 11, start_stop);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG, buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
#else
    mavlink_oaire_rfsensor_setconfig_t packet;
    packet.center_frq = center_frq;
    packet.span = span;
    packet.no_points = no_points;
    packet.continuous = continuous;
    packet.start_stop = start_stop;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG, (const char *)&packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
#endif
}

/**
 * @brief Send a oaire_rfsensor_setconfig message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_oaire_rfsensor_setconfig_send_struct(mavlink_channel_t chan, const mavlink_oaire_rfsensor_setconfig_t* oaire_rfsensor_setconfig)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_oaire_rfsensor_setconfig_send(chan, oaire_rfsensor_setconfig->center_frq, oaire_rfsensor_setconfig->span, oaire_rfsensor_setconfig->no_points, oaire_rfsensor_setconfig->continuous, oaire_rfsensor_setconfig->start_stop);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG, (const char *)oaire_rfsensor_setconfig, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
#endif
}

#if MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_oaire_rfsensor_setconfig_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float center_frq, float span, int16_t no_points, int8_t continuous, int8_t start_stop)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, center_frq);
    _mav_put_float(buf, 4, span);
    _mav_put_int16_t(buf, 8, no_points);
    _mav_put_int8_t(buf, 10, continuous);
    _mav_put_int8_t(buf, 11, start_stop);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG, buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
#else
    mavlink_oaire_rfsensor_setconfig_t *packet = (mavlink_oaire_rfsensor_setconfig_t *)msgbuf;
    packet->center_frq = center_frq;
    packet->span = span;
    packet->no_points = no_points;
    packet->continuous = continuous;
    packet->start_stop = start_stop;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG, (const char *)packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_CRC);
#endif
}
#endif

#endif

// MESSAGE OAIRE_RFSENSOR_SETCONFIG UNPACKING


/**
 * @brief Get field center_frq from oaire_rfsensor_setconfig message
 *
 * @return [Hz] Center Frequency to set on RFSensor
 */
static inline float mavlink_msg_oaire_rfsensor_setconfig_get_center_frq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field span from oaire_rfsensor_setconfig message
 *
 * @return [Hz] Span of the frequency
 */
static inline float mavlink_msg_oaire_rfsensor_setconfig_get_span(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field no_points from oaire_rfsensor_setconfig message
 *
 * @return  No of points
 */
static inline int16_t mavlink_msg_oaire_rfsensor_setconfig_get_no_points(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field continuous from oaire_rfsensor_setconfig message
 *
 * @return  Bool value indicating continuous of single sweep
 */
static inline int8_t mavlink_msg_oaire_rfsensor_setconfig_get_continuous(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  10);
}

/**
 * @brief Get field start_stop from oaire_rfsensor_setconfig message
 *
 * @return  Bool value to set sensor from idle to active state
 */
static inline int8_t mavlink_msg_oaire_rfsensor_setconfig_get_start_stop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  11);
}

/**
 * @brief Decode a oaire_rfsensor_setconfig message into a struct
 *
 * @param msg The message to decode
 * @param oaire_rfsensor_setconfig C-struct to decode the message contents into
 */
static inline void mavlink_msg_oaire_rfsensor_setconfig_decode(const mavlink_message_t* msg, mavlink_oaire_rfsensor_setconfig_t* oaire_rfsensor_setconfig)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    oaire_rfsensor_setconfig->center_frq = mavlink_msg_oaire_rfsensor_setconfig_get_center_frq(msg);
    oaire_rfsensor_setconfig->span = mavlink_msg_oaire_rfsensor_setconfig_get_span(msg);
    oaire_rfsensor_setconfig->no_points = mavlink_msg_oaire_rfsensor_setconfig_get_no_points(msg);
    oaire_rfsensor_setconfig->continuous = mavlink_msg_oaire_rfsensor_setconfig_get_continuous(msg);
    oaire_rfsensor_setconfig->start_stop = mavlink_msg_oaire_rfsensor_setconfig_get_start_stop(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN? msg->len : MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN;
        memset(oaire_rfsensor_setconfig, 0, MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_LEN);
    memcpy(oaire_rfsensor_setconfig, _MAV_PAYLOAD(msg), len);
#endif
}

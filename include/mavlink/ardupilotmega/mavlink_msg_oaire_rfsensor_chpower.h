#pragma once
// MESSAGE OAIRE_RFSENSOR_CHPOWER PACKING

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER 11043


typedef struct __mavlink_oaire_rfsensor_chpower_t {
 float frq; /*<  Center Frequency Value*/
 float chpower; /*<  Channel Power*/
} mavlink_oaire_rfsensor_chpower_t;

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN 8
#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN 8
#define MAVLINK_MSG_ID_11043_LEN 8
#define MAVLINK_MSG_ID_11043_MIN_LEN 8

#define MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC 131
#define MAVLINK_MSG_ID_11043_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OAIRE_RFSENSOR_CHPOWER { \
    11043, \
    "OAIRE_RFSENSOR_CHPOWER", \
    2, \
    {  { "frq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_oaire_rfsensor_chpower_t, frq) }, \
         { "chpower", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_oaire_rfsensor_chpower_t, chpower) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OAIRE_RFSENSOR_CHPOWER { \
    "OAIRE_RFSENSOR_CHPOWER", \
    2, \
    {  { "frq", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_oaire_rfsensor_chpower_t, frq) }, \
         { "chpower", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_oaire_rfsensor_chpower_t, chpower) }, \
         } \
}
#endif

/**
 * @brief Pack a oaire_rfsensor_chpower message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param frq  Center Frequency Value
 * @param chpower  Channel Power
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_chpower_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float frq, float chpower)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN];
    _mav_put_float(buf, 0, frq);
    _mav_put_float(buf, 4, chpower);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN);
#else
    mavlink_oaire_rfsensor_chpower_t packet;
    packet.frq = frq;
    packet.chpower = chpower;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
}

/**
 * @brief Pack a oaire_rfsensor_chpower message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param frq  Center Frequency Value
 * @param chpower  Channel Power
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_chpower_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float frq,float chpower)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN];
    _mav_put_float(buf, 0, frq);
    _mav_put_float(buf, 4, chpower);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN);
#else
    mavlink_oaire_rfsensor_chpower_t packet;
    packet.frq = frq;
    packet.chpower = chpower;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
}

/**
 * @brief Encode a oaire_rfsensor_chpower struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param oaire_rfsensor_chpower C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_chpower_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_oaire_rfsensor_chpower_t* oaire_rfsensor_chpower)
{
    return mavlink_msg_oaire_rfsensor_chpower_pack(system_id, component_id, msg, oaire_rfsensor_chpower->frq, oaire_rfsensor_chpower->chpower);
}

/**
 * @brief Encode a oaire_rfsensor_chpower struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param oaire_rfsensor_chpower C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_oaire_rfsensor_chpower_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_oaire_rfsensor_chpower_t* oaire_rfsensor_chpower)
{
    return mavlink_msg_oaire_rfsensor_chpower_pack_chan(system_id, component_id, chan, msg, oaire_rfsensor_chpower->frq, oaire_rfsensor_chpower->chpower);
}

/**
 * @brief Send a oaire_rfsensor_chpower message
 * @param chan MAVLink channel to send the message
 *
 * @param frq  Center Frequency Value
 * @param chpower  Channel Power
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_oaire_rfsensor_chpower_send(mavlink_channel_t chan, float frq, float chpower)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN];
    _mav_put_float(buf, 0, frq);
    _mav_put_float(buf, 4, chpower);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER, buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
#else
    mavlink_oaire_rfsensor_chpower_t packet;
    packet.frq = frq;
    packet.chpower = chpower;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER, (const char *)&packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
#endif
}

/**
 * @brief Send a oaire_rfsensor_chpower message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_oaire_rfsensor_chpower_send_struct(mavlink_channel_t chan, const mavlink_oaire_rfsensor_chpower_t* oaire_rfsensor_chpower)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_oaire_rfsensor_chpower_send(chan, oaire_rfsensor_chpower->frq, oaire_rfsensor_chpower->chpower);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER, (const char *)oaire_rfsensor_chpower, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
#endif
}

#if MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_oaire_rfsensor_chpower_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float frq, float chpower)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, frq);
    _mav_put_float(buf, 4, chpower);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER, buf, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
#else
    mavlink_oaire_rfsensor_chpower_t *packet = (mavlink_oaire_rfsensor_chpower_t *)msgbuf;
    packet->frq = frq;
    packet->chpower = chpower;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER, (const char *)packet, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_CRC);
#endif
}
#endif

#endif

// MESSAGE OAIRE_RFSENSOR_CHPOWER UNPACKING


/**
 * @brief Get field frq from oaire_rfsensor_chpower message
 *
 * @return  Center Frequency Value
 */
static inline float mavlink_msg_oaire_rfsensor_chpower_get_frq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field chpower from oaire_rfsensor_chpower message
 *
 * @return  Channel Power
 */
static inline float mavlink_msg_oaire_rfsensor_chpower_get_chpower(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a oaire_rfsensor_chpower message into a struct
 *
 * @param msg The message to decode
 * @param oaire_rfsensor_chpower C-struct to decode the message contents into
 */
static inline void mavlink_msg_oaire_rfsensor_chpower_decode(const mavlink_message_t* msg, mavlink_oaire_rfsensor_chpower_t* oaire_rfsensor_chpower)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    oaire_rfsensor_chpower->frq = mavlink_msg_oaire_rfsensor_chpower_get_frq(msg);
    oaire_rfsensor_chpower->chpower = mavlink_msg_oaire_rfsensor_chpower_get_chpower(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN? msg->len : MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN;
        memset(oaire_rfsensor_chpower, 0, MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_LEN);
    memcpy(oaire_rfsensor_chpower, _MAV_PAYLOAD(msg), len);
#endif
}

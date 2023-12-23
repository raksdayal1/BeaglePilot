// MESSAGE OAIRE_RFSENSOR_SETCONFIG_ACK support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief OAIRE_RFSENSOR_SETCONFIG_ACK message
 *
 * Ack message from Onboard computer with state.
 */
struct OAIRE_RFSENSOR_SETCONFIG_ACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11041;
    static constexpr size_t LENGTH = 13;
    static constexpr size_t MIN_LENGTH = 13;
    static constexpr uint8_t CRC_EXTRA = 205;
    static constexpr auto NAME = "OAIRE_RFSENSOR_SETCONFIG_ACK";


    float center_frq; /*< [Hz] Center Frequency to set on RFSensor */
    float span; /*< [Hz] Span of the frequency */
    int16_t no_points; /*<  No of points */
    int8_t continuous; /*<  Bool value indicating continuous of single sweep */
    int8_t start_stop; /*<  Bool value to set sensor from idle to active state */
    int8_t state; /*<  Bool value indicating sensor is active or idle */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  center_frq: " << center_frq << std::endl;
        ss << "  span: " << span << std::endl;
        ss << "  no_points: " << no_points << std::endl;
        ss << "  continuous: " << +continuous << std::endl;
        ss << "  start_stop: " << +start_stop << std::endl;
        ss << "  state: " << +state << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << center_frq;                    // offset: 0
        map << span;                          // offset: 4
        map << no_points;                     // offset: 8
        map << continuous;                    // offset: 10
        map << start_stop;                    // offset: 11
        map << state;                         // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> center_frq;                    // offset: 0
        map >> span;                          // offset: 4
        map >> no_points;                     // offset: 8
        map >> continuous;                    // offset: 10
        map >> start_stop;                    // offset: 11
        map >> state;                         // offset: 12
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink

// MESSAGE OAIRE_RFSENSOR_SETCONFIG support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief OAIRE_RFSENSOR_SETCONFIG message
 *
 * Set configuration for rf sensor .
 */
struct OAIRE_RFSENSOR_SETCONFIG : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11040;
    static constexpr size_t LENGTH = 12;
    static constexpr size_t MIN_LENGTH = 12;
    static constexpr uint8_t CRC_EXTRA = 141;
    static constexpr auto NAME = "OAIRE_RFSENSOR_SETCONFIG";


    float center_frq; /*< [Hz] Center Frequency to set on RFSensor */
    float span; /*< [Hz] Span of the frequency */
    int16_t no_points; /*<  No of points */
    int8_t continuous; /*<  Bool value indicating continuous of single sweep */
    int8_t start_stop; /*<  Bool value to set sensor from idle to active state */


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
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> center_frq;                    // offset: 0
        map >> span;                          // offset: 4
        map >> no_points;                     // offset: 8
        map >> continuous;                    // offset: 10
        map >> start_stop;                    // offset: 11
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink

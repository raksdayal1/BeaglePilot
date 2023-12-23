// MESSAGE OAIRE_RFSENSOR_TRACE support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief OAIRE_RFSENSOR_TRACE message
 *
 * Trace data from RF sensor.
 */
struct OAIRE_RFSENSOR_TRACE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11042;
    static constexpr size_t LENGTH = 8000;
    static constexpr size_t MIN_LENGTH = 8000;
    static constexpr uint8_t CRC_EXTRA = 83;
    static constexpr auto NAME = "OAIRE_RFSENSOR_TRACE";


    std::array<float, 1000> frequency; /*<  Frequency Array */
    std::array<float, 1000> trace; /*<  Trace Data */


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
        ss << "  frequency: [" << to_string(frequency) << "]" << std::endl;
        ss << "  trace: [" << to_string(trace) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << frequency;                     // offset: 0
        map << trace;                         // offset: 4000
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> frequency;                     // offset: 0
        map >> trace;                         // offset: 4000
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink

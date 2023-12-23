// MESSAGE OAIRE_RFSENSOR_CHPOWER support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief OAIRE_RFSENSOR_CHPOWER message
 *
 * Channel power data at the center frequency.
 */
struct OAIRE_RFSENSOR_CHPOWER : mavlink::Message {
    static constexpr msgid_t MSG_ID = 11043;
    static constexpr size_t LENGTH = 8;
    static constexpr size_t MIN_LENGTH = 8;
    static constexpr uint8_t CRC_EXTRA = 131;
    static constexpr auto NAME = "OAIRE_RFSENSOR_CHPOWER";


    float frq; /*<  Center Frequency Value */
    float chpower; /*<  Channel Power */


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
        ss << "  frq: " << frq << std::endl;
        ss << "  chpower: " << chpower << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << frq;                           // offset: 0
        map << chpower;                       // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> frq;                           // offset: 0
        map >> chpower;                       // offset: 4
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink

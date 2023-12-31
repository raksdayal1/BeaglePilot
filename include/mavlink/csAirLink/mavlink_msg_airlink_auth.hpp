// MESSAGE AIRLINK_AUTH support class

#pragma once

namespace mavlink {
namespace csAirLink {
namespace msg {

/**
 * @brief AIRLINK_AUTH message
 *
 * Authorization package
 */
struct AIRLINK_AUTH : mavlink::Message {
    static constexpr msgid_t MSG_ID = 52000;
    static constexpr size_t LENGTH = 100;
    static constexpr size_t MIN_LENGTH = 100;
    static constexpr uint8_t CRC_EXTRA = 13;
    static constexpr auto NAME = "AIRLINK_AUTH";


    std::array<char, 50> login; /*<  Login */
    std::array<char, 50> password; /*<  Password */


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
        ss << "  login: \"" << to_string(login) << "\"" << std::endl;
        ss << "  password: \"" << to_string(password) << "\"" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << login;                         // offset: 0
        map << password;                      // offset: 50
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> login;                         // offset: 0
        map >> password;                      // offset: 50
    }
};

} // namespace msg
} // namespace csAirLink
} // namespace mavlink

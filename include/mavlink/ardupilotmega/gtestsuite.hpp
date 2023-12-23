/** @file
 *	@brief MAVLink comm testsuite protocol generated from ardupilotmega.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "ardupilotmega.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(ardupilotmega, SENSOR_OFFSETS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::SENSOR_OFFSETS packet_in{};
    packet_in.mag_ofs_x = 19107;
    packet_in.mag_ofs_y = 19211;
    packet_in.mag_ofs_z = 19315;
    packet_in.mag_declination = 17.0;
    packet_in.raw_press = 963497672;
    packet_in.raw_temp = 963497880;
    packet_in.gyro_cal_x = 101.0;
    packet_in.gyro_cal_y = 129.0;
    packet_in.gyro_cal_z = 157.0;
    packet_in.accel_cal_x = 185.0;
    packet_in.accel_cal_y = 213.0;
    packet_in.accel_cal_z = 241.0;

    mavlink::ardupilotmega::msg::SENSOR_OFFSETS packet1{};
    mavlink::ardupilotmega::msg::SENSOR_OFFSETS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.mag_ofs_x, packet2.mag_ofs_x);
    EXPECT_EQ(packet1.mag_ofs_y, packet2.mag_ofs_y);
    EXPECT_EQ(packet1.mag_ofs_z, packet2.mag_ofs_z);
    EXPECT_EQ(packet1.mag_declination, packet2.mag_declination);
    EXPECT_EQ(packet1.raw_press, packet2.raw_press);
    EXPECT_EQ(packet1.raw_temp, packet2.raw_temp);
    EXPECT_EQ(packet1.gyro_cal_x, packet2.gyro_cal_x);
    EXPECT_EQ(packet1.gyro_cal_y, packet2.gyro_cal_y);
    EXPECT_EQ(packet1.gyro_cal_z, packet2.gyro_cal_z);
    EXPECT_EQ(packet1.accel_cal_x, packet2.accel_cal_x);
    EXPECT_EQ(packet1.accel_cal_y, packet2.accel_cal_y);
    EXPECT_EQ(packet1.accel_cal_z, packet2.accel_cal_z);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, SENSOR_OFFSETS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sensor_offsets_t packet_c {
         17.0, 963497672, 963497880, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 19107, 19211, 19315
    };

    mavlink::ardupilotmega::msg::SENSOR_OFFSETS packet_in{};
    packet_in.mag_ofs_x = 19107;
    packet_in.mag_ofs_y = 19211;
    packet_in.mag_ofs_z = 19315;
    packet_in.mag_declination = 17.0;
    packet_in.raw_press = 963497672;
    packet_in.raw_temp = 963497880;
    packet_in.gyro_cal_x = 101.0;
    packet_in.gyro_cal_y = 129.0;
    packet_in.gyro_cal_z = 157.0;
    packet_in.accel_cal_x = 185.0;
    packet_in.accel_cal_y = 213.0;
    packet_in.accel_cal_z = 241.0;

    mavlink::ardupilotmega::msg::SENSOR_OFFSETS packet2{};

    mavlink_msg_sensor_offsets_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.mag_ofs_x, packet2.mag_ofs_x);
    EXPECT_EQ(packet_in.mag_ofs_y, packet2.mag_ofs_y);
    EXPECT_EQ(packet_in.mag_ofs_z, packet2.mag_ofs_z);
    EXPECT_EQ(packet_in.mag_declination, packet2.mag_declination);
    EXPECT_EQ(packet_in.raw_press, packet2.raw_press);
    EXPECT_EQ(packet_in.raw_temp, packet2.raw_temp);
    EXPECT_EQ(packet_in.gyro_cal_x, packet2.gyro_cal_x);
    EXPECT_EQ(packet_in.gyro_cal_y, packet2.gyro_cal_y);
    EXPECT_EQ(packet_in.gyro_cal_z, packet2.gyro_cal_z);
    EXPECT_EQ(packet_in.accel_cal_x, packet2.accel_cal_x);
    EXPECT_EQ(packet_in.accel_cal_y, packet2.accel_cal_y);
    EXPECT_EQ(packet_in.accel_cal_z, packet2.accel_cal_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, SET_MAG_OFFSETS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::SET_MAG_OFFSETS packet_in{};
    packet_in.target_system = 151;
    packet_in.target_component = 218;
    packet_in.mag_ofs_x = 17235;
    packet_in.mag_ofs_y = 17339;
    packet_in.mag_ofs_z = 17443;

    mavlink::ardupilotmega::msg::SET_MAG_OFFSETS packet1{};
    mavlink::ardupilotmega::msg::SET_MAG_OFFSETS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.mag_ofs_x, packet2.mag_ofs_x);
    EXPECT_EQ(packet1.mag_ofs_y, packet2.mag_ofs_y);
    EXPECT_EQ(packet1.mag_ofs_z, packet2.mag_ofs_z);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, SET_MAG_OFFSETS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_set_mag_offsets_t packet_c {
         17235, 17339, 17443, 151, 218
    };

    mavlink::ardupilotmega::msg::SET_MAG_OFFSETS packet_in{};
    packet_in.target_system = 151;
    packet_in.target_component = 218;
    packet_in.mag_ofs_x = 17235;
    packet_in.mag_ofs_y = 17339;
    packet_in.mag_ofs_z = 17443;

    mavlink::ardupilotmega::msg::SET_MAG_OFFSETS packet2{};

    mavlink_msg_set_mag_offsets_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.mag_ofs_x, packet2.mag_ofs_x);
    EXPECT_EQ(packet_in.mag_ofs_y, packet2.mag_ofs_y);
    EXPECT_EQ(packet_in.mag_ofs_z, packet2.mag_ofs_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, MEMINFO)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::MEMINFO packet_in{};
    packet_in.brkval = 17235;
    packet_in.freemem = 17339;
    packet_in.freemem32 = 963497672;

    mavlink::ardupilotmega::msg::MEMINFO packet1{};
    mavlink::ardupilotmega::msg::MEMINFO packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.brkval, packet2.brkval);
    EXPECT_EQ(packet1.freemem, packet2.freemem);
    EXPECT_EQ(packet1.freemem32, packet2.freemem32);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, MEMINFO)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_meminfo_t packet_c {
         17235, 17339, 963497672
    };

    mavlink::ardupilotmega::msg::MEMINFO packet_in{};
    packet_in.brkval = 17235;
    packet_in.freemem = 17339;
    packet_in.freemem32 = 963497672;

    mavlink::ardupilotmega::msg::MEMINFO packet2{};

    mavlink_msg_meminfo_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.brkval, packet2.brkval);
    EXPECT_EQ(packet_in.freemem, packet2.freemem);
    EXPECT_EQ(packet_in.freemem32, packet2.freemem32);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AP_ADC)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AP_ADC packet_in{};
    packet_in.adc1 = 17235;
    packet_in.adc2 = 17339;
    packet_in.adc3 = 17443;
    packet_in.adc4 = 17547;
    packet_in.adc5 = 17651;
    packet_in.adc6 = 17755;

    mavlink::ardupilotmega::msg::AP_ADC packet1{};
    mavlink::ardupilotmega::msg::AP_ADC packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.adc1, packet2.adc1);
    EXPECT_EQ(packet1.adc2, packet2.adc2);
    EXPECT_EQ(packet1.adc3, packet2.adc3);
    EXPECT_EQ(packet1.adc4, packet2.adc4);
    EXPECT_EQ(packet1.adc5, packet2.adc5);
    EXPECT_EQ(packet1.adc6, packet2.adc6);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AP_ADC)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ap_adc_t packet_c {
         17235, 17339, 17443, 17547, 17651, 17755
    };

    mavlink::ardupilotmega::msg::AP_ADC packet_in{};
    packet_in.adc1 = 17235;
    packet_in.adc2 = 17339;
    packet_in.adc3 = 17443;
    packet_in.adc4 = 17547;
    packet_in.adc5 = 17651;
    packet_in.adc6 = 17755;

    mavlink::ardupilotmega::msg::AP_ADC packet2{};

    mavlink_msg_ap_adc_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.adc1, packet2.adc1);
    EXPECT_EQ(packet_in.adc2, packet2.adc2);
    EXPECT_EQ(packet_in.adc3, packet2.adc3);
    EXPECT_EQ(packet_in.adc4, packet2.adc4);
    EXPECT_EQ(packet_in.adc5, packet2.adc5);
    EXPECT_EQ(packet_in.adc6, packet2.adc6);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DIGICAM_CONFIGURE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DIGICAM_CONFIGURE packet_in{};
    packet_in.target_system = 151;
    packet_in.target_component = 218;
    packet_in.mode = 29;
    packet_in.shutter_speed = 17443;
    packet_in.aperture = 96;
    packet_in.iso = 163;
    packet_in.exposure_type = 230;
    packet_in.command_id = 41;
    packet_in.engine_cut_off = 108;
    packet_in.extra_param = 175;
    packet_in.extra_value = 17.0;

    mavlink::ardupilotmega::msg::DIGICAM_CONFIGURE packet1{};
    mavlink::ardupilotmega::msg::DIGICAM_CONFIGURE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.mode, packet2.mode);
    EXPECT_EQ(packet1.shutter_speed, packet2.shutter_speed);
    EXPECT_EQ(packet1.aperture, packet2.aperture);
    EXPECT_EQ(packet1.iso, packet2.iso);
    EXPECT_EQ(packet1.exposure_type, packet2.exposure_type);
    EXPECT_EQ(packet1.command_id, packet2.command_id);
    EXPECT_EQ(packet1.engine_cut_off, packet2.engine_cut_off);
    EXPECT_EQ(packet1.extra_param, packet2.extra_param);
    EXPECT_EQ(packet1.extra_value, packet2.extra_value);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DIGICAM_CONFIGURE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_digicam_configure_t packet_c {
         17.0, 17443, 151, 218, 29, 96, 163, 230, 41, 108, 175
    };

    mavlink::ardupilotmega::msg::DIGICAM_CONFIGURE packet_in{};
    packet_in.target_system = 151;
    packet_in.target_component = 218;
    packet_in.mode = 29;
    packet_in.shutter_speed = 17443;
    packet_in.aperture = 96;
    packet_in.iso = 163;
    packet_in.exposure_type = 230;
    packet_in.command_id = 41;
    packet_in.engine_cut_off = 108;
    packet_in.extra_param = 175;
    packet_in.extra_value = 17.0;

    mavlink::ardupilotmega::msg::DIGICAM_CONFIGURE packet2{};

    mavlink_msg_digicam_configure_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.mode, packet2.mode);
    EXPECT_EQ(packet_in.shutter_speed, packet2.shutter_speed);
    EXPECT_EQ(packet_in.aperture, packet2.aperture);
    EXPECT_EQ(packet_in.iso, packet2.iso);
    EXPECT_EQ(packet_in.exposure_type, packet2.exposure_type);
    EXPECT_EQ(packet_in.command_id, packet2.command_id);
    EXPECT_EQ(packet_in.engine_cut_off, packet2.engine_cut_off);
    EXPECT_EQ(packet_in.extra_param, packet2.extra_param);
    EXPECT_EQ(packet_in.extra_value, packet2.extra_value);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DIGICAM_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DIGICAM_CONTROL packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.session = 151;
    packet_in.zoom_pos = 218;
    packet_in.zoom_step = 29;
    packet_in.focus_lock = 96;
    packet_in.shot = 163;
    packet_in.command_id = 230;
    packet_in.extra_param = 41;
    packet_in.extra_value = 17.0;

    mavlink::ardupilotmega::msg::DIGICAM_CONTROL packet1{};
    mavlink::ardupilotmega::msg::DIGICAM_CONTROL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.session, packet2.session);
    EXPECT_EQ(packet1.zoom_pos, packet2.zoom_pos);
    EXPECT_EQ(packet1.zoom_step, packet2.zoom_step);
    EXPECT_EQ(packet1.focus_lock, packet2.focus_lock);
    EXPECT_EQ(packet1.shot, packet2.shot);
    EXPECT_EQ(packet1.command_id, packet2.command_id);
    EXPECT_EQ(packet1.extra_param, packet2.extra_param);
    EXPECT_EQ(packet1.extra_value, packet2.extra_value);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DIGICAM_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_digicam_control_t packet_c {
         17.0, 17, 84, 151, 218, 29, 96, 163, 230, 41
    };

    mavlink::ardupilotmega::msg::DIGICAM_CONTROL packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.session = 151;
    packet_in.zoom_pos = 218;
    packet_in.zoom_step = 29;
    packet_in.focus_lock = 96;
    packet_in.shot = 163;
    packet_in.command_id = 230;
    packet_in.extra_param = 41;
    packet_in.extra_value = 17.0;

    mavlink::ardupilotmega::msg::DIGICAM_CONTROL packet2{};

    mavlink_msg_digicam_control_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.session, packet2.session);
    EXPECT_EQ(packet_in.zoom_pos, packet2.zoom_pos);
    EXPECT_EQ(packet_in.zoom_step, packet2.zoom_step);
    EXPECT_EQ(packet_in.focus_lock, packet2.focus_lock);
    EXPECT_EQ(packet_in.shot, packet2.shot);
    EXPECT_EQ(packet_in.command_id, packet2.command_id);
    EXPECT_EQ(packet_in.extra_param, packet2.extra_param);
    EXPECT_EQ(packet_in.extra_value, packet2.extra_value);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, MOUNT_CONFIGURE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::MOUNT_CONFIGURE packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.mount_mode = 139;
    packet_in.stab_roll = 206;
    packet_in.stab_pitch = 17;
    packet_in.stab_yaw = 84;

    mavlink::ardupilotmega::msg::MOUNT_CONFIGURE packet1{};
    mavlink::ardupilotmega::msg::MOUNT_CONFIGURE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.mount_mode, packet2.mount_mode);
    EXPECT_EQ(packet1.stab_roll, packet2.stab_roll);
    EXPECT_EQ(packet1.stab_pitch, packet2.stab_pitch);
    EXPECT_EQ(packet1.stab_yaw, packet2.stab_yaw);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, MOUNT_CONFIGURE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mount_configure_t packet_c {
         5, 72, 139, 206, 17, 84
    };

    mavlink::ardupilotmega::msg::MOUNT_CONFIGURE packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.mount_mode = 139;
    packet_in.stab_roll = 206;
    packet_in.stab_pitch = 17;
    packet_in.stab_yaw = 84;

    mavlink::ardupilotmega::msg::MOUNT_CONFIGURE packet2{};

    mavlink_msg_mount_configure_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.mount_mode, packet2.mount_mode);
    EXPECT_EQ(packet_in.stab_roll, packet2.stab_roll);
    EXPECT_EQ(packet_in.stab_pitch, packet2.stab_pitch);
    EXPECT_EQ(packet_in.stab_yaw, packet2.stab_yaw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, MOUNT_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::MOUNT_CONTROL packet_in{};
    packet_in.target_system = 41;
    packet_in.target_component = 108;
    packet_in.input_a = 963497464;
    packet_in.input_b = 963497672;
    packet_in.input_c = 963497880;
    packet_in.save_position = 175;

    mavlink::ardupilotmega::msg::MOUNT_CONTROL packet1{};
    mavlink::ardupilotmega::msg::MOUNT_CONTROL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.input_a, packet2.input_a);
    EXPECT_EQ(packet1.input_b, packet2.input_b);
    EXPECT_EQ(packet1.input_c, packet2.input_c);
    EXPECT_EQ(packet1.save_position, packet2.save_position);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, MOUNT_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mount_control_t packet_c {
         963497464, 963497672, 963497880, 41, 108, 175
    };

    mavlink::ardupilotmega::msg::MOUNT_CONTROL packet_in{};
    packet_in.target_system = 41;
    packet_in.target_component = 108;
    packet_in.input_a = 963497464;
    packet_in.input_b = 963497672;
    packet_in.input_c = 963497880;
    packet_in.save_position = 175;

    mavlink::ardupilotmega::msg::MOUNT_CONTROL packet2{};

    mavlink_msg_mount_control_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.input_a, packet2.input_a);
    EXPECT_EQ(packet_in.input_b, packet2.input_b);
    EXPECT_EQ(packet_in.input_c, packet2.input_c);
    EXPECT_EQ(packet_in.save_position, packet2.save_position);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, MOUNT_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::MOUNT_STATUS packet_in{};
    packet_in.target_system = 41;
    packet_in.target_component = 108;
    packet_in.pointing_a = 963497464;
    packet_in.pointing_b = 963497672;
    packet_in.pointing_c = 963497880;
    packet_in.mount_mode = 175;

    mavlink::ardupilotmega::msg::MOUNT_STATUS packet1{};
    mavlink::ardupilotmega::msg::MOUNT_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.pointing_a, packet2.pointing_a);
    EXPECT_EQ(packet1.pointing_b, packet2.pointing_b);
    EXPECT_EQ(packet1.pointing_c, packet2.pointing_c);
    EXPECT_EQ(packet1.mount_mode, packet2.mount_mode);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, MOUNT_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mount_status_t packet_c {
         963497464, 963497672, 963497880, 41, 108, 175
    };

    mavlink::ardupilotmega::msg::MOUNT_STATUS packet_in{};
    packet_in.target_system = 41;
    packet_in.target_component = 108;
    packet_in.pointing_a = 963497464;
    packet_in.pointing_b = 963497672;
    packet_in.pointing_c = 963497880;
    packet_in.mount_mode = 175;

    mavlink::ardupilotmega::msg::MOUNT_STATUS packet2{};

    mavlink_msg_mount_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.pointing_a, packet2.pointing_a);
    EXPECT_EQ(packet_in.pointing_b, packet2.pointing_b);
    EXPECT_EQ(packet_in.pointing_c, packet2.pointing_c);
    EXPECT_EQ(packet_in.mount_mode, packet2.mount_mode);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, FENCE_POINT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::FENCE_POINT packet_in{};
    packet_in.target_system = 29;
    packet_in.target_component = 96;
    packet_in.idx = 163;
    packet_in.count = 230;
    packet_in.lat = 17.0;
    packet_in.lng = 45.0;

    mavlink::ardupilotmega::msg::FENCE_POINT packet1{};
    mavlink::ardupilotmega::msg::FENCE_POINT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.idx, packet2.idx);
    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, FENCE_POINT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_fence_point_t packet_c {
         17.0, 45.0, 29, 96, 163, 230
    };

    mavlink::ardupilotmega::msg::FENCE_POINT packet_in{};
    packet_in.target_system = 29;
    packet_in.target_component = 96;
    packet_in.idx = 163;
    packet_in.count = 230;
    packet_in.lat = 17.0;
    packet_in.lng = 45.0;

    mavlink::ardupilotmega::msg::FENCE_POINT packet2{};

    mavlink_msg_fence_point_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.idx, packet2.idx);
    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, FENCE_FETCH_POINT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::FENCE_FETCH_POINT packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.idx = 139;

    mavlink::ardupilotmega::msg::FENCE_FETCH_POINT packet1{};
    mavlink::ardupilotmega::msg::FENCE_FETCH_POINT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.idx, packet2.idx);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, FENCE_FETCH_POINT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_fence_fetch_point_t packet_c {
         5, 72, 139
    };

    mavlink::ardupilotmega::msg::FENCE_FETCH_POINT packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.idx = 139;

    mavlink::ardupilotmega::msg::FENCE_FETCH_POINT packet2{};

    mavlink_msg_fence_fetch_point_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.idx, packet2.idx);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AHRS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AHRS packet_in{};
    packet_in.omegaIx = 17.0;
    packet_in.omegaIy = 45.0;
    packet_in.omegaIz = 73.0;
    packet_in.accel_weight = 101.0;
    packet_in.renorm_val = 129.0;
    packet_in.error_rp = 157.0;
    packet_in.error_yaw = 185.0;

    mavlink::ardupilotmega::msg::AHRS packet1{};
    mavlink::ardupilotmega::msg::AHRS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.omegaIx, packet2.omegaIx);
    EXPECT_EQ(packet1.omegaIy, packet2.omegaIy);
    EXPECT_EQ(packet1.omegaIz, packet2.omegaIz);
    EXPECT_EQ(packet1.accel_weight, packet2.accel_weight);
    EXPECT_EQ(packet1.renorm_val, packet2.renorm_val);
    EXPECT_EQ(packet1.error_rp, packet2.error_rp);
    EXPECT_EQ(packet1.error_yaw, packet2.error_yaw);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AHRS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0
    };

    mavlink::ardupilotmega::msg::AHRS packet_in{};
    packet_in.omegaIx = 17.0;
    packet_in.omegaIy = 45.0;
    packet_in.omegaIz = 73.0;
    packet_in.accel_weight = 101.0;
    packet_in.renorm_val = 129.0;
    packet_in.error_rp = 157.0;
    packet_in.error_yaw = 185.0;

    mavlink::ardupilotmega::msg::AHRS packet2{};

    mavlink_msg_ahrs_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.omegaIx, packet2.omegaIx);
    EXPECT_EQ(packet_in.omegaIy, packet2.omegaIy);
    EXPECT_EQ(packet_in.omegaIz, packet2.omegaIz);
    EXPECT_EQ(packet_in.accel_weight, packet2.accel_weight);
    EXPECT_EQ(packet_in.renorm_val, packet2.renorm_val);
    EXPECT_EQ(packet_in.error_rp, packet2.error_rp);
    EXPECT_EQ(packet_in.error_yaw, packet2.error_yaw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, SIMSTATE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::SIMSTATE packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.xacc = 101.0;
    packet_in.yacc = 129.0;
    packet_in.zacc = 157.0;
    packet_in.xgyro = 185.0;
    packet_in.ygyro = 213.0;
    packet_in.zgyro = 241.0;
    packet_in.lat = 963499336;
    packet_in.lng = 963499544;

    mavlink::ardupilotmega::msg::SIMSTATE packet1{};
    mavlink::ardupilotmega::msg::SIMSTATE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.xacc, packet2.xacc);
    EXPECT_EQ(packet1.yacc, packet2.yacc);
    EXPECT_EQ(packet1.zacc, packet2.zacc);
    EXPECT_EQ(packet1.xgyro, packet2.xgyro);
    EXPECT_EQ(packet1.ygyro, packet2.ygyro);
    EXPECT_EQ(packet1.zgyro, packet2.zgyro);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, SIMSTATE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_simstate_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 963499336, 963499544
    };

    mavlink::ardupilotmega::msg::SIMSTATE packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.xacc = 101.0;
    packet_in.yacc = 129.0;
    packet_in.zacc = 157.0;
    packet_in.xgyro = 185.0;
    packet_in.ygyro = 213.0;
    packet_in.zgyro = 241.0;
    packet_in.lat = 963499336;
    packet_in.lng = 963499544;

    mavlink::ardupilotmega::msg::SIMSTATE packet2{};

    mavlink_msg_simstate_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.xacc, packet2.xacc);
    EXPECT_EQ(packet_in.yacc, packet2.yacc);
    EXPECT_EQ(packet_in.zacc, packet2.zacc);
    EXPECT_EQ(packet_in.xgyro, packet2.xgyro);
    EXPECT_EQ(packet_in.ygyro, packet2.ygyro);
    EXPECT_EQ(packet_in.zgyro, packet2.zgyro);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, HWSTATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::HWSTATUS packet_in{};
    packet_in.Vcc = 17235;
    packet_in.I2Cerr = 139;

    mavlink::ardupilotmega::msg::HWSTATUS packet1{};
    mavlink::ardupilotmega::msg::HWSTATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.Vcc, packet2.Vcc);
    EXPECT_EQ(packet1.I2Cerr, packet2.I2Cerr);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, HWSTATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_hwstatus_t packet_c {
         17235, 139
    };

    mavlink::ardupilotmega::msg::HWSTATUS packet_in{};
    packet_in.Vcc = 17235;
    packet_in.I2Cerr = 139;

    mavlink::ardupilotmega::msg::HWSTATUS packet2{};

    mavlink_msg_hwstatus_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.Vcc, packet2.Vcc);
    EXPECT_EQ(packet_in.I2Cerr, packet2.I2Cerr);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, RADIO)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::RADIO packet_in{};
    packet_in.rssi = 17;
    packet_in.remrssi = 84;
    packet_in.txbuf = 151;
    packet_in.noise = 218;
    packet_in.remnoise = 29;
    packet_in.rxerrors = 17235;
    packet_in.fixed = 17339;

    mavlink::ardupilotmega::msg::RADIO packet1{};
    mavlink::ardupilotmega::msg::RADIO packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.rssi, packet2.rssi);
    EXPECT_EQ(packet1.remrssi, packet2.remrssi);
    EXPECT_EQ(packet1.txbuf, packet2.txbuf);
    EXPECT_EQ(packet1.noise, packet2.noise);
    EXPECT_EQ(packet1.remnoise, packet2.remnoise);
    EXPECT_EQ(packet1.rxerrors, packet2.rxerrors);
    EXPECT_EQ(packet1.fixed, packet2.fixed);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, RADIO)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_radio_t packet_c {
         17235, 17339, 17, 84, 151, 218, 29
    };

    mavlink::ardupilotmega::msg::RADIO packet_in{};
    packet_in.rssi = 17;
    packet_in.remrssi = 84;
    packet_in.txbuf = 151;
    packet_in.noise = 218;
    packet_in.remnoise = 29;
    packet_in.rxerrors = 17235;
    packet_in.fixed = 17339;

    mavlink::ardupilotmega::msg::RADIO packet2{};

    mavlink_msg_radio_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.rssi, packet2.rssi);
    EXPECT_EQ(packet_in.remrssi, packet2.remrssi);
    EXPECT_EQ(packet_in.txbuf, packet2.txbuf);
    EXPECT_EQ(packet_in.noise, packet2.noise);
    EXPECT_EQ(packet_in.remnoise, packet2.remnoise);
    EXPECT_EQ(packet_in.rxerrors, packet2.rxerrors);
    EXPECT_EQ(packet_in.fixed, packet2.fixed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, LIMITS_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::LIMITS_STATUS packet_in{};
    packet_in.limits_state = 187;
    packet_in.last_trigger = 963497464;
    packet_in.last_action = 963497672;
    packet_in.last_recovery = 963497880;
    packet_in.last_clear = 963498088;
    packet_in.breach_count = 18067;
    packet_in.mods_enabled = 254;
    packet_in.mods_required = 65;
    packet_in.mods_triggered = 132;

    mavlink::ardupilotmega::msg::LIMITS_STATUS packet1{};
    mavlink::ardupilotmega::msg::LIMITS_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.limits_state, packet2.limits_state);
    EXPECT_EQ(packet1.last_trigger, packet2.last_trigger);
    EXPECT_EQ(packet1.last_action, packet2.last_action);
    EXPECT_EQ(packet1.last_recovery, packet2.last_recovery);
    EXPECT_EQ(packet1.last_clear, packet2.last_clear);
    EXPECT_EQ(packet1.breach_count, packet2.breach_count);
    EXPECT_EQ(packet1.mods_enabled, packet2.mods_enabled);
    EXPECT_EQ(packet1.mods_required, packet2.mods_required);
    EXPECT_EQ(packet1.mods_triggered, packet2.mods_triggered);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, LIMITS_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_limits_status_t packet_c {
         963497464, 963497672, 963497880, 963498088, 18067, 187, 254, 65, 132
    };

    mavlink::ardupilotmega::msg::LIMITS_STATUS packet_in{};
    packet_in.limits_state = 187;
    packet_in.last_trigger = 963497464;
    packet_in.last_action = 963497672;
    packet_in.last_recovery = 963497880;
    packet_in.last_clear = 963498088;
    packet_in.breach_count = 18067;
    packet_in.mods_enabled = 254;
    packet_in.mods_required = 65;
    packet_in.mods_triggered = 132;

    mavlink::ardupilotmega::msg::LIMITS_STATUS packet2{};

    mavlink_msg_limits_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.limits_state, packet2.limits_state);
    EXPECT_EQ(packet_in.last_trigger, packet2.last_trigger);
    EXPECT_EQ(packet_in.last_action, packet2.last_action);
    EXPECT_EQ(packet_in.last_recovery, packet2.last_recovery);
    EXPECT_EQ(packet_in.last_clear, packet2.last_clear);
    EXPECT_EQ(packet_in.breach_count, packet2.breach_count);
    EXPECT_EQ(packet_in.mods_enabled, packet2.mods_enabled);
    EXPECT_EQ(packet_in.mods_required, packet2.mods_required);
    EXPECT_EQ(packet_in.mods_triggered, packet2.mods_triggered);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, WIND)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::WIND packet_in{};
    packet_in.direction = 17.0;
    packet_in.speed = 45.0;
    packet_in.speed_z = 73.0;

    mavlink::ardupilotmega::msg::WIND packet1{};
    mavlink::ardupilotmega::msg::WIND packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.direction, packet2.direction);
    EXPECT_EQ(packet1.speed, packet2.speed);
    EXPECT_EQ(packet1.speed_z, packet2.speed_z);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, WIND)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_wind_t packet_c {
         17.0, 45.0, 73.0
    };

    mavlink::ardupilotmega::msg::WIND packet_in{};
    packet_in.direction = 17.0;
    packet_in.speed = 45.0;
    packet_in.speed_z = 73.0;

    mavlink::ardupilotmega::msg::WIND packet2{};

    mavlink_msg_wind_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.direction, packet2.direction);
    EXPECT_EQ(packet_in.speed, packet2.speed);
    EXPECT_EQ(packet_in.speed_z, packet2.speed_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DATA16)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DATA16 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154 }};

    mavlink::ardupilotmega::msg::DATA16 packet1{};
    mavlink::ardupilotmega::msg::DATA16 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.len, packet2.len);
    EXPECT_EQ(packet1.data, packet2.data);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DATA16)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_data16_t packet_c {
         5, 72, { 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154 }
    };

    mavlink::ardupilotmega::msg::DATA16 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154 }};

    mavlink::ardupilotmega::msg::DATA16 packet2{};

    mavlink_msg_data16_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.len, packet2.len);
    EXPECT_EQ(packet_in.data, packet2.data);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DATA32)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DATA32 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170 }};

    mavlink::ardupilotmega::msg::DATA32 packet1{};
    mavlink::ardupilotmega::msg::DATA32 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.len, packet2.len);
    EXPECT_EQ(packet1.data, packet2.data);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DATA32)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_data32_t packet_c {
         5, 72, { 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170 }
    };

    mavlink::ardupilotmega::msg::DATA32 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170 }};

    mavlink::ardupilotmega::msg::DATA32 packet2{};

    mavlink_msg_data32_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.len, packet2.len);
    EXPECT_EQ(packet_in.data, packet2.data);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DATA64)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DATA64 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202 }};

    mavlink::ardupilotmega::msg::DATA64 packet1{};
    mavlink::ardupilotmega::msg::DATA64 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.len, packet2.len);
    EXPECT_EQ(packet1.data, packet2.data);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DATA64)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_data64_t packet_c {
         5, 72, { 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202 }
    };

    mavlink::ardupilotmega::msg::DATA64 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202 }};

    mavlink::ardupilotmega::msg::DATA64 packet2{};

    mavlink_msg_data64_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.len, packet2.len);
    EXPECT_EQ(packet_in.data, packet2.data);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DATA96)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DATA96 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234 }};

    mavlink::ardupilotmega::msg::DATA96 packet1{};
    mavlink::ardupilotmega::msg::DATA96 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.type, packet2.type);
    EXPECT_EQ(packet1.len, packet2.len);
    EXPECT_EQ(packet1.data, packet2.data);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DATA96)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_data96_t packet_c {
         5, 72, { 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234 }
    };

    mavlink::ardupilotmega::msg::DATA96 packet_in{};
    packet_in.type = 5;
    packet_in.len = 72;
    packet_in.data = {{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234 }};

    mavlink::ardupilotmega::msg::DATA96 packet2{};

    mavlink_msg_data96_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.type, packet2.type);
    EXPECT_EQ(packet_in.len, packet2.len);
    EXPECT_EQ(packet_in.data, packet2.data);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, RANGEFINDER)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::RANGEFINDER packet_in{};
    packet_in.distance = 17.0;
    packet_in.voltage = 45.0;

    mavlink::ardupilotmega::msg::RANGEFINDER packet1{};
    mavlink::ardupilotmega::msg::RANGEFINDER packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.distance, packet2.distance);
    EXPECT_EQ(packet1.voltage, packet2.voltage);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, RANGEFINDER)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rangefinder_t packet_c {
         17.0, 45.0
    };

    mavlink::ardupilotmega::msg::RANGEFINDER packet_in{};
    packet_in.distance = 17.0;
    packet_in.voltage = 45.0;

    mavlink::ardupilotmega::msg::RANGEFINDER packet2{};

    mavlink_msg_rangefinder_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.distance, packet2.distance);
    EXPECT_EQ(packet_in.voltage, packet2.voltage);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AIRSPEED_AUTOCAL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AIRSPEED_AUTOCAL packet_in{};
    packet_in.vx = 17.0;
    packet_in.vy = 45.0;
    packet_in.vz = 73.0;
    packet_in.diff_pressure = 101.0;
    packet_in.EAS2TAS = 129.0;
    packet_in.ratio = 157.0;
    packet_in.state_x = 185.0;
    packet_in.state_y = 213.0;
    packet_in.state_z = 241.0;
    packet_in.Pax = 269.0;
    packet_in.Pby = 297.0;
    packet_in.Pcz = 325.0;

    mavlink::ardupilotmega::msg::AIRSPEED_AUTOCAL packet1{};
    mavlink::ardupilotmega::msg::AIRSPEED_AUTOCAL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.vx, packet2.vx);
    EXPECT_EQ(packet1.vy, packet2.vy);
    EXPECT_EQ(packet1.vz, packet2.vz);
    EXPECT_EQ(packet1.diff_pressure, packet2.diff_pressure);
    EXPECT_EQ(packet1.EAS2TAS, packet2.EAS2TAS);
    EXPECT_EQ(packet1.ratio, packet2.ratio);
    EXPECT_EQ(packet1.state_x, packet2.state_x);
    EXPECT_EQ(packet1.state_y, packet2.state_y);
    EXPECT_EQ(packet1.state_z, packet2.state_z);
    EXPECT_EQ(packet1.Pax, packet2.Pax);
    EXPECT_EQ(packet1.Pby, packet2.Pby);
    EXPECT_EQ(packet1.Pcz, packet2.Pcz);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AIRSPEED_AUTOCAL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_airspeed_autocal_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0
    };

    mavlink::ardupilotmega::msg::AIRSPEED_AUTOCAL packet_in{};
    packet_in.vx = 17.0;
    packet_in.vy = 45.0;
    packet_in.vz = 73.0;
    packet_in.diff_pressure = 101.0;
    packet_in.EAS2TAS = 129.0;
    packet_in.ratio = 157.0;
    packet_in.state_x = 185.0;
    packet_in.state_y = 213.0;
    packet_in.state_z = 241.0;
    packet_in.Pax = 269.0;
    packet_in.Pby = 297.0;
    packet_in.Pcz = 325.0;

    mavlink::ardupilotmega::msg::AIRSPEED_AUTOCAL packet2{};

    mavlink_msg_airspeed_autocal_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.vx, packet2.vx);
    EXPECT_EQ(packet_in.vy, packet2.vy);
    EXPECT_EQ(packet_in.vz, packet2.vz);
    EXPECT_EQ(packet_in.diff_pressure, packet2.diff_pressure);
    EXPECT_EQ(packet_in.EAS2TAS, packet2.EAS2TAS);
    EXPECT_EQ(packet_in.ratio, packet2.ratio);
    EXPECT_EQ(packet_in.state_x, packet2.state_x);
    EXPECT_EQ(packet_in.state_y, packet2.state_y);
    EXPECT_EQ(packet_in.state_z, packet2.state_z);
    EXPECT_EQ(packet_in.Pax, packet2.Pax);
    EXPECT_EQ(packet_in.Pby, packet2.Pby);
    EXPECT_EQ(packet_in.Pcz, packet2.Pcz);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, RALLY_POINT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::RALLY_POINT packet_in{};
    packet_in.target_system = 175;
    packet_in.target_component = 242;
    packet_in.idx = 53;
    packet_in.count = 120;
    packet_in.lat = 963497464;
    packet_in.lng = 963497672;
    packet_in.alt = 17651;
    packet_in.break_alt = 17755;
    packet_in.land_dir = 17859;
    packet_in.flags = 187;

    mavlink::ardupilotmega::msg::RALLY_POINT packet1{};
    mavlink::ardupilotmega::msg::RALLY_POINT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.idx, packet2.idx);
    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
    EXPECT_EQ(packet1.alt, packet2.alt);
    EXPECT_EQ(packet1.break_alt, packet2.break_alt);
    EXPECT_EQ(packet1.land_dir, packet2.land_dir);
    EXPECT_EQ(packet1.flags, packet2.flags);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, RALLY_POINT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rally_point_t packet_c {
         963497464, 963497672, 17651, 17755, 17859, 175, 242, 53, 120, 187
    };

    mavlink::ardupilotmega::msg::RALLY_POINT packet_in{};
    packet_in.target_system = 175;
    packet_in.target_component = 242;
    packet_in.idx = 53;
    packet_in.count = 120;
    packet_in.lat = 963497464;
    packet_in.lng = 963497672;
    packet_in.alt = 17651;
    packet_in.break_alt = 17755;
    packet_in.land_dir = 17859;
    packet_in.flags = 187;

    mavlink::ardupilotmega::msg::RALLY_POINT packet2{};

    mavlink_msg_rally_point_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.idx, packet2.idx);
    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);
    EXPECT_EQ(packet_in.alt, packet2.alt);
    EXPECT_EQ(packet_in.break_alt, packet2.break_alt);
    EXPECT_EQ(packet_in.land_dir, packet2.land_dir);
    EXPECT_EQ(packet_in.flags, packet2.flags);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, RALLY_FETCH_POINT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::RALLY_FETCH_POINT packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.idx = 139;

    mavlink::ardupilotmega::msg::RALLY_FETCH_POINT packet1{};
    mavlink::ardupilotmega::msg::RALLY_FETCH_POINT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.idx, packet2.idx);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, RALLY_FETCH_POINT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rally_fetch_point_t packet_c {
         5, 72, 139
    };

    mavlink::ardupilotmega::msg::RALLY_FETCH_POINT packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.idx = 139;

    mavlink::ardupilotmega::msg::RALLY_FETCH_POINT packet2{};

    mavlink_msg_rally_fetch_point_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.idx, packet2.idx);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, COMPASSMOT_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::COMPASSMOT_STATUS packet_in{};
    packet_in.throttle = 18067;
    packet_in.current = 17.0;
    packet_in.interference = 18171;
    packet_in.CompensationX = 45.0;
    packet_in.CompensationY = 73.0;
    packet_in.CompensationZ = 101.0;

    mavlink::ardupilotmega::msg::COMPASSMOT_STATUS packet1{};
    mavlink::ardupilotmega::msg::COMPASSMOT_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.throttle, packet2.throttle);
    EXPECT_EQ(packet1.current, packet2.current);
    EXPECT_EQ(packet1.interference, packet2.interference);
    EXPECT_EQ(packet1.CompensationX, packet2.CompensationX);
    EXPECT_EQ(packet1.CompensationY, packet2.CompensationY);
    EXPECT_EQ(packet1.CompensationZ, packet2.CompensationZ);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, COMPASSMOT_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_compassmot_status_t packet_c {
         17.0, 45.0, 73.0, 101.0, 18067, 18171
    };

    mavlink::ardupilotmega::msg::COMPASSMOT_STATUS packet_in{};
    packet_in.throttle = 18067;
    packet_in.current = 17.0;
    packet_in.interference = 18171;
    packet_in.CompensationX = 45.0;
    packet_in.CompensationY = 73.0;
    packet_in.CompensationZ = 101.0;

    mavlink::ardupilotmega::msg::COMPASSMOT_STATUS packet2{};

    mavlink_msg_compassmot_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.throttle, packet2.throttle);
    EXPECT_EQ(packet_in.current, packet2.current);
    EXPECT_EQ(packet_in.interference, packet2.interference);
    EXPECT_EQ(packet_in.CompensationX, packet2.CompensationX);
    EXPECT_EQ(packet_in.CompensationY, packet2.CompensationY);
    EXPECT_EQ(packet_in.CompensationZ, packet2.CompensationZ);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AHRS2)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AHRS2 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;

    mavlink::ardupilotmega::msg::AHRS2 packet1{};
    mavlink::ardupilotmega::msg::AHRS2 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AHRS2)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs2_t packet_c {
         17.0, 45.0, 73.0, 101.0, 963498296, 963498504
    };

    mavlink::ardupilotmega::msg::AHRS2 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;

    mavlink::ardupilotmega::msg::AHRS2 packet2{};

    mavlink_msg_ahrs2_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, CAMERA_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::CAMERA_STATUS packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.target_system = 211;
    packet_in.cam_idx = 22;
    packet_in.img_idx = 18483;
    packet_in.event_id = 89;
    packet_in.p1 = 73.0;
    packet_in.p2 = 101.0;
    packet_in.p3 = 129.0;
    packet_in.p4 = 157.0;

    mavlink::ardupilotmega::msg::CAMERA_STATUS packet1{};
    mavlink::ardupilotmega::msg::CAMERA_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.cam_idx, packet2.cam_idx);
    EXPECT_EQ(packet1.img_idx, packet2.img_idx);
    EXPECT_EQ(packet1.event_id, packet2.event_id);
    EXPECT_EQ(packet1.p1, packet2.p1);
    EXPECT_EQ(packet1.p2, packet2.p2);
    EXPECT_EQ(packet1.p3, packet2.p3);
    EXPECT_EQ(packet1.p4, packet2.p4);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, CAMERA_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_camera_status_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 18483, 211, 22, 89
    };

    mavlink::ardupilotmega::msg::CAMERA_STATUS packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.target_system = 211;
    packet_in.cam_idx = 22;
    packet_in.img_idx = 18483;
    packet_in.event_id = 89;
    packet_in.p1 = 73.0;
    packet_in.p2 = 101.0;
    packet_in.p3 = 129.0;
    packet_in.p4 = 157.0;

    mavlink::ardupilotmega::msg::CAMERA_STATUS packet2{};

    mavlink_msg_camera_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.cam_idx, packet2.cam_idx);
    EXPECT_EQ(packet_in.img_idx, packet2.img_idx);
    EXPECT_EQ(packet_in.event_id, packet2.event_id);
    EXPECT_EQ(packet_in.p1, packet2.p1);
    EXPECT_EQ(packet_in.p2, packet2.p2);
    EXPECT_EQ(packet_in.p3, packet2.p3);
    EXPECT_EQ(packet_in.p4, packet2.p4);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, CAMERA_FEEDBACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::CAMERA_FEEDBACK packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.target_system = 3;
    packet_in.cam_idx = 70;
    packet_in.img_idx = 19315;
    packet_in.lat = 963497880;
    packet_in.lng = 963498088;
    packet_in.alt_msl = 129.0;
    packet_in.alt_rel = 157.0;
    packet_in.roll = 185.0;
    packet_in.pitch = 213.0;
    packet_in.yaw = 241.0;
    packet_in.foc_len = 269.0;
    packet_in.flags = 137;
    packet_in.completed_captures = 19575;

    mavlink::ardupilotmega::msg::CAMERA_FEEDBACK packet1{};
    mavlink::ardupilotmega::msg::CAMERA_FEEDBACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.cam_idx, packet2.cam_idx);
    EXPECT_EQ(packet1.img_idx, packet2.img_idx);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
    EXPECT_EQ(packet1.alt_msl, packet2.alt_msl);
    EXPECT_EQ(packet1.alt_rel, packet2.alt_rel);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.foc_len, packet2.foc_len);
    EXPECT_EQ(packet1.flags, packet2.flags);
    EXPECT_EQ(packet1.completed_captures, packet2.completed_captures);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, CAMERA_FEEDBACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_camera_feedback_t packet_c {
         93372036854775807ULL, 963497880, 963498088, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 19315, 3, 70, 137, 19575
    };

    mavlink::ardupilotmega::msg::CAMERA_FEEDBACK packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.target_system = 3;
    packet_in.cam_idx = 70;
    packet_in.img_idx = 19315;
    packet_in.lat = 963497880;
    packet_in.lng = 963498088;
    packet_in.alt_msl = 129.0;
    packet_in.alt_rel = 157.0;
    packet_in.roll = 185.0;
    packet_in.pitch = 213.0;
    packet_in.yaw = 241.0;
    packet_in.foc_len = 269.0;
    packet_in.flags = 137;
    packet_in.completed_captures = 19575;

    mavlink::ardupilotmega::msg::CAMERA_FEEDBACK packet2{};

    mavlink_msg_camera_feedback_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.cam_idx, packet2.cam_idx);
    EXPECT_EQ(packet_in.img_idx, packet2.img_idx);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);
    EXPECT_EQ(packet_in.alt_msl, packet2.alt_msl);
    EXPECT_EQ(packet_in.alt_rel, packet2.alt_rel);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.foc_len, packet2.foc_len);
    EXPECT_EQ(packet_in.flags, packet2.flags);
    EXPECT_EQ(packet_in.completed_captures, packet2.completed_captures);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, BATTERY2)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::BATTERY2 packet_in{};
    packet_in.voltage = 17235;
    packet_in.current_battery = 17339;

    mavlink::ardupilotmega::msg::BATTERY2 packet1{};
    mavlink::ardupilotmega::msg::BATTERY2 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.voltage, packet2.voltage);
    EXPECT_EQ(packet1.current_battery, packet2.current_battery);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, BATTERY2)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_battery2_t packet_c {
         17235, 17339
    };

    mavlink::ardupilotmega::msg::BATTERY2 packet_in{};
    packet_in.voltage = 17235;
    packet_in.current_battery = 17339;

    mavlink::ardupilotmega::msg::BATTERY2 packet2{};

    mavlink_msg_battery2_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.voltage, packet2.voltage);
    EXPECT_EQ(packet_in.current_battery, packet2.current_battery);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AHRS3)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AHRS3 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;
    packet_in.v1 = 185.0;
    packet_in.v2 = 213.0;
    packet_in.v3 = 241.0;
    packet_in.v4 = 269.0;

    mavlink::ardupilotmega::msg::AHRS3 packet1{};
    mavlink::ardupilotmega::msg::AHRS3 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
    EXPECT_EQ(packet1.v1, packet2.v1);
    EXPECT_EQ(packet1.v2, packet2.v2);
    EXPECT_EQ(packet1.v3, packet2.v3);
    EXPECT_EQ(packet1.v4, packet2.v4);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AHRS3)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ahrs3_t packet_c {
         17.0, 45.0, 73.0, 101.0, 963498296, 963498504, 185.0, 213.0, 241.0, 269.0
    };

    mavlink::ardupilotmega::msg::AHRS3 packet_in{};
    packet_in.roll = 17.0;
    packet_in.pitch = 45.0;
    packet_in.yaw = 73.0;
    packet_in.altitude = 101.0;
    packet_in.lat = 963498296;
    packet_in.lng = 963498504;
    packet_in.v1 = 185.0;
    packet_in.v2 = 213.0;
    packet_in.v3 = 241.0;
    packet_in.v4 = 269.0;

    mavlink::ardupilotmega::msg::AHRS3 packet2{};

    mavlink_msg_ahrs3_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);
    EXPECT_EQ(packet_in.v1, packet2.v1);
    EXPECT_EQ(packet_in.v2, packet2.v2);
    EXPECT_EQ(packet_in.v3, packet2.v3);
    EXPECT_EQ(packet_in.v4, packet2.v4);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AUTOPILOT_VERSION_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AUTOPILOT_VERSION_REQUEST packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;

    mavlink::ardupilotmega::msg::AUTOPILOT_VERSION_REQUEST packet1{};
    mavlink::ardupilotmega::msg::AUTOPILOT_VERSION_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AUTOPILOT_VERSION_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_autopilot_version_request_t packet_c {
         5, 72
    };

    mavlink::ardupilotmega::msg::AUTOPILOT_VERSION_REQUEST packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;

    mavlink::ardupilotmega::msg::AUTOPILOT_VERSION_REQUEST packet2{};

    mavlink_msg_autopilot_version_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, REMOTE_LOG_DATA_BLOCK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::REMOTE_LOG_DATA_BLOCK packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.seqno = 963497464;
    packet_in.data = {{ 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94 }};

    mavlink::ardupilotmega::msg::REMOTE_LOG_DATA_BLOCK packet1{};
    mavlink::ardupilotmega::msg::REMOTE_LOG_DATA_BLOCK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.seqno, packet2.seqno);
    EXPECT_EQ(packet1.data, packet2.data);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, REMOTE_LOG_DATA_BLOCK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_remote_log_data_block_t packet_c {
         963497464, 17, 84, { 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94 }
    };

    mavlink::ardupilotmega::msg::REMOTE_LOG_DATA_BLOCK packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.seqno = 963497464;
    packet_in.data = {{ 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94 }};

    mavlink::ardupilotmega::msg::REMOTE_LOG_DATA_BLOCK packet2{};

    mavlink_msg_remote_log_data_block_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.seqno, packet2.seqno);
    EXPECT_EQ(packet_in.data, packet2.data);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, REMOTE_LOG_BLOCK_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::REMOTE_LOG_BLOCK_STATUS packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.seqno = 963497464;
    packet_in.status = 151;

    mavlink::ardupilotmega::msg::REMOTE_LOG_BLOCK_STATUS packet1{};
    mavlink::ardupilotmega::msg::REMOTE_LOG_BLOCK_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.seqno, packet2.seqno);
    EXPECT_EQ(packet1.status, packet2.status);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, REMOTE_LOG_BLOCK_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_remote_log_block_status_t packet_c {
         963497464, 17, 84, 151
    };

    mavlink::ardupilotmega::msg::REMOTE_LOG_BLOCK_STATUS packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.seqno = 963497464;
    packet_in.status = 151;

    mavlink::ardupilotmega::msg::REMOTE_LOG_BLOCK_STATUS packet2{};

    mavlink_msg_remote_log_block_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.seqno, packet2.seqno);
    EXPECT_EQ(packet_in.status, packet2.status);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, LED_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::LED_CONTROL packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.instance = 139;
    packet_in.pattern = 206;
    packet_in.custom_len = 17;
    packet_in.custom_bytes = {{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }};

    mavlink::ardupilotmega::msg::LED_CONTROL packet1{};
    mavlink::ardupilotmega::msg::LED_CONTROL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.instance, packet2.instance);
    EXPECT_EQ(packet1.pattern, packet2.pattern);
    EXPECT_EQ(packet1.custom_len, packet2.custom_len);
    EXPECT_EQ(packet1.custom_bytes, packet2.custom_bytes);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, LED_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_led_control_t packet_c {
         5, 72, 139, 206, 17, { 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }
    };

    mavlink::ardupilotmega::msg::LED_CONTROL packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.instance = 139;
    packet_in.pattern = 206;
    packet_in.custom_len = 17;
    packet_in.custom_bytes = {{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }};

    mavlink::ardupilotmega::msg::LED_CONTROL packet2{};

    mavlink_msg_led_control_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.instance, packet2.instance);
    EXPECT_EQ(packet_in.pattern, packet2.pattern);
    EXPECT_EQ(packet_in.custom_len, packet2.custom_len);
    EXPECT_EQ(packet_in.custom_bytes, packet2.custom_bytes);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, MAG_CAL_PROGRESS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::MAG_CAL_PROGRESS packet_in{};
    packet_in.compass_id = 41;
    packet_in.cal_mask = 108;
    packet_in.cal_status = 175;
    packet_in.attempt = 242;
    packet_in.completion_pct = 53;
    packet_in.completion_mask = {{ 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 }};
    packet_in.direction_x = 17.0;
    packet_in.direction_y = 45.0;
    packet_in.direction_z = 73.0;

    mavlink::ardupilotmega::msg::MAG_CAL_PROGRESS packet1{};
    mavlink::ardupilotmega::msg::MAG_CAL_PROGRESS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.compass_id, packet2.compass_id);
    EXPECT_EQ(packet1.cal_mask, packet2.cal_mask);
    EXPECT_EQ(packet1.cal_status, packet2.cal_status);
    EXPECT_EQ(packet1.attempt, packet2.attempt);
    EXPECT_EQ(packet1.completion_pct, packet2.completion_pct);
    EXPECT_EQ(packet1.completion_mask, packet2.completion_mask);
    EXPECT_EQ(packet1.direction_x, packet2.direction_x);
    EXPECT_EQ(packet1.direction_y, packet2.direction_y);
    EXPECT_EQ(packet1.direction_z, packet2.direction_z);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, MAG_CAL_PROGRESS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mag_cal_progress_t packet_c {
         17.0, 45.0, 73.0, 41, 108, 175, 242, 53, { 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 }
    };

    mavlink::ardupilotmega::msg::MAG_CAL_PROGRESS packet_in{};
    packet_in.compass_id = 41;
    packet_in.cal_mask = 108;
    packet_in.cal_status = 175;
    packet_in.attempt = 242;
    packet_in.completion_pct = 53;
    packet_in.completion_mask = {{ 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 }};
    packet_in.direction_x = 17.0;
    packet_in.direction_y = 45.0;
    packet_in.direction_z = 73.0;

    mavlink::ardupilotmega::msg::MAG_CAL_PROGRESS packet2{};

    mavlink_msg_mag_cal_progress_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.compass_id, packet2.compass_id);
    EXPECT_EQ(packet_in.cal_mask, packet2.cal_mask);
    EXPECT_EQ(packet_in.cal_status, packet2.cal_status);
    EXPECT_EQ(packet_in.attempt, packet2.attempt);
    EXPECT_EQ(packet_in.completion_pct, packet2.completion_pct);
    EXPECT_EQ(packet_in.completion_mask, packet2.completion_mask);
    EXPECT_EQ(packet_in.direction_x, packet2.direction_x);
    EXPECT_EQ(packet_in.direction_y, packet2.direction_y);
    EXPECT_EQ(packet_in.direction_z, packet2.direction_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, EKF_STATUS_REPORT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::EKF_STATUS_REPORT packet_in{};
    packet_in.flags = 18275;
    packet_in.velocity_variance = 17.0;
    packet_in.pos_horiz_variance = 45.0;
    packet_in.pos_vert_variance = 73.0;
    packet_in.compass_variance = 101.0;
    packet_in.terrain_alt_variance = 129.0;
    packet_in.airspeed_variance = 171.0;

    mavlink::ardupilotmega::msg::EKF_STATUS_REPORT packet1{};
    mavlink::ardupilotmega::msg::EKF_STATUS_REPORT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.flags, packet2.flags);
    EXPECT_EQ(packet1.velocity_variance, packet2.velocity_variance);
    EXPECT_EQ(packet1.pos_horiz_variance, packet2.pos_horiz_variance);
    EXPECT_EQ(packet1.pos_vert_variance, packet2.pos_vert_variance);
    EXPECT_EQ(packet1.compass_variance, packet2.compass_variance);
    EXPECT_EQ(packet1.terrain_alt_variance, packet2.terrain_alt_variance);
    EXPECT_EQ(packet1.airspeed_variance, packet2.airspeed_variance);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, EKF_STATUS_REPORT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ekf_status_report_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 18275, 171.0
    };

    mavlink::ardupilotmega::msg::EKF_STATUS_REPORT packet_in{};
    packet_in.flags = 18275;
    packet_in.velocity_variance = 17.0;
    packet_in.pos_horiz_variance = 45.0;
    packet_in.pos_vert_variance = 73.0;
    packet_in.compass_variance = 101.0;
    packet_in.terrain_alt_variance = 129.0;
    packet_in.airspeed_variance = 171.0;

    mavlink::ardupilotmega::msg::EKF_STATUS_REPORT packet2{};

    mavlink_msg_ekf_status_report_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.flags, packet2.flags);
    EXPECT_EQ(packet_in.velocity_variance, packet2.velocity_variance);
    EXPECT_EQ(packet_in.pos_horiz_variance, packet2.pos_horiz_variance);
    EXPECT_EQ(packet_in.pos_vert_variance, packet2.pos_vert_variance);
    EXPECT_EQ(packet_in.compass_variance, packet2.compass_variance);
    EXPECT_EQ(packet_in.terrain_alt_variance, packet2.terrain_alt_variance);
    EXPECT_EQ(packet_in.airspeed_variance, packet2.airspeed_variance);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, PID_TUNING)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::PID_TUNING packet_in{};
    packet_in.axis = 77;
    packet_in.desired = 17.0;
    packet_in.achieved = 45.0;
    packet_in.FF = 73.0;
    packet_in.P = 101.0;
    packet_in.I = 129.0;
    packet_in.D = 157.0;
    packet_in.SRate = 192.0;
    packet_in.PDmod = 220.0;

    mavlink::ardupilotmega::msg::PID_TUNING packet1{};
    mavlink::ardupilotmega::msg::PID_TUNING packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.axis, packet2.axis);
    EXPECT_EQ(packet1.desired, packet2.desired);
    EXPECT_EQ(packet1.achieved, packet2.achieved);
    EXPECT_EQ(packet1.FF, packet2.FF);
    EXPECT_EQ(packet1.P, packet2.P);
    EXPECT_EQ(packet1.I, packet2.I);
    EXPECT_EQ(packet1.D, packet2.D);
    EXPECT_EQ(packet1.SRate, packet2.SRate);
    EXPECT_EQ(packet1.PDmod, packet2.PDmod);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, PID_TUNING)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_pid_tuning_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 77, 192.0, 220.0
    };

    mavlink::ardupilotmega::msg::PID_TUNING packet_in{};
    packet_in.axis = 77;
    packet_in.desired = 17.0;
    packet_in.achieved = 45.0;
    packet_in.FF = 73.0;
    packet_in.P = 101.0;
    packet_in.I = 129.0;
    packet_in.D = 157.0;
    packet_in.SRate = 192.0;
    packet_in.PDmod = 220.0;

    mavlink::ardupilotmega::msg::PID_TUNING packet2{};

    mavlink_msg_pid_tuning_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.axis, packet2.axis);
    EXPECT_EQ(packet_in.desired, packet2.desired);
    EXPECT_EQ(packet_in.achieved, packet2.achieved);
    EXPECT_EQ(packet_in.FF, packet2.FF);
    EXPECT_EQ(packet_in.P, packet2.P);
    EXPECT_EQ(packet_in.I, packet2.I);
    EXPECT_EQ(packet_in.D, packet2.D);
    EXPECT_EQ(packet_in.SRate, packet2.SRate);
    EXPECT_EQ(packet_in.PDmod, packet2.PDmod);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DEEPSTALL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DEEPSTALL packet_in{};
    packet_in.landing_lat = 963497464;
    packet_in.landing_lon = 963497672;
    packet_in.path_lat = 963497880;
    packet_in.path_lon = 963498088;
    packet_in.arc_entry_lat = 963498296;
    packet_in.arc_entry_lon = 963498504;
    packet_in.altitude = 185.0;
    packet_in.expected_travel_distance = 213.0;
    packet_in.cross_track_error = 241.0;
    packet_in.stage = 113;

    mavlink::ardupilotmega::msg::DEEPSTALL packet1{};
    mavlink::ardupilotmega::msg::DEEPSTALL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.landing_lat, packet2.landing_lat);
    EXPECT_EQ(packet1.landing_lon, packet2.landing_lon);
    EXPECT_EQ(packet1.path_lat, packet2.path_lat);
    EXPECT_EQ(packet1.path_lon, packet2.path_lon);
    EXPECT_EQ(packet1.arc_entry_lat, packet2.arc_entry_lat);
    EXPECT_EQ(packet1.arc_entry_lon, packet2.arc_entry_lon);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.expected_travel_distance, packet2.expected_travel_distance);
    EXPECT_EQ(packet1.cross_track_error, packet2.cross_track_error);
    EXPECT_EQ(packet1.stage, packet2.stage);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DEEPSTALL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_deepstall_t packet_c {
         963497464, 963497672, 963497880, 963498088, 963498296, 963498504, 185.0, 213.0, 241.0, 113
    };

    mavlink::ardupilotmega::msg::DEEPSTALL packet_in{};
    packet_in.landing_lat = 963497464;
    packet_in.landing_lon = 963497672;
    packet_in.path_lat = 963497880;
    packet_in.path_lon = 963498088;
    packet_in.arc_entry_lat = 963498296;
    packet_in.arc_entry_lon = 963498504;
    packet_in.altitude = 185.0;
    packet_in.expected_travel_distance = 213.0;
    packet_in.cross_track_error = 241.0;
    packet_in.stage = 113;

    mavlink::ardupilotmega::msg::DEEPSTALL packet2{};

    mavlink_msg_deepstall_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.landing_lat, packet2.landing_lat);
    EXPECT_EQ(packet_in.landing_lon, packet2.landing_lon);
    EXPECT_EQ(packet_in.path_lat, packet2.path_lat);
    EXPECT_EQ(packet_in.path_lon, packet2.path_lon);
    EXPECT_EQ(packet_in.arc_entry_lat, packet2.arc_entry_lat);
    EXPECT_EQ(packet_in.arc_entry_lon, packet2.arc_entry_lon);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.expected_travel_distance, packet2.expected_travel_distance);
    EXPECT_EQ(packet_in.cross_track_error, packet2.cross_track_error);
    EXPECT_EQ(packet_in.stage, packet2.stage);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GIMBAL_REPORT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GIMBAL_REPORT packet_in{};
    packet_in.target_system = 125;
    packet_in.target_component = 192;
    packet_in.delta_time = 17.0;
    packet_in.delta_angle_x = 45.0;
    packet_in.delta_angle_y = 73.0;
    packet_in.delta_angle_z = 101.0;
    packet_in.delta_velocity_x = 129.0;
    packet_in.delta_velocity_y = 157.0;
    packet_in.delta_velocity_z = 185.0;
    packet_in.joint_roll = 213.0;
    packet_in.joint_el = 241.0;
    packet_in.joint_az = 269.0;

    mavlink::ardupilotmega::msg::GIMBAL_REPORT packet1{};
    mavlink::ardupilotmega::msg::GIMBAL_REPORT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.delta_time, packet2.delta_time);
    EXPECT_EQ(packet1.delta_angle_x, packet2.delta_angle_x);
    EXPECT_EQ(packet1.delta_angle_y, packet2.delta_angle_y);
    EXPECT_EQ(packet1.delta_angle_z, packet2.delta_angle_z);
    EXPECT_EQ(packet1.delta_velocity_x, packet2.delta_velocity_x);
    EXPECT_EQ(packet1.delta_velocity_y, packet2.delta_velocity_y);
    EXPECT_EQ(packet1.delta_velocity_z, packet2.delta_velocity_z);
    EXPECT_EQ(packet1.joint_roll, packet2.joint_roll);
    EXPECT_EQ(packet1.joint_el, packet2.joint_el);
    EXPECT_EQ(packet1.joint_az, packet2.joint_az);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GIMBAL_REPORT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gimbal_report_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 125, 192
    };

    mavlink::ardupilotmega::msg::GIMBAL_REPORT packet_in{};
    packet_in.target_system = 125;
    packet_in.target_component = 192;
    packet_in.delta_time = 17.0;
    packet_in.delta_angle_x = 45.0;
    packet_in.delta_angle_y = 73.0;
    packet_in.delta_angle_z = 101.0;
    packet_in.delta_velocity_x = 129.0;
    packet_in.delta_velocity_y = 157.0;
    packet_in.delta_velocity_z = 185.0;
    packet_in.joint_roll = 213.0;
    packet_in.joint_el = 241.0;
    packet_in.joint_az = 269.0;

    mavlink::ardupilotmega::msg::GIMBAL_REPORT packet2{};

    mavlink_msg_gimbal_report_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.delta_time, packet2.delta_time);
    EXPECT_EQ(packet_in.delta_angle_x, packet2.delta_angle_x);
    EXPECT_EQ(packet_in.delta_angle_y, packet2.delta_angle_y);
    EXPECT_EQ(packet_in.delta_angle_z, packet2.delta_angle_z);
    EXPECT_EQ(packet_in.delta_velocity_x, packet2.delta_velocity_x);
    EXPECT_EQ(packet_in.delta_velocity_y, packet2.delta_velocity_y);
    EXPECT_EQ(packet_in.delta_velocity_z, packet2.delta_velocity_z);
    EXPECT_EQ(packet_in.joint_roll, packet2.joint_roll);
    EXPECT_EQ(packet_in.joint_el, packet2.joint_el);
    EXPECT_EQ(packet_in.joint_az, packet2.joint_az);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GIMBAL_CONTROL)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GIMBAL_CONTROL packet_in{};
    packet_in.target_system = 41;
    packet_in.target_component = 108;
    packet_in.demanded_rate_x = 17.0;
    packet_in.demanded_rate_y = 45.0;
    packet_in.demanded_rate_z = 73.0;

    mavlink::ardupilotmega::msg::GIMBAL_CONTROL packet1{};
    mavlink::ardupilotmega::msg::GIMBAL_CONTROL packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.demanded_rate_x, packet2.demanded_rate_x);
    EXPECT_EQ(packet1.demanded_rate_y, packet2.demanded_rate_y);
    EXPECT_EQ(packet1.demanded_rate_z, packet2.demanded_rate_z);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GIMBAL_CONTROL)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gimbal_control_t packet_c {
         17.0, 45.0, 73.0, 41, 108
    };

    mavlink::ardupilotmega::msg::GIMBAL_CONTROL packet_in{};
    packet_in.target_system = 41;
    packet_in.target_component = 108;
    packet_in.demanded_rate_x = 17.0;
    packet_in.demanded_rate_y = 45.0;
    packet_in.demanded_rate_z = 73.0;

    mavlink::ardupilotmega::msg::GIMBAL_CONTROL packet2{};

    mavlink_msg_gimbal_control_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.demanded_rate_x, packet2.demanded_rate_x);
    EXPECT_EQ(packet_in.demanded_rate_y, packet2.demanded_rate_y);
    EXPECT_EQ(packet_in.demanded_rate_z, packet2.demanded_rate_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GIMBAL_TORQUE_CMD_REPORT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GIMBAL_TORQUE_CMD_REPORT packet_in{};
    packet_in.target_system = 151;
    packet_in.target_component = 218;
    packet_in.rl_torque_cmd = 17235;
    packet_in.el_torque_cmd = 17339;
    packet_in.az_torque_cmd = 17443;

    mavlink::ardupilotmega::msg::GIMBAL_TORQUE_CMD_REPORT packet1{};
    mavlink::ardupilotmega::msg::GIMBAL_TORQUE_CMD_REPORT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.rl_torque_cmd, packet2.rl_torque_cmd);
    EXPECT_EQ(packet1.el_torque_cmd, packet2.el_torque_cmd);
    EXPECT_EQ(packet1.az_torque_cmd, packet2.az_torque_cmd);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GIMBAL_TORQUE_CMD_REPORT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gimbal_torque_cmd_report_t packet_c {
         17235, 17339, 17443, 151, 218
    };

    mavlink::ardupilotmega::msg::GIMBAL_TORQUE_CMD_REPORT packet_in{};
    packet_in.target_system = 151;
    packet_in.target_component = 218;
    packet_in.rl_torque_cmd = 17235;
    packet_in.el_torque_cmd = 17339;
    packet_in.az_torque_cmd = 17443;

    mavlink::ardupilotmega::msg::GIMBAL_TORQUE_CMD_REPORT packet2{};

    mavlink_msg_gimbal_torque_cmd_report_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.rl_torque_cmd, packet2.rl_torque_cmd);
    EXPECT_EQ(packet_in.el_torque_cmd, packet2.el_torque_cmd);
    EXPECT_EQ(packet_in.az_torque_cmd, packet2.az_torque_cmd);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GOPRO_HEARTBEAT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GOPRO_HEARTBEAT packet_in{};
    packet_in.status = 5;
    packet_in.capture_mode = 72;
    packet_in.flags = 139;

    mavlink::ardupilotmega::msg::GOPRO_HEARTBEAT packet1{};
    mavlink::ardupilotmega::msg::GOPRO_HEARTBEAT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.status, packet2.status);
    EXPECT_EQ(packet1.capture_mode, packet2.capture_mode);
    EXPECT_EQ(packet1.flags, packet2.flags);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GOPRO_HEARTBEAT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gopro_heartbeat_t packet_c {
         5, 72, 139
    };

    mavlink::ardupilotmega::msg::GOPRO_HEARTBEAT packet_in{};
    packet_in.status = 5;
    packet_in.capture_mode = 72;
    packet_in.flags = 139;

    mavlink::ardupilotmega::msg::GOPRO_HEARTBEAT packet2{};

    mavlink_msg_gopro_heartbeat_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.status, packet2.status);
    EXPECT_EQ(packet_in.capture_mode, packet2.capture_mode);
    EXPECT_EQ(packet_in.flags, packet2.flags);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GOPRO_GET_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GOPRO_GET_REQUEST packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.cmd_id = 139;

    mavlink::ardupilotmega::msg::GOPRO_GET_REQUEST packet1{};
    mavlink::ardupilotmega::msg::GOPRO_GET_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.cmd_id, packet2.cmd_id);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GOPRO_GET_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gopro_get_request_t packet_c {
         5, 72, 139
    };

    mavlink::ardupilotmega::msg::GOPRO_GET_REQUEST packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.cmd_id = 139;

    mavlink::ardupilotmega::msg::GOPRO_GET_REQUEST packet2{};

    mavlink_msg_gopro_get_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.cmd_id, packet2.cmd_id);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GOPRO_GET_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GOPRO_GET_RESPONSE packet_in{};
    packet_in.cmd_id = 5;
    packet_in.status = 72;
    packet_in.value = {{ 139, 140, 141, 142 }};

    mavlink::ardupilotmega::msg::GOPRO_GET_RESPONSE packet1{};
    mavlink::ardupilotmega::msg::GOPRO_GET_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.cmd_id, packet2.cmd_id);
    EXPECT_EQ(packet1.status, packet2.status);
    EXPECT_EQ(packet1.value, packet2.value);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GOPRO_GET_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gopro_get_response_t packet_c {
         5, 72, { 139, 140, 141, 142 }
    };

    mavlink::ardupilotmega::msg::GOPRO_GET_RESPONSE packet_in{};
    packet_in.cmd_id = 5;
    packet_in.status = 72;
    packet_in.value = {{ 139, 140, 141, 142 }};

    mavlink::ardupilotmega::msg::GOPRO_GET_RESPONSE packet2{};

    mavlink_msg_gopro_get_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.cmd_id, packet2.cmd_id);
    EXPECT_EQ(packet_in.status, packet2.status);
    EXPECT_EQ(packet_in.value, packet2.value);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GOPRO_SET_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GOPRO_SET_REQUEST packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.cmd_id = 139;
    packet_in.value = {{ 206, 207, 208, 209 }};

    mavlink::ardupilotmega::msg::GOPRO_SET_REQUEST packet1{};
    mavlink::ardupilotmega::msg::GOPRO_SET_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.cmd_id, packet2.cmd_id);
    EXPECT_EQ(packet1.value, packet2.value);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GOPRO_SET_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gopro_set_request_t packet_c {
         5, 72, 139, { 206, 207, 208, 209 }
    };

    mavlink::ardupilotmega::msg::GOPRO_SET_REQUEST packet_in{};
    packet_in.target_system = 5;
    packet_in.target_component = 72;
    packet_in.cmd_id = 139;
    packet_in.value = {{ 206, 207, 208, 209 }};

    mavlink::ardupilotmega::msg::GOPRO_SET_REQUEST packet2{};

    mavlink_msg_gopro_set_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.cmd_id, packet2.cmd_id);
    EXPECT_EQ(packet_in.value, packet2.value);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, GOPRO_SET_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::GOPRO_SET_RESPONSE packet_in{};
    packet_in.cmd_id = 5;
    packet_in.status = 72;

    mavlink::ardupilotmega::msg::GOPRO_SET_RESPONSE packet1{};
    mavlink::ardupilotmega::msg::GOPRO_SET_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.cmd_id, packet2.cmd_id);
    EXPECT_EQ(packet1.status, packet2.status);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, GOPRO_SET_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gopro_set_response_t packet_c {
         5, 72
    };

    mavlink::ardupilotmega::msg::GOPRO_SET_RESPONSE packet_in{};
    packet_in.cmd_id = 5;
    packet_in.status = 72;

    mavlink::ardupilotmega::msg::GOPRO_SET_RESPONSE packet2{};

    mavlink_msg_gopro_set_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.cmd_id, packet2.cmd_id);
    EXPECT_EQ(packet_in.status, packet2.status);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, RPM)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::RPM packet_in{};
    packet_in.rpm1 = 17.0;
    packet_in.rpm2 = 45.0;

    mavlink::ardupilotmega::msg::RPM packet1{};
    mavlink::ardupilotmega::msg::RPM packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.rpm1, packet2.rpm1);
    EXPECT_EQ(packet1.rpm2, packet2.rpm2);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, RPM)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_rpm_t packet_c {
         17.0, 45.0
    };

    mavlink::ardupilotmega::msg::RPM packet_in{};
    packet_in.rpm1 = 17.0;
    packet_in.rpm2 = 45.0;

    mavlink::ardupilotmega::msg::RPM packet2{};

    mavlink_msg_rpm_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.rpm1, packet2.rpm1);
    EXPECT_EQ(packet_in.rpm2, packet2.rpm2);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DEVICE_OP_READ)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DEVICE_OP_READ packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.request_id = 963497464;
    packet_in.bustype = 151;
    packet_in.bus = 218;
    packet_in.address = 29;
    packet_in.busname = to_char_array("JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV");
    packet_in.regstart = 216;
    packet_in.count = 27;
    packet_in.bank = 94;

    mavlink::ardupilotmega::msg::DEVICE_OP_READ packet1{};
    mavlink::ardupilotmega::msg::DEVICE_OP_READ packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.bustype, packet2.bustype);
    EXPECT_EQ(packet1.bus, packet2.bus);
    EXPECT_EQ(packet1.address, packet2.address);
    EXPECT_EQ(packet1.busname, packet2.busname);
    EXPECT_EQ(packet1.regstart, packet2.regstart);
    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.bank, packet2.bank);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DEVICE_OP_READ)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_device_op_read_t packet_c {
         963497464, 17, 84, 151, 218, 29, "JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV", 216, 27, 94
    };

    mavlink::ardupilotmega::msg::DEVICE_OP_READ packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.request_id = 963497464;
    packet_in.bustype = 151;
    packet_in.bus = 218;
    packet_in.address = 29;
    packet_in.busname = to_char_array("JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV");
    packet_in.regstart = 216;
    packet_in.count = 27;
    packet_in.bank = 94;

    mavlink::ardupilotmega::msg::DEVICE_OP_READ packet2{};

    mavlink_msg_device_op_read_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.bustype, packet2.bustype);
    EXPECT_EQ(packet_in.bus, packet2.bus);
    EXPECT_EQ(packet_in.address, packet2.address);
    EXPECT_EQ(packet_in.busname, packet2.busname);
    EXPECT_EQ(packet_in.regstart, packet2.regstart);
    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.bank, packet2.bank);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DEVICE_OP_READ_REPLY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DEVICE_OP_READ_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 17;
    packet_in.regstart = 84;
    packet_in.count = 151;
    packet_in.data = {{ 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 }};
    packet_in.bank = 90;

    mavlink::ardupilotmega::msg::DEVICE_OP_READ_REPLY packet1{};
    mavlink::ardupilotmega::msg::DEVICE_OP_READ_REPLY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.result, packet2.result);
    EXPECT_EQ(packet1.regstart, packet2.regstart);
    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.data, packet2.data);
    EXPECT_EQ(packet1.bank, packet2.bank);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DEVICE_OP_READ_REPLY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_device_op_read_reply_t packet_c {
         963497464, 17, 84, 151, { 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 }, 90
    };

    mavlink::ardupilotmega::msg::DEVICE_OP_READ_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 17;
    packet_in.regstart = 84;
    packet_in.count = 151;
    packet_in.data = {{ 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 }};
    packet_in.bank = 90;

    mavlink::ardupilotmega::msg::DEVICE_OP_READ_REPLY packet2{};

    mavlink_msg_device_op_read_reply_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.result, packet2.result);
    EXPECT_EQ(packet_in.regstart, packet2.regstart);
    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.data, packet2.data);
    EXPECT_EQ(packet_in.bank, packet2.bank);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DEVICE_OP_WRITE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.request_id = 963497464;
    packet_in.bustype = 151;
    packet_in.bus = 218;
    packet_in.address = 29;
    packet_in.busname = to_char_array("JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV");
    packet_in.regstart = 216;
    packet_in.count = 27;
    packet_in.data = {{ 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221 }};
    packet_in.bank = 222;

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE packet1{};
    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.bustype, packet2.bustype);
    EXPECT_EQ(packet1.bus, packet2.bus);
    EXPECT_EQ(packet1.address, packet2.address);
    EXPECT_EQ(packet1.busname, packet2.busname);
    EXPECT_EQ(packet1.regstart, packet2.regstart);
    EXPECT_EQ(packet1.count, packet2.count);
    EXPECT_EQ(packet1.data, packet2.data);
    EXPECT_EQ(packet1.bank, packet2.bank);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DEVICE_OP_WRITE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_device_op_write_t packet_c {
         963497464, 17, 84, 151, 218, 29, "JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV", 216, 27, { 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221 }, 222
    };

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.request_id = 963497464;
    packet_in.bustype = 151;
    packet_in.bus = 218;
    packet_in.address = 29;
    packet_in.busname = to_char_array("JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV");
    packet_in.regstart = 216;
    packet_in.count = 27;
    packet_in.data = {{ 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221 }};
    packet_in.bank = 222;

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE packet2{};

    mavlink_msg_device_op_write_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.bustype, packet2.bustype);
    EXPECT_EQ(packet_in.bus, packet2.bus);
    EXPECT_EQ(packet_in.address, packet2.address);
    EXPECT_EQ(packet_in.busname, packet2.busname);
    EXPECT_EQ(packet_in.regstart, packet2.regstart);
    EXPECT_EQ(packet_in.count, packet2.count);
    EXPECT_EQ(packet_in.data, packet2.data);
    EXPECT_EQ(packet_in.bank, packet2.bank);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, DEVICE_OP_WRITE_REPLY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 17;

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE_REPLY packet1{};
    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE_REPLY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.result, packet2.result);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, DEVICE_OP_WRITE_REPLY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_device_op_write_reply_t packet_c {
         963497464, 17
    };

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 17;

    mavlink::ardupilotmega::msg::DEVICE_OP_WRITE_REPLY packet2{};

    mavlink_msg_device_op_write_reply_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.result, packet2.result);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, ADAP_TUNING)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::ADAP_TUNING packet_in{};
    packet_in.axis = 149;
    packet_in.desired = 17.0;
    packet_in.achieved = 45.0;
    packet_in.error = 73.0;
    packet_in.theta = 101.0;
    packet_in.omega = 129.0;
    packet_in.sigma = 157.0;
    packet_in.theta_dot = 185.0;
    packet_in.omega_dot = 213.0;
    packet_in.sigma_dot = 241.0;
    packet_in.f = 269.0;
    packet_in.f_dot = 297.0;
    packet_in.u = 325.0;

    mavlink::ardupilotmega::msg::ADAP_TUNING packet1{};
    mavlink::ardupilotmega::msg::ADAP_TUNING packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.axis, packet2.axis);
    EXPECT_EQ(packet1.desired, packet2.desired);
    EXPECT_EQ(packet1.achieved, packet2.achieved);
    EXPECT_EQ(packet1.error, packet2.error);
    EXPECT_EQ(packet1.theta, packet2.theta);
    EXPECT_EQ(packet1.omega, packet2.omega);
    EXPECT_EQ(packet1.sigma, packet2.sigma);
    EXPECT_EQ(packet1.theta_dot, packet2.theta_dot);
    EXPECT_EQ(packet1.omega_dot, packet2.omega_dot);
    EXPECT_EQ(packet1.sigma_dot, packet2.sigma_dot);
    EXPECT_EQ(packet1.f, packet2.f);
    EXPECT_EQ(packet1.f_dot, packet2.f_dot);
    EXPECT_EQ(packet1.u, packet2.u);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, ADAP_TUNING)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_adap_tuning_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0, 297.0, 325.0, 149
    };

    mavlink::ardupilotmega::msg::ADAP_TUNING packet_in{};
    packet_in.axis = 149;
    packet_in.desired = 17.0;
    packet_in.achieved = 45.0;
    packet_in.error = 73.0;
    packet_in.theta = 101.0;
    packet_in.omega = 129.0;
    packet_in.sigma = 157.0;
    packet_in.theta_dot = 185.0;
    packet_in.omega_dot = 213.0;
    packet_in.sigma_dot = 241.0;
    packet_in.f = 269.0;
    packet_in.f_dot = 297.0;
    packet_in.u = 325.0;

    mavlink::ardupilotmega::msg::ADAP_TUNING packet2{};

    mavlink_msg_adap_tuning_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.axis, packet2.axis);
    EXPECT_EQ(packet_in.desired, packet2.desired);
    EXPECT_EQ(packet_in.achieved, packet2.achieved);
    EXPECT_EQ(packet_in.error, packet2.error);
    EXPECT_EQ(packet_in.theta, packet2.theta);
    EXPECT_EQ(packet_in.omega, packet2.omega);
    EXPECT_EQ(packet_in.sigma, packet2.sigma);
    EXPECT_EQ(packet_in.theta_dot, packet2.theta_dot);
    EXPECT_EQ(packet_in.omega_dot, packet2.omega_dot);
    EXPECT_EQ(packet_in.sigma_dot, packet2.sigma_dot);
    EXPECT_EQ(packet_in.f, packet2.f);
    EXPECT_EQ(packet_in.f_dot, packet2.f_dot);
    EXPECT_EQ(packet_in.u, packet2.u);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, VISION_POSITION_DELTA)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::VISION_POSITION_DELTA packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.time_delta_usec = 93372036854776311ULL;
    packet_in.angle_delta = {{ 129.0, 130.0, 131.0 }};
    packet_in.position_delta = {{ 213.0, 214.0, 215.0 }};
    packet_in.confidence = 297.0;

    mavlink::ardupilotmega::msg::VISION_POSITION_DELTA packet1{};
    mavlink::ardupilotmega::msg::VISION_POSITION_DELTA packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.time_delta_usec, packet2.time_delta_usec);
    EXPECT_EQ(packet1.angle_delta, packet2.angle_delta);
    EXPECT_EQ(packet1.position_delta, packet2.position_delta);
    EXPECT_EQ(packet1.confidence, packet2.confidence);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, VISION_POSITION_DELTA)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_vision_position_delta_t packet_c {
         93372036854775807ULL, 93372036854776311ULL, { 129.0, 130.0, 131.0 }, { 213.0, 214.0, 215.0 }, 297.0
    };

    mavlink::ardupilotmega::msg::VISION_POSITION_DELTA packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.time_delta_usec = 93372036854776311ULL;
    packet_in.angle_delta = {{ 129.0, 130.0, 131.0 }};
    packet_in.position_delta = {{ 213.0, 214.0, 215.0 }};
    packet_in.confidence = 297.0;

    mavlink::ardupilotmega::msg::VISION_POSITION_DELTA packet2{};

    mavlink_msg_vision_position_delta_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.time_delta_usec, packet2.time_delta_usec);
    EXPECT_EQ(packet_in.angle_delta, packet2.angle_delta);
    EXPECT_EQ(packet_in.position_delta, packet2.position_delta);
    EXPECT_EQ(packet_in.confidence, packet2.confidence);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, AOA_SSA)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::AOA_SSA packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.AOA = 73.0;
    packet_in.SSA = 101.0;

    mavlink::ardupilotmega::msg::AOA_SSA packet1{};
    mavlink::ardupilotmega::msg::AOA_SSA packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_usec, packet2.time_usec);
    EXPECT_EQ(packet1.AOA, packet2.AOA);
    EXPECT_EQ(packet1.SSA, packet2.SSA);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, AOA_SSA)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_aoa_ssa_t packet_c {
         93372036854775807ULL, 73.0, 101.0
    };

    mavlink::ardupilotmega::msg::AOA_SSA packet_in{};
    packet_in.time_usec = 93372036854775807ULL;
    packet_in.AOA = 73.0;
    packet_in.SSA = 101.0;

    mavlink::ardupilotmega::msg::AOA_SSA packet2{};

    mavlink_msg_aoa_ssa_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_usec, packet2.time_usec);
    EXPECT_EQ(packet_in.AOA, packet2.AOA);
    EXPECT_EQ(packet_in.SSA, packet2.SSA);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, ESC_TELEMETRY_1_TO_4)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_1_TO_4 packet_in{};
    packet_in.temperature = {{ 125, 126, 127, 128 }};
    packet_in.voltage = {{ 17235, 17236, 17237, 17238 }};
    packet_in.current = {{ 17651, 17652, 17653, 17654 }};
    packet_in.totalcurrent = {{ 18067, 18068, 18069, 18070 }};
    packet_in.rpm = {{ 18483, 18484, 18485, 18486 }};
    packet_in.count = {{ 18899, 18900, 18901, 18902 }};

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_1_TO_4 packet1{};
    mavlink::ardupilotmega::msg::ESC_TELEMETRY_1_TO_4 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.temperature, packet2.temperature);
    EXPECT_EQ(packet1.voltage, packet2.voltage);
    EXPECT_EQ(packet1.current, packet2.current);
    EXPECT_EQ(packet1.totalcurrent, packet2.totalcurrent);
    EXPECT_EQ(packet1.rpm, packet2.rpm);
    EXPECT_EQ(packet1.count, packet2.count);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, ESC_TELEMETRY_1_TO_4)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_esc_telemetry_1_to_4_t packet_c {
         { 17235, 17236, 17237, 17238 }, { 17651, 17652, 17653, 17654 }, { 18067, 18068, 18069, 18070 }, { 18483, 18484, 18485, 18486 }, { 18899, 18900, 18901, 18902 }, { 125, 126, 127, 128 }
    };

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_1_TO_4 packet_in{};
    packet_in.temperature = {{ 125, 126, 127, 128 }};
    packet_in.voltage = {{ 17235, 17236, 17237, 17238 }};
    packet_in.current = {{ 17651, 17652, 17653, 17654 }};
    packet_in.totalcurrent = {{ 18067, 18068, 18069, 18070 }};
    packet_in.rpm = {{ 18483, 18484, 18485, 18486 }};
    packet_in.count = {{ 18899, 18900, 18901, 18902 }};

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_1_TO_4 packet2{};

    mavlink_msg_esc_telemetry_1_to_4_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.temperature, packet2.temperature);
    EXPECT_EQ(packet_in.voltage, packet2.voltage);
    EXPECT_EQ(packet_in.current, packet2.current);
    EXPECT_EQ(packet_in.totalcurrent, packet2.totalcurrent);
    EXPECT_EQ(packet_in.rpm, packet2.rpm);
    EXPECT_EQ(packet_in.count, packet2.count);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, ESC_TELEMETRY_5_TO_8)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_5_TO_8 packet_in{};
    packet_in.temperature = {{ 125, 126, 127, 128 }};
    packet_in.voltage = {{ 17235, 17236, 17237, 17238 }};
    packet_in.current = {{ 17651, 17652, 17653, 17654 }};
    packet_in.totalcurrent = {{ 18067, 18068, 18069, 18070 }};
    packet_in.rpm = {{ 18483, 18484, 18485, 18486 }};
    packet_in.count = {{ 18899, 18900, 18901, 18902 }};

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_5_TO_8 packet1{};
    mavlink::ardupilotmega::msg::ESC_TELEMETRY_5_TO_8 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.temperature, packet2.temperature);
    EXPECT_EQ(packet1.voltage, packet2.voltage);
    EXPECT_EQ(packet1.current, packet2.current);
    EXPECT_EQ(packet1.totalcurrent, packet2.totalcurrent);
    EXPECT_EQ(packet1.rpm, packet2.rpm);
    EXPECT_EQ(packet1.count, packet2.count);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, ESC_TELEMETRY_5_TO_8)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_esc_telemetry_5_to_8_t packet_c {
         { 17235, 17236, 17237, 17238 }, { 17651, 17652, 17653, 17654 }, { 18067, 18068, 18069, 18070 }, { 18483, 18484, 18485, 18486 }, { 18899, 18900, 18901, 18902 }, { 125, 126, 127, 128 }
    };

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_5_TO_8 packet_in{};
    packet_in.temperature = {{ 125, 126, 127, 128 }};
    packet_in.voltage = {{ 17235, 17236, 17237, 17238 }};
    packet_in.current = {{ 17651, 17652, 17653, 17654 }};
    packet_in.totalcurrent = {{ 18067, 18068, 18069, 18070 }};
    packet_in.rpm = {{ 18483, 18484, 18485, 18486 }};
    packet_in.count = {{ 18899, 18900, 18901, 18902 }};

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_5_TO_8 packet2{};

    mavlink_msg_esc_telemetry_5_to_8_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.temperature, packet2.temperature);
    EXPECT_EQ(packet_in.voltage, packet2.voltage);
    EXPECT_EQ(packet_in.current, packet2.current);
    EXPECT_EQ(packet_in.totalcurrent, packet2.totalcurrent);
    EXPECT_EQ(packet_in.rpm, packet2.rpm);
    EXPECT_EQ(packet_in.count, packet2.count);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, ESC_TELEMETRY_9_TO_12)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_9_TO_12 packet_in{};
    packet_in.temperature = {{ 125, 126, 127, 128 }};
    packet_in.voltage = {{ 17235, 17236, 17237, 17238 }};
    packet_in.current = {{ 17651, 17652, 17653, 17654 }};
    packet_in.totalcurrent = {{ 18067, 18068, 18069, 18070 }};
    packet_in.rpm = {{ 18483, 18484, 18485, 18486 }};
    packet_in.count = {{ 18899, 18900, 18901, 18902 }};

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_9_TO_12 packet1{};
    mavlink::ardupilotmega::msg::ESC_TELEMETRY_9_TO_12 packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.temperature, packet2.temperature);
    EXPECT_EQ(packet1.voltage, packet2.voltage);
    EXPECT_EQ(packet1.current, packet2.current);
    EXPECT_EQ(packet1.totalcurrent, packet2.totalcurrent);
    EXPECT_EQ(packet1.rpm, packet2.rpm);
    EXPECT_EQ(packet1.count, packet2.count);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, ESC_TELEMETRY_9_TO_12)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_esc_telemetry_9_to_12_t packet_c {
         { 17235, 17236, 17237, 17238 }, { 17651, 17652, 17653, 17654 }, { 18067, 18068, 18069, 18070 }, { 18483, 18484, 18485, 18486 }, { 18899, 18900, 18901, 18902 }, { 125, 126, 127, 128 }
    };

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_9_TO_12 packet_in{};
    packet_in.temperature = {{ 125, 126, 127, 128 }};
    packet_in.voltage = {{ 17235, 17236, 17237, 17238 }};
    packet_in.current = {{ 17651, 17652, 17653, 17654 }};
    packet_in.totalcurrent = {{ 18067, 18068, 18069, 18070 }};
    packet_in.rpm = {{ 18483, 18484, 18485, 18486 }};
    packet_in.count = {{ 18899, 18900, 18901, 18902 }};

    mavlink::ardupilotmega::msg::ESC_TELEMETRY_9_TO_12 packet2{};

    mavlink_msg_esc_telemetry_9_to_12_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.temperature, packet2.temperature);
    EXPECT_EQ(packet_in.voltage, packet2.voltage);
    EXPECT_EQ(packet_in.current, packet2.current);
    EXPECT_EQ(packet_in.totalcurrent, packet2.totalcurrent);
    EXPECT_EQ(packet_in.rpm, packet2.rpm);
    EXPECT_EQ(packet_in.count, packet2.count);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OSD_PARAM_CONFIG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG packet_in{};
    packet_in.target_system = 53;
    packet_in.target_component = 120;
    packet_in.request_id = 963497464;
    packet_in.osd_screen = 187;
    packet_in.osd_index = 254;
    packet_in.param_id = to_char_array("UVWXYZABCDEFGHI");
    packet_in.config_type = 113;
    packet_in.min_value = 45.0;
    packet_in.max_value = 73.0;
    packet_in.increment = 101.0;

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG packet1{};
    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.osd_screen, packet2.osd_screen);
    EXPECT_EQ(packet1.osd_index, packet2.osd_index);
    EXPECT_EQ(packet1.param_id, packet2.param_id);
    EXPECT_EQ(packet1.config_type, packet2.config_type);
    EXPECT_EQ(packet1.min_value, packet2.min_value);
    EXPECT_EQ(packet1.max_value, packet2.max_value);
    EXPECT_EQ(packet1.increment, packet2.increment);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OSD_PARAM_CONFIG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_osd_param_config_t packet_c {
         963497464, 45.0, 73.0, 101.0, 53, 120, 187, 254, "UVWXYZABCDEFGHI", 113
    };

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG packet_in{};
    packet_in.target_system = 53;
    packet_in.target_component = 120;
    packet_in.request_id = 963497464;
    packet_in.osd_screen = 187;
    packet_in.osd_index = 254;
    packet_in.param_id = to_char_array("UVWXYZABCDEFGHI");
    packet_in.config_type = 113;
    packet_in.min_value = 45.0;
    packet_in.max_value = 73.0;
    packet_in.increment = 101.0;

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG packet2{};

    mavlink_msg_osd_param_config_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.osd_screen, packet2.osd_screen);
    EXPECT_EQ(packet_in.osd_index, packet2.osd_index);
    EXPECT_EQ(packet_in.param_id, packet2.param_id);
    EXPECT_EQ(packet_in.config_type, packet2.config_type);
    EXPECT_EQ(packet_in.min_value, packet2.min_value);
    EXPECT_EQ(packet_in.max_value, packet2.max_value);
    EXPECT_EQ(packet_in.increment, packet2.increment);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OSD_PARAM_CONFIG_REPLY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 17;

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG_REPLY packet1{};
    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG_REPLY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.result, packet2.result);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OSD_PARAM_CONFIG_REPLY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_osd_param_config_reply_t packet_c {
         963497464, 17
    };

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 17;

    mavlink::ardupilotmega::msg::OSD_PARAM_CONFIG_REPLY packet2{};

    mavlink_msg_osd_param_config_reply_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.result, packet2.result);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OSD_PARAM_SHOW_CONFIG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.request_id = 963497464;
    packet_in.osd_screen = 151;
    packet_in.osd_index = 218;

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG packet1{};
    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.osd_screen, packet2.osd_screen);
    EXPECT_EQ(packet1.osd_index, packet2.osd_index);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OSD_PARAM_SHOW_CONFIG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_osd_param_show_config_t packet_c {
         963497464, 17, 84, 151, 218
    };

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG packet_in{};
    packet_in.target_system = 17;
    packet_in.target_component = 84;
    packet_in.request_id = 963497464;
    packet_in.osd_screen = 151;
    packet_in.osd_index = 218;

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG packet2{};

    mavlink_msg_osd_param_show_config_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.osd_screen, packet2.osd_screen);
    EXPECT_EQ(packet_in.osd_index, packet2.osd_index);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OSD_PARAM_SHOW_CONFIG_REPLY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 53;
    packet_in.param_id = to_char_array("RSTUVWXYZABCDEF");
    packet_in.config_type = 168;
    packet_in.min_value = 45.0;
    packet_in.max_value = 73.0;
    packet_in.increment = 101.0;

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG_REPLY packet1{};
    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG_REPLY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.request_id, packet2.request_id);
    EXPECT_EQ(packet1.result, packet2.result);
    EXPECT_EQ(packet1.param_id, packet2.param_id);
    EXPECT_EQ(packet1.config_type, packet2.config_type);
    EXPECT_EQ(packet1.min_value, packet2.min_value);
    EXPECT_EQ(packet1.max_value, packet2.max_value);
    EXPECT_EQ(packet1.increment, packet2.increment);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OSD_PARAM_SHOW_CONFIG_REPLY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_osd_param_show_config_reply_t packet_c {
         963497464, 45.0, 73.0, 101.0, 53, "RSTUVWXYZABCDEF", 168
    };

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG_REPLY packet_in{};
    packet_in.request_id = 963497464;
    packet_in.result = 53;
    packet_in.param_id = to_char_array("RSTUVWXYZABCDEF");
    packet_in.config_type = 168;
    packet_in.min_value = 45.0;
    packet_in.max_value = 73.0;
    packet_in.increment = 101.0;

    mavlink::ardupilotmega::msg::OSD_PARAM_SHOW_CONFIG_REPLY packet2{};

    mavlink_msg_osd_param_show_config_reply_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.request_id, packet2.request_id);
    EXPECT_EQ(packet_in.result, packet2.result);
    EXPECT_EQ(packet_in.param_id, packet2.param_id);
    EXPECT_EQ(packet_in.config_type, packet2.config_type);
    EXPECT_EQ(packet_in.min_value, packet2.min_value);
    EXPECT_EQ(packet_in.max_value, packet2.max_value);
    EXPECT_EQ(packet_in.increment, packet2.increment);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OBSTACLE_DISTANCE_3D)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OBSTACLE_DISTANCE_3D packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.sensor_type = 211;
    packet_in.frame = 22;
    packet_in.obstacle_id = 18483;
    packet_in.x = 45.0;
    packet_in.y = 73.0;
    packet_in.z = 101.0;
    packet_in.min_distance = 129.0;
    packet_in.max_distance = 157.0;

    mavlink::ardupilotmega::msg::OBSTACLE_DISTANCE_3D packet1{};
    mavlink::ardupilotmega::msg::OBSTACLE_DISTANCE_3D packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.sensor_type, packet2.sensor_type);
    EXPECT_EQ(packet1.frame, packet2.frame);
    EXPECT_EQ(packet1.obstacle_id, packet2.obstacle_id);
    EXPECT_EQ(packet1.x, packet2.x);
    EXPECT_EQ(packet1.y, packet2.y);
    EXPECT_EQ(packet1.z, packet2.z);
    EXPECT_EQ(packet1.min_distance, packet2.min_distance);
    EXPECT_EQ(packet1.max_distance, packet2.max_distance);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OBSTACLE_DISTANCE_3D)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_obstacle_distance_3d_t packet_c {
         963497464, 45.0, 73.0, 101.0, 129.0, 157.0, 18483, 211, 22
    };

    mavlink::ardupilotmega::msg::OBSTACLE_DISTANCE_3D packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.sensor_type = 211;
    packet_in.frame = 22;
    packet_in.obstacle_id = 18483;
    packet_in.x = 45.0;
    packet_in.y = 73.0;
    packet_in.z = 101.0;
    packet_in.min_distance = 129.0;
    packet_in.max_distance = 157.0;

    mavlink::ardupilotmega::msg::OBSTACLE_DISTANCE_3D packet2{};

    mavlink_msg_obstacle_distance_3d_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.sensor_type, packet2.sensor_type);
    EXPECT_EQ(packet_in.frame, packet2.frame);
    EXPECT_EQ(packet_in.obstacle_id, packet2.obstacle_id);
    EXPECT_EQ(packet_in.x, packet2.x);
    EXPECT_EQ(packet_in.y, packet2.y);
    EXPECT_EQ(packet_in.z, packet2.z);
    EXPECT_EQ(packet_in.min_distance, packet2.min_distance);
    EXPECT_EQ(packet_in.max_distance, packet2.max_distance);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, WATER_DEPTH)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::WATER_DEPTH packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.id = 113;
    packet_in.healthy = 180;
    packet_in.lat = 963497672;
    packet_in.lng = 963497880;
    packet_in.alt = 101.0;
    packet_in.roll = 129.0;
    packet_in.pitch = 157.0;
    packet_in.yaw = 185.0;
    packet_in.distance = 213.0;
    packet_in.temperature = 241.0;

    mavlink::ardupilotmega::msg::WATER_DEPTH packet1{};
    mavlink::ardupilotmega::msg::WATER_DEPTH packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet1.id, packet2.id);
    EXPECT_EQ(packet1.healthy, packet2.healthy);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lng, packet2.lng);
    EXPECT_EQ(packet1.alt, packet2.alt);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
    EXPECT_EQ(packet1.distance, packet2.distance);
    EXPECT_EQ(packet1.temperature, packet2.temperature);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, WATER_DEPTH)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_water_depth_t packet_c {
         963497464, 963497672, 963497880, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 113, 180
    };

    mavlink::ardupilotmega::msg::WATER_DEPTH packet_in{};
    packet_in.time_boot_ms = 963497464;
    packet_in.id = 113;
    packet_in.healthy = 180;
    packet_in.lat = 963497672;
    packet_in.lng = 963497880;
    packet_in.alt = 101.0;
    packet_in.roll = 129.0;
    packet_in.pitch = 157.0;
    packet_in.yaw = 185.0;
    packet_in.distance = 213.0;
    packet_in.temperature = 241.0;

    mavlink::ardupilotmega::msg::WATER_DEPTH packet2{};

    mavlink_msg_water_depth_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_boot_ms, packet2.time_boot_ms);
    EXPECT_EQ(packet_in.id, packet2.id);
    EXPECT_EQ(packet_in.healthy, packet2.healthy);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lng, packet2.lng);
    EXPECT_EQ(packet_in.alt, packet2.alt);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);
    EXPECT_EQ(packet_in.distance, packet2.distance);
    EXPECT_EQ(packet_in.temperature, packet2.temperature);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, MCU_STATUS)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::MCU_STATUS packet_in{};
    packet_in.id = 29;
    packet_in.MCU_temperature = 17235;
    packet_in.MCU_voltage = 17339;
    packet_in.MCU_voltage_min = 17443;
    packet_in.MCU_voltage_max = 17547;

    mavlink::ardupilotmega::msg::MCU_STATUS packet1{};
    mavlink::ardupilotmega::msg::MCU_STATUS packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.id, packet2.id);
    EXPECT_EQ(packet1.MCU_temperature, packet2.MCU_temperature);
    EXPECT_EQ(packet1.MCU_voltage, packet2.MCU_voltage);
    EXPECT_EQ(packet1.MCU_voltage_min, packet2.MCU_voltage_min);
    EXPECT_EQ(packet1.MCU_voltage_max, packet2.MCU_voltage_max);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, MCU_STATUS)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_mcu_status_t packet_c {
         17235, 17339, 17443, 17547, 29
    };

    mavlink::ardupilotmega::msg::MCU_STATUS packet_in{};
    packet_in.id = 29;
    packet_in.MCU_temperature = 17235;
    packet_in.MCU_voltage = 17339;
    packet_in.MCU_voltage_min = 17443;
    packet_in.MCU_voltage_max = 17547;

    mavlink::ardupilotmega::msg::MCU_STATUS packet2{};

    mavlink_msg_mcu_status_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.id, packet2.id);
    EXPECT_EQ(packet_in.MCU_temperature, packet2.MCU_temperature);
    EXPECT_EQ(packet_in.MCU_voltage, packet2.MCU_voltage);
    EXPECT_EQ(packet_in.MCU_voltage_min, packet2.MCU_voltage_min);
    EXPECT_EQ(packet_in.MCU_voltage_max, packet2.MCU_voltage_max);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OAIRE_RFSENSOR_SETCONFIG)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG packet_in{};
    packet_in.center_frq = 17.0;
    packet_in.span = 45.0;
    packet_in.no_points = 17651;
    packet_in.continuous = -93;
    packet_in.start_stop = -26;

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG packet1{};
    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.center_frq, packet2.center_frq);
    EXPECT_EQ(packet1.span, packet2.span);
    EXPECT_EQ(packet1.no_points, packet2.no_points);
    EXPECT_EQ(packet1.continuous, packet2.continuous);
    EXPECT_EQ(packet1.start_stop, packet2.start_stop);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OAIRE_RFSENSOR_SETCONFIG)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_oaire_rfsensor_setconfig_t packet_c {
         17.0, 45.0, 17651, -93, -26
    };

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG packet_in{};
    packet_in.center_frq = 17.0;
    packet_in.span = 45.0;
    packet_in.no_points = 17651;
    packet_in.continuous = -93;
    packet_in.start_stop = -26;

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG packet2{};

    mavlink_msg_oaire_rfsensor_setconfig_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.center_frq, packet2.center_frq);
    EXPECT_EQ(packet_in.span, packet2.span);
    EXPECT_EQ(packet_in.no_points, packet2.no_points);
    EXPECT_EQ(packet_in.continuous, packet2.continuous);
    EXPECT_EQ(packet_in.start_stop, packet2.start_stop);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OAIRE_RFSENSOR_SETCONFIG_ACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG_ACK packet_in{};
    packet_in.center_frq = 17.0;
    packet_in.span = 45.0;
    packet_in.no_points = 17651;
    packet_in.continuous = -93;
    packet_in.start_stop = -26;
    packet_in.state = 41;

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG_ACK packet1{};
    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG_ACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.center_frq, packet2.center_frq);
    EXPECT_EQ(packet1.span, packet2.span);
    EXPECT_EQ(packet1.no_points, packet2.no_points);
    EXPECT_EQ(packet1.continuous, packet2.continuous);
    EXPECT_EQ(packet1.start_stop, packet2.start_stop);
    EXPECT_EQ(packet1.state, packet2.state);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OAIRE_RFSENSOR_SETCONFIG_ACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_oaire_rfsensor_setconfig_ack_t packet_c {
         17.0, 45.0, 17651, -93, -26, 41
    };

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG_ACK packet_in{};
    packet_in.center_frq = 17.0;
    packet_in.span = 45.0;
    packet_in.no_points = 17651;
    packet_in.continuous = -93;
    packet_in.start_stop = -26;
    packet_in.state = 41;

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_SETCONFIG_ACK packet2{};

    mavlink_msg_oaire_rfsensor_setconfig_ack_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.center_frq, packet2.center_frq);
    EXPECT_EQ(packet_in.span, packet2.span);
    EXPECT_EQ(packet_in.no_points, packet2.no_points);
    EXPECT_EQ(packet_in.continuous, packet2.continuous);
    EXPECT_EQ(packet_in.start_stop, packet2.start_stop);
    EXPECT_EQ(packet_in.state, packet2.state);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OAIRE_RFSENSOR_TRACE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_TRACE packet_in{};
    packet_in.frequency = {{ 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0, 193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0, 203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0, 213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0, 223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0, 233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0, 253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0, 263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0, 273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0, 283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0, 293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0, 303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0, 313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0, 323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0, 333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0, 343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0, 353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0, 363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0, 373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0, 383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0, 393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0, 401.0, 402.0, 403.0, 404.0, 405.0, 406.0, 407.0, 408.0, 409.0, 410.0, 411.0, 412.0, 413.0, 414.0, 415.0, 416.0, 417.0, 418.0, 419.0, 420.0, 421.0, 422.0, 423.0, 424.0, 425.0, 426.0, 427.0, 428.0, 429.0, 430.0, 431.0, 432.0, 433.0, 434.0, 435.0, 436.0, 437.0, 438.0, 439.0, 440.0, 441.0, 442.0, 443.0, 444.0, 445.0, 446.0, 447.0, 448.0, 449.0, 450.0, 451.0, 452.0, 453.0, 454.0, 455.0, 456.0, 457.0, 458.0, 459.0, 460.0, 461.0, 462.0, 463.0, 464.0, 465.0, 466.0, 467.0, 468.0, 469.0, 470.0, 471.0, 472.0, 473.0, 474.0, 475.0, 476.0, 477.0, 478.0, 479.0, 480.0, 481.0, 482.0, 483.0, 484.0, 485.0, 486.0, 487.0, 488.0, 489.0, 490.0, 491.0, 492.0, 493.0, 494.0, 495.0, 496.0, 497.0, 498.0, 499.0, 500.0, 501.0, 502.0, 503.0, 504.0, 505.0, 506.0, 507.0, 508.0, 509.0, 510.0, 511.0, 512.0, 513.0, 514.0, 515.0, 516.0, 517.0, 518.0, 519.0, 520.0, 521.0, 522.0, 523.0, 524.0, 525.0, 526.0, 527.0, 528.0, 529.0, 530.0, 531.0, 532.0, 533.0, 534.0, 535.0, 536.0, 537.0, 538.0, 539.0, 540.0, 541.0, 542.0, 543.0, 544.0, 545.0, 546.0, 547.0, 548.0, 549.0, 550.0, 551.0, 552.0, 553.0, 554.0, 555.0, 556.0, 557.0, 558.0, 559.0, 560.0, 561.0, 562.0, 563.0, 564.0, 565.0, 566.0, 567.0, 568.0, 569.0, 570.0, 571.0, 572.0, 573.0, 574.0, 575.0, 576.0, 577.0, 578.0, 579.0, 580.0, 581.0, 582.0, 583.0, 584.0, 585.0, 586.0, 587.0, 588.0, 589.0, 590.0, 591.0, 592.0, 593.0, 594.0, 595.0, 596.0, 597.0, 598.0, 599.0, 600.0, 601.0, 602.0, 603.0, 604.0, 605.0, 606.0, 607.0, 608.0, 609.0, 610.0, 611.0, 612.0, 613.0, 614.0, 615.0, 616.0, 617.0, 618.0, 619.0, 620.0, 621.0, 622.0, 623.0, 624.0, 625.0, 626.0, 627.0, 628.0, 629.0, 630.0, 631.0, 632.0, 633.0, 634.0, 635.0, 636.0, 637.0, 638.0, 639.0, 640.0, 641.0, 642.0, 643.0, 644.0, 645.0, 646.0, 647.0, 648.0, 649.0, 650.0, 651.0, 652.0, 653.0, 654.0, 655.0, 656.0, 657.0, 658.0, 659.0, 660.0, 661.0, 662.0, 663.0, 664.0, 665.0, 666.0, 667.0, 668.0, 669.0, 670.0, 671.0, 672.0, 673.0, 674.0, 675.0, 676.0, 677.0, 678.0, 679.0, 680.0, 681.0, 682.0, 683.0, 684.0, 685.0, 686.0, 687.0, 688.0, 689.0, 690.0, 691.0, 692.0, 693.0, 694.0, 695.0, 696.0, 697.0, 698.0, 699.0, 700.0, 701.0, 702.0, 703.0, 704.0, 705.0, 706.0, 707.0, 708.0, 709.0, 710.0, 711.0, 712.0, 713.0, 714.0, 715.0, 716.0, 717.0, 718.0, 719.0, 720.0, 721.0, 722.0, 723.0, 724.0, 725.0, 726.0, 727.0, 728.0, 729.0, 730.0, 731.0, 732.0, 733.0, 734.0, 735.0, 736.0, 737.0, 738.0, 739.0, 740.0, 741.0, 742.0, 743.0, 744.0, 745.0, 746.0, 747.0, 748.0, 749.0, 750.0, 751.0, 752.0, 753.0, 754.0, 755.0, 756.0, 757.0, 758.0, 759.0, 760.0, 761.0, 762.0, 763.0, 764.0, 765.0, 766.0, 767.0, 768.0, 769.0, 770.0, 771.0, 772.0, 773.0, 774.0, 775.0, 776.0, 777.0, 778.0, 779.0, 780.0, 781.0, 782.0, 783.0, 784.0, 785.0, 786.0, 787.0, 788.0, 789.0, 790.0, 791.0, 792.0, 793.0, 794.0, 795.0, 796.0, 797.0, 798.0, 799.0, 800.0, 801.0, 802.0, 803.0, 804.0, 805.0, 806.0, 807.0, 808.0, 809.0, 810.0, 811.0, 812.0, 813.0, 814.0, 815.0, 816.0, 817.0, 818.0, 819.0, 820.0, 821.0, 822.0, 823.0, 824.0, 825.0, 826.0, 827.0, 828.0, 829.0, 830.0, 831.0, 832.0, 833.0, 834.0, 835.0, 836.0, 837.0, 838.0, 839.0, 840.0, 841.0, 842.0, 843.0, 844.0, 845.0, 846.0, 847.0, 848.0, 849.0, 850.0, 851.0, 852.0, 853.0, 854.0, 855.0, 856.0, 857.0, 858.0, 859.0, 860.0, 861.0, 862.0, 863.0, 864.0, 865.0, 866.0, 867.0, 868.0, 869.0, 870.0, 871.0, 872.0, 873.0, 874.0, 875.0, 876.0, 877.0, 878.0, 879.0, 880.0, 881.0, 882.0, 883.0, 884.0, 885.0, 886.0, 887.0, 888.0, 889.0, 890.0, 891.0, 892.0, 893.0, 894.0, 895.0, 896.0, 897.0, 898.0, 899.0, 900.0, 901.0, 902.0, 903.0, 904.0, 905.0, 906.0, 907.0, 908.0, 909.0, 910.0, 911.0, 912.0, 913.0, 914.0, 915.0, 916.0, 917.0, 918.0, 919.0, 920.0, 921.0, 922.0, 923.0, 924.0, 925.0, 926.0, 927.0, 928.0, 929.0, 930.0, 931.0, 932.0, 933.0, 934.0, 935.0, 936.0, 937.0, 938.0, 939.0, 940.0, 941.0, 942.0, 943.0, 944.0, 945.0, 946.0, 947.0, 948.0, 949.0, 950.0, 951.0, 952.0, 953.0, 954.0, 955.0, 956.0, 957.0, 958.0, 959.0, 960.0, 961.0, 962.0, 963.0, 964.0, 965.0, 966.0, 967.0, 968.0, 969.0, 970.0, 971.0, 972.0, 973.0, 974.0, 975.0, 976.0, 977.0, 978.0, 979.0, 980.0, 981.0, 982.0, 983.0, 984.0, 985.0, 986.0, 987.0, 988.0, 989.0, 990.0, 991.0, 992.0, 993.0, 994.0, 995.0, 996.0, 997.0, 998.0, 999.0, 1000.0, 1001.0, 1002.0, 1003.0, 1004.0, 1005.0, 1006.0, 1007.0, 1008.0, 1009.0, 1010.0, 1011.0, 1012.0, 1013.0, 1014.0, 1015.0, 1016.0 }};
    packet_in.trace = {{ 28017.0, 28018.0, 28019.0, 28020.0, 28021.0, 28022.0, 28023.0, 28024.0, 28025.0, 28026.0, 28027.0, 28028.0, 28029.0, 28030.0, 28031.0, 28032.0, 28033.0, 28034.0, 28035.0, 28036.0, 28037.0, 28038.0, 28039.0, 28040.0, 28041.0, 28042.0, 28043.0, 28044.0, 28045.0, 28046.0, 28047.0, 28048.0, 28049.0, 28050.0, 28051.0, 28052.0, 28053.0, 28054.0, 28055.0, 28056.0, 28057.0, 28058.0, 28059.0, 28060.0, 28061.0, 28062.0, 28063.0, 28064.0, 28065.0, 28066.0, 28067.0, 28068.0, 28069.0, 28070.0, 28071.0, 28072.0, 28073.0, 28074.0, 28075.0, 28076.0, 28077.0, 28078.0, 28079.0, 28080.0, 28081.0, 28082.0, 28083.0, 28084.0, 28085.0, 28086.0, 28087.0, 28088.0, 28089.0, 28090.0, 28091.0, 28092.0, 28093.0, 28094.0, 28095.0, 28096.0, 28097.0, 28098.0, 28099.0, 28100.0, 28101.0, 28102.0, 28103.0, 28104.0, 28105.0, 28106.0, 28107.0, 28108.0, 28109.0, 28110.0, 28111.0, 28112.0, 28113.0, 28114.0, 28115.0, 28116.0, 28117.0, 28118.0, 28119.0, 28120.0, 28121.0, 28122.0, 28123.0, 28124.0, 28125.0, 28126.0, 28127.0, 28128.0, 28129.0, 28130.0, 28131.0, 28132.0, 28133.0, 28134.0, 28135.0, 28136.0, 28137.0, 28138.0, 28139.0, 28140.0, 28141.0, 28142.0, 28143.0, 28144.0, 28145.0, 28146.0, 28147.0, 28148.0, 28149.0, 28150.0, 28151.0, 28152.0, 28153.0, 28154.0, 28155.0, 28156.0, 28157.0, 28158.0, 28159.0, 28160.0, 28161.0, 28162.0, 28163.0, 28164.0, 28165.0, 28166.0, 28167.0, 28168.0, 28169.0, 28170.0, 28171.0, 28172.0, 28173.0, 28174.0, 28175.0, 28176.0, 28177.0, 28178.0, 28179.0, 28180.0, 28181.0, 28182.0, 28183.0, 28184.0, 28185.0, 28186.0, 28187.0, 28188.0, 28189.0, 28190.0, 28191.0, 28192.0, 28193.0, 28194.0, 28195.0, 28196.0, 28197.0, 28198.0, 28199.0, 28200.0, 28201.0, 28202.0, 28203.0, 28204.0, 28205.0, 28206.0, 28207.0, 28208.0, 28209.0, 28210.0, 28211.0, 28212.0, 28213.0, 28214.0, 28215.0, 28216.0, 28217.0, 28218.0, 28219.0, 28220.0, 28221.0, 28222.0, 28223.0, 28224.0, 28225.0, 28226.0, 28227.0, 28228.0, 28229.0, 28230.0, 28231.0, 28232.0, 28233.0, 28234.0, 28235.0, 28236.0, 28237.0, 28238.0, 28239.0, 28240.0, 28241.0, 28242.0, 28243.0, 28244.0, 28245.0, 28246.0, 28247.0, 28248.0, 28249.0, 28250.0, 28251.0, 28252.0, 28253.0, 28254.0, 28255.0, 28256.0, 28257.0, 28258.0, 28259.0, 28260.0, 28261.0, 28262.0, 28263.0, 28264.0, 28265.0, 28266.0, 28267.0, 28268.0, 28269.0, 28270.0, 28271.0, 28272.0, 28273.0, 28274.0, 28275.0, 28276.0, 28277.0, 28278.0, 28279.0, 28280.0, 28281.0, 28282.0, 28283.0, 28284.0, 28285.0, 28286.0, 28287.0, 28288.0, 28289.0, 28290.0, 28291.0, 28292.0, 28293.0, 28294.0, 28295.0, 28296.0, 28297.0, 28298.0, 28299.0, 28300.0, 28301.0, 28302.0, 28303.0, 28304.0, 28305.0, 28306.0, 28307.0, 28308.0, 28309.0, 28310.0, 28311.0, 28312.0, 28313.0, 28314.0, 28315.0, 28316.0, 28317.0, 28318.0, 28319.0, 28320.0, 28321.0, 28322.0, 28323.0, 28324.0, 28325.0, 28326.0, 28327.0, 28328.0, 28329.0, 28330.0, 28331.0, 28332.0, 28333.0, 28334.0, 28335.0, 28336.0, 28337.0, 28338.0, 28339.0, 28340.0, 28341.0, 28342.0, 28343.0, 28344.0, 28345.0, 28346.0, 28347.0, 28348.0, 28349.0, 28350.0, 28351.0, 28352.0, 28353.0, 28354.0, 28355.0, 28356.0, 28357.0, 28358.0, 28359.0, 28360.0, 28361.0, 28362.0, 28363.0, 28364.0, 28365.0, 28366.0, 28367.0, 28368.0, 28369.0, 28370.0, 28371.0, 28372.0, 28373.0, 28374.0, 28375.0, 28376.0, 28377.0, 28378.0, 28379.0, 28380.0, 28381.0, 28382.0, 28383.0, 28384.0, 28385.0, 28386.0, 28387.0, 28388.0, 28389.0, 28390.0, 28391.0, 28392.0, 28393.0, 28394.0, 28395.0, 28396.0, 28397.0, 28398.0, 28399.0, 28400.0, 28401.0, 28402.0, 28403.0, 28404.0, 28405.0, 28406.0, 28407.0, 28408.0, 28409.0, 28410.0, 28411.0, 28412.0, 28413.0, 28414.0, 28415.0, 28416.0, 28417.0, 28418.0, 28419.0, 28420.0, 28421.0, 28422.0, 28423.0, 28424.0, 28425.0, 28426.0, 28427.0, 28428.0, 28429.0, 28430.0, 28431.0, 28432.0, 28433.0, 28434.0, 28435.0, 28436.0, 28437.0, 28438.0, 28439.0, 28440.0, 28441.0, 28442.0, 28443.0, 28444.0, 28445.0, 28446.0, 28447.0, 28448.0, 28449.0, 28450.0, 28451.0, 28452.0, 28453.0, 28454.0, 28455.0, 28456.0, 28457.0, 28458.0, 28459.0, 28460.0, 28461.0, 28462.0, 28463.0, 28464.0, 28465.0, 28466.0, 28467.0, 28468.0, 28469.0, 28470.0, 28471.0, 28472.0, 28473.0, 28474.0, 28475.0, 28476.0, 28477.0, 28478.0, 28479.0, 28480.0, 28481.0, 28482.0, 28483.0, 28484.0, 28485.0, 28486.0, 28487.0, 28488.0, 28489.0, 28490.0, 28491.0, 28492.0, 28493.0, 28494.0, 28495.0, 28496.0, 28497.0, 28498.0, 28499.0, 28500.0, 28501.0, 28502.0, 28503.0, 28504.0, 28505.0, 28506.0, 28507.0, 28508.0, 28509.0, 28510.0, 28511.0, 28512.0, 28513.0, 28514.0, 28515.0, 28516.0, 28517.0, 28518.0, 28519.0, 28520.0, 28521.0, 28522.0, 28523.0, 28524.0, 28525.0, 28526.0, 28527.0, 28528.0, 28529.0, 28530.0, 28531.0, 28532.0, 28533.0, 28534.0, 28535.0, 28536.0, 28537.0, 28538.0, 28539.0, 28540.0, 28541.0, 28542.0, 28543.0, 28544.0, 28545.0, 28546.0, 28547.0, 28548.0, 28549.0, 28550.0, 28551.0, 28552.0, 28553.0, 28554.0, 28555.0, 28556.0, 28557.0, 28558.0, 28559.0, 28560.0, 28561.0, 28562.0, 28563.0, 28564.0, 28565.0, 28566.0, 28567.0, 28568.0, 28569.0, 28570.0, 28571.0, 28572.0, 28573.0, 28574.0, 28575.0, 28576.0, 28577.0, 28578.0, 28579.0, 28580.0, 28581.0, 28582.0, 28583.0, 28584.0, 28585.0, 28586.0, 28587.0, 28588.0, 28589.0, 28590.0, 28591.0, 28592.0, 28593.0, 28594.0, 28595.0, 28596.0, 28597.0, 28598.0, 28599.0, 28600.0, 28601.0, 28602.0, 28603.0, 28604.0, 28605.0, 28606.0, 28607.0, 28608.0, 28609.0, 28610.0, 28611.0, 28612.0, 28613.0, 28614.0, 28615.0, 28616.0, 28617.0, 28618.0, 28619.0, 28620.0, 28621.0, 28622.0, 28623.0, 28624.0, 28625.0, 28626.0, 28627.0, 28628.0, 28629.0, 28630.0, 28631.0, 28632.0, 28633.0, 28634.0, 28635.0, 28636.0, 28637.0, 28638.0, 28639.0, 28640.0, 28641.0, 28642.0, 28643.0, 28644.0, 28645.0, 28646.0, 28647.0, 28648.0, 28649.0, 28650.0, 28651.0, 28652.0, 28653.0, 28654.0, 28655.0, 28656.0, 28657.0, 28658.0, 28659.0, 28660.0, 28661.0, 28662.0, 28663.0, 28664.0, 28665.0, 28666.0, 28667.0, 28668.0, 28669.0, 28670.0, 28671.0, 28672.0, 28673.0, 28674.0, 28675.0, 28676.0, 28677.0, 28678.0, 28679.0, 28680.0, 28681.0, 28682.0, 28683.0, 28684.0, 28685.0, 28686.0, 28687.0, 28688.0, 28689.0, 28690.0, 28691.0, 28692.0, 28693.0, 28694.0, 28695.0, 28696.0, 28697.0, 28698.0, 28699.0, 28700.0, 28701.0, 28702.0, 28703.0, 28704.0, 28705.0, 28706.0, 28707.0, 28708.0, 28709.0, 28710.0, 28711.0, 28712.0, 28713.0, 28714.0, 28715.0, 28716.0, 28717.0, 28718.0, 28719.0, 28720.0, 28721.0, 28722.0, 28723.0, 28724.0, 28725.0, 28726.0, 28727.0, 28728.0, 28729.0, 28730.0, 28731.0, 28732.0, 28733.0, 28734.0, 28735.0, 28736.0, 28737.0, 28738.0, 28739.0, 28740.0, 28741.0, 28742.0, 28743.0, 28744.0, 28745.0, 28746.0, 28747.0, 28748.0, 28749.0, 28750.0, 28751.0, 28752.0, 28753.0, 28754.0, 28755.0, 28756.0, 28757.0, 28758.0, 28759.0, 28760.0, 28761.0, 28762.0, 28763.0, 28764.0, 28765.0, 28766.0, 28767.0, 28768.0, 28769.0, 28770.0, 28771.0, 28772.0, 28773.0, 28774.0, 28775.0, 28776.0, 28777.0, 28778.0, 28779.0, 28780.0, 28781.0, 28782.0, 28783.0, 28784.0, 28785.0, 28786.0, 28787.0, 28788.0, 28789.0, 28790.0, 28791.0, 28792.0, 28793.0, 28794.0, 28795.0, 28796.0, 28797.0, 28798.0, 28799.0, 28800.0, 28801.0, 28802.0, 28803.0, 28804.0, 28805.0, 28806.0, 28807.0, 28808.0, 28809.0, 28810.0, 28811.0, 28812.0, 28813.0, 28814.0, 28815.0, 28816.0, 28817.0, 28818.0, 28819.0, 28820.0, 28821.0, 28822.0, 28823.0, 28824.0, 28825.0, 28826.0, 28827.0, 28828.0, 28829.0, 28830.0, 28831.0, 28832.0, 28833.0, 28834.0, 28835.0, 28836.0, 28837.0, 28838.0, 28839.0, 28840.0, 28841.0, 28842.0, 28843.0, 28844.0, 28845.0, 28846.0, 28847.0, 28848.0, 28849.0, 28850.0, 28851.0, 28852.0, 28853.0, 28854.0, 28855.0, 28856.0, 28857.0, 28858.0, 28859.0, 28860.0, 28861.0, 28862.0, 28863.0, 28864.0, 28865.0, 28866.0, 28867.0, 28868.0, 28869.0, 28870.0, 28871.0, 28872.0, 28873.0, 28874.0, 28875.0, 28876.0, 28877.0, 28878.0, 28879.0, 28880.0, 28881.0, 28882.0, 28883.0, 28884.0, 28885.0, 28886.0, 28887.0, 28888.0, 28889.0, 28890.0, 28891.0, 28892.0, 28893.0, 28894.0, 28895.0, 28896.0, 28897.0, 28898.0, 28899.0, 28900.0, 28901.0, 28902.0, 28903.0, 28904.0, 28905.0, 28906.0, 28907.0, 28908.0, 28909.0, 28910.0, 28911.0, 28912.0, 28913.0, 28914.0, 28915.0, 28916.0, 28917.0, 28918.0, 28919.0, 28920.0, 28921.0, 28922.0, 28923.0, 28924.0, 28925.0, 28926.0, 28927.0, 28928.0, 28929.0, 28930.0, 28931.0, 28932.0, 28933.0, 28934.0, 28935.0, 28936.0, 28937.0, 28938.0, 28939.0, 28940.0, 28941.0, 28942.0, 28943.0, 28944.0, 28945.0, 28946.0, 28947.0, 28948.0, 28949.0, 28950.0, 28951.0, 28952.0, 28953.0, 28954.0, 28955.0, 28956.0, 28957.0, 28958.0, 28959.0, 28960.0, 28961.0, 28962.0, 28963.0, 28964.0, 28965.0, 28966.0, 28967.0, 28968.0, 28969.0, 28970.0, 28971.0, 28972.0, 28973.0, 28974.0, 28975.0, 28976.0, 28977.0, 28978.0, 28979.0, 28980.0, 28981.0, 28982.0, 28983.0, 28984.0, 28985.0, 28986.0, 28987.0, 28988.0, 28989.0, 28990.0, 28991.0, 28992.0, 28993.0, 28994.0, 28995.0, 28996.0, 28997.0, 28998.0, 28999.0, 29000.0, 29001.0, 29002.0, 29003.0, 29004.0, 29005.0, 29006.0, 29007.0, 29008.0, 29009.0, 29010.0, 29011.0, 29012.0, 29013.0, 29014.0, 29015.0, 29016.0 }};

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_TRACE packet1{};
    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_TRACE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.frequency, packet2.frequency);
    EXPECT_EQ(packet1.trace, packet2.trace);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OAIRE_RFSENSOR_TRACE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_oaire_rfsensor_trace_t packet_c {
         { 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0, 193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0, 203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0, 213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0, 223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0, 233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0, 253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0, 263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0, 273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0, 283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0, 293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0, 303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0, 313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0, 323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0, 333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0, 343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0, 353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0, 363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0, 373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0, 383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0, 393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0, 401.0, 402.0, 403.0, 404.0, 405.0, 406.0, 407.0, 408.0, 409.0, 410.0, 411.0, 412.0, 413.0, 414.0, 415.0, 416.0, 417.0, 418.0, 419.0, 420.0, 421.0, 422.0, 423.0, 424.0, 425.0, 426.0, 427.0, 428.0, 429.0, 430.0, 431.0, 432.0, 433.0, 434.0, 435.0, 436.0, 437.0, 438.0, 439.0, 440.0, 441.0, 442.0, 443.0, 444.0, 445.0, 446.0, 447.0, 448.0, 449.0, 450.0, 451.0, 452.0, 453.0, 454.0, 455.0, 456.0, 457.0, 458.0, 459.0, 460.0, 461.0, 462.0, 463.0, 464.0, 465.0, 466.0, 467.0, 468.0, 469.0, 470.0, 471.0, 472.0, 473.0, 474.0, 475.0, 476.0, 477.0, 478.0, 479.0, 480.0, 481.0, 482.0, 483.0, 484.0, 485.0, 486.0, 487.0, 488.0, 489.0, 490.0, 491.0, 492.0, 493.0, 494.0, 495.0, 496.0, 497.0, 498.0, 499.0, 500.0, 501.0, 502.0, 503.0, 504.0, 505.0, 506.0, 507.0, 508.0, 509.0, 510.0, 511.0, 512.0, 513.0, 514.0, 515.0, 516.0, 517.0, 518.0, 519.0, 520.0, 521.0, 522.0, 523.0, 524.0, 525.0, 526.0, 527.0, 528.0, 529.0, 530.0, 531.0, 532.0, 533.0, 534.0, 535.0, 536.0, 537.0, 538.0, 539.0, 540.0, 541.0, 542.0, 543.0, 544.0, 545.0, 546.0, 547.0, 548.0, 549.0, 550.0, 551.0, 552.0, 553.0, 554.0, 555.0, 556.0, 557.0, 558.0, 559.0, 560.0, 561.0, 562.0, 563.0, 564.0, 565.0, 566.0, 567.0, 568.0, 569.0, 570.0, 571.0, 572.0, 573.0, 574.0, 575.0, 576.0, 577.0, 578.0, 579.0, 580.0, 581.0, 582.0, 583.0, 584.0, 585.0, 586.0, 587.0, 588.0, 589.0, 590.0, 591.0, 592.0, 593.0, 594.0, 595.0, 596.0, 597.0, 598.0, 599.0, 600.0, 601.0, 602.0, 603.0, 604.0, 605.0, 606.0, 607.0, 608.0, 609.0, 610.0, 611.0, 612.0, 613.0, 614.0, 615.0, 616.0, 617.0, 618.0, 619.0, 620.0, 621.0, 622.0, 623.0, 624.0, 625.0, 626.0, 627.0, 628.0, 629.0, 630.0, 631.0, 632.0, 633.0, 634.0, 635.0, 636.0, 637.0, 638.0, 639.0, 640.0, 641.0, 642.0, 643.0, 644.0, 645.0, 646.0, 647.0, 648.0, 649.0, 650.0, 651.0, 652.0, 653.0, 654.0, 655.0, 656.0, 657.0, 658.0, 659.0, 660.0, 661.0, 662.0, 663.0, 664.0, 665.0, 666.0, 667.0, 668.0, 669.0, 670.0, 671.0, 672.0, 673.0, 674.0, 675.0, 676.0, 677.0, 678.0, 679.0, 680.0, 681.0, 682.0, 683.0, 684.0, 685.0, 686.0, 687.0, 688.0, 689.0, 690.0, 691.0, 692.0, 693.0, 694.0, 695.0, 696.0, 697.0, 698.0, 699.0, 700.0, 701.0, 702.0, 703.0, 704.0, 705.0, 706.0, 707.0, 708.0, 709.0, 710.0, 711.0, 712.0, 713.0, 714.0, 715.0, 716.0, 717.0, 718.0, 719.0, 720.0, 721.0, 722.0, 723.0, 724.0, 725.0, 726.0, 727.0, 728.0, 729.0, 730.0, 731.0, 732.0, 733.0, 734.0, 735.0, 736.0, 737.0, 738.0, 739.0, 740.0, 741.0, 742.0, 743.0, 744.0, 745.0, 746.0, 747.0, 748.0, 749.0, 750.0, 751.0, 752.0, 753.0, 754.0, 755.0, 756.0, 757.0, 758.0, 759.0, 760.0, 761.0, 762.0, 763.0, 764.0, 765.0, 766.0, 767.0, 768.0, 769.0, 770.0, 771.0, 772.0, 773.0, 774.0, 775.0, 776.0, 777.0, 778.0, 779.0, 780.0, 781.0, 782.0, 783.0, 784.0, 785.0, 786.0, 787.0, 788.0, 789.0, 790.0, 791.0, 792.0, 793.0, 794.0, 795.0, 796.0, 797.0, 798.0, 799.0, 800.0, 801.0, 802.0, 803.0, 804.0, 805.0, 806.0, 807.0, 808.0, 809.0, 810.0, 811.0, 812.0, 813.0, 814.0, 815.0, 816.0, 817.0, 818.0, 819.0, 820.0, 821.0, 822.0, 823.0, 824.0, 825.0, 826.0, 827.0, 828.0, 829.0, 830.0, 831.0, 832.0, 833.0, 834.0, 835.0, 836.0, 837.0, 838.0, 839.0, 840.0, 841.0, 842.0, 843.0, 844.0, 845.0, 846.0, 847.0, 848.0, 849.0, 850.0, 851.0, 852.0, 853.0, 854.0, 855.0, 856.0, 857.0, 858.0, 859.0, 860.0, 861.0, 862.0, 863.0, 864.0, 865.0, 866.0, 867.0, 868.0, 869.0, 870.0, 871.0, 872.0, 873.0, 874.0, 875.0, 876.0, 877.0, 878.0, 879.0, 880.0, 881.0, 882.0, 883.0, 884.0, 885.0, 886.0, 887.0, 888.0, 889.0, 890.0, 891.0, 892.0, 893.0, 894.0, 895.0, 896.0, 897.0, 898.0, 899.0, 900.0, 901.0, 902.0, 903.0, 904.0, 905.0, 906.0, 907.0, 908.0, 909.0, 910.0, 911.0, 912.0, 913.0, 914.0, 915.0, 916.0, 917.0, 918.0, 919.0, 920.0, 921.0, 922.0, 923.0, 924.0, 925.0, 926.0, 927.0, 928.0, 929.0, 930.0, 931.0, 932.0, 933.0, 934.0, 935.0, 936.0, 937.0, 938.0, 939.0, 940.0, 941.0, 942.0, 943.0, 944.0, 945.0, 946.0, 947.0, 948.0, 949.0, 950.0, 951.0, 952.0, 953.0, 954.0, 955.0, 956.0, 957.0, 958.0, 959.0, 960.0, 961.0, 962.0, 963.0, 964.0, 965.0, 966.0, 967.0, 968.0, 969.0, 970.0, 971.0, 972.0, 973.0, 974.0, 975.0, 976.0, 977.0, 978.0, 979.0, 980.0, 981.0, 982.0, 983.0, 984.0, 985.0, 986.0, 987.0, 988.0, 989.0, 990.0, 991.0, 992.0, 993.0, 994.0, 995.0, 996.0, 997.0, 998.0, 999.0, 1000.0, 1001.0, 1002.0, 1003.0, 1004.0, 1005.0, 1006.0, 1007.0, 1008.0, 1009.0, 1010.0, 1011.0, 1012.0, 1013.0, 1014.0, 1015.0, 1016.0 }, { 28017.0, 28018.0, 28019.0, 28020.0, 28021.0, 28022.0, 28023.0, 28024.0, 28025.0, 28026.0, 28027.0, 28028.0, 28029.0, 28030.0, 28031.0, 28032.0, 28033.0, 28034.0, 28035.0, 28036.0, 28037.0, 28038.0, 28039.0, 28040.0, 28041.0, 28042.0, 28043.0, 28044.0, 28045.0, 28046.0, 28047.0, 28048.0, 28049.0, 28050.0, 28051.0, 28052.0, 28053.0, 28054.0, 28055.0, 28056.0, 28057.0, 28058.0, 28059.0, 28060.0, 28061.0, 28062.0, 28063.0, 28064.0, 28065.0, 28066.0, 28067.0, 28068.0, 28069.0, 28070.0, 28071.0, 28072.0, 28073.0, 28074.0, 28075.0, 28076.0, 28077.0, 28078.0, 28079.0, 28080.0, 28081.0, 28082.0, 28083.0, 28084.0, 28085.0, 28086.0, 28087.0, 28088.0, 28089.0, 28090.0, 28091.0, 28092.0, 28093.0, 28094.0, 28095.0, 28096.0, 28097.0, 28098.0, 28099.0, 28100.0, 28101.0, 28102.0, 28103.0, 28104.0, 28105.0, 28106.0, 28107.0, 28108.0, 28109.0, 28110.0, 28111.0, 28112.0, 28113.0, 28114.0, 28115.0, 28116.0, 28117.0, 28118.0, 28119.0, 28120.0, 28121.0, 28122.0, 28123.0, 28124.0, 28125.0, 28126.0, 28127.0, 28128.0, 28129.0, 28130.0, 28131.0, 28132.0, 28133.0, 28134.0, 28135.0, 28136.0, 28137.0, 28138.0, 28139.0, 28140.0, 28141.0, 28142.0, 28143.0, 28144.0, 28145.0, 28146.0, 28147.0, 28148.0, 28149.0, 28150.0, 28151.0, 28152.0, 28153.0, 28154.0, 28155.0, 28156.0, 28157.0, 28158.0, 28159.0, 28160.0, 28161.0, 28162.0, 28163.0, 28164.0, 28165.0, 28166.0, 28167.0, 28168.0, 28169.0, 28170.0, 28171.0, 28172.0, 28173.0, 28174.0, 28175.0, 28176.0, 28177.0, 28178.0, 28179.0, 28180.0, 28181.0, 28182.0, 28183.0, 28184.0, 28185.0, 28186.0, 28187.0, 28188.0, 28189.0, 28190.0, 28191.0, 28192.0, 28193.0, 28194.0, 28195.0, 28196.0, 28197.0, 28198.0, 28199.0, 28200.0, 28201.0, 28202.0, 28203.0, 28204.0, 28205.0, 28206.0, 28207.0, 28208.0, 28209.0, 28210.0, 28211.0, 28212.0, 28213.0, 28214.0, 28215.0, 28216.0, 28217.0, 28218.0, 28219.0, 28220.0, 28221.0, 28222.0, 28223.0, 28224.0, 28225.0, 28226.0, 28227.0, 28228.0, 28229.0, 28230.0, 28231.0, 28232.0, 28233.0, 28234.0, 28235.0, 28236.0, 28237.0, 28238.0, 28239.0, 28240.0, 28241.0, 28242.0, 28243.0, 28244.0, 28245.0, 28246.0, 28247.0, 28248.0, 28249.0, 28250.0, 28251.0, 28252.0, 28253.0, 28254.0, 28255.0, 28256.0, 28257.0, 28258.0, 28259.0, 28260.0, 28261.0, 28262.0, 28263.0, 28264.0, 28265.0, 28266.0, 28267.0, 28268.0, 28269.0, 28270.0, 28271.0, 28272.0, 28273.0, 28274.0, 28275.0, 28276.0, 28277.0, 28278.0, 28279.0, 28280.0, 28281.0, 28282.0, 28283.0, 28284.0, 28285.0, 28286.0, 28287.0, 28288.0, 28289.0, 28290.0, 28291.0, 28292.0, 28293.0, 28294.0, 28295.0, 28296.0, 28297.0, 28298.0, 28299.0, 28300.0, 28301.0, 28302.0, 28303.0, 28304.0, 28305.0, 28306.0, 28307.0, 28308.0, 28309.0, 28310.0, 28311.0, 28312.0, 28313.0, 28314.0, 28315.0, 28316.0, 28317.0, 28318.0, 28319.0, 28320.0, 28321.0, 28322.0, 28323.0, 28324.0, 28325.0, 28326.0, 28327.0, 28328.0, 28329.0, 28330.0, 28331.0, 28332.0, 28333.0, 28334.0, 28335.0, 28336.0, 28337.0, 28338.0, 28339.0, 28340.0, 28341.0, 28342.0, 28343.0, 28344.0, 28345.0, 28346.0, 28347.0, 28348.0, 28349.0, 28350.0, 28351.0, 28352.0, 28353.0, 28354.0, 28355.0, 28356.0, 28357.0, 28358.0, 28359.0, 28360.0, 28361.0, 28362.0, 28363.0, 28364.0, 28365.0, 28366.0, 28367.0, 28368.0, 28369.0, 28370.0, 28371.0, 28372.0, 28373.0, 28374.0, 28375.0, 28376.0, 28377.0, 28378.0, 28379.0, 28380.0, 28381.0, 28382.0, 28383.0, 28384.0, 28385.0, 28386.0, 28387.0, 28388.0, 28389.0, 28390.0, 28391.0, 28392.0, 28393.0, 28394.0, 28395.0, 28396.0, 28397.0, 28398.0, 28399.0, 28400.0, 28401.0, 28402.0, 28403.0, 28404.0, 28405.0, 28406.0, 28407.0, 28408.0, 28409.0, 28410.0, 28411.0, 28412.0, 28413.0, 28414.0, 28415.0, 28416.0, 28417.0, 28418.0, 28419.0, 28420.0, 28421.0, 28422.0, 28423.0, 28424.0, 28425.0, 28426.0, 28427.0, 28428.0, 28429.0, 28430.0, 28431.0, 28432.0, 28433.0, 28434.0, 28435.0, 28436.0, 28437.0, 28438.0, 28439.0, 28440.0, 28441.0, 28442.0, 28443.0, 28444.0, 28445.0, 28446.0, 28447.0, 28448.0, 28449.0, 28450.0, 28451.0, 28452.0, 28453.0, 28454.0, 28455.0, 28456.0, 28457.0, 28458.0, 28459.0, 28460.0, 28461.0, 28462.0, 28463.0, 28464.0, 28465.0, 28466.0, 28467.0, 28468.0, 28469.0, 28470.0, 28471.0, 28472.0, 28473.0, 28474.0, 28475.0, 28476.0, 28477.0, 28478.0, 28479.0, 28480.0, 28481.0, 28482.0, 28483.0, 28484.0, 28485.0, 28486.0, 28487.0, 28488.0, 28489.0, 28490.0, 28491.0, 28492.0, 28493.0, 28494.0, 28495.0, 28496.0, 28497.0, 28498.0, 28499.0, 28500.0, 28501.0, 28502.0, 28503.0, 28504.0, 28505.0, 28506.0, 28507.0, 28508.0, 28509.0, 28510.0, 28511.0, 28512.0, 28513.0, 28514.0, 28515.0, 28516.0, 28517.0, 28518.0, 28519.0, 28520.0, 28521.0, 28522.0, 28523.0, 28524.0, 28525.0, 28526.0, 28527.0, 28528.0, 28529.0, 28530.0, 28531.0, 28532.0, 28533.0, 28534.0, 28535.0, 28536.0, 28537.0, 28538.0, 28539.0, 28540.0, 28541.0, 28542.0, 28543.0, 28544.0, 28545.0, 28546.0, 28547.0, 28548.0, 28549.0, 28550.0, 28551.0, 28552.0, 28553.0, 28554.0, 28555.0, 28556.0, 28557.0, 28558.0, 28559.0, 28560.0, 28561.0, 28562.0, 28563.0, 28564.0, 28565.0, 28566.0, 28567.0, 28568.0, 28569.0, 28570.0, 28571.0, 28572.0, 28573.0, 28574.0, 28575.0, 28576.0, 28577.0, 28578.0, 28579.0, 28580.0, 28581.0, 28582.0, 28583.0, 28584.0, 28585.0, 28586.0, 28587.0, 28588.0, 28589.0, 28590.0, 28591.0, 28592.0, 28593.0, 28594.0, 28595.0, 28596.0, 28597.0, 28598.0, 28599.0, 28600.0, 28601.0, 28602.0, 28603.0, 28604.0, 28605.0, 28606.0, 28607.0, 28608.0, 28609.0, 28610.0, 28611.0, 28612.0, 28613.0, 28614.0, 28615.0, 28616.0, 28617.0, 28618.0, 28619.0, 28620.0, 28621.0, 28622.0, 28623.0, 28624.0, 28625.0, 28626.0, 28627.0, 28628.0, 28629.0, 28630.0, 28631.0, 28632.0, 28633.0, 28634.0, 28635.0, 28636.0, 28637.0, 28638.0, 28639.0, 28640.0, 28641.0, 28642.0, 28643.0, 28644.0, 28645.0, 28646.0, 28647.0, 28648.0, 28649.0, 28650.0, 28651.0, 28652.0, 28653.0, 28654.0, 28655.0, 28656.0, 28657.0, 28658.0, 28659.0, 28660.0, 28661.0, 28662.0, 28663.0, 28664.0, 28665.0, 28666.0, 28667.0, 28668.0, 28669.0, 28670.0, 28671.0, 28672.0, 28673.0, 28674.0, 28675.0, 28676.0, 28677.0, 28678.0, 28679.0, 28680.0, 28681.0, 28682.0, 28683.0, 28684.0, 28685.0, 28686.0, 28687.0, 28688.0, 28689.0, 28690.0, 28691.0, 28692.0, 28693.0, 28694.0, 28695.0, 28696.0, 28697.0, 28698.0, 28699.0, 28700.0, 28701.0, 28702.0, 28703.0, 28704.0, 28705.0, 28706.0, 28707.0, 28708.0, 28709.0, 28710.0, 28711.0, 28712.0, 28713.0, 28714.0, 28715.0, 28716.0, 28717.0, 28718.0, 28719.0, 28720.0, 28721.0, 28722.0, 28723.0, 28724.0, 28725.0, 28726.0, 28727.0, 28728.0, 28729.0, 28730.0, 28731.0, 28732.0, 28733.0, 28734.0, 28735.0, 28736.0, 28737.0, 28738.0, 28739.0, 28740.0, 28741.0, 28742.0, 28743.0, 28744.0, 28745.0, 28746.0, 28747.0, 28748.0, 28749.0, 28750.0, 28751.0, 28752.0, 28753.0, 28754.0, 28755.0, 28756.0, 28757.0, 28758.0, 28759.0, 28760.0, 28761.0, 28762.0, 28763.0, 28764.0, 28765.0, 28766.0, 28767.0, 28768.0, 28769.0, 28770.0, 28771.0, 28772.0, 28773.0, 28774.0, 28775.0, 28776.0, 28777.0, 28778.0, 28779.0, 28780.0, 28781.0, 28782.0, 28783.0, 28784.0, 28785.0, 28786.0, 28787.0, 28788.0, 28789.0, 28790.0, 28791.0, 28792.0, 28793.0, 28794.0, 28795.0, 28796.0, 28797.0, 28798.0, 28799.0, 28800.0, 28801.0, 28802.0, 28803.0, 28804.0, 28805.0, 28806.0, 28807.0, 28808.0, 28809.0, 28810.0, 28811.0, 28812.0, 28813.0, 28814.0, 28815.0, 28816.0, 28817.0, 28818.0, 28819.0, 28820.0, 28821.0, 28822.0, 28823.0, 28824.0, 28825.0, 28826.0, 28827.0, 28828.0, 28829.0, 28830.0, 28831.0, 28832.0, 28833.0, 28834.0, 28835.0, 28836.0, 28837.0, 28838.0, 28839.0, 28840.0, 28841.0, 28842.0, 28843.0, 28844.0, 28845.0, 28846.0, 28847.0, 28848.0, 28849.0, 28850.0, 28851.0, 28852.0, 28853.0, 28854.0, 28855.0, 28856.0, 28857.0, 28858.0, 28859.0, 28860.0, 28861.0, 28862.0, 28863.0, 28864.0, 28865.0, 28866.0, 28867.0, 28868.0, 28869.0, 28870.0, 28871.0, 28872.0, 28873.0, 28874.0, 28875.0, 28876.0, 28877.0, 28878.0, 28879.0, 28880.0, 28881.0, 28882.0, 28883.0, 28884.0, 28885.0, 28886.0, 28887.0, 28888.0, 28889.0, 28890.0, 28891.0, 28892.0, 28893.0, 28894.0, 28895.0, 28896.0, 28897.0, 28898.0, 28899.0, 28900.0, 28901.0, 28902.0, 28903.0, 28904.0, 28905.0, 28906.0, 28907.0, 28908.0, 28909.0, 28910.0, 28911.0, 28912.0, 28913.0, 28914.0, 28915.0, 28916.0, 28917.0, 28918.0, 28919.0, 28920.0, 28921.0, 28922.0, 28923.0, 28924.0, 28925.0, 28926.0, 28927.0, 28928.0, 28929.0, 28930.0, 28931.0, 28932.0, 28933.0, 28934.0, 28935.0, 28936.0, 28937.0, 28938.0, 28939.0, 28940.0, 28941.0, 28942.0, 28943.0, 28944.0, 28945.0, 28946.0, 28947.0, 28948.0, 28949.0, 28950.0, 28951.0, 28952.0, 28953.0, 28954.0, 28955.0, 28956.0, 28957.0, 28958.0, 28959.0, 28960.0, 28961.0, 28962.0, 28963.0, 28964.0, 28965.0, 28966.0, 28967.0, 28968.0, 28969.0, 28970.0, 28971.0, 28972.0, 28973.0, 28974.0, 28975.0, 28976.0, 28977.0, 28978.0, 28979.0, 28980.0, 28981.0, 28982.0, 28983.0, 28984.0, 28985.0, 28986.0, 28987.0, 28988.0, 28989.0, 28990.0, 28991.0, 28992.0, 28993.0, 28994.0, 28995.0, 28996.0, 28997.0, 28998.0, 28999.0, 29000.0, 29001.0, 29002.0, 29003.0, 29004.0, 29005.0, 29006.0, 29007.0, 29008.0, 29009.0, 29010.0, 29011.0, 29012.0, 29013.0, 29014.0, 29015.0, 29016.0 }
    };

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_TRACE packet_in{};
    packet_in.frequency = {{ 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0, 193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0, 203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0, 213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0, 223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0, 233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0, 253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0, 263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0, 273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0, 283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0, 293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0, 303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0, 313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0, 323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0, 333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0, 343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0, 353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0, 363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0, 373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0, 383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0, 393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0, 401.0, 402.0, 403.0, 404.0, 405.0, 406.0, 407.0, 408.0, 409.0, 410.0, 411.0, 412.0, 413.0, 414.0, 415.0, 416.0, 417.0, 418.0, 419.0, 420.0, 421.0, 422.0, 423.0, 424.0, 425.0, 426.0, 427.0, 428.0, 429.0, 430.0, 431.0, 432.0, 433.0, 434.0, 435.0, 436.0, 437.0, 438.0, 439.0, 440.0, 441.0, 442.0, 443.0, 444.0, 445.0, 446.0, 447.0, 448.0, 449.0, 450.0, 451.0, 452.0, 453.0, 454.0, 455.0, 456.0, 457.0, 458.0, 459.0, 460.0, 461.0, 462.0, 463.0, 464.0, 465.0, 466.0, 467.0, 468.0, 469.0, 470.0, 471.0, 472.0, 473.0, 474.0, 475.0, 476.0, 477.0, 478.0, 479.0, 480.0, 481.0, 482.0, 483.0, 484.0, 485.0, 486.0, 487.0, 488.0, 489.0, 490.0, 491.0, 492.0, 493.0, 494.0, 495.0, 496.0, 497.0, 498.0, 499.0, 500.0, 501.0, 502.0, 503.0, 504.0, 505.0, 506.0, 507.0, 508.0, 509.0, 510.0, 511.0, 512.0, 513.0, 514.0, 515.0, 516.0, 517.0, 518.0, 519.0, 520.0, 521.0, 522.0, 523.0, 524.0, 525.0, 526.0, 527.0, 528.0, 529.0, 530.0, 531.0, 532.0, 533.0, 534.0, 535.0, 536.0, 537.0, 538.0, 539.0, 540.0, 541.0, 542.0, 543.0, 544.0, 545.0, 546.0, 547.0, 548.0, 549.0, 550.0, 551.0, 552.0, 553.0, 554.0, 555.0, 556.0, 557.0, 558.0, 559.0, 560.0, 561.0, 562.0, 563.0, 564.0, 565.0, 566.0, 567.0, 568.0, 569.0, 570.0, 571.0, 572.0, 573.0, 574.0, 575.0, 576.0, 577.0, 578.0, 579.0, 580.0, 581.0, 582.0, 583.0, 584.0, 585.0, 586.0, 587.0, 588.0, 589.0, 590.0, 591.0, 592.0, 593.0, 594.0, 595.0, 596.0, 597.0, 598.0, 599.0, 600.0, 601.0, 602.0, 603.0, 604.0, 605.0, 606.0, 607.0, 608.0, 609.0, 610.0, 611.0, 612.0, 613.0, 614.0, 615.0, 616.0, 617.0, 618.0, 619.0, 620.0, 621.0, 622.0, 623.0, 624.0, 625.0, 626.0, 627.0, 628.0, 629.0, 630.0, 631.0, 632.0, 633.0, 634.0, 635.0, 636.0, 637.0, 638.0, 639.0, 640.0, 641.0, 642.0, 643.0, 644.0, 645.0, 646.0, 647.0, 648.0, 649.0, 650.0, 651.0, 652.0, 653.0, 654.0, 655.0, 656.0, 657.0, 658.0, 659.0, 660.0, 661.0, 662.0, 663.0, 664.0, 665.0, 666.0, 667.0, 668.0, 669.0, 670.0, 671.0, 672.0, 673.0, 674.0, 675.0, 676.0, 677.0, 678.0, 679.0, 680.0, 681.0, 682.0, 683.0, 684.0, 685.0, 686.0, 687.0, 688.0, 689.0, 690.0, 691.0, 692.0, 693.0, 694.0, 695.0, 696.0, 697.0, 698.0, 699.0, 700.0, 701.0, 702.0, 703.0, 704.0, 705.0, 706.0, 707.0, 708.0, 709.0, 710.0, 711.0, 712.0, 713.0, 714.0, 715.0, 716.0, 717.0, 718.0, 719.0, 720.0, 721.0, 722.0, 723.0, 724.0, 725.0, 726.0, 727.0, 728.0, 729.0, 730.0, 731.0, 732.0, 733.0, 734.0, 735.0, 736.0, 737.0, 738.0, 739.0, 740.0, 741.0, 742.0, 743.0, 744.0, 745.0, 746.0, 747.0, 748.0, 749.0, 750.0, 751.0, 752.0, 753.0, 754.0, 755.0, 756.0, 757.0, 758.0, 759.0, 760.0, 761.0, 762.0, 763.0, 764.0, 765.0, 766.0, 767.0, 768.0, 769.0, 770.0, 771.0, 772.0, 773.0, 774.0, 775.0, 776.0, 777.0, 778.0, 779.0, 780.0, 781.0, 782.0, 783.0, 784.0, 785.0, 786.0, 787.0, 788.0, 789.0, 790.0, 791.0, 792.0, 793.0, 794.0, 795.0, 796.0, 797.0, 798.0, 799.0, 800.0, 801.0, 802.0, 803.0, 804.0, 805.0, 806.0, 807.0, 808.0, 809.0, 810.0, 811.0, 812.0, 813.0, 814.0, 815.0, 816.0, 817.0, 818.0, 819.0, 820.0, 821.0, 822.0, 823.0, 824.0, 825.0, 826.0, 827.0, 828.0, 829.0, 830.0, 831.0, 832.0, 833.0, 834.0, 835.0, 836.0, 837.0, 838.0, 839.0, 840.0, 841.0, 842.0, 843.0, 844.0, 845.0, 846.0, 847.0, 848.0, 849.0, 850.0, 851.0, 852.0, 853.0, 854.0, 855.0, 856.0, 857.0, 858.0, 859.0, 860.0, 861.0, 862.0, 863.0, 864.0, 865.0, 866.0, 867.0, 868.0, 869.0, 870.0, 871.0, 872.0, 873.0, 874.0, 875.0, 876.0, 877.0, 878.0, 879.0, 880.0, 881.0, 882.0, 883.0, 884.0, 885.0, 886.0, 887.0, 888.0, 889.0, 890.0, 891.0, 892.0, 893.0, 894.0, 895.0, 896.0, 897.0, 898.0, 899.0, 900.0, 901.0, 902.0, 903.0, 904.0, 905.0, 906.0, 907.0, 908.0, 909.0, 910.0, 911.0, 912.0, 913.0, 914.0, 915.0, 916.0, 917.0, 918.0, 919.0, 920.0, 921.0, 922.0, 923.0, 924.0, 925.0, 926.0, 927.0, 928.0, 929.0, 930.0, 931.0, 932.0, 933.0, 934.0, 935.0, 936.0, 937.0, 938.0, 939.0, 940.0, 941.0, 942.0, 943.0, 944.0, 945.0, 946.0, 947.0, 948.0, 949.0, 950.0, 951.0, 952.0, 953.0, 954.0, 955.0, 956.0, 957.0, 958.0, 959.0, 960.0, 961.0, 962.0, 963.0, 964.0, 965.0, 966.0, 967.0, 968.0, 969.0, 970.0, 971.0, 972.0, 973.0, 974.0, 975.0, 976.0, 977.0, 978.0, 979.0, 980.0, 981.0, 982.0, 983.0, 984.0, 985.0, 986.0, 987.0, 988.0, 989.0, 990.0, 991.0, 992.0, 993.0, 994.0, 995.0, 996.0, 997.0, 998.0, 999.0, 1000.0, 1001.0, 1002.0, 1003.0, 1004.0, 1005.0, 1006.0, 1007.0, 1008.0, 1009.0, 1010.0, 1011.0, 1012.0, 1013.0, 1014.0, 1015.0, 1016.0 }};
    packet_in.trace = {{ 28017.0, 28018.0, 28019.0, 28020.0, 28021.0, 28022.0, 28023.0, 28024.0, 28025.0, 28026.0, 28027.0, 28028.0, 28029.0, 28030.0, 28031.0, 28032.0, 28033.0, 28034.0, 28035.0, 28036.0, 28037.0, 28038.0, 28039.0, 28040.0, 28041.0, 28042.0, 28043.0, 28044.0, 28045.0, 28046.0, 28047.0, 28048.0, 28049.0, 28050.0, 28051.0, 28052.0, 28053.0, 28054.0, 28055.0, 28056.0, 28057.0, 28058.0, 28059.0, 28060.0, 28061.0, 28062.0, 28063.0, 28064.0, 28065.0, 28066.0, 28067.0, 28068.0, 28069.0, 28070.0, 28071.0, 28072.0, 28073.0, 28074.0, 28075.0, 28076.0, 28077.0, 28078.0, 28079.0, 28080.0, 28081.0, 28082.0, 28083.0, 28084.0, 28085.0, 28086.0, 28087.0, 28088.0, 28089.0, 28090.0, 28091.0, 28092.0, 28093.0, 28094.0, 28095.0, 28096.0, 28097.0, 28098.0, 28099.0, 28100.0, 28101.0, 28102.0, 28103.0, 28104.0, 28105.0, 28106.0, 28107.0, 28108.0, 28109.0, 28110.0, 28111.0, 28112.0, 28113.0, 28114.0, 28115.0, 28116.0, 28117.0, 28118.0, 28119.0, 28120.0, 28121.0, 28122.0, 28123.0, 28124.0, 28125.0, 28126.0, 28127.0, 28128.0, 28129.0, 28130.0, 28131.0, 28132.0, 28133.0, 28134.0, 28135.0, 28136.0, 28137.0, 28138.0, 28139.0, 28140.0, 28141.0, 28142.0, 28143.0, 28144.0, 28145.0, 28146.0, 28147.0, 28148.0, 28149.0, 28150.0, 28151.0, 28152.0, 28153.0, 28154.0, 28155.0, 28156.0, 28157.0, 28158.0, 28159.0, 28160.0, 28161.0, 28162.0, 28163.0, 28164.0, 28165.0, 28166.0, 28167.0, 28168.0, 28169.0, 28170.0, 28171.0, 28172.0, 28173.0, 28174.0, 28175.0, 28176.0, 28177.0, 28178.0, 28179.0, 28180.0, 28181.0, 28182.0, 28183.0, 28184.0, 28185.0, 28186.0, 28187.0, 28188.0, 28189.0, 28190.0, 28191.0, 28192.0, 28193.0, 28194.0, 28195.0, 28196.0, 28197.0, 28198.0, 28199.0, 28200.0, 28201.0, 28202.0, 28203.0, 28204.0, 28205.0, 28206.0, 28207.0, 28208.0, 28209.0, 28210.0, 28211.0, 28212.0, 28213.0, 28214.0, 28215.0, 28216.0, 28217.0, 28218.0, 28219.0, 28220.0, 28221.0, 28222.0, 28223.0, 28224.0, 28225.0, 28226.0, 28227.0, 28228.0, 28229.0, 28230.0, 28231.0, 28232.0, 28233.0, 28234.0, 28235.0, 28236.0, 28237.0, 28238.0, 28239.0, 28240.0, 28241.0, 28242.0, 28243.0, 28244.0, 28245.0, 28246.0, 28247.0, 28248.0, 28249.0, 28250.0, 28251.0, 28252.0, 28253.0, 28254.0, 28255.0, 28256.0, 28257.0, 28258.0, 28259.0, 28260.0, 28261.0, 28262.0, 28263.0, 28264.0, 28265.0, 28266.0, 28267.0, 28268.0, 28269.0, 28270.0, 28271.0, 28272.0, 28273.0, 28274.0, 28275.0, 28276.0, 28277.0, 28278.0, 28279.0, 28280.0, 28281.0, 28282.0, 28283.0, 28284.0, 28285.0, 28286.0, 28287.0, 28288.0, 28289.0, 28290.0, 28291.0, 28292.0, 28293.0, 28294.0, 28295.0, 28296.0, 28297.0, 28298.0, 28299.0, 28300.0, 28301.0, 28302.0, 28303.0, 28304.0, 28305.0, 28306.0, 28307.0, 28308.0, 28309.0, 28310.0, 28311.0, 28312.0, 28313.0, 28314.0, 28315.0, 28316.0, 28317.0, 28318.0, 28319.0, 28320.0, 28321.0, 28322.0, 28323.0, 28324.0, 28325.0, 28326.0, 28327.0, 28328.0, 28329.0, 28330.0, 28331.0, 28332.0, 28333.0, 28334.0, 28335.0, 28336.0, 28337.0, 28338.0, 28339.0, 28340.0, 28341.0, 28342.0, 28343.0, 28344.0, 28345.0, 28346.0, 28347.0, 28348.0, 28349.0, 28350.0, 28351.0, 28352.0, 28353.0, 28354.0, 28355.0, 28356.0, 28357.0, 28358.0, 28359.0, 28360.0, 28361.0, 28362.0, 28363.0, 28364.0, 28365.0, 28366.0, 28367.0, 28368.0, 28369.0, 28370.0, 28371.0, 28372.0, 28373.0, 28374.0, 28375.0, 28376.0, 28377.0, 28378.0, 28379.0, 28380.0, 28381.0, 28382.0, 28383.0, 28384.0, 28385.0, 28386.0, 28387.0, 28388.0, 28389.0, 28390.0, 28391.0, 28392.0, 28393.0, 28394.0, 28395.0, 28396.0, 28397.0, 28398.0, 28399.0, 28400.0, 28401.0, 28402.0, 28403.0, 28404.0, 28405.0, 28406.0, 28407.0, 28408.0, 28409.0, 28410.0, 28411.0, 28412.0, 28413.0, 28414.0, 28415.0, 28416.0, 28417.0, 28418.0, 28419.0, 28420.0, 28421.0, 28422.0, 28423.0, 28424.0, 28425.0, 28426.0, 28427.0, 28428.0, 28429.0, 28430.0, 28431.0, 28432.0, 28433.0, 28434.0, 28435.0, 28436.0, 28437.0, 28438.0, 28439.0, 28440.0, 28441.0, 28442.0, 28443.0, 28444.0, 28445.0, 28446.0, 28447.0, 28448.0, 28449.0, 28450.0, 28451.0, 28452.0, 28453.0, 28454.0, 28455.0, 28456.0, 28457.0, 28458.0, 28459.0, 28460.0, 28461.0, 28462.0, 28463.0, 28464.0, 28465.0, 28466.0, 28467.0, 28468.0, 28469.0, 28470.0, 28471.0, 28472.0, 28473.0, 28474.0, 28475.0, 28476.0, 28477.0, 28478.0, 28479.0, 28480.0, 28481.0, 28482.0, 28483.0, 28484.0, 28485.0, 28486.0, 28487.0, 28488.0, 28489.0, 28490.0, 28491.0, 28492.0, 28493.0, 28494.0, 28495.0, 28496.0, 28497.0, 28498.0, 28499.0, 28500.0, 28501.0, 28502.0, 28503.0, 28504.0, 28505.0, 28506.0, 28507.0, 28508.0, 28509.0, 28510.0, 28511.0, 28512.0, 28513.0, 28514.0, 28515.0, 28516.0, 28517.0, 28518.0, 28519.0, 28520.0, 28521.0, 28522.0, 28523.0, 28524.0, 28525.0, 28526.0, 28527.0, 28528.0, 28529.0, 28530.0, 28531.0, 28532.0, 28533.0, 28534.0, 28535.0, 28536.0, 28537.0, 28538.0, 28539.0, 28540.0, 28541.0, 28542.0, 28543.0, 28544.0, 28545.0, 28546.0, 28547.0, 28548.0, 28549.0, 28550.0, 28551.0, 28552.0, 28553.0, 28554.0, 28555.0, 28556.0, 28557.0, 28558.0, 28559.0, 28560.0, 28561.0, 28562.0, 28563.0, 28564.0, 28565.0, 28566.0, 28567.0, 28568.0, 28569.0, 28570.0, 28571.0, 28572.0, 28573.0, 28574.0, 28575.0, 28576.0, 28577.0, 28578.0, 28579.0, 28580.0, 28581.0, 28582.0, 28583.0, 28584.0, 28585.0, 28586.0, 28587.0, 28588.0, 28589.0, 28590.0, 28591.0, 28592.0, 28593.0, 28594.0, 28595.0, 28596.0, 28597.0, 28598.0, 28599.0, 28600.0, 28601.0, 28602.0, 28603.0, 28604.0, 28605.0, 28606.0, 28607.0, 28608.0, 28609.0, 28610.0, 28611.0, 28612.0, 28613.0, 28614.0, 28615.0, 28616.0, 28617.0, 28618.0, 28619.0, 28620.0, 28621.0, 28622.0, 28623.0, 28624.0, 28625.0, 28626.0, 28627.0, 28628.0, 28629.0, 28630.0, 28631.0, 28632.0, 28633.0, 28634.0, 28635.0, 28636.0, 28637.0, 28638.0, 28639.0, 28640.0, 28641.0, 28642.0, 28643.0, 28644.0, 28645.0, 28646.0, 28647.0, 28648.0, 28649.0, 28650.0, 28651.0, 28652.0, 28653.0, 28654.0, 28655.0, 28656.0, 28657.0, 28658.0, 28659.0, 28660.0, 28661.0, 28662.0, 28663.0, 28664.0, 28665.0, 28666.0, 28667.0, 28668.0, 28669.0, 28670.0, 28671.0, 28672.0, 28673.0, 28674.0, 28675.0, 28676.0, 28677.0, 28678.0, 28679.0, 28680.0, 28681.0, 28682.0, 28683.0, 28684.0, 28685.0, 28686.0, 28687.0, 28688.0, 28689.0, 28690.0, 28691.0, 28692.0, 28693.0, 28694.0, 28695.0, 28696.0, 28697.0, 28698.0, 28699.0, 28700.0, 28701.0, 28702.0, 28703.0, 28704.0, 28705.0, 28706.0, 28707.0, 28708.0, 28709.0, 28710.0, 28711.0, 28712.0, 28713.0, 28714.0, 28715.0, 28716.0, 28717.0, 28718.0, 28719.0, 28720.0, 28721.0, 28722.0, 28723.0, 28724.0, 28725.0, 28726.0, 28727.0, 28728.0, 28729.0, 28730.0, 28731.0, 28732.0, 28733.0, 28734.0, 28735.0, 28736.0, 28737.0, 28738.0, 28739.0, 28740.0, 28741.0, 28742.0, 28743.0, 28744.0, 28745.0, 28746.0, 28747.0, 28748.0, 28749.0, 28750.0, 28751.0, 28752.0, 28753.0, 28754.0, 28755.0, 28756.0, 28757.0, 28758.0, 28759.0, 28760.0, 28761.0, 28762.0, 28763.0, 28764.0, 28765.0, 28766.0, 28767.0, 28768.0, 28769.0, 28770.0, 28771.0, 28772.0, 28773.0, 28774.0, 28775.0, 28776.0, 28777.0, 28778.0, 28779.0, 28780.0, 28781.0, 28782.0, 28783.0, 28784.0, 28785.0, 28786.0, 28787.0, 28788.0, 28789.0, 28790.0, 28791.0, 28792.0, 28793.0, 28794.0, 28795.0, 28796.0, 28797.0, 28798.0, 28799.0, 28800.0, 28801.0, 28802.0, 28803.0, 28804.0, 28805.0, 28806.0, 28807.0, 28808.0, 28809.0, 28810.0, 28811.0, 28812.0, 28813.0, 28814.0, 28815.0, 28816.0, 28817.0, 28818.0, 28819.0, 28820.0, 28821.0, 28822.0, 28823.0, 28824.0, 28825.0, 28826.0, 28827.0, 28828.0, 28829.0, 28830.0, 28831.0, 28832.0, 28833.0, 28834.0, 28835.0, 28836.0, 28837.0, 28838.0, 28839.0, 28840.0, 28841.0, 28842.0, 28843.0, 28844.0, 28845.0, 28846.0, 28847.0, 28848.0, 28849.0, 28850.0, 28851.0, 28852.0, 28853.0, 28854.0, 28855.0, 28856.0, 28857.0, 28858.0, 28859.0, 28860.0, 28861.0, 28862.0, 28863.0, 28864.0, 28865.0, 28866.0, 28867.0, 28868.0, 28869.0, 28870.0, 28871.0, 28872.0, 28873.0, 28874.0, 28875.0, 28876.0, 28877.0, 28878.0, 28879.0, 28880.0, 28881.0, 28882.0, 28883.0, 28884.0, 28885.0, 28886.0, 28887.0, 28888.0, 28889.0, 28890.0, 28891.0, 28892.0, 28893.0, 28894.0, 28895.0, 28896.0, 28897.0, 28898.0, 28899.0, 28900.0, 28901.0, 28902.0, 28903.0, 28904.0, 28905.0, 28906.0, 28907.0, 28908.0, 28909.0, 28910.0, 28911.0, 28912.0, 28913.0, 28914.0, 28915.0, 28916.0, 28917.0, 28918.0, 28919.0, 28920.0, 28921.0, 28922.0, 28923.0, 28924.0, 28925.0, 28926.0, 28927.0, 28928.0, 28929.0, 28930.0, 28931.0, 28932.0, 28933.0, 28934.0, 28935.0, 28936.0, 28937.0, 28938.0, 28939.0, 28940.0, 28941.0, 28942.0, 28943.0, 28944.0, 28945.0, 28946.0, 28947.0, 28948.0, 28949.0, 28950.0, 28951.0, 28952.0, 28953.0, 28954.0, 28955.0, 28956.0, 28957.0, 28958.0, 28959.0, 28960.0, 28961.0, 28962.0, 28963.0, 28964.0, 28965.0, 28966.0, 28967.0, 28968.0, 28969.0, 28970.0, 28971.0, 28972.0, 28973.0, 28974.0, 28975.0, 28976.0, 28977.0, 28978.0, 28979.0, 28980.0, 28981.0, 28982.0, 28983.0, 28984.0, 28985.0, 28986.0, 28987.0, 28988.0, 28989.0, 28990.0, 28991.0, 28992.0, 28993.0, 28994.0, 28995.0, 28996.0, 28997.0, 28998.0, 28999.0, 29000.0, 29001.0, 29002.0, 29003.0, 29004.0, 29005.0, 29006.0, 29007.0, 29008.0, 29009.0, 29010.0, 29011.0, 29012.0, 29013.0, 29014.0, 29015.0, 29016.0 }};

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_TRACE packet2{};

    mavlink_msg_oaire_rfsensor_trace_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.frequency, packet2.frequency);
    EXPECT_EQ(packet_in.trace, packet2.trace);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(ardupilotmega, OAIRE_RFSENSOR_CHPOWER)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_CHPOWER packet_in{};
    packet_in.frq = 17.0;
    packet_in.chpower = 45.0;

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_CHPOWER packet1{};
    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_CHPOWER packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.frq, packet2.frq);
    EXPECT_EQ(packet1.chpower, packet2.chpower);
}

#ifdef TEST_INTEROP
TEST(ardupilotmega_interop, OAIRE_RFSENSOR_CHPOWER)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_oaire_rfsensor_chpower_t packet_c {
         17.0, 45.0
    };

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_CHPOWER packet_in{};
    packet_in.frq = 17.0;
    packet_in.chpower = 45.0;

    mavlink::ardupilotmega::msg::OAIRE_RFSENSOR_CHPOWER packet2{};

    mavlink_msg_oaire_rfsensor_chpower_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.frq, packet2.frq);
    EXPECT_EQ(packet_in.chpower, packet2.chpower);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

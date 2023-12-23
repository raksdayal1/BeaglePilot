/** @file
 *    @brief MAVLink comm protocol testsuite generated from ardupilotmega.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef ARDUPILOTMEGA_TESTSUITE_H
#define ARDUPILOTMEGA_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_uAvionix(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_icarous(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_cubepilot(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_csAirLink(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ardupilotmega(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_uAvionix(system_id, component_id, last_msg);
    mavlink_test_icarous(system_id, component_id, last_msg);
    mavlink_test_cubepilot(system_id, component_id, last_msg);
    mavlink_test_csAirLink(system_id, component_id, last_msg);
    mavlink_test_ardupilotmega(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"
#include "../uAvionix/testsuite.h"
#include "../icarous/testsuite.h"
#include "../cubepilot/testsuite.h"
#include "../csAirLink/testsuite.h"


static void mavlink_test_sensor_offsets(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SENSOR_OFFSETS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_sensor_offsets_t packet_in = {
        17.0,963497672,963497880,101.0,129.0,157.0,185.0,213.0,241.0,19107,19211,19315
    };
    mavlink_sensor_offsets_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mag_declination = packet_in.mag_declination;
        packet1.raw_press = packet_in.raw_press;
        packet1.raw_temp = packet_in.raw_temp;
        packet1.gyro_cal_x = packet_in.gyro_cal_x;
        packet1.gyro_cal_y = packet_in.gyro_cal_y;
        packet1.gyro_cal_z = packet_in.gyro_cal_z;
        packet1.accel_cal_x = packet_in.accel_cal_x;
        packet1.accel_cal_y = packet_in.accel_cal_y;
        packet1.accel_cal_z = packet_in.accel_cal_z;
        packet1.mag_ofs_x = packet_in.mag_ofs_x;
        packet1.mag_ofs_y = packet_in.mag_ofs_y;
        packet1.mag_ofs_z = packet_in.mag_ofs_z;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SENSOR_OFFSETS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SENSOR_OFFSETS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_offsets_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_sensor_offsets_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_offsets_pack(system_id, component_id, &msg , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
    mavlink_msg_sensor_offsets_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_offsets_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
    mavlink_msg_sensor_offsets_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_sensor_offsets_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_sensor_offsets_send(MAVLINK_COMM_1 , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z , packet1.mag_declination , packet1.raw_press , packet1.raw_temp , packet1.gyro_cal_x , packet1.gyro_cal_y , packet1.gyro_cal_z , packet1.accel_cal_x , packet1.accel_cal_y , packet1.accel_cal_z );
    mavlink_msg_sensor_offsets_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SENSOR_OFFSETS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SENSOR_OFFSETS) != NULL);
#endif
}

static void mavlink_test_set_mag_offsets(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SET_MAG_OFFSETS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_set_mag_offsets_t packet_in = {
        17235,17339,17443,151,218
    };
    mavlink_set_mag_offsets_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mag_ofs_x = packet_in.mag_ofs_x;
        packet1.mag_ofs_y = packet_in.mag_ofs_y;
        packet1.mag_ofs_z = packet_in.mag_ofs_z;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SET_MAG_OFFSETS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SET_MAG_OFFSETS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_mag_offsets_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_set_mag_offsets_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_mag_offsets_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
    mavlink_msg_set_mag_offsets_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_mag_offsets_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
    mavlink_msg_set_mag_offsets_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_set_mag_offsets_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_mag_offsets_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.mag_ofs_x , packet1.mag_ofs_y , packet1.mag_ofs_z );
    mavlink_msg_set_mag_offsets_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SET_MAG_OFFSETS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SET_MAG_OFFSETS) != NULL);
#endif
}

static void mavlink_test_meminfo(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MEMINFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_meminfo_t packet_in = {
        17235,17339,963497672
    };
    mavlink_meminfo_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.brkval = packet_in.brkval;
        packet1.freemem = packet_in.freemem;
        packet1.freemem32 = packet_in.freemem32;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MEMINFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MEMINFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_meminfo_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_meminfo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_meminfo_pack(system_id, component_id, &msg , packet1.brkval , packet1.freemem , packet1.freemem32 );
    mavlink_msg_meminfo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_meminfo_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.brkval , packet1.freemem , packet1.freemem32 );
    mavlink_msg_meminfo_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_meminfo_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_meminfo_send(MAVLINK_COMM_1 , packet1.brkval , packet1.freemem , packet1.freemem32 );
    mavlink_msg_meminfo_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MEMINFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MEMINFO) != NULL);
#endif
}

static void mavlink_test_ap_adc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AP_ADC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ap_adc_t packet_in = {
        17235,17339,17443,17547,17651,17755
    };
    mavlink_ap_adc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.adc1 = packet_in.adc1;
        packet1.adc2 = packet_in.adc2;
        packet1.adc3 = packet_in.adc3;
        packet1.adc4 = packet_in.adc4;
        packet1.adc5 = packet_in.adc5;
        packet1.adc6 = packet_in.adc6;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AP_ADC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AP_ADC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ap_adc_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ap_adc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ap_adc_pack(system_id, component_id, &msg , packet1.adc1 , packet1.adc2 , packet1.adc3 , packet1.adc4 , packet1.adc5 , packet1.adc6 );
    mavlink_msg_ap_adc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ap_adc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.adc1 , packet1.adc2 , packet1.adc3 , packet1.adc4 , packet1.adc5 , packet1.adc6 );
    mavlink_msg_ap_adc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ap_adc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ap_adc_send(MAVLINK_COMM_1 , packet1.adc1 , packet1.adc2 , packet1.adc3 , packet1.adc4 , packet1.adc5 , packet1.adc6 );
    mavlink_msg_ap_adc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AP_ADC") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AP_ADC) != NULL);
#endif
}

static void mavlink_test_digicam_configure(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DIGICAM_CONFIGURE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_digicam_configure_t packet_in = {
        17.0,17443,151,218,29,96,163,230,41,108,175
    };
    mavlink_digicam_configure_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.extra_value = packet_in.extra_value;
        packet1.shutter_speed = packet_in.shutter_speed;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.mode = packet_in.mode;
        packet1.aperture = packet_in.aperture;
        packet1.iso = packet_in.iso;
        packet1.exposure_type = packet_in.exposure_type;
        packet1.command_id = packet_in.command_id;
        packet1.engine_cut_off = packet_in.engine_cut_off;
        packet1.extra_param = packet_in.extra_param;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DIGICAM_CONFIGURE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DIGICAM_CONFIGURE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_configure_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_digicam_configure_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_configure_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.mode , packet1.shutter_speed , packet1.aperture , packet1.iso , packet1.exposure_type , packet1.command_id , packet1.engine_cut_off , packet1.extra_param , packet1.extra_value );
    mavlink_msg_digicam_configure_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_configure_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.mode , packet1.shutter_speed , packet1.aperture , packet1.iso , packet1.exposure_type , packet1.command_id , packet1.engine_cut_off , packet1.extra_param , packet1.extra_value );
    mavlink_msg_digicam_configure_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_digicam_configure_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_configure_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.mode , packet1.shutter_speed , packet1.aperture , packet1.iso , packet1.exposure_type , packet1.command_id , packet1.engine_cut_off , packet1.extra_param , packet1.extra_value );
    mavlink_msg_digicam_configure_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DIGICAM_CONFIGURE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DIGICAM_CONFIGURE) != NULL);
#endif
}

static void mavlink_test_digicam_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DIGICAM_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_digicam_control_t packet_in = {
        17.0,17,84,151,218,29,96,163,230,41
    };
    mavlink_digicam_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.extra_value = packet_in.extra_value;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.session = packet_in.session;
        packet1.zoom_pos = packet_in.zoom_pos;
        packet1.zoom_step = packet_in.zoom_step;
        packet1.focus_lock = packet_in.focus_lock;
        packet1.shot = packet_in.shot;
        packet1.command_id = packet_in.command_id;
        packet1.extra_param = packet_in.extra_param;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DIGICAM_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DIGICAM_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_digicam_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_control_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.session , packet1.zoom_pos , packet1.zoom_step , packet1.focus_lock , packet1.shot , packet1.command_id , packet1.extra_param , packet1.extra_value );
    mavlink_msg_digicam_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.session , packet1.zoom_pos , packet1.zoom_step , packet1.focus_lock , packet1.shot , packet1.command_id , packet1.extra_param , packet1.extra_value );
    mavlink_msg_digicam_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_digicam_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_digicam_control_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.session , packet1.zoom_pos , packet1.zoom_step , packet1.focus_lock , packet1.shot , packet1.command_id , packet1.extra_param , packet1.extra_value );
    mavlink_msg_digicam_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DIGICAM_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DIGICAM_CONTROL) != NULL);
#endif
}

static void mavlink_test_mount_configure(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOUNT_CONFIGURE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mount_configure_t packet_in = {
        5,72,139,206,17,84
    };
    mavlink_mount_configure_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.mount_mode = packet_in.mount_mode;
        packet1.stab_roll = packet_in.stab_roll;
        packet1.stab_pitch = packet_in.stab_pitch;
        packet1.stab_yaw = packet_in.stab_yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOUNT_CONFIGURE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOUNT_CONFIGURE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_configure_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mount_configure_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_configure_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.mount_mode , packet1.stab_roll , packet1.stab_pitch , packet1.stab_yaw );
    mavlink_msg_mount_configure_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_configure_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.mount_mode , packet1.stab_roll , packet1.stab_pitch , packet1.stab_yaw );
    mavlink_msg_mount_configure_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mount_configure_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_configure_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.mount_mode , packet1.stab_roll , packet1.stab_pitch , packet1.stab_yaw );
    mavlink_msg_mount_configure_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MOUNT_CONFIGURE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MOUNT_CONFIGURE) != NULL);
#endif
}

static void mavlink_test_mount_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOUNT_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mount_control_t packet_in = {
        963497464,963497672,963497880,41,108,175
    };
    mavlink_mount_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.input_a = packet_in.input_a;
        packet1.input_b = packet_in.input_b;
        packet1.input_c = packet_in.input_c;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.save_position = packet_in.save_position;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOUNT_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOUNT_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mount_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_control_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.input_a , packet1.input_b , packet1.input_c , packet1.save_position );
    mavlink_msg_mount_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.input_a , packet1.input_b , packet1.input_c , packet1.save_position );
    mavlink_msg_mount_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mount_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_control_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.input_a , packet1.input_b , packet1.input_c , packet1.save_position );
    mavlink_msg_mount_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MOUNT_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MOUNT_CONTROL) != NULL);
#endif
}

static void mavlink_test_mount_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOUNT_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mount_status_t packet_in = {
        963497464,963497672,963497880,41,108,175
    };
    mavlink_mount_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pointing_a = packet_in.pointing_a;
        packet1.pointing_b = packet_in.pointing_b;
        packet1.pointing_c = packet_in.pointing_c;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.mount_mode = packet_in.mount_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOUNT_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOUNT_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mount_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_status_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.pointing_a , packet1.pointing_b , packet1.pointing_c , packet1.mount_mode );
    mavlink_msg_mount_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.pointing_a , packet1.pointing_b , packet1.pointing_c , packet1.mount_mode );
    mavlink_msg_mount_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mount_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mount_status_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.pointing_a , packet1.pointing_b , packet1.pointing_c , packet1.mount_mode );
    mavlink_msg_mount_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MOUNT_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MOUNT_STATUS) != NULL);
#endif
}

static void mavlink_test_fence_point(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FENCE_POINT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fence_point_t packet_in = {
        17.0,45.0,29,96,163,230
    };
    mavlink_fence_point_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.idx = packet_in.idx;
        packet1.count = packet_in.count;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FENCE_POINT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FENCE_POINT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_point_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fence_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_point_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.idx , packet1.count , packet1.lat , packet1.lng );
    mavlink_msg_fence_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_point_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.idx , packet1.count , packet1.lat , packet1.lng );
    mavlink_msg_fence_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fence_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_point_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.idx , packet1.count , packet1.lat , packet1.lng );
    mavlink_msg_fence_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FENCE_POINT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FENCE_POINT) != NULL);
#endif
}

static void mavlink_test_fence_fetch_point(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FENCE_FETCH_POINT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fence_fetch_point_t packet_in = {
        5,72,139
    };
    mavlink_fence_fetch_point_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.idx = packet_in.idx;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FENCE_FETCH_POINT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FENCE_FETCH_POINT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_fetch_point_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fence_fetch_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_fetch_point_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.idx );
    mavlink_msg_fence_fetch_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_fetch_point_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.idx );
    mavlink_msg_fence_fetch_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fence_fetch_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fence_fetch_point_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.idx );
    mavlink_msg_fence_fetch_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FENCE_FETCH_POINT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FENCE_FETCH_POINT) != NULL);
#endif
}

static void mavlink_test_ahrs(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AHRS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ahrs_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0
    };
    mavlink_ahrs_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.omegaIx = packet_in.omegaIx;
        packet1.omegaIy = packet_in.omegaIy;
        packet1.omegaIz = packet_in.omegaIz;
        packet1.accel_weight = packet_in.accel_weight;
        packet1.renorm_val = packet_in.renorm_val;
        packet1.error_rp = packet_in.error_rp;
        packet1.error_yaw = packet_in.error_yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AHRS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AHRS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_pack(system_id, component_id, &msg , packet1.omegaIx , packet1.omegaIy , packet1.omegaIz , packet1.accel_weight , packet1.renorm_val , packet1.error_rp , packet1.error_yaw );
    mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.omegaIx , packet1.omegaIy , packet1.omegaIz , packet1.accel_weight , packet1.renorm_val , packet1.error_rp , packet1.error_yaw );
    mavlink_msg_ahrs_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs_send(MAVLINK_COMM_1 , packet1.omegaIx , packet1.omegaIy , packet1.omegaIz , packet1.accel_weight , packet1.renorm_val , packet1.error_rp , packet1.error_yaw );
    mavlink_msg_ahrs_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AHRS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AHRS) != NULL);
#endif
}

static void mavlink_test_simstate(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SIMSTATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_simstate_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,963499336,963499544
    };
    mavlink_simstate_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.xacc = packet_in.xacc;
        packet1.yacc = packet_in.yacc;
        packet1.zacc = packet_in.zacc;
        packet1.xgyro = packet_in.xgyro;
        packet1.ygyro = packet_in.ygyro;
        packet1.zgyro = packet_in.zgyro;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SIMSTATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SIMSTATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_simstate_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_simstate_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_simstate_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.lat , packet1.lng );
    mavlink_msg_simstate_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_simstate_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.lat , packet1.lng );
    mavlink_msg_simstate_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_simstate_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_simstate_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro , packet1.lat , packet1.lng );
    mavlink_msg_simstate_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SIMSTATE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SIMSTATE) != NULL);
#endif
}

static void mavlink_test_hwstatus(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HWSTATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_hwstatus_t packet_in = {
        17235,139
    };
    mavlink_hwstatus_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.Vcc = packet_in.Vcc;
        packet1.I2Cerr = packet_in.I2Cerr;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HWSTATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HWSTATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hwstatus_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_hwstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hwstatus_pack(system_id, component_id, &msg , packet1.Vcc , packet1.I2Cerr );
    mavlink_msg_hwstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hwstatus_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.Vcc , packet1.I2Cerr );
    mavlink_msg_hwstatus_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_hwstatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_hwstatus_send(MAVLINK_COMM_1 , packet1.Vcc , packet1.I2Cerr );
    mavlink_msg_hwstatus_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("HWSTATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_HWSTATUS) != NULL);
#endif
}

static void mavlink_test_radio(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radio_t packet_in = {
        17235,17339,17,84,151,218,29
    };
    mavlink_radio_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rxerrors = packet_in.rxerrors;
        packet1.fixed = packet_in.fixed;
        packet1.rssi = packet_in.rssi;
        packet1.remrssi = packet_in.remrssi;
        packet1.txbuf = packet_in.txbuf;
        packet1.noise = packet_in.noise;
        packet1.remnoise = packet_in.remnoise;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radio_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_pack(system_id, component_id, &msg , packet1.rssi , packet1.remrssi , packet1.txbuf , packet1.noise , packet1.remnoise , packet1.rxerrors , packet1.fixed );
    mavlink_msg_radio_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.rssi , packet1.remrssi , packet1.txbuf , packet1.noise , packet1.remnoise , packet1.rxerrors , packet1.fixed );
    mavlink_msg_radio_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radio_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_send(MAVLINK_COMM_1 , packet1.rssi , packet1.remrssi , packet1.txbuf , packet1.noise , packet1.remnoise , packet1.rxerrors , packet1.fixed );
    mavlink_msg_radio_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIO) != NULL);
#endif
}

static void mavlink_test_limits_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LIMITS_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_limits_status_t packet_in = {
        963497464,963497672,963497880,963498088,18067,187,254,65,132
    };
    mavlink_limits_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.last_trigger = packet_in.last_trigger;
        packet1.last_action = packet_in.last_action;
        packet1.last_recovery = packet_in.last_recovery;
        packet1.last_clear = packet_in.last_clear;
        packet1.breach_count = packet_in.breach_count;
        packet1.limits_state = packet_in.limits_state;
        packet1.mods_enabled = packet_in.mods_enabled;
        packet1.mods_required = packet_in.mods_required;
        packet1.mods_triggered = packet_in.mods_triggered;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_limits_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_limits_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_limits_status_pack(system_id, component_id, &msg , packet1.limits_state , packet1.last_trigger , packet1.last_action , packet1.last_recovery , packet1.last_clear , packet1.breach_count , packet1.mods_enabled , packet1.mods_required , packet1.mods_triggered );
    mavlink_msg_limits_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_limits_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.limits_state , packet1.last_trigger , packet1.last_action , packet1.last_recovery , packet1.last_clear , packet1.breach_count , packet1.mods_enabled , packet1.mods_required , packet1.mods_triggered );
    mavlink_msg_limits_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_limits_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_limits_status_send(MAVLINK_COMM_1 , packet1.limits_state , packet1.last_trigger , packet1.last_action , packet1.last_recovery , packet1.last_clear , packet1.breach_count , packet1.mods_enabled , packet1.mods_required , packet1.mods_triggered );
    mavlink_msg_limits_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LIMITS_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LIMITS_STATUS) != NULL);
#endif
}

static void mavlink_test_wind(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WIND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wind_t packet_in = {
        17.0,45.0,73.0
    };
    mavlink_wind_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.direction = packet_in.direction;
        packet1.speed = packet_in.speed;
        packet1.speed_z = packet_in.speed_z;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WIND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WIND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wind_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_pack(system_id, component_id, &msg , packet1.direction , packet1.speed , packet1.speed_z );
    mavlink_msg_wind_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.direction , packet1.speed , packet1.speed_z );
    mavlink_msg_wind_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wind_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_send(MAVLINK_COMM_1 , packet1.direction , packet1.speed , packet1.speed_z );
    mavlink_msg_wind_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WIND") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WIND) != NULL);
#endif
}

static void mavlink_test_data16(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA16 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_data16_t packet_in = {
        5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154 }
    };
    mavlink_data16_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        packet1.len = packet_in.len;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA16_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA16_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data16_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_data16_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data16_pack(system_id, component_id, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data16_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data16_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data16_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_data16_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data16_send(MAVLINK_COMM_1 , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data16_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DATA16") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DATA16) != NULL);
#endif
}

static void mavlink_test_data32(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA32 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_data32_t packet_in = {
        5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170 }
    };
    mavlink_data32_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        packet1.len = packet_in.len;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA32_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA32_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data32_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_data32_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data32_pack(system_id, component_id, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data32_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data32_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data32_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_data32_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data32_send(MAVLINK_COMM_1 , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data32_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DATA32") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DATA32) != NULL);
#endif
}

static void mavlink_test_data64(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA64 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_data64_t packet_in = {
        5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202 }
    };
    mavlink_data64_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        packet1.len = packet_in.len;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*64);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA64_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA64_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data64_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_data64_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data64_pack(system_id, component_id, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data64_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data64_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data64_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_data64_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data64_send(MAVLINK_COMM_1 , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data64_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DATA64") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DATA64) != NULL);
#endif
}

static void mavlink_test_data96(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DATA96 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_data96_t packet_in = {
        5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234 }
    };
    mavlink_data96_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.type = packet_in.type;
        packet1.len = packet_in.len;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*96);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DATA96_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DATA96_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data96_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_data96_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data96_pack(system_id, component_id, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data96_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data96_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data96_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_data96_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_data96_send(MAVLINK_COMM_1 , packet1.type , packet1.len , packet1.data );
    mavlink_msg_data96_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DATA96") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DATA96) != NULL);
#endif
}

static void mavlink_test_rangefinder(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RANGEFINDER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rangefinder_t packet_in = {
        17.0,45.0
    };
    mavlink_rangefinder_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.distance = packet_in.distance;
        packet1.voltage = packet_in.voltage;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RANGEFINDER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RANGEFINDER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rangefinder_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rangefinder_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rangefinder_pack(system_id, component_id, &msg , packet1.distance , packet1.voltage );
    mavlink_msg_rangefinder_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rangefinder_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.distance , packet1.voltage );
    mavlink_msg_rangefinder_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rangefinder_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rangefinder_send(MAVLINK_COMM_1 , packet1.distance , packet1.voltage );
    mavlink_msg_rangefinder_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RANGEFINDER") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RANGEFINDER) != NULL);
#endif
}

static void mavlink_test_airspeed_autocal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AIRSPEED_AUTOCAL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_airspeed_autocal_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0
    };
    mavlink_airspeed_autocal_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.vx = packet_in.vx;
        packet1.vy = packet_in.vy;
        packet1.vz = packet_in.vz;
        packet1.diff_pressure = packet_in.diff_pressure;
        packet1.EAS2TAS = packet_in.EAS2TAS;
        packet1.ratio = packet_in.ratio;
        packet1.state_x = packet_in.state_x;
        packet1.state_y = packet_in.state_y;
        packet1.state_z = packet_in.state_z;
        packet1.Pax = packet_in.Pax;
        packet1.Pby = packet_in.Pby;
        packet1.Pcz = packet_in.Pcz;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AIRSPEED_AUTOCAL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AIRSPEED_AUTOCAL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_autocal_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_airspeed_autocal_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_autocal_pack(system_id, component_id, &msg , packet1.vx , packet1.vy , packet1.vz , packet1.diff_pressure , packet1.EAS2TAS , packet1.ratio , packet1.state_x , packet1.state_y , packet1.state_z , packet1.Pax , packet1.Pby , packet1.Pcz );
    mavlink_msg_airspeed_autocal_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_autocal_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.vx , packet1.vy , packet1.vz , packet1.diff_pressure , packet1.EAS2TAS , packet1.ratio , packet1.state_x , packet1.state_y , packet1.state_z , packet1.Pax , packet1.Pby , packet1.Pcz );
    mavlink_msg_airspeed_autocal_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_airspeed_autocal_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_autocal_send(MAVLINK_COMM_1 , packet1.vx , packet1.vy , packet1.vz , packet1.diff_pressure , packet1.EAS2TAS , packet1.ratio , packet1.state_x , packet1.state_y , packet1.state_z , packet1.Pax , packet1.Pby , packet1.Pcz );
    mavlink_msg_airspeed_autocal_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AIRSPEED_AUTOCAL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AIRSPEED_AUTOCAL) != NULL);
#endif
}

static void mavlink_test_rally_point(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RALLY_POINT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rally_point_t packet_in = {
        963497464,963497672,17651,17755,17859,175,242,53,120,187
    };
    mavlink_rally_point_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.alt = packet_in.alt;
        packet1.break_alt = packet_in.break_alt;
        packet1.land_dir = packet_in.land_dir;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.idx = packet_in.idx;
        packet1.count = packet_in.count;
        packet1.flags = packet_in.flags;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RALLY_POINT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RALLY_POINT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_point_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rally_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_point_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.idx , packet1.count , packet1.lat , packet1.lng , packet1.alt , packet1.break_alt , packet1.land_dir , packet1.flags );
    mavlink_msg_rally_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_point_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.idx , packet1.count , packet1.lat , packet1.lng , packet1.alt , packet1.break_alt , packet1.land_dir , packet1.flags );
    mavlink_msg_rally_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rally_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_point_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.idx , packet1.count , packet1.lat , packet1.lng , packet1.alt , packet1.break_alt , packet1.land_dir , packet1.flags );
    mavlink_msg_rally_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RALLY_POINT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RALLY_POINT) != NULL);
#endif
}

static void mavlink_test_rally_fetch_point(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RALLY_FETCH_POINT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rally_fetch_point_t packet_in = {
        5,72,139
    };
    mavlink_rally_fetch_point_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.idx = packet_in.idx;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RALLY_FETCH_POINT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RALLY_FETCH_POINT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_fetch_point_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rally_fetch_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_fetch_point_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.idx );
    mavlink_msg_rally_fetch_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_fetch_point_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.idx );
    mavlink_msg_rally_fetch_point_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rally_fetch_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rally_fetch_point_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.idx );
    mavlink_msg_rally_fetch_point_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RALLY_FETCH_POINT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RALLY_FETCH_POINT) != NULL);
#endif
}

static void mavlink_test_compassmot_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_COMPASSMOT_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_compassmot_status_t packet_in = {
        17.0,45.0,73.0,101.0,18067,18171
    };
    mavlink_compassmot_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.current = packet_in.current;
        packet1.CompensationX = packet_in.CompensationX;
        packet1.CompensationY = packet_in.CompensationY;
        packet1.CompensationZ = packet_in.CompensationZ;
        packet1.throttle = packet_in.throttle;
        packet1.interference = packet_in.interference;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_COMPASSMOT_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_COMPASSMOT_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_compassmot_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_compassmot_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_compassmot_status_pack(system_id, component_id, &msg , packet1.throttle , packet1.current , packet1.interference , packet1.CompensationX , packet1.CompensationY , packet1.CompensationZ );
    mavlink_msg_compassmot_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_compassmot_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.throttle , packet1.current , packet1.interference , packet1.CompensationX , packet1.CompensationY , packet1.CompensationZ );
    mavlink_msg_compassmot_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_compassmot_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_compassmot_status_send(MAVLINK_COMM_1 , packet1.throttle , packet1.current , packet1.interference , packet1.CompensationX , packet1.CompensationY , packet1.CompensationZ );
    mavlink_msg_compassmot_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("COMPASSMOT_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_COMPASSMOT_STATUS) != NULL);
#endif
}

static void mavlink_test_ahrs2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AHRS2 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ahrs2_t packet_in = {
        17.0,45.0,73.0,101.0,963498296,963498504
    };
    mavlink_ahrs2_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.altitude = packet_in.altitude;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AHRS2_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AHRS2_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs2_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ahrs2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs2_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng );
    mavlink_msg_ahrs2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs2_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng );
    mavlink_msg_ahrs2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ahrs2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs2_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng );
    mavlink_msg_ahrs2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AHRS2") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AHRS2) != NULL);
#endif
}

static void mavlink_test_camera_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CAMERA_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_camera_status_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,157.0,18483,211,22,89
    };
    mavlink_camera_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.p1 = packet_in.p1;
        packet1.p2 = packet_in.p2;
        packet1.p3 = packet_in.p3;
        packet1.p4 = packet_in.p4;
        packet1.img_idx = packet_in.img_idx;
        packet1.target_system = packet_in.target_system;
        packet1.cam_idx = packet_in.cam_idx;
        packet1.event_id = packet_in.event_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CAMERA_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CAMERA_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_camera_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_status_pack(system_id, component_id, &msg , packet1.time_usec , packet1.target_system , packet1.cam_idx , packet1.img_idx , packet1.event_id , packet1.p1 , packet1.p2 , packet1.p3 , packet1.p4 );
    mavlink_msg_camera_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.target_system , packet1.cam_idx , packet1.img_idx , packet1.event_id , packet1.p1 , packet1.p2 , packet1.p3 , packet1.p4 );
    mavlink_msg_camera_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_camera_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_status_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.target_system , packet1.cam_idx , packet1.img_idx , packet1.event_id , packet1.p1 , packet1.p2 , packet1.p3 , packet1.p4 );
    mavlink_msg_camera_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CAMERA_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CAMERA_STATUS) != NULL);
#endif
}

static void mavlink_test_camera_feedback(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CAMERA_FEEDBACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_camera_feedback_t packet_in = {
        93372036854775807ULL,963497880,963498088,129.0,157.0,185.0,213.0,241.0,269.0,19315,3,70,137,19575
    };
    mavlink_camera_feedback_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.alt_msl = packet_in.alt_msl;
        packet1.alt_rel = packet_in.alt_rel;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.foc_len = packet_in.foc_len;
        packet1.img_idx = packet_in.img_idx;
        packet1.target_system = packet_in.target_system;
        packet1.cam_idx = packet_in.cam_idx;
        packet1.flags = packet_in.flags;
        packet1.completed_captures = packet_in.completed_captures;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CAMERA_FEEDBACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CAMERA_FEEDBACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_feedback_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_camera_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_feedback_pack(system_id, component_id, &msg , packet1.time_usec , packet1.target_system , packet1.cam_idx , packet1.img_idx , packet1.lat , packet1.lng , packet1.alt_msl , packet1.alt_rel , packet1.roll , packet1.pitch , packet1.yaw , packet1.foc_len , packet1.flags , packet1.completed_captures );
    mavlink_msg_camera_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_feedback_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.target_system , packet1.cam_idx , packet1.img_idx , packet1.lat , packet1.lng , packet1.alt_msl , packet1.alt_rel , packet1.roll , packet1.pitch , packet1.yaw , packet1.foc_len , packet1.flags , packet1.completed_captures );
    mavlink_msg_camera_feedback_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_camera_feedback_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_camera_feedback_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.target_system , packet1.cam_idx , packet1.img_idx , packet1.lat , packet1.lng , packet1.alt_msl , packet1.alt_rel , packet1.roll , packet1.pitch , packet1.yaw , packet1.foc_len , packet1.flags , packet1.completed_captures );
    mavlink_msg_camera_feedback_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CAMERA_FEEDBACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CAMERA_FEEDBACK) != NULL);
#endif
}

static void mavlink_test_battery2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BATTERY2 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_battery2_t packet_in = {
        17235,17339
    };
    mavlink_battery2_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.voltage = packet_in.voltage;
        packet1.current_battery = packet_in.current_battery;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BATTERY2_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BATTERY2_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery2_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_battery2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery2_pack(system_id, component_id, &msg , packet1.voltage , packet1.current_battery );
    mavlink_msg_battery2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery2_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.voltage , packet1.current_battery );
    mavlink_msg_battery2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_battery2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery2_send(MAVLINK_COMM_1 , packet1.voltage , packet1.current_battery );
    mavlink_msg_battery2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BATTERY2") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BATTERY2) != NULL);
#endif
}

static void mavlink_test_ahrs3(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AHRS3 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ahrs3_t packet_in = {
        17.0,45.0,73.0,101.0,963498296,963498504,185.0,213.0,241.0,269.0
    };
    mavlink_ahrs3_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.altitude = packet_in.altitude;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.v1 = packet_in.v1;
        packet1.v2 = packet_in.v2;
        packet1.v3 = packet_in.v3;
        packet1.v4 = packet_in.v4;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AHRS3_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AHRS3_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs3_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ahrs3_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs3_pack(system_id, component_id, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng , packet1.v1 , packet1.v2 , packet1.v3 , packet1.v4 );
    mavlink_msg_ahrs3_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs3_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng , packet1.v1 , packet1.v2 , packet1.v3 , packet1.v4 );
    mavlink_msg_ahrs3_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ahrs3_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ahrs3_send(MAVLINK_COMM_1 , packet1.roll , packet1.pitch , packet1.yaw , packet1.altitude , packet1.lat , packet1.lng , packet1.v1 , packet1.v2 , packet1.v3 , packet1.v4 );
    mavlink_msg_ahrs3_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AHRS3") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AHRS3) != NULL);
#endif
}

static void mavlink_test_autopilot_version_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AUTOPILOT_VERSION_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_autopilot_version_request_t packet_in = {
        5,72
    };
    mavlink_autopilot_version_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AUTOPILOT_VERSION_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AUTOPILOT_VERSION_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_autopilot_version_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_autopilot_version_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_autopilot_version_request_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component );
    mavlink_msg_autopilot_version_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_autopilot_version_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component );
    mavlink_msg_autopilot_version_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_autopilot_version_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_autopilot_version_request_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component );
    mavlink_msg_autopilot_version_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AUTOPILOT_VERSION_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AUTOPILOT_VERSION_REQUEST) != NULL);
#endif
}

static void mavlink_test_remote_log_data_block(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_REMOTE_LOG_DATA_BLOCK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_remote_log_data_block_t packet_in = {
        963497464,17,84,{ 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94 }
    };
    mavlink_remote_log_data_block_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seqno = packet_in.seqno;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*200);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_REMOTE_LOG_DATA_BLOCK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_REMOTE_LOG_DATA_BLOCK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_data_block_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_remote_log_data_block_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_data_block_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.seqno , packet1.data );
    mavlink_msg_remote_log_data_block_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_data_block_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.seqno , packet1.data );
    mavlink_msg_remote_log_data_block_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_remote_log_data_block_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_data_block_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.seqno , packet1.data );
    mavlink_msg_remote_log_data_block_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("REMOTE_LOG_DATA_BLOCK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_REMOTE_LOG_DATA_BLOCK) != NULL);
#endif
}

static void mavlink_test_remote_log_block_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_REMOTE_LOG_BLOCK_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_remote_log_block_status_t packet_in = {
        963497464,17,84,151
    };
    mavlink_remote_log_block_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seqno = packet_in.seqno;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.status = packet_in.status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_REMOTE_LOG_BLOCK_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_REMOTE_LOG_BLOCK_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_block_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_remote_log_block_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_block_status_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.seqno , packet1.status );
    mavlink_msg_remote_log_block_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_block_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.seqno , packet1.status );
    mavlink_msg_remote_log_block_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_remote_log_block_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_remote_log_block_status_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.seqno , packet1.status );
    mavlink_msg_remote_log_block_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("REMOTE_LOG_BLOCK_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_REMOTE_LOG_BLOCK_STATUS) != NULL);
#endif
}

static void mavlink_test_led_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_LED_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_led_control_t packet_in = {
        5,72,139,206,17,{ 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107 }
    };
    mavlink_led_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.instance = packet_in.instance;
        packet1.pattern = packet_in.pattern;
        packet1.custom_len = packet_in.custom_len;
        
        mav_array_memcpy(packet1.custom_bytes, packet_in.custom_bytes, sizeof(uint8_t)*24);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_LED_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_LED_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_led_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_led_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_led_control_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.instance , packet1.pattern , packet1.custom_len , packet1.custom_bytes );
    mavlink_msg_led_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_led_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.instance , packet1.pattern , packet1.custom_len , packet1.custom_bytes );
    mavlink_msg_led_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_led_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_led_control_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.instance , packet1.pattern , packet1.custom_len , packet1.custom_bytes );
    mavlink_msg_led_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("LED_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_LED_CONTROL) != NULL);
#endif
}

static void mavlink_test_mag_cal_progress(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MAG_CAL_PROGRESS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mag_cal_progress_t packet_in = {
        17.0,45.0,73.0,41,108,175,242,53,{ 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 }
    };
    mavlink_mag_cal_progress_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.direction_x = packet_in.direction_x;
        packet1.direction_y = packet_in.direction_y;
        packet1.direction_z = packet_in.direction_z;
        packet1.compass_id = packet_in.compass_id;
        packet1.cal_mask = packet_in.cal_mask;
        packet1.cal_status = packet_in.cal_status;
        packet1.attempt = packet_in.attempt;
        packet1.completion_pct = packet_in.completion_pct;
        
        mav_array_memcpy(packet1.completion_mask, packet_in.completion_mask, sizeof(uint8_t)*10);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MAG_CAL_PROGRESS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MAG_CAL_PROGRESS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_cal_progress_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mag_cal_progress_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_cal_progress_pack(system_id, component_id, &msg , packet1.compass_id , packet1.cal_mask , packet1.cal_status , packet1.attempt , packet1.completion_pct , packet1.completion_mask , packet1.direction_x , packet1.direction_y , packet1.direction_z );
    mavlink_msg_mag_cal_progress_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_cal_progress_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.compass_id , packet1.cal_mask , packet1.cal_status , packet1.attempt , packet1.completion_pct , packet1.completion_mask , packet1.direction_x , packet1.direction_y , packet1.direction_z );
    mavlink_msg_mag_cal_progress_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mag_cal_progress_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mag_cal_progress_send(MAVLINK_COMM_1 , packet1.compass_id , packet1.cal_mask , packet1.cal_status , packet1.attempt , packet1.completion_pct , packet1.completion_mask , packet1.direction_x , packet1.direction_y , packet1.direction_z );
    mavlink_msg_mag_cal_progress_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MAG_CAL_PROGRESS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MAG_CAL_PROGRESS) != NULL);
#endif
}

static void mavlink_test_ekf_status_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EKF_STATUS_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ekf_status_report_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,18275,171.0
    };
    mavlink_ekf_status_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.velocity_variance = packet_in.velocity_variance;
        packet1.pos_horiz_variance = packet_in.pos_horiz_variance;
        packet1.pos_vert_variance = packet_in.pos_vert_variance;
        packet1.compass_variance = packet_in.compass_variance;
        packet1.terrain_alt_variance = packet_in.terrain_alt_variance;
        packet1.flags = packet_in.flags;
        packet1.airspeed_variance = packet_in.airspeed_variance;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EKF_STATUS_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EKF_STATUS_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ekf_status_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ekf_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ekf_status_report_pack(system_id, component_id, &msg , packet1.flags , packet1.velocity_variance , packet1.pos_horiz_variance , packet1.pos_vert_variance , packet1.compass_variance , packet1.terrain_alt_variance , packet1.airspeed_variance );
    mavlink_msg_ekf_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ekf_status_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.flags , packet1.velocity_variance , packet1.pos_horiz_variance , packet1.pos_vert_variance , packet1.compass_variance , packet1.terrain_alt_variance , packet1.airspeed_variance );
    mavlink_msg_ekf_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ekf_status_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ekf_status_report_send(MAVLINK_COMM_1 , packet1.flags , packet1.velocity_variance , packet1.pos_horiz_variance , packet1.pos_vert_variance , packet1.compass_variance , packet1.terrain_alt_variance , packet1.airspeed_variance );
    mavlink_msg_ekf_status_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EKF_STATUS_REPORT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EKF_STATUS_REPORT) != NULL);
#endif
}

static void mavlink_test_pid_tuning(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PID_TUNING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pid_tuning_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,77,192.0,220.0
    };
    mavlink_pid_tuning_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.desired = packet_in.desired;
        packet1.achieved = packet_in.achieved;
        packet1.FF = packet_in.FF;
        packet1.P = packet_in.P;
        packet1.I = packet_in.I;
        packet1.D = packet_in.D;
        packet1.axis = packet_in.axis;
        packet1.SRate = packet_in.SRate;
        packet1.PDmod = packet_in.PDmod;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PID_TUNING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PID_TUNING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_tuning_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pid_tuning_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_tuning_pack(system_id, component_id, &msg , packet1.axis , packet1.desired , packet1.achieved , packet1.FF , packet1.P , packet1.I , packet1.D , packet1.SRate , packet1.PDmod );
    mavlink_msg_pid_tuning_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_tuning_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.axis , packet1.desired , packet1.achieved , packet1.FF , packet1.P , packet1.I , packet1.D , packet1.SRate , packet1.PDmod );
    mavlink_msg_pid_tuning_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pid_tuning_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pid_tuning_send(MAVLINK_COMM_1 , packet1.axis , packet1.desired , packet1.achieved , packet1.FF , packet1.P , packet1.I , packet1.D , packet1.SRate , packet1.PDmod );
    mavlink_msg_pid_tuning_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PID_TUNING") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PID_TUNING) != NULL);
#endif
}

static void mavlink_test_deepstall(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEEPSTALL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_deepstall_t packet_in = {
        963497464,963497672,963497880,963498088,963498296,963498504,185.0,213.0,241.0,113
    };
    mavlink_deepstall_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.landing_lat = packet_in.landing_lat;
        packet1.landing_lon = packet_in.landing_lon;
        packet1.path_lat = packet_in.path_lat;
        packet1.path_lon = packet_in.path_lon;
        packet1.arc_entry_lat = packet_in.arc_entry_lat;
        packet1.arc_entry_lon = packet_in.arc_entry_lon;
        packet1.altitude = packet_in.altitude;
        packet1.expected_travel_distance = packet_in.expected_travel_distance;
        packet1.cross_track_error = packet_in.cross_track_error;
        packet1.stage = packet_in.stage;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEEPSTALL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEEPSTALL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_deepstall_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_deepstall_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_deepstall_pack(system_id, component_id, &msg , packet1.landing_lat , packet1.landing_lon , packet1.path_lat , packet1.path_lon , packet1.arc_entry_lat , packet1.arc_entry_lon , packet1.altitude , packet1.expected_travel_distance , packet1.cross_track_error , packet1.stage );
    mavlink_msg_deepstall_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_deepstall_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.landing_lat , packet1.landing_lon , packet1.path_lat , packet1.path_lon , packet1.arc_entry_lat , packet1.arc_entry_lon , packet1.altitude , packet1.expected_travel_distance , packet1.cross_track_error , packet1.stage );
    mavlink_msg_deepstall_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_deepstall_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_deepstall_send(MAVLINK_COMM_1 , packet1.landing_lat , packet1.landing_lon , packet1.path_lat , packet1.path_lon , packet1.arc_entry_lat , packet1.arc_entry_lon , packet1.altitude , packet1.expected_travel_distance , packet1.cross_track_error , packet1.stage );
    mavlink_msg_deepstall_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEEPSTALL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEEPSTALL) != NULL);
#endif
}

static void mavlink_test_gimbal_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_report_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,125,192
    };
    mavlink_gimbal_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.delta_time = packet_in.delta_time;
        packet1.delta_angle_x = packet_in.delta_angle_x;
        packet1.delta_angle_y = packet_in.delta_angle_y;
        packet1.delta_angle_z = packet_in.delta_angle_z;
        packet1.delta_velocity_x = packet_in.delta_velocity_x;
        packet1.delta_velocity_y = packet_in.delta_velocity_y;
        packet1.delta_velocity_z = packet_in.delta_velocity_z;
        packet1.joint_roll = packet_in.joint_roll;
        packet1.joint_el = packet_in.joint_el;
        packet1.joint_az = packet_in.joint_az;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_report_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.delta_time , packet1.delta_angle_x , packet1.delta_angle_y , packet1.delta_angle_z , packet1.delta_velocity_x , packet1.delta_velocity_y , packet1.delta_velocity_z , packet1.joint_roll , packet1.joint_el , packet1.joint_az );
    mavlink_msg_gimbal_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.delta_time , packet1.delta_angle_x , packet1.delta_angle_y , packet1.delta_angle_z , packet1.delta_velocity_x , packet1.delta_velocity_y , packet1.delta_velocity_z , packet1.joint_roll , packet1.joint_el , packet1.joint_az );
    mavlink_msg_gimbal_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_report_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.delta_time , packet1.delta_angle_x , packet1.delta_angle_y , packet1.delta_angle_z , packet1.delta_velocity_x , packet1.delta_velocity_y , packet1.delta_velocity_z , packet1.joint_roll , packet1.joint_el , packet1.joint_az );
    mavlink_msg_gimbal_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_REPORT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_REPORT) != NULL);
#endif
}

static void mavlink_test_gimbal_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_control_t packet_in = {
        17.0,45.0,73.0,41,108
    };
    mavlink_gimbal_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.demanded_rate_x = packet_in.demanded_rate_x;
        packet1.demanded_rate_y = packet_in.demanded_rate_y;
        packet1.demanded_rate_z = packet_in.demanded_rate_z;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.demanded_rate_x , packet1.demanded_rate_y , packet1.demanded_rate_z );
    mavlink_msg_gimbal_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.demanded_rate_x , packet1.demanded_rate_y , packet1.demanded_rate_z );
    mavlink_msg_gimbal_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_control_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.demanded_rate_x , packet1.demanded_rate_y , packet1.demanded_rate_z );
    mavlink_msg_gimbal_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_CONTROL) != NULL);
#endif
}

static void mavlink_test_gimbal_torque_cmd_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gimbal_torque_cmd_report_t packet_in = {
        17235,17339,17443,151,218
    };
    mavlink_gimbal_torque_cmd_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rl_torque_cmd = packet_in.rl_torque_cmd;
        packet1.el_torque_cmd = packet_in.el_torque_cmd;
        packet1.az_torque_cmd = packet_in.az_torque_cmd;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_torque_cmd_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gimbal_torque_cmd_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_torque_cmd_report_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.rl_torque_cmd , packet1.el_torque_cmd , packet1.az_torque_cmd );
    mavlink_msg_gimbal_torque_cmd_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_torque_cmd_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.rl_torque_cmd , packet1.el_torque_cmd , packet1.az_torque_cmd );
    mavlink_msg_gimbal_torque_cmd_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gimbal_torque_cmd_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gimbal_torque_cmd_report_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.rl_torque_cmd , packet1.el_torque_cmd , packet1.az_torque_cmd );
    mavlink_msg_gimbal_torque_cmd_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GIMBAL_TORQUE_CMD_REPORT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GIMBAL_TORQUE_CMD_REPORT) != NULL);
#endif
}

static void mavlink_test_gopro_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GOPRO_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gopro_heartbeat_t packet_in = {
        5,72,139
    };
    mavlink_gopro_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.status = packet_in.status;
        packet1.capture_mode = packet_in.capture_mode;
        packet1.flags = packet_in.flags;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GOPRO_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GOPRO_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gopro_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_heartbeat_pack(system_id, component_id, &msg , packet1.status , packet1.capture_mode , packet1.flags );
    mavlink_msg_gopro_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.status , packet1.capture_mode , packet1.flags );
    mavlink_msg_gopro_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gopro_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_heartbeat_send(MAVLINK_COMM_1 , packet1.status , packet1.capture_mode , packet1.flags );
    mavlink_msg_gopro_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GOPRO_HEARTBEAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GOPRO_HEARTBEAT) != NULL);
#endif
}

static void mavlink_test_gopro_get_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GOPRO_GET_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gopro_get_request_t packet_in = {
        5,72,139
    };
    mavlink_gopro_get_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.cmd_id = packet_in.cmd_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GOPRO_GET_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GOPRO_GET_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gopro_get_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_request_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.cmd_id );
    mavlink_msg_gopro_get_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.cmd_id );
    mavlink_msg_gopro_get_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gopro_get_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_request_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.cmd_id );
    mavlink_msg_gopro_get_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GOPRO_GET_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GOPRO_GET_REQUEST) != NULL);
#endif
}

static void mavlink_test_gopro_get_response(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GOPRO_GET_RESPONSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gopro_get_response_t packet_in = {
        5,72,{ 139, 140, 141, 142 }
    };
    mavlink_gopro_get_response_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_id = packet_in.cmd_id;
        packet1.status = packet_in.status;
        
        mav_array_memcpy(packet1.value, packet_in.value, sizeof(uint8_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GOPRO_GET_RESPONSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GOPRO_GET_RESPONSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_response_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gopro_get_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_response_pack(system_id, component_id, &msg , packet1.cmd_id , packet1.status , packet1.value );
    mavlink_msg_gopro_get_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_response_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_id , packet1.status , packet1.value );
    mavlink_msg_gopro_get_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gopro_get_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_get_response_send(MAVLINK_COMM_1 , packet1.cmd_id , packet1.status , packet1.value );
    mavlink_msg_gopro_get_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GOPRO_GET_RESPONSE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GOPRO_GET_RESPONSE) != NULL);
#endif
}

static void mavlink_test_gopro_set_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GOPRO_SET_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gopro_set_request_t packet_in = {
        5,72,139,{ 206, 207, 208, 209 }
    };
    mavlink_gopro_set_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.cmd_id = packet_in.cmd_id;
        
        mav_array_memcpy(packet1.value, packet_in.value, sizeof(uint8_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GOPRO_SET_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GOPRO_SET_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gopro_set_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_request_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.cmd_id , packet1.value );
    mavlink_msg_gopro_set_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.cmd_id , packet1.value );
    mavlink_msg_gopro_set_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gopro_set_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_request_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.cmd_id , packet1.value );
    mavlink_msg_gopro_set_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GOPRO_SET_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GOPRO_SET_REQUEST) != NULL);
#endif
}

static void mavlink_test_gopro_set_response(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GOPRO_SET_RESPONSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gopro_set_response_t packet_in = {
        5,72
    };
    mavlink_gopro_set_response_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.cmd_id = packet_in.cmd_id;
        packet1.status = packet_in.status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GOPRO_SET_RESPONSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GOPRO_SET_RESPONSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_response_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gopro_set_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_response_pack(system_id, component_id, &msg , packet1.cmd_id , packet1.status );
    mavlink_msg_gopro_set_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_response_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.cmd_id , packet1.status );
    mavlink_msg_gopro_set_response_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gopro_set_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gopro_set_response_send(MAVLINK_COMM_1 , packet1.cmd_id , packet1.status );
    mavlink_msg_gopro_set_response_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GOPRO_SET_RESPONSE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GOPRO_SET_RESPONSE) != NULL);
#endif
}

static void mavlink_test_rpm(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RPM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_rpm_t packet_in = {
        17.0,45.0
    };
    mavlink_rpm_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rpm1 = packet_in.rpm1;
        packet1.rpm2 = packet_in.rpm2;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RPM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RPM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rpm_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_rpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rpm_pack(system_id, component_id, &msg , packet1.rpm1 , packet1.rpm2 );
    mavlink_msg_rpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rpm_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.rpm1 , packet1.rpm2 );
    mavlink_msg_rpm_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_rpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_rpm_send(MAVLINK_COMM_1 , packet1.rpm1 , packet1.rpm2 );
    mavlink_msg_rpm_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RPM") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RPM) != NULL);
#endif
}

static void mavlink_test_device_op_read(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_OP_READ >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_op_read_t packet_in = {
        963497464,17,84,151,218,29,"JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV",216,27,94
    };
    mavlink_device_op_read_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.bustype = packet_in.bustype;
        packet1.bus = packet_in.bus;
        packet1.address = packet_in.address;
        packet1.regstart = packet_in.regstart;
        packet1.count = packet_in.count;
        packet1.bank = packet_in.bank;
        
        mav_array_memcpy(packet1.busname, packet_in.busname, sizeof(char)*40);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_OP_READ_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_OP_READ_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_op_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.bustype , packet1.bus , packet1.address , packet1.busname , packet1.regstart , packet1.count , packet1.bank );
    mavlink_msg_device_op_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.bustype , packet1.bus , packet1.address , packet1.busname , packet1.regstart , packet1.count , packet1.bank );
    mavlink_msg_device_op_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_op_read_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.request_id , packet1.bustype , packet1.bus , packet1.address , packet1.busname , packet1.regstart , packet1.count , packet1.bank );
    mavlink_msg_device_op_read_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_OP_READ") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_OP_READ) != NULL);
#endif
}

static void mavlink_test_device_op_read_reply(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_op_read_reply_t packet_in = {
        963497464,17,84,151,{ 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 },90
    };
    mavlink_device_op_read_reply_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.result = packet_in.result;
        packet1.regstart = packet_in.regstart;
        packet1.count = packet_in.count;
        packet1.bank = packet_in.bank;
        
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*128);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_reply_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_op_read_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_reply_pack(system_id, component_id, &msg , packet1.request_id , packet1.result , packet1.regstart , packet1.count , packet1.data , packet1.bank );
    mavlink_msg_device_op_read_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_reply_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_id , packet1.result , packet1.regstart , packet1.count , packet1.data , packet1.bank );
    mavlink_msg_device_op_read_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_op_read_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_read_reply_send(MAVLINK_COMM_1 , packet1.request_id , packet1.result , packet1.regstart , packet1.count , packet1.data , packet1.bank );
    mavlink_msg_device_op_read_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_OP_READ_REPLY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_OP_READ_REPLY) != NULL);
#endif
}

static void mavlink_test_device_op_write(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_OP_WRITE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_op_write_t packet_in = {
        963497464,17,84,151,218,29,"JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV",216,27,{ 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221 },222
    };
    mavlink_device_op_write_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.bustype = packet_in.bustype;
        packet1.bus = packet_in.bus;
        packet1.address = packet_in.address;
        packet1.regstart = packet_in.regstart;
        packet1.count = packet_in.count;
        packet1.bank = packet_in.bank;
        
        mav_array_memcpy(packet1.busname, packet_in.busname, sizeof(char)*40);
        mav_array_memcpy(packet1.data, packet_in.data, sizeof(uint8_t)*128);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_OP_WRITE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_OP_WRITE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_op_write_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.bustype , packet1.bus , packet1.address , packet1.busname , packet1.regstart , packet1.count , packet1.data , packet1.bank );
    mavlink_msg_device_op_write_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.bustype , packet1.bus , packet1.address , packet1.busname , packet1.regstart , packet1.count , packet1.data , packet1.bank );
    mavlink_msg_device_op_write_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_op_write_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.request_id , packet1.bustype , packet1.bus , packet1.address , packet1.busname , packet1.regstart , packet1.count , packet1.data , packet1.bank );
    mavlink_msg_device_op_write_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_OP_WRITE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_OP_WRITE) != NULL);
#endif
}

static void mavlink_test_device_op_write_reply(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEVICE_OP_WRITE_REPLY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_device_op_write_reply_t packet_in = {
        963497464,17
    };
    mavlink_device_op_write_reply_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.result = packet_in.result;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEVICE_OP_WRITE_REPLY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEVICE_OP_WRITE_REPLY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_reply_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_device_op_write_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_reply_pack(system_id, component_id, &msg , packet1.request_id , packet1.result );
    mavlink_msg_device_op_write_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_reply_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_id , packet1.result );
    mavlink_msg_device_op_write_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_device_op_write_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_device_op_write_reply_send(MAVLINK_COMM_1 , packet1.request_id , packet1.result );
    mavlink_msg_device_op_write_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEVICE_OP_WRITE_REPLY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEVICE_OP_WRITE_REPLY) != NULL);
#endif
}

static void mavlink_test_adap_tuning(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ADAP_TUNING >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_adap_tuning_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0,325.0,149
    };
    mavlink_adap_tuning_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.desired = packet_in.desired;
        packet1.achieved = packet_in.achieved;
        packet1.error = packet_in.error;
        packet1.theta = packet_in.theta;
        packet1.omega = packet_in.omega;
        packet1.sigma = packet_in.sigma;
        packet1.theta_dot = packet_in.theta_dot;
        packet1.omega_dot = packet_in.omega_dot;
        packet1.sigma_dot = packet_in.sigma_dot;
        packet1.f = packet_in.f;
        packet1.f_dot = packet_in.f_dot;
        packet1.u = packet_in.u;
        packet1.axis = packet_in.axis;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ADAP_TUNING_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ADAP_TUNING_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_adap_tuning_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_adap_tuning_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_adap_tuning_pack(system_id, component_id, &msg , packet1.axis , packet1.desired , packet1.achieved , packet1.error , packet1.theta , packet1.omega , packet1.sigma , packet1.theta_dot , packet1.omega_dot , packet1.sigma_dot , packet1.f , packet1.f_dot , packet1.u );
    mavlink_msg_adap_tuning_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_adap_tuning_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.axis , packet1.desired , packet1.achieved , packet1.error , packet1.theta , packet1.omega , packet1.sigma , packet1.theta_dot , packet1.omega_dot , packet1.sigma_dot , packet1.f , packet1.f_dot , packet1.u );
    mavlink_msg_adap_tuning_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_adap_tuning_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_adap_tuning_send(MAVLINK_COMM_1 , packet1.axis , packet1.desired , packet1.achieved , packet1.error , packet1.theta , packet1.omega , packet1.sigma , packet1.theta_dot , packet1.omega_dot , packet1.sigma_dot , packet1.f , packet1.f_dot , packet1.u );
    mavlink_msg_adap_tuning_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ADAP_TUNING") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ADAP_TUNING) != NULL);
#endif
}

static void mavlink_test_vision_position_delta(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VISION_POSITION_DELTA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_vision_position_delta_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,{ 129.0, 130.0, 131.0 },{ 213.0, 214.0, 215.0 },297.0
    };
    mavlink_vision_position_delta_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.time_delta_usec = packet_in.time_delta_usec;
        packet1.confidence = packet_in.confidence;
        
        mav_array_memcpy(packet1.angle_delta, packet_in.angle_delta, sizeof(float)*3);
        mav_array_memcpy(packet1.position_delta, packet_in.position_delta, sizeof(float)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VISION_POSITION_DELTA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VISION_POSITION_DELTA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_position_delta_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_vision_position_delta_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_position_delta_pack(system_id, component_id, &msg , packet1.time_usec , packet1.time_delta_usec , packet1.angle_delta , packet1.position_delta , packet1.confidence );
    mavlink_msg_vision_position_delta_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_position_delta_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.time_delta_usec , packet1.angle_delta , packet1.position_delta , packet1.confidence );
    mavlink_msg_vision_position_delta_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_vision_position_delta_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vision_position_delta_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.time_delta_usec , packet1.angle_delta , packet1.position_delta , packet1.confidence );
    mavlink_msg_vision_position_delta_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VISION_POSITION_DELTA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VISION_POSITION_DELTA) != NULL);
#endif
}

static void mavlink_test_aoa_ssa(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AOA_SSA >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_aoa_ssa_t packet_in = {
        93372036854775807ULL,73.0,101.0
    };
    mavlink_aoa_ssa_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.AOA = packet_in.AOA;
        packet1.SSA = packet_in.SSA;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AOA_SSA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AOA_SSA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_aoa_ssa_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_aoa_ssa_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_aoa_ssa_pack(system_id, component_id, &msg , packet1.time_usec , packet1.AOA , packet1.SSA );
    mavlink_msg_aoa_ssa_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_aoa_ssa_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.AOA , packet1.SSA );
    mavlink_msg_aoa_ssa_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_aoa_ssa_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_aoa_ssa_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.AOA , packet1.SSA );
    mavlink_msg_aoa_ssa_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AOA_SSA") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AOA_SSA) != NULL);
#endif
}

static void mavlink_test_esc_telemetry_1_to_4(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ESC_TELEMETRY_1_TO_4 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_esc_telemetry_1_to_4_t packet_in = {
        { 17235, 17236, 17237, 17238 },{ 17651, 17652, 17653, 17654 },{ 18067, 18068, 18069, 18070 },{ 18483, 18484, 18485, 18486 },{ 18899, 18900, 18901, 18902 },{ 125, 126, 127, 128 }
    };
    mavlink_esc_telemetry_1_to_4_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.voltage, packet_in.voltage, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.current, packet_in.current, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.totalcurrent, packet_in.totalcurrent, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.rpm, packet_in.rpm, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.count, packet_in.count, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.temperature, packet_in.temperature, sizeof(uint8_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ESC_TELEMETRY_1_TO_4_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ESC_TELEMETRY_1_TO_4_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_1_to_4_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_esc_telemetry_1_to_4_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_1_to_4_pack(system_id, component_id, &msg , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_1_to_4_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_1_to_4_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_1_to_4_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_esc_telemetry_1_to_4_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_1_to_4_send(MAVLINK_COMM_1 , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_1_to_4_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ESC_TELEMETRY_1_TO_4") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ESC_TELEMETRY_1_TO_4) != NULL);
#endif
}

static void mavlink_test_esc_telemetry_5_to_8(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ESC_TELEMETRY_5_TO_8 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_esc_telemetry_5_to_8_t packet_in = {
        { 17235, 17236, 17237, 17238 },{ 17651, 17652, 17653, 17654 },{ 18067, 18068, 18069, 18070 },{ 18483, 18484, 18485, 18486 },{ 18899, 18900, 18901, 18902 },{ 125, 126, 127, 128 }
    };
    mavlink_esc_telemetry_5_to_8_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.voltage, packet_in.voltage, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.current, packet_in.current, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.totalcurrent, packet_in.totalcurrent, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.rpm, packet_in.rpm, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.count, packet_in.count, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.temperature, packet_in.temperature, sizeof(uint8_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ESC_TELEMETRY_5_TO_8_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ESC_TELEMETRY_5_TO_8_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_5_to_8_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_esc_telemetry_5_to_8_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_5_to_8_pack(system_id, component_id, &msg , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_5_to_8_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_5_to_8_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_5_to_8_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_esc_telemetry_5_to_8_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_5_to_8_send(MAVLINK_COMM_1 , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_5_to_8_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ESC_TELEMETRY_5_TO_8") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ESC_TELEMETRY_5_TO_8) != NULL);
#endif
}

static void mavlink_test_esc_telemetry_9_to_12(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ESC_TELEMETRY_9_TO_12 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_esc_telemetry_9_to_12_t packet_in = {
        { 17235, 17236, 17237, 17238 },{ 17651, 17652, 17653, 17654 },{ 18067, 18068, 18069, 18070 },{ 18483, 18484, 18485, 18486 },{ 18899, 18900, 18901, 18902 },{ 125, 126, 127, 128 }
    };
    mavlink_esc_telemetry_9_to_12_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.voltage, packet_in.voltage, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.current, packet_in.current, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.totalcurrent, packet_in.totalcurrent, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.rpm, packet_in.rpm, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.count, packet_in.count, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.temperature, packet_in.temperature, sizeof(uint8_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ESC_TELEMETRY_9_TO_12_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ESC_TELEMETRY_9_TO_12_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_9_to_12_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_esc_telemetry_9_to_12_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_9_to_12_pack(system_id, component_id, &msg , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_9_to_12_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_9_to_12_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_9_to_12_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_esc_telemetry_9_to_12_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_esc_telemetry_9_to_12_send(MAVLINK_COMM_1 , packet1.temperature , packet1.voltage , packet1.current , packet1.totalcurrent , packet1.rpm , packet1.count );
    mavlink_msg_esc_telemetry_9_to_12_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("ESC_TELEMETRY_9_TO_12") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_ESC_TELEMETRY_9_TO_12) != NULL);
#endif
}

static void mavlink_test_osd_param_config(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OSD_PARAM_CONFIG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_osd_param_config_t packet_in = {
        963497464,45.0,73.0,101.0,53,120,187,254,"UVWXYZABCDEFGHI",113
    };
    mavlink_osd_param_config_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.min_value = packet_in.min_value;
        packet1.max_value = packet_in.max_value;
        packet1.increment = packet_in.increment;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.osd_screen = packet_in.osd_screen;
        packet1.osd_index = packet_in.osd_index;
        packet1.config_type = packet_in.config_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OSD_PARAM_CONFIG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OSD_PARAM_CONFIG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_osd_param_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.osd_screen , packet1.osd_index , packet1.param_id , packet1.config_type , packet1.min_value , packet1.max_value , packet1.increment );
    mavlink_msg_osd_param_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.osd_screen , packet1.osd_index , packet1.param_id , packet1.config_type , packet1.min_value , packet1.max_value , packet1.increment );
    mavlink_msg_osd_param_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_osd_param_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.request_id , packet1.osd_screen , packet1.osd_index , packet1.param_id , packet1.config_type , packet1.min_value , packet1.max_value , packet1.increment );
    mavlink_msg_osd_param_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OSD_PARAM_CONFIG") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OSD_PARAM_CONFIG) != NULL);
#endif
}

static void mavlink_test_osd_param_config_reply(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OSD_PARAM_CONFIG_REPLY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_osd_param_config_reply_t packet_in = {
        963497464,17
    };
    mavlink_osd_param_config_reply_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.result = packet_in.result;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OSD_PARAM_CONFIG_REPLY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OSD_PARAM_CONFIG_REPLY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_reply_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_osd_param_config_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_reply_pack(system_id, component_id, &msg , packet1.request_id , packet1.result );
    mavlink_msg_osd_param_config_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_reply_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_id , packet1.result );
    mavlink_msg_osd_param_config_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_osd_param_config_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_config_reply_send(MAVLINK_COMM_1 , packet1.request_id , packet1.result );
    mavlink_msg_osd_param_config_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OSD_PARAM_CONFIG_REPLY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OSD_PARAM_CONFIG_REPLY) != NULL);
#endif
}

static void mavlink_test_osd_param_show_config(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_osd_param_show_config_t packet_in = {
        963497464,17,84,151,218
    };
    mavlink_osd_param_show_config_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.osd_screen = packet_in.osd_screen;
        packet1.osd_index = packet_in.osd_index;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_osd_param_show_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.osd_screen , packet1.osd_index );
    mavlink_msg_osd_param_show_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.request_id , packet1.osd_screen , packet1.osd_index );
    mavlink_msg_osd_param_show_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_osd_param_show_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.request_id , packet1.osd_screen , packet1.osd_index );
    mavlink_msg_osd_param_show_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OSD_PARAM_SHOW_CONFIG") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG) != NULL);
#endif
}

static void mavlink_test_osd_param_show_config_reply(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_osd_param_show_config_reply_t packet_in = {
        963497464,45.0,73.0,101.0,53,"RSTUVWXYZABCDEF",168
    };
    mavlink_osd_param_show_config_reply_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.request_id = packet_in.request_id;
        packet1.min_value = packet_in.min_value;
        packet1.max_value = packet_in.max_value;
        packet1.increment = packet_in.increment;
        packet1.result = packet_in.result;
        packet1.config_type = packet_in.config_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_reply_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_osd_param_show_config_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_reply_pack(system_id, component_id, &msg , packet1.request_id , packet1.result , packet1.param_id , packet1.config_type , packet1.min_value , packet1.max_value , packet1.increment );
    mavlink_msg_osd_param_show_config_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_reply_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.request_id , packet1.result , packet1.param_id , packet1.config_type , packet1.min_value , packet1.max_value , packet1.increment );
    mavlink_msg_osd_param_show_config_reply_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_osd_param_show_config_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_osd_param_show_config_reply_send(MAVLINK_COMM_1 , packet1.request_id , packet1.result , packet1.param_id , packet1.config_type , packet1.min_value , packet1.max_value , packet1.increment );
    mavlink_msg_osd_param_show_config_reply_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OSD_PARAM_SHOW_CONFIG_REPLY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OSD_PARAM_SHOW_CONFIG_REPLY) != NULL);
#endif
}

static void mavlink_test_obstacle_distance_3d(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OBSTACLE_DISTANCE_3D >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_obstacle_distance_3d_t packet_in = {
        963497464,45.0,73.0,101.0,129.0,157.0,18483,211,22
    };
    mavlink_obstacle_distance_3d_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.min_distance = packet_in.min_distance;
        packet1.max_distance = packet_in.max_distance;
        packet1.obstacle_id = packet_in.obstacle_id;
        packet1.sensor_type = packet_in.sensor_type;
        packet1.frame = packet_in.frame;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OBSTACLE_DISTANCE_3D_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OBSTACLE_DISTANCE_3D_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_obstacle_distance_3d_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_obstacle_distance_3d_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_obstacle_distance_3d_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.sensor_type , packet1.frame , packet1.obstacle_id , packet1.x , packet1.y , packet1.z , packet1.min_distance , packet1.max_distance );
    mavlink_msg_obstacle_distance_3d_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_obstacle_distance_3d_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.sensor_type , packet1.frame , packet1.obstacle_id , packet1.x , packet1.y , packet1.z , packet1.min_distance , packet1.max_distance );
    mavlink_msg_obstacle_distance_3d_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_obstacle_distance_3d_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_obstacle_distance_3d_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.sensor_type , packet1.frame , packet1.obstacle_id , packet1.x , packet1.y , packet1.z , packet1.min_distance , packet1.max_distance );
    mavlink_msg_obstacle_distance_3d_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OBSTACLE_DISTANCE_3D") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OBSTACLE_DISTANCE_3D) != NULL);
#endif
}

static void mavlink_test_water_depth(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WATER_DEPTH >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_water_depth_t packet_in = {
        963497464,963497672,963497880,101.0,129.0,157.0,185.0,213.0,241.0,113,180
    };
    mavlink_water_depth_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.lat = packet_in.lat;
        packet1.lng = packet_in.lng;
        packet1.alt = packet_in.alt;
        packet1.roll = packet_in.roll;
        packet1.pitch = packet_in.pitch;
        packet1.yaw = packet_in.yaw;
        packet1.distance = packet_in.distance;
        packet1.temperature = packet_in.temperature;
        packet1.id = packet_in.id;
        packet1.healthy = packet_in.healthy;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WATER_DEPTH_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WATER_DEPTH_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_water_depth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.id , packet1.healthy , packet1.lat , packet1.lng , packet1.alt , packet1.roll , packet1.pitch , packet1.yaw , packet1.distance , packet1.temperature );
    mavlink_msg_water_depth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.id , packet1.healthy , packet1.lat , packet1.lng , packet1.alt , packet1.roll , packet1.pitch , packet1.yaw , packet1.distance , packet1.temperature );
    mavlink_msg_water_depth_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_water_depth_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.id , packet1.healthy , packet1.lat , packet1.lng , packet1.alt , packet1.roll , packet1.pitch , packet1.yaw , packet1.distance , packet1.temperature );
    mavlink_msg_water_depth_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WATER_DEPTH") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WATER_DEPTH) != NULL);
#endif
}

static void mavlink_test_mcu_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MCU_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mcu_status_t packet_in = {
        17235,17339,17443,17547,29
    };
    mavlink_mcu_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.MCU_temperature = packet_in.MCU_temperature;
        packet1.MCU_voltage = packet_in.MCU_voltage;
        packet1.MCU_voltage_min = packet_in.MCU_voltage_min;
        packet1.MCU_voltage_max = packet_in.MCU_voltage_max;
        packet1.id = packet_in.id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MCU_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MCU_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mcu_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mcu_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mcu_status_pack(system_id, component_id, &msg , packet1.id , packet1.MCU_temperature , packet1.MCU_voltage , packet1.MCU_voltage_min , packet1.MCU_voltage_max );
    mavlink_msg_mcu_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mcu_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.MCU_temperature , packet1.MCU_voltage , packet1.MCU_voltage_min , packet1.MCU_voltage_max );
    mavlink_msg_mcu_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mcu_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mcu_status_send(MAVLINK_COMM_1 , packet1.id , packet1.MCU_temperature , packet1.MCU_voltage , packet1.MCU_voltage_min , packet1.MCU_voltage_max );
    mavlink_msg_mcu_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MCU_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MCU_STATUS) != NULL);
#endif
}

static void mavlink_test_oaire_rfsensor_setconfig(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_oaire_rfsensor_setconfig_t packet_in = {
        17.0,45.0,17651,163,230
    };
    mavlink_oaire_rfsensor_setconfig_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.center_frq = packet_in.center_frq;
        packet1.span = packet_in.span;
        packet1.no_points = packet_in.no_points;
        packet1.continuous = packet_in.continuous;
        packet1.start_stop = packet_in.start_stop;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_oaire_rfsensor_setconfig_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_pack(system_id, component_id, &msg , packet1.center_frq , packet1.span , packet1.no_points , packet1.continuous , packet1.start_stop );
    mavlink_msg_oaire_rfsensor_setconfig_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.center_frq , packet1.span , packet1.no_points , packet1.continuous , packet1.start_stop );
    mavlink_msg_oaire_rfsensor_setconfig_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_oaire_rfsensor_setconfig_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_send(MAVLINK_COMM_1 , packet1.center_frq , packet1.span , packet1.no_points , packet1.continuous , packet1.start_stop );
    mavlink_msg_oaire_rfsensor_setconfig_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OAIRE_RFSENSOR_SETCONFIG") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG) != NULL);
#endif
}

static void mavlink_test_oaire_rfsensor_setconfig_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_oaire_rfsensor_setconfig_ack_t packet_in = {
        17.0,45.0,17651,163,230,41
    };
    mavlink_oaire_rfsensor_setconfig_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.center_frq = packet_in.center_frq;
        packet1.span = packet_in.span;
        packet1.no_points = packet_in.no_points;
        packet1.continuous = packet_in.continuous;
        packet1.start_stop = packet_in.start_stop;
        packet1.state = packet_in.state;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_oaire_rfsensor_setconfig_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_ack_pack(system_id, component_id, &msg , packet1.center_frq , packet1.span , packet1.no_points , packet1.continuous , packet1.start_stop , packet1.state );
    mavlink_msg_oaire_rfsensor_setconfig_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.center_frq , packet1.span , packet1.no_points , packet1.continuous , packet1.start_stop , packet1.state );
    mavlink_msg_oaire_rfsensor_setconfig_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_oaire_rfsensor_setconfig_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_setconfig_ack_send(MAVLINK_COMM_1 , packet1.center_frq , packet1.span , packet1.no_points , packet1.continuous , packet1.start_stop , packet1.state );
    mavlink_msg_oaire_rfsensor_setconfig_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OAIRE_RFSENSOR_SETCONFIG_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OAIRE_RFSENSOR_SETCONFIG_ACK) != NULL);
#endif
}

static void mavlink_test_oaire_rfsensor_trace(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_oaire_rfsensor_trace_t packet_in = {
        { 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0, 41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0, 105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0, 116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0, 127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0, 138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0, 149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0, 160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0, 171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0, 182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0, 193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0, 201.0, 202.0, 203.0, 204.0, 205.0, 206.0, 207.0, 208.0, 209.0, 210.0, 211.0, 212.0, 213.0, 214.0, 215.0, 216.0, 217.0, 218.0, 219.0, 220.0, 221.0, 222.0, 223.0, 224.0, 225.0, 226.0, 227.0, 228.0, 229.0, 230.0, 231.0, 232.0, 233.0, 234.0, 235.0, 236.0, 237.0, 238.0, 239.0, 240.0, 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0, 250.0, 251.0, 252.0, 253.0, 254.0, 255.0, 256.0, 257.0, 258.0, 259.0, 260.0, 261.0, 262.0, 263.0, 264.0, 265.0, 266.0, 267.0, 268.0, 269.0, 270.0, 271.0, 272.0, 273.0, 274.0, 275.0, 276.0, 277.0, 278.0, 279.0, 280.0, 281.0, 282.0, 283.0, 284.0, 285.0, 286.0, 287.0, 288.0, 289.0, 290.0, 291.0, 292.0, 293.0, 294.0, 295.0, 296.0, 297.0, 298.0, 299.0, 300.0, 301.0, 302.0, 303.0, 304.0, 305.0, 306.0, 307.0, 308.0, 309.0, 310.0, 311.0, 312.0, 313.0, 314.0, 315.0, 316.0, 317.0, 318.0, 319.0, 320.0, 321.0, 322.0, 323.0, 324.0, 325.0, 326.0, 327.0, 328.0, 329.0, 330.0, 331.0, 332.0, 333.0, 334.0, 335.0, 336.0, 337.0, 338.0, 339.0, 340.0, 341.0, 342.0, 343.0, 344.0, 345.0, 346.0, 347.0, 348.0, 349.0, 350.0, 351.0, 352.0, 353.0, 354.0, 355.0, 356.0, 357.0, 358.0, 359.0, 360.0, 361.0, 362.0, 363.0, 364.0, 365.0, 366.0, 367.0, 368.0, 369.0, 370.0, 371.0, 372.0, 373.0, 374.0, 375.0, 376.0, 377.0, 378.0, 379.0, 380.0, 381.0, 382.0, 383.0, 384.0, 385.0, 386.0, 387.0, 388.0, 389.0, 390.0, 391.0, 392.0, 393.0, 394.0, 395.0, 396.0, 397.0, 398.0, 399.0, 400.0, 401.0, 402.0, 403.0, 404.0, 405.0, 406.0, 407.0, 408.0, 409.0, 410.0, 411.0, 412.0, 413.0, 414.0, 415.0, 416.0, 417.0, 418.0, 419.0, 420.0, 421.0, 422.0, 423.0, 424.0, 425.0, 426.0, 427.0, 428.0, 429.0, 430.0, 431.0, 432.0, 433.0, 434.0, 435.0, 436.0, 437.0, 438.0, 439.0, 440.0, 441.0, 442.0, 443.0, 444.0, 445.0, 446.0, 447.0, 448.0, 449.0, 450.0, 451.0, 452.0, 453.0, 454.0, 455.0, 456.0, 457.0, 458.0, 459.0, 460.0, 461.0, 462.0, 463.0, 464.0, 465.0, 466.0, 467.0, 468.0, 469.0, 470.0, 471.0, 472.0, 473.0, 474.0, 475.0, 476.0, 477.0, 478.0, 479.0, 480.0, 481.0, 482.0, 483.0, 484.0, 485.0, 486.0, 487.0, 488.0, 489.0, 490.0, 491.0, 492.0, 493.0, 494.0, 495.0, 496.0, 497.0, 498.0, 499.0, 500.0, 501.0, 502.0, 503.0, 504.0, 505.0, 506.0, 507.0, 508.0, 509.0, 510.0, 511.0, 512.0, 513.0, 514.0, 515.0, 516.0, 517.0, 518.0, 519.0, 520.0, 521.0, 522.0, 523.0, 524.0, 525.0, 526.0, 527.0, 528.0, 529.0, 530.0, 531.0, 532.0, 533.0, 534.0, 535.0, 536.0, 537.0, 538.0, 539.0, 540.0, 541.0, 542.0, 543.0, 544.0, 545.0, 546.0, 547.0, 548.0, 549.0, 550.0, 551.0, 552.0, 553.0, 554.0, 555.0, 556.0, 557.0, 558.0, 559.0, 560.0, 561.0, 562.0, 563.0, 564.0, 565.0, 566.0, 567.0, 568.0, 569.0, 570.0, 571.0, 572.0, 573.0, 574.0, 575.0, 576.0, 577.0, 578.0, 579.0, 580.0, 581.0, 582.0, 583.0, 584.0, 585.0, 586.0, 587.0, 588.0, 589.0, 590.0, 591.0, 592.0, 593.0, 594.0, 595.0, 596.0, 597.0, 598.0, 599.0, 600.0, 601.0, 602.0, 603.0, 604.0, 605.0, 606.0, 607.0, 608.0, 609.0, 610.0, 611.0, 612.0, 613.0, 614.0, 615.0, 616.0, 617.0, 618.0, 619.0, 620.0, 621.0, 622.0, 623.0, 624.0, 625.0, 626.0, 627.0, 628.0, 629.0, 630.0, 631.0, 632.0, 633.0, 634.0, 635.0, 636.0, 637.0, 638.0, 639.0, 640.0, 641.0, 642.0, 643.0, 644.0, 645.0, 646.0, 647.0, 648.0, 649.0, 650.0, 651.0, 652.0, 653.0, 654.0, 655.0, 656.0, 657.0, 658.0, 659.0, 660.0, 661.0, 662.0, 663.0, 664.0, 665.0, 666.0, 667.0, 668.0, 669.0, 670.0, 671.0, 672.0, 673.0, 674.0, 675.0, 676.0, 677.0, 678.0, 679.0, 680.0, 681.0, 682.0, 683.0, 684.0, 685.0, 686.0, 687.0, 688.0, 689.0, 690.0, 691.0, 692.0, 693.0, 694.0, 695.0, 696.0, 697.0, 698.0, 699.0, 700.0, 701.0, 702.0, 703.0, 704.0, 705.0, 706.0, 707.0, 708.0, 709.0, 710.0, 711.0, 712.0, 713.0, 714.0, 715.0, 716.0, 717.0, 718.0, 719.0, 720.0, 721.0, 722.0, 723.0, 724.0, 725.0, 726.0, 727.0, 728.0, 729.0, 730.0, 731.0, 732.0, 733.0, 734.0, 735.0, 736.0, 737.0, 738.0, 739.0, 740.0, 741.0, 742.0, 743.0, 744.0, 745.0, 746.0, 747.0, 748.0, 749.0, 750.0, 751.0, 752.0, 753.0, 754.0, 755.0, 756.0, 757.0, 758.0, 759.0, 760.0, 761.0, 762.0, 763.0, 764.0, 765.0, 766.0, 767.0, 768.0, 769.0, 770.0, 771.0, 772.0, 773.0, 774.0, 775.0, 776.0, 777.0, 778.0, 779.0, 780.0, 781.0, 782.0, 783.0, 784.0, 785.0, 786.0, 787.0, 788.0, 789.0, 790.0, 791.0, 792.0, 793.0, 794.0, 795.0, 796.0, 797.0, 798.0, 799.0, 800.0, 801.0, 802.0, 803.0, 804.0, 805.0, 806.0, 807.0, 808.0, 809.0, 810.0, 811.0, 812.0, 813.0, 814.0, 815.0, 816.0, 817.0, 818.0, 819.0, 820.0, 821.0, 822.0, 823.0, 824.0, 825.0, 826.0, 827.0, 828.0, 829.0, 830.0, 831.0, 832.0, 833.0, 834.0, 835.0, 836.0, 837.0, 838.0, 839.0, 840.0, 841.0, 842.0, 843.0, 844.0, 845.0, 846.0, 847.0, 848.0, 849.0, 850.0, 851.0, 852.0, 853.0, 854.0, 855.0, 856.0, 857.0, 858.0, 859.0, 860.0, 861.0, 862.0, 863.0, 864.0, 865.0, 866.0, 867.0, 868.0, 869.0, 870.0, 871.0, 872.0, 873.0, 874.0, 875.0, 876.0, 877.0, 878.0, 879.0, 880.0, 881.0, 882.0, 883.0, 884.0, 885.0, 886.0, 887.0, 888.0, 889.0, 890.0, 891.0, 892.0, 893.0, 894.0, 895.0, 896.0, 897.0, 898.0, 899.0, 900.0, 901.0, 902.0, 903.0, 904.0, 905.0, 906.0, 907.0, 908.0, 909.0, 910.0, 911.0, 912.0, 913.0, 914.0, 915.0, 916.0, 917.0, 918.0, 919.0, 920.0, 921.0, 922.0, 923.0, 924.0, 925.0, 926.0, 927.0, 928.0, 929.0, 930.0, 931.0, 932.0, 933.0, 934.0, 935.0, 936.0, 937.0, 938.0, 939.0, 940.0, 941.0, 942.0, 943.0, 944.0, 945.0, 946.0, 947.0, 948.0, 949.0, 950.0, 951.0, 952.0, 953.0, 954.0, 955.0, 956.0, 957.0, 958.0, 959.0, 960.0, 961.0, 962.0, 963.0, 964.0, 965.0, 966.0, 967.0, 968.0, 969.0, 970.0, 971.0, 972.0, 973.0, 974.0, 975.0, 976.0, 977.0, 978.0, 979.0, 980.0, 981.0, 982.0, 983.0, 984.0, 985.0, 986.0, 987.0, 988.0, 989.0, 990.0, 991.0, 992.0, 993.0, 994.0, 995.0, 996.0, 997.0, 998.0, 999.0, 1000.0, 1001.0, 1002.0, 1003.0, 1004.0, 1005.0, 1006.0, 1007.0, 1008.0, 1009.0, 1010.0, 1011.0, 1012.0, 1013.0, 1014.0, 1015.0, 1016.0 },{ 28017.0, 28018.0, 28019.0, 28020.0, 28021.0, 28022.0, 28023.0, 28024.0, 28025.0, 28026.0, 28027.0, 28028.0, 28029.0, 28030.0, 28031.0, 28032.0, 28033.0, 28034.0, 28035.0, 28036.0, 28037.0, 28038.0, 28039.0, 28040.0, 28041.0, 28042.0, 28043.0, 28044.0, 28045.0, 28046.0, 28047.0, 28048.0, 28049.0, 28050.0, 28051.0, 28052.0, 28053.0, 28054.0, 28055.0, 28056.0, 28057.0, 28058.0, 28059.0, 28060.0, 28061.0, 28062.0, 28063.0, 28064.0, 28065.0, 28066.0, 28067.0, 28068.0, 28069.0, 28070.0, 28071.0, 28072.0, 28073.0, 28074.0, 28075.0, 28076.0, 28077.0, 28078.0, 28079.0, 28080.0, 28081.0, 28082.0, 28083.0, 28084.0, 28085.0, 28086.0, 28087.0, 28088.0, 28089.0, 28090.0, 28091.0, 28092.0, 28093.0, 28094.0, 28095.0, 28096.0, 28097.0, 28098.0, 28099.0, 28100.0, 28101.0, 28102.0, 28103.0, 28104.0, 28105.0, 28106.0, 28107.0, 28108.0, 28109.0, 28110.0, 28111.0, 28112.0, 28113.0, 28114.0, 28115.0, 28116.0, 28117.0, 28118.0, 28119.0, 28120.0, 28121.0, 28122.0, 28123.0, 28124.0, 28125.0, 28126.0, 28127.0, 28128.0, 28129.0, 28130.0, 28131.0, 28132.0, 28133.0, 28134.0, 28135.0, 28136.0, 28137.0, 28138.0, 28139.0, 28140.0, 28141.0, 28142.0, 28143.0, 28144.0, 28145.0, 28146.0, 28147.0, 28148.0, 28149.0, 28150.0, 28151.0, 28152.0, 28153.0, 28154.0, 28155.0, 28156.0, 28157.0, 28158.0, 28159.0, 28160.0, 28161.0, 28162.0, 28163.0, 28164.0, 28165.0, 28166.0, 28167.0, 28168.0, 28169.0, 28170.0, 28171.0, 28172.0, 28173.0, 28174.0, 28175.0, 28176.0, 28177.0, 28178.0, 28179.0, 28180.0, 28181.0, 28182.0, 28183.0, 28184.0, 28185.0, 28186.0, 28187.0, 28188.0, 28189.0, 28190.0, 28191.0, 28192.0, 28193.0, 28194.0, 28195.0, 28196.0, 28197.0, 28198.0, 28199.0, 28200.0, 28201.0, 28202.0, 28203.0, 28204.0, 28205.0, 28206.0, 28207.0, 28208.0, 28209.0, 28210.0, 28211.0, 28212.0, 28213.0, 28214.0, 28215.0, 28216.0, 28217.0, 28218.0, 28219.0, 28220.0, 28221.0, 28222.0, 28223.0, 28224.0, 28225.0, 28226.0, 28227.0, 28228.0, 28229.0, 28230.0, 28231.0, 28232.0, 28233.0, 28234.0, 28235.0, 28236.0, 28237.0, 28238.0, 28239.0, 28240.0, 28241.0, 28242.0, 28243.0, 28244.0, 28245.0, 28246.0, 28247.0, 28248.0, 28249.0, 28250.0, 28251.0, 28252.0, 28253.0, 28254.0, 28255.0, 28256.0, 28257.0, 28258.0, 28259.0, 28260.0, 28261.0, 28262.0, 28263.0, 28264.0, 28265.0, 28266.0, 28267.0, 28268.0, 28269.0, 28270.0, 28271.0, 28272.0, 28273.0, 28274.0, 28275.0, 28276.0, 28277.0, 28278.0, 28279.0, 28280.0, 28281.0, 28282.0, 28283.0, 28284.0, 28285.0, 28286.0, 28287.0, 28288.0, 28289.0, 28290.0, 28291.0, 28292.0, 28293.0, 28294.0, 28295.0, 28296.0, 28297.0, 28298.0, 28299.0, 28300.0, 28301.0, 28302.0, 28303.0, 28304.0, 28305.0, 28306.0, 28307.0, 28308.0, 28309.0, 28310.0, 28311.0, 28312.0, 28313.0, 28314.0, 28315.0, 28316.0, 28317.0, 28318.0, 28319.0, 28320.0, 28321.0, 28322.0, 28323.0, 28324.0, 28325.0, 28326.0, 28327.0, 28328.0, 28329.0, 28330.0, 28331.0, 28332.0, 28333.0, 28334.0, 28335.0, 28336.0, 28337.0, 28338.0, 28339.0, 28340.0, 28341.0, 28342.0, 28343.0, 28344.0, 28345.0, 28346.0, 28347.0, 28348.0, 28349.0, 28350.0, 28351.0, 28352.0, 28353.0, 28354.0, 28355.0, 28356.0, 28357.0, 28358.0, 28359.0, 28360.0, 28361.0, 28362.0, 28363.0, 28364.0, 28365.0, 28366.0, 28367.0, 28368.0, 28369.0, 28370.0, 28371.0, 28372.0, 28373.0, 28374.0, 28375.0, 28376.0, 28377.0, 28378.0, 28379.0, 28380.0, 28381.0, 28382.0, 28383.0, 28384.0, 28385.0, 28386.0, 28387.0, 28388.0, 28389.0, 28390.0, 28391.0, 28392.0, 28393.0, 28394.0, 28395.0, 28396.0, 28397.0, 28398.0, 28399.0, 28400.0, 28401.0, 28402.0, 28403.0, 28404.0, 28405.0, 28406.0, 28407.0, 28408.0, 28409.0, 28410.0, 28411.0, 28412.0, 28413.0, 28414.0, 28415.0, 28416.0, 28417.0, 28418.0, 28419.0, 28420.0, 28421.0, 28422.0, 28423.0, 28424.0, 28425.0, 28426.0, 28427.0, 28428.0, 28429.0, 28430.0, 28431.0, 28432.0, 28433.0, 28434.0, 28435.0, 28436.0, 28437.0, 28438.0, 28439.0, 28440.0, 28441.0, 28442.0, 28443.0, 28444.0, 28445.0, 28446.0, 28447.0, 28448.0, 28449.0, 28450.0, 28451.0, 28452.0, 28453.0, 28454.0, 28455.0, 28456.0, 28457.0, 28458.0, 28459.0, 28460.0, 28461.0, 28462.0, 28463.0, 28464.0, 28465.0, 28466.0, 28467.0, 28468.0, 28469.0, 28470.0, 28471.0, 28472.0, 28473.0, 28474.0, 28475.0, 28476.0, 28477.0, 28478.0, 28479.0, 28480.0, 28481.0, 28482.0, 28483.0, 28484.0, 28485.0, 28486.0, 28487.0, 28488.0, 28489.0, 28490.0, 28491.0, 28492.0, 28493.0, 28494.0, 28495.0, 28496.0, 28497.0, 28498.0, 28499.0, 28500.0, 28501.0, 28502.0, 28503.0, 28504.0, 28505.0, 28506.0, 28507.0, 28508.0, 28509.0, 28510.0, 28511.0, 28512.0, 28513.0, 28514.0, 28515.0, 28516.0, 28517.0, 28518.0, 28519.0, 28520.0, 28521.0, 28522.0, 28523.0, 28524.0, 28525.0, 28526.0, 28527.0, 28528.0, 28529.0, 28530.0, 28531.0, 28532.0, 28533.0, 28534.0, 28535.0, 28536.0, 28537.0, 28538.0, 28539.0, 28540.0, 28541.0, 28542.0, 28543.0, 28544.0, 28545.0, 28546.0, 28547.0, 28548.0, 28549.0, 28550.0, 28551.0, 28552.0, 28553.0, 28554.0, 28555.0, 28556.0, 28557.0, 28558.0, 28559.0, 28560.0, 28561.0, 28562.0, 28563.0, 28564.0, 28565.0, 28566.0, 28567.0, 28568.0, 28569.0, 28570.0, 28571.0, 28572.0, 28573.0, 28574.0, 28575.0, 28576.0, 28577.0, 28578.0, 28579.0, 28580.0, 28581.0, 28582.0, 28583.0, 28584.0, 28585.0, 28586.0, 28587.0, 28588.0, 28589.0, 28590.0, 28591.0, 28592.0, 28593.0, 28594.0, 28595.0, 28596.0, 28597.0, 28598.0, 28599.0, 28600.0, 28601.0, 28602.0, 28603.0, 28604.0, 28605.0, 28606.0, 28607.0, 28608.0, 28609.0, 28610.0, 28611.0, 28612.0, 28613.0, 28614.0, 28615.0, 28616.0, 28617.0, 28618.0, 28619.0, 28620.0, 28621.0, 28622.0, 28623.0, 28624.0, 28625.0, 28626.0, 28627.0, 28628.0, 28629.0, 28630.0, 28631.0, 28632.0, 28633.0, 28634.0, 28635.0, 28636.0, 28637.0, 28638.0, 28639.0, 28640.0, 28641.0, 28642.0, 28643.0, 28644.0, 28645.0, 28646.0, 28647.0, 28648.0, 28649.0, 28650.0, 28651.0, 28652.0, 28653.0, 28654.0, 28655.0, 28656.0, 28657.0, 28658.0, 28659.0, 28660.0, 28661.0, 28662.0, 28663.0, 28664.0, 28665.0, 28666.0, 28667.0, 28668.0, 28669.0, 28670.0, 28671.0, 28672.0, 28673.0, 28674.0, 28675.0, 28676.0, 28677.0, 28678.0, 28679.0, 28680.0, 28681.0, 28682.0, 28683.0, 28684.0, 28685.0, 28686.0, 28687.0, 28688.0, 28689.0, 28690.0, 28691.0, 28692.0, 28693.0, 28694.0, 28695.0, 28696.0, 28697.0, 28698.0, 28699.0, 28700.0, 28701.0, 28702.0, 28703.0, 28704.0, 28705.0, 28706.0, 28707.0, 28708.0, 28709.0, 28710.0, 28711.0, 28712.0, 28713.0, 28714.0, 28715.0, 28716.0, 28717.0, 28718.0, 28719.0, 28720.0, 28721.0, 28722.0, 28723.0, 28724.0, 28725.0, 28726.0, 28727.0, 28728.0, 28729.0, 28730.0, 28731.0, 28732.0, 28733.0, 28734.0, 28735.0, 28736.0, 28737.0, 28738.0, 28739.0, 28740.0, 28741.0, 28742.0, 28743.0, 28744.0, 28745.0, 28746.0, 28747.0, 28748.0, 28749.0, 28750.0, 28751.0, 28752.0, 28753.0, 28754.0, 28755.0, 28756.0, 28757.0, 28758.0, 28759.0, 28760.0, 28761.0, 28762.0, 28763.0, 28764.0, 28765.0, 28766.0, 28767.0, 28768.0, 28769.0, 28770.0, 28771.0, 28772.0, 28773.0, 28774.0, 28775.0, 28776.0, 28777.0, 28778.0, 28779.0, 28780.0, 28781.0, 28782.0, 28783.0, 28784.0, 28785.0, 28786.0, 28787.0, 28788.0, 28789.0, 28790.0, 28791.0, 28792.0, 28793.0, 28794.0, 28795.0, 28796.0, 28797.0, 28798.0, 28799.0, 28800.0, 28801.0, 28802.0, 28803.0, 28804.0, 28805.0, 28806.0, 28807.0, 28808.0, 28809.0, 28810.0, 28811.0, 28812.0, 28813.0, 28814.0, 28815.0, 28816.0, 28817.0, 28818.0, 28819.0, 28820.0, 28821.0, 28822.0, 28823.0, 28824.0, 28825.0, 28826.0, 28827.0, 28828.0, 28829.0, 28830.0, 28831.0, 28832.0, 28833.0, 28834.0, 28835.0, 28836.0, 28837.0, 28838.0, 28839.0, 28840.0, 28841.0, 28842.0, 28843.0, 28844.0, 28845.0, 28846.0, 28847.0, 28848.0, 28849.0, 28850.0, 28851.0, 28852.0, 28853.0, 28854.0, 28855.0, 28856.0, 28857.0, 28858.0, 28859.0, 28860.0, 28861.0, 28862.0, 28863.0, 28864.0, 28865.0, 28866.0, 28867.0, 28868.0, 28869.0, 28870.0, 28871.0, 28872.0, 28873.0, 28874.0, 28875.0, 28876.0, 28877.0, 28878.0, 28879.0, 28880.0, 28881.0, 28882.0, 28883.0, 28884.0, 28885.0, 28886.0, 28887.0, 28888.0, 28889.0, 28890.0, 28891.0, 28892.0, 28893.0, 28894.0, 28895.0, 28896.0, 28897.0, 28898.0, 28899.0, 28900.0, 28901.0, 28902.0, 28903.0, 28904.0, 28905.0, 28906.0, 28907.0, 28908.0, 28909.0, 28910.0, 28911.0, 28912.0, 28913.0, 28914.0, 28915.0, 28916.0, 28917.0, 28918.0, 28919.0, 28920.0, 28921.0, 28922.0, 28923.0, 28924.0, 28925.0, 28926.0, 28927.0, 28928.0, 28929.0, 28930.0, 28931.0, 28932.0, 28933.0, 28934.0, 28935.0, 28936.0, 28937.0, 28938.0, 28939.0, 28940.0, 28941.0, 28942.0, 28943.0, 28944.0, 28945.0, 28946.0, 28947.0, 28948.0, 28949.0, 28950.0, 28951.0, 28952.0, 28953.0, 28954.0, 28955.0, 28956.0, 28957.0, 28958.0, 28959.0, 28960.0, 28961.0, 28962.0, 28963.0, 28964.0, 28965.0, 28966.0, 28967.0, 28968.0, 28969.0, 28970.0, 28971.0, 28972.0, 28973.0, 28974.0, 28975.0, 28976.0, 28977.0, 28978.0, 28979.0, 28980.0, 28981.0, 28982.0, 28983.0, 28984.0, 28985.0, 28986.0, 28987.0, 28988.0, 28989.0, 28990.0, 28991.0, 28992.0, 28993.0, 28994.0, 28995.0, 28996.0, 28997.0, 28998.0, 28999.0, 29000.0, 29001.0, 29002.0, 29003.0, 29004.0, 29005.0, 29006.0, 29007.0, 29008.0, 29009.0, 29010.0, 29011.0, 29012.0, 29013.0, 29014.0, 29015.0, 29016.0 }
    };
    mavlink_oaire_rfsensor_trace_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.frequency, packet_in.frequency, sizeof(float)*1000);
        mav_array_memcpy(packet1.trace, packet_in.trace, sizeof(float)*1000);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_trace_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_oaire_rfsensor_trace_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_trace_pack(system_id, component_id, &msg , packet1.frequency , packet1.trace );
    mavlink_msg_oaire_rfsensor_trace_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_trace_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.frequency , packet1.trace );
    mavlink_msg_oaire_rfsensor_trace_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_oaire_rfsensor_trace_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_trace_send(MAVLINK_COMM_1 , packet1.frequency , packet1.trace );
    mavlink_msg_oaire_rfsensor_trace_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OAIRE_RFSENSOR_TRACE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OAIRE_RFSENSOR_TRACE) != NULL);
#endif
}

static void mavlink_test_oaire_rfsensor_chpower(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_oaire_rfsensor_chpower_t packet_in = {
        17.0,45.0
    };
    mavlink_oaire_rfsensor_chpower_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.frq = packet_in.frq;
        packet1.chpower = packet_in.chpower;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_chpower_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_oaire_rfsensor_chpower_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_chpower_pack(system_id, component_id, &msg , packet1.frq , packet1.chpower );
    mavlink_msg_oaire_rfsensor_chpower_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_chpower_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.frq , packet1.chpower );
    mavlink_msg_oaire_rfsensor_chpower_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_oaire_rfsensor_chpower_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_oaire_rfsensor_chpower_send(MAVLINK_COMM_1 , packet1.frq , packet1.chpower );
    mavlink_msg_oaire_rfsensor_chpower_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("OAIRE_RFSENSOR_CHPOWER") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_OAIRE_RFSENSOR_CHPOWER) != NULL);
#endif
}

static void mavlink_test_ardupilotmega(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_sensor_offsets(system_id, component_id, last_msg);
    mavlink_test_set_mag_offsets(system_id, component_id, last_msg);
    mavlink_test_meminfo(system_id, component_id, last_msg);
    mavlink_test_ap_adc(system_id, component_id, last_msg);
    mavlink_test_digicam_configure(system_id, component_id, last_msg);
    mavlink_test_digicam_control(system_id, component_id, last_msg);
    mavlink_test_mount_configure(system_id, component_id, last_msg);
    mavlink_test_mount_control(system_id, component_id, last_msg);
    mavlink_test_mount_status(system_id, component_id, last_msg);
    mavlink_test_fence_point(system_id, component_id, last_msg);
    mavlink_test_fence_fetch_point(system_id, component_id, last_msg);
    mavlink_test_ahrs(system_id, component_id, last_msg);
    mavlink_test_simstate(system_id, component_id, last_msg);
    mavlink_test_hwstatus(system_id, component_id, last_msg);
    mavlink_test_radio(system_id, component_id, last_msg);
    mavlink_test_limits_status(system_id, component_id, last_msg);
    mavlink_test_wind(system_id, component_id, last_msg);
    mavlink_test_data16(system_id, component_id, last_msg);
    mavlink_test_data32(system_id, component_id, last_msg);
    mavlink_test_data64(system_id, component_id, last_msg);
    mavlink_test_data96(system_id, component_id, last_msg);
    mavlink_test_rangefinder(system_id, component_id, last_msg);
    mavlink_test_airspeed_autocal(system_id, component_id, last_msg);
    mavlink_test_rally_point(system_id, component_id, last_msg);
    mavlink_test_rally_fetch_point(system_id, component_id, last_msg);
    mavlink_test_compassmot_status(system_id, component_id, last_msg);
    mavlink_test_ahrs2(system_id, component_id, last_msg);
    mavlink_test_camera_status(system_id, component_id, last_msg);
    mavlink_test_camera_feedback(system_id, component_id, last_msg);
    mavlink_test_battery2(system_id, component_id, last_msg);
    mavlink_test_ahrs3(system_id, component_id, last_msg);
    mavlink_test_autopilot_version_request(system_id, component_id, last_msg);
    mavlink_test_remote_log_data_block(system_id, component_id, last_msg);
    mavlink_test_remote_log_block_status(system_id, component_id, last_msg);
    mavlink_test_led_control(system_id, component_id, last_msg);
    mavlink_test_mag_cal_progress(system_id, component_id, last_msg);
    mavlink_test_ekf_status_report(system_id, component_id, last_msg);
    mavlink_test_pid_tuning(system_id, component_id, last_msg);
    mavlink_test_deepstall(system_id, component_id, last_msg);
    mavlink_test_gimbal_report(system_id, component_id, last_msg);
    mavlink_test_gimbal_control(system_id, component_id, last_msg);
    mavlink_test_gimbal_torque_cmd_report(system_id, component_id, last_msg);
    mavlink_test_gopro_heartbeat(system_id, component_id, last_msg);
    mavlink_test_gopro_get_request(system_id, component_id, last_msg);
    mavlink_test_gopro_get_response(system_id, component_id, last_msg);
    mavlink_test_gopro_set_request(system_id, component_id, last_msg);
    mavlink_test_gopro_set_response(system_id, component_id, last_msg);
    mavlink_test_rpm(system_id, component_id, last_msg);
    mavlink_test_device_op_read(system_id, component_id, last_msg);
    mavlink_test_device_op_read_reply(system_id, component_id, last_msg);
    mavlink_test_device_op_write(system_id, component_id, last_msg);
    mavlink_test_device_op_write_reply(system_id, component_id, last_msg);
    mavlink_test_adap_tuning(system_id, component_id, last_msg);
    mavlink_test_vision_position_delta(system_id, component_id, last_msg);
    mavlink_test_aoa_ssa(system_id, component_id, last_msg);
    mavlink_test_esc_telemetry_1_to_4(system_id, component_id, last_msg);
    mavlink_test_esc_telemetry_5_to_8(system_id, component_id, last_msg);
    mavlink_test_esc_telemetry_9_to_12(system_id, component_id, last_msg);
    mavlink_test_osd_param_config(system_id, component_id, last_msg);
    mavlink_test_osd_param_config_reply(system_id, component_id, last_msg);
    mavlink_test_osd_param_show_config(system_id, component_id, last_msg);
    mavlink_test_osd_param_show_config_reply(system_id, component_id, last_msg);
    mavlink_test_obstacle_distance_3d(system_id, component_id, last_msg);
    mavlink_test_water_depth(system_id, component_id, last_msg);
    mavlink_test_mcu_status(system_id, component_id, last_msg);
    mavlink_test_oaire_rfsensor_setconfig(system_id, component_id, last_msg);
    mavlink_test_oaire_rfsensor_setconfig_ack(system_id, component_id, last_msg);
    mavlink_test_oaire_rfsensor_trace(system_id, component_id, last_msg);
    mavlink_test_oaire_rfsensor_chpower(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ARDUPILOTMEGA_TESTSUITE_H

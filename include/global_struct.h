#pragma once
#ifndef _GLOBALS_STRUCT_H
#define _GLOBALS_STRUCT_H

struct SensorData {
    int    imu_count=0; /// imu count value to check for new values
    double accel[3];	///< accelerometer (XYZ) in units of m/s^2
	double gyro[3];		///< gyroscope (XYZ) in units of degrees/s
	double mag[3];		///< magnetometer (XYZ) in units of uT
	double temp;		///< thermometer, in units of degrees Celsius

    int bmp_count = 0;  /// bmp sensor update count
    double pressure_pa;	///< current pressure in pascals

    int gps_count=0;   /// gps count value to check for new values
    double lat;        /// latitude (deg)
    double lon;        /// longitude (deg)
    double alt;        /// altitude MSL (m)
    double alt_agl;    /// altitude AGL (m)
};


struct StateData {
    float p_n = 0;
    float p_e = 0;
    float p_d = 0;
    float h = 0;

    float u = 0;
    float v = 0;
    float w = 0;

    float quat[4] = {1,0,0,0};

    float p = 0;
    float q = 0;
    float r = 0;

    float alpha = 0;
    float beta = 0;

};

struct Control{
    float throttle;
    float aileron;
    float elevator;
    float rudder;
};

extern SensorData sensor_data;
extern StateData state;
extern Control control;

#endif

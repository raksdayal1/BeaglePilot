#pragma once
#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <stdio.h>
#include <rc/pthread.h>

// Debug Flags
#define SENSOR_DEBUG 0
#define RC_DEBUG 0

// MPU I2C bus for Robotics Cape and BeagleboneBlue is 2
#define I2C_BUS 2

// choice of 1,2,4,8,16 oversampling. Here we use 16 and sample at 25hz which
// is close to the update rate specified in rc/bmp.h for that oversample.
#define OVERSAMPLE  BMP_OVERSAMPLE_16

// choice of OFF, 2, 4, 8, 16 filter constants. Here we turn off the filter and
// opt to use our own 2nd order filter instead.
#define INTERNAL_FILTER	BMP_FILTER_OFF


// ====================== GLOBAL Variables ============================ //
extern int __running;

typedef enum flight_mode_t{
	MANUAL,
	STABILIZE,
    GUIDED,
    AUTO
} flight_mode_t;

extern flight_mode_t flight_mode;

// ====================== END GLOBAL Variables ======================== //

// ====================== Thread functions ============================= //
// static void* __sensor_thread(void* arg) // This is the template for a thread function
void* __sensor_thread(void* );
void* __rc_thread(void* );
void* __telemetry_thread(void* );
void* __control_thread(void* );

#endif
/**
  * @file sensor.cpp
  * @brief thread function that runs all the internal sensors
  * available on the Beaglebone Blue as well the connected sensors
  * This thread will run at 400Hz and sample all sensors and fill the
  * sensor struct
  *
  * Available Sensors
  *     1. IMU - Accel, Gyro, Magnetometer, Thermometer
  *     2. BMP - Pressure sensor, 
  *
  * Connected Sensors
  *     1. GPS -  CAN GPS
  *     2. Airspeed - I2C airspeed Sensors(not on the board)
*/

#include "globals.h"
#include "global_struct.h"
#include <rc/mpu.h>
#include <rc/bmp.h>
#include <rc/time.h>

// bus for Robotics Cape and BeagleboneBlue is 2
#define I2C_BUS 2
// choice of 1,2,4,8,16 oversampling. Here we use 16 and sample at 25hz which
// is close to the update rate specified in rc/bmp.h for that oversample.
#define OVERSAMPLE  BMP_OVERSAMPLE_16

// choice of OFF, 2, 4, 8, 16 filter constants. Here we turn off the filter and
// opt to use our own 2nd order filter instead.
#define INTERNAL_FILTER	BMP_FILTER_OFF

#define LOOP_RATE_HZ 200

void* __sensor_thread(void* arg)
{

  static int thread_ret_val;
  printf("Starting sensor thread\n");
    
  rc_mpu_data_t mpu_data; //struct to hold mpu data
  rc_bmp_data_t bmp_data; //struct to hold bmp data

  // use defaults for now, except also enable magnetometer.
	rc_mpu_config_t mpu_conf = rc_mpu_default_config();
	mpu_conf.i2c_bus = I2C_BUS;
	mpu_conf.enable_magnetometer = 1;
  mpu_conf.show_warnings = 0;

  // Init the sensors
  // init barometer and read in first data
	if(rc_bmp_init(OVERSAMPLE, INTERNAL_FILTER)){
    fprintf(stderr,"rc_bmp_init failed\n");
    thread_ret_val = -1;
	  return (void*)&thread_ret_val;
  }

	if(rc_bmp_read(&bmp_data)){
    fprintf(stderr,"rc_bmp_read failed\n");
    thread_ret_val = -1;
	  return (void*)&thread_ret_val;
  }

  // Init the IMU
  if(rc_mpu_initialize(&mpu_data, mpu_conf)){
		fprintf(stderr,"rc_mpu_initialize failed\n");
		thread_ret_val = -1;
	  return (void*)&thread_ret_val;
	}

  if(SENSOR_DEBUG){
    printf("   Accel XYZ(m/s^2)  |");
    printf("   Gyro XYZ (rad/s)  |");
    printf("  Mag Field XYZ(uT)  |");
    printf(" IMU Temp (C) |");
    printf(" BMP Temp (C) |");
    printf(" pressure kpa |");
    printf("\n");
  }

  while(__running)
  {
    // read MPU sensor data
    if(rc_mpu_read_accel(&mpu_data)<0 && rc_mpu_read_gyro(&mpu_data)<0 && rc_mpu_read_mag(&mpu_data) && rc_mpu_read_temp(&mpu_data))
    {
      printf("Sensor update failed\n");
    }
    else{
      sensor_data.imu_count += 1;
      sensor_data.accel[0] = 	mpu_data.accel[0];
      sensor_data.accel[1] = 	mpu_data.accel[0];
      sensor_data.accel[2] = 	mpu_data.accel[0];

      sensor_data.gyro[0] = 	mpu_data.gyro[0]*DEG_TO_RAD;
      sensor_data.gyro[1] = 	mpu_data.gyro[0]*DEG_TO_RAD;
      sensor_data.gyro[2] = 	mpu_data.gyro[0]*DEG_TO_RAD;

      sensor_data.mag[0] = 	mpu_data.mag[0];
      sensor_data.mag[1] = 	mpu_data.mag[0];
      sensor_data.mag[2] = 	mpu_data.mag[0];

      sensor_data.temp = mpu_data.temp;
    }

    
    // read the BMP sensor data
    if(rc_bmp_read(&bmp_data)){
       continue;
    }
    else{
      sensor_data.bmp_count += 1;
      sensor_data.pressure_pa = bmp_data.pressure_pa/1000.0;
    }

    //if(gps_read)
    //{}

    if(SENSOR_DEBUG){

      printf("\r");
      printf("%6.2f %6.2f %6.2f |",	mpu_data.accel[0],\
                mpu_data.accel[1],\
                mpu_data.accel[2]);
      printf("%6.1f %6.1f %6.1f |",	mpu_data.gyro[0]*DEG_TO_RAD,\
                mpu_data.gyro[1]*DEG_TO_RAD,\
                mpu_data.gyro[2]*DEG_TO_RAD);
      printf("%6.1f %6.1f %6.1f |",	mpu_data.mag[0],\
                mpu_data.mag[1],\
                mpu_data.mag[2]);
      printf(" %4.1f |", mpu_data.temp);
      printf("%6.2lf |", bmp_data.temp_c);
      printf("%7.2lf |", bmp_data.pressure_pa/1000.0);

      fflush(stdout);
    }
    
    // loop rate
    rc_usleep(1000000/LOOP_RATE_HZ);

  }
  printf("\n");

  // When loop terminates exit the sensors
  rc_mpu_power_off();
  rc_bmp_power_off();

	printf("exiting sensor thread\n");
	thread_ret_val=0;
	return (void*)&thread_ret_val;
}
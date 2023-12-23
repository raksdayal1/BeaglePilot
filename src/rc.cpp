/**
  * @file rc.cpp
  * @brief thread function that runs all the radio controller loop
  * This thread will run at 40Hz and has a passthrough function 
  * implemented in MANUAL MODE
  * 
*/

#include <stdio.h>
#include <getopt.h>
#include <signal.h>
#include <rc/dsm.h>
#include <rc/servo.h>
#include <rc/time.h>
#include <rc/adc.h>

#include "globals.h"
#include "global_struct.h"

#define LOOP_RATE_HZ 40

typedef enum p_mode_t{
	NONE,
	POWERON,
	POWEROFF
} p_mode_t;

// function to be called every time new a new DSM packet is received.
static void __send_pulses(void)
{
	int i, ch, val;

	// send single to working channels
	for(i=1; i<=8; i++){
		val=rc_dsm_ch_raw(i);
		if(val>0 && flight_mode == MANUAL) rc_servo_send_pulse_us(i, val); // passthrough only in manual mode
	}

	if(RC_DEBUG){
		// print all channels
		printf("\r");
		ch = rc_dsm_channels();
		for(i=1;i<=ch;i++){
			printf("% 4d   ", rc_dsm_ch_raw(i));
		}
		fflush(stdout);
	}
	return;
}

void* __rc_thread(void* arg)
{
    static int thread_ret_val;
    printf("Starting RC thread\n");

    p_mode_t mode = POWEROFF;

    if(rc_dsm_init()==-1){
        thread_ret_val = -1;
	    return (void*)&thread_ret_val;
    }

	// if power has been requested, make sure battery is connected!
	if(mode == POWERON){
		// read adc to make sure battery is connected
		if(rc_adc_init()){
			fprintf(stderr,"ERROR: failed to run rc_adc_init()\n");
            thread_ret_val = -1;
            return (void*)&thread_ret_val;
		}
		if(rc_adc_batt()<6.0){
			fprintf(stderr,"ERROR: battery disconnected or insufficiently charged to drive motors\n");
            thread_ret_val = -1;
            return (void*)&thread_ret_val;
		}
		rc_adc_cleanup();
		if(rc_servo_power_rail_en(1)){
			fprintf(stderr,"failed to enable power rail\n");
            thread_ret_val = -1;
            return (void*)&thread_ret_val;
		}
	}

    rc_dsm_set_callback(&__send_pulses);
	while(__running){
		if(rc_dsm_is_connection_active()==0){
            if(RC_DEBUG){
                printf("\rSeconds since last DSM packet: ");
                printf("%0.1f ", rc_dsm_nanos_since_last_packet()/1000000000.0);
                printf("                             ");
                fflush(stdout);
            }
		}
		rc_usleep(1000000/LOOP_RATE_HZ);
	}
	printf("\n");
	rc_dsm_cleanup();

    printf("exiting RC thread\n");
	thread_ret_val=0;
	return (void*)&thread_ret_val;
}
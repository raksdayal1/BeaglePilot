#include <stdio.h>
#include <unistd.h> // for sleep
#include <signal.h>
#include <stdlib.h> // for strtol
#include <iostream>

#include "globals.h"

// interrupt handler to catch ctrl-c
static void __signal_handler(__attribute__ ((unused)) int dummy)
{
	__running=0;
	return;
}

static int __get_policy(char p, int *policy)
{
	switch (p) {
	case 'f': *policy = SCHED_FIFO;     return 0;
	case 'r': *policy = SCHED_RR;       return 0;
	case 'o': *policy = SCHED_OTHER;    return 0;
	default:
		fprintf(stderr, "invalid policy\n");
		return -1;
	}
}

int main(){

	static pthread_t sthread, rc_thread, telem_thread, control_thread;
	int s_ret, rc_ret, telem_ret, control_ret;
	int policy;
	int spriority, rcpriority, telempriority, controlpriority;
	char p = 'o';

	spriority = 0; // priority for sensor thread
	rcpriority = 0; // priority for rc thread
	telempriority = 0; // priority for telem thread
	controlpriority = 0; //priority for control thread

	int arg=2; // argument sent to the thread
	void *sensor_retval, *rc_retval, *telem_retval, *control_retval; // return value of threads
	
	__get_policy(p, &policy);

    // set signal handler so the loop can exit cleanly
	signal(SIGINT, __signal_handler);

	__running = 1;

	// start sensor thread
	if(rc_pthread_create(&sthread, __sensor_thread, (void*)&arg, policy, spriority)){
		fprintf(stderr, "failed to start Sensor thread\n");
		return -1;
	}

	// start rc thread
	if(rc_pthread_create(&rc_thread, __rc_thread, (void*)&arg, policy, rcpriority)){
		fprintf(stderr, "failed to start RC thread\n");
		return -1;
	}

	// start telem thread
	if(rc_pthread_create(&telem_thread, __telemetry_thread, (void*)&arg, policy, telempriority)){
		fprintf(stderr, "failed to start Telem thread\n");
		return -1;
	}

	// start control thread
	if(rc_pthread_create(&control_thread, __control_thread, (void*)&arg, policy, controlpriority)){
		fprintf(stderr, "failed to start Control thread\n");
		return -1;
	}

	// wait for shutdown signal
	while(__running)	sleep(1);

	// join sensor thread with 1.5s timeout
	s_ret=rc_pthread_timed_join(sthread, &sensor_retval, 1);
	if(s_ret==1) fprintf(stderr,"joining sensor thread timed out\n");
	printf("Sensor thread returned: %d\n", *(int*)sensor_retval);

	rc_ret=rc_pthread_timed_join(rc_thread, &rc_retval, 1);
	if(rc_ret==1) fprintf(stderr,"joining rc thread timed out\n");
	printf("RC thread returned: %d\n", *(int*)rc_retval);

	telem_ret=rc_pthread_timed_join(telem_thread, &telem_retval, 1);
	if(rc_ret==1) fprintf(stderr,"joining telem thread timed out\n");
	printf("Telem thread returned: %d\n", *(int*)telem_retval);

	control_ret=rc_pthread_timed_join(control_thread, &control_retval, 1);
	if(control_ret==1) fprintf(stderr,"joining control thread timed out\n");
	printf("Control thread returned: %d\n", *(int*)control_retval);

    return 0;
}
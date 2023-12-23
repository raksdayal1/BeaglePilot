/**
  * @file rc.cpp
  * @brief thread function that runs all the controller functionality. Loop runs 
  * at 50 Hz
  * 
*/
#include "globals.h"
#include "global_struct.h"
#include <rc/time.h>

#include "pid.h"


#define LOOP_RATE_HZ 100

void* __control_thread(void* arg)
{

  static int thread_ret_val;
  printf("Starting Control thread\n");
  
  
  while(__running)
  {



    // loop rate
    rc_usleep(1000000/LOOP_RATE_HZ);
  }

  printf("exiting Control thread\n");
  thread_ret_val=0;
  return (void*)&thread_ret_val;
}
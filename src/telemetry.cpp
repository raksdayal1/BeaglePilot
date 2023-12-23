/**
  * @file telemetry.cpp
  * @brief thread function that runs all the telemetry functions
  * 
*/

#include "globals.h"
#include "global_struct.h"
#include <rc/time.h>
#include "common/mavlink.h"


void* __telemetry_thread(void* arg)
{
  static int thread_ret_val;
  printf("Starting telemetry thread\n");
  
  // Init Serial. arg is used to pass the serial params


  bool hb_recvd = false;
  while(__running && !hb_recvd)
  {
    // send heartbeat and wait for heartbeat
  }
 
  while(__running)
  {
    // send hb at 1hz

    // send attitude data at 10 hz

    // send HUD data at 4 hz

    // send GPS at 4 hz

    // read any requests from GCS

  }

  printf("exiting telemetry thread\n");
  thread_ret_val=0;
  return (void*)&thread_ret_val;
}
#include "globals.h"
#include "global_struct.h"

// flag to indicate if all threads are running
int __running = 0;

// flight mode
flight_mode_t flight_mode = MANUAL;

// Global Struct for holding SensorData
SensorData sensor_data = {};

// Global Struct for holding StateData
StateData state = {};

// Global Struct for Control
Control control = {};

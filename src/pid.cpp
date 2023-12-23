#include "pid.h"

PID::PID(float Kp, float Ki, float Kd, float dt)
{
    kp = Kp;
    kd = Kd;
    ki = Ki;
    dt = dt;

    error = 0;
    error_prev = 0;
    error_i = 0;
}

PID::~PID()
{

}

void PID::update(float y, float y_cmd, float& u)
{
    error = y_cmd - y;

    error_d = (error - error_prev)/dt;

    error_i += error;

    u = kp*error + kd*error_d + ki*error_i;
}



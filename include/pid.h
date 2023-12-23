#pragma once
#ifndef _PID_H_
#define _PID_H_

class PID{
    public:
        PID(float Kp, float Ki, float Kd, float dt);
        ~PID();

        void update(float y, float y_cmd, float& u);

    private:
        float dt;
        float kp, ki, kd;
        float error, error_prev, error_d, error_i;
};


#endif
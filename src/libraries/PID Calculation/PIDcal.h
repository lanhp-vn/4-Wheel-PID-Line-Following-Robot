#ifndef PIDCAL
#define PIDCAL

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class PIDcal {
  public:
    //Constructor
    PIDcal(int ENA, int ENB);
    //Methods
    void setPIDspeed(float PIDval, int left_speed, int right_speed, int init_speed);
    float PID_cal(float error, float previousError); //return PIDvalue
    float errorVal();
  private:
    float Kp, Ki, Kd, P, I, D;
    int _ENA;
    int _ENB;
};
#endif
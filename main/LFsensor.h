#ifndef LFSENSOR
#define LFSENSOR

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class LFsensor {
  public:
    //Constructor
    LFsensor(int S1, int S2, int S3, int S4, int S5);
    //Methods
    void readLFsensor();
    void testLineFollowSensor();
    float errorVal();
    float modeVal();
  private:
    int _s1, _s2, _s3, _s4, _s5;
    int LFS1, LFS2, LFS3, LFS4, LFS5;
    int STOP, FOLLOWING_LINE, FINISH, TURNING_left, TURNING_right, mode;
    float error;
};
#endif
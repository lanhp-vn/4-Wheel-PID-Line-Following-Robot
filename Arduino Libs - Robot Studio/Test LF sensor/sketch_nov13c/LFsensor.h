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
    void readLFsensor(int mode, float error);
  private:
    int _s1, _s2, _s3, _s4, _s5;
    int STOPPED, FOLLOWING_LINE, NO_LINE;
    int LFSensor[];
};
#endif
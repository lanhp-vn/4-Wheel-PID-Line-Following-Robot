#ifndef encoder
#define encoder

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Encoder_Read
{
  public:
    //Constructor
    Encoder_Read();
    //Methods
    bool noIntrFound(long dtime);
    //int rpm_cal();
    float velo_cal(int RPM);
    float dist_cal(int count);
    float angle_cal(int leftCount, int rightCount);
  
  private:
    //volatile unsigned int _enLeft, _enRight;
    float radius;
    unsigned long prev_ms;
};

#endif
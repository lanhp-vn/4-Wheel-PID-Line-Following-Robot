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
    void left_ISR();
    void right_ISR();
    void noIntrFound();
    void rpm_cal(int count);
    void velo_cal();
    void dist_cal(int count);
    void deg90_cal(int leftCount, int rightCount);
  
  private:
    //volatile unsigned int _enLeft, _enRight;
    int left_count, right_count;
    int angle;
    float radius, rpm, v, dist, t, timetaken;
    unsigned long cur_ms, prev_ms, dtime;
};

#endif
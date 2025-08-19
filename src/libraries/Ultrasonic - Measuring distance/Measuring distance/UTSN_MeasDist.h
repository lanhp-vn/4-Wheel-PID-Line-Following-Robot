#ifndef UTSN_measdist
#define UTSN_measdist

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class UTSN_MeasDist {
  public:
    //Constructor
    UTSN_MeasDist(int trigPin);
    //Methods
    float measDist(int echoPin);
  private:
    int trig_Pin;

};
#endif
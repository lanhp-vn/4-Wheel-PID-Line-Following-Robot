#ifndef ultrasonic
#define ultrasonic

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Ultrasonic {
  public:
    //Constructor
    Ultrasonic(int trigPin);
    //Methods
    float measDist(int echoPin);
    bool no_obstacle(int meas_pin, float dist);
  private:
    int trig_pin;

};
#endif
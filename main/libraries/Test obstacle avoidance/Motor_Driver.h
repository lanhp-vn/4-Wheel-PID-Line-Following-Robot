#ifndef motorDriver
#define motorDriver

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Motor_Driver {

  public:
    //Constructor
    Motor_Driver(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4);
    //Methods
    void setSpeed(int leftVal, int rightVal);
    void stopCar();
    void forward();
    void backward(int speed);
    void turnRight(int deg);
    void turnLeft(int deg);

  private:
    int _ENA;
    int _ENB;
    int _IN1;
    int _IN2;
    int _IN3;
    int _IN4;

};

#endif
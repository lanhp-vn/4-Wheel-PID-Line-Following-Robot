#include "Motor_Driver.h"
#include "Encoder_Read.h"
#include "Ultrasonic.h"
#include "SimpleKalmanFilter.h"

#define ENA A1
#define ENB A0
#define Trig A2
#define Front A3
#define Right A4
#define Left A5
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define leftEncoder 2
#define rightEncoder 3

volatile int left_count, right_count, rotation;
unsigned long timetaken, pevtime, dtime;
float v, angle, left_dist, right_dist, dist;
int rpm, rpm_filtered;
int leftVal = 200;
int rightVal = leftVal - 10;

//Declare classes in included libraries
Motor_Driver driver = Motor_Driver(ENA,ENB,IN1,IN2,IN3,IN4);
Encoder_Read encod = Encoder_Read();
SimpleKalmanFilter filter = SimpleKalmanFilter(2, 2, 0.01);


//***//
void setup() {
  // put your setup code here, to run once:

}



//***//
// ISR functions
void left_ISR()
{
  left_count ++; delay(10);
}

void right_ISR()
{
  right_count ++; delay(10);
  rotation++;
  dtime = millis();
  if(rotation>=40)
  {
    timetaken = (millis() - pevtime)/2;
    rpm = (1000/timetaken)*60;
    rpm = filter.updateEstimate(rpm);
    pevtime = millis();
    rotation = 0;
  }
}



//*****//
void loop() {
  // put your main code here, to run repeatedly:

}

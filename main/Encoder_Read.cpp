#include "Arduino.h"
#include "Encoder_Read.h"

Encoder_Read::Encoder_Read()
{
  //Initialize all variables to be 0
  prev_ms = 0;
  radius = 0.033; //radius of wheel in meter
}


bool Encoder_Read::noIntrFound(unsigned long dfr_time, int wait_time)
{
  if(millis() - dfr_time > wait_time){return true;}
}

//Calculate robot's velocity
float Encoder_Read::velo_cal(int RPM)
{
  //Velocity = 2π × radius × RPS 
  float v = (2*3.14*radius) * (RPM/60);
  return v;
}

//Calculate robot's distance
float Encoder_Read::dist_cal(int count)
{
  float dist = (2*3.14*radius) * (count/40);
  return dist;
}

//Calculate robot's rotating angle
float Encoder_Read::angle_cal(int leftCount, int rightCount)
{
  float angle_left = (leftCount % 360) * (90/80);
  float angle_right = (rightCount % 360) * (90/80);
  float angle = angle_right - angle_left;  
  return angle;
}

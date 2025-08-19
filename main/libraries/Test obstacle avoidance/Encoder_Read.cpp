#include "Arduino.h"
#include "Encoder_Read.h"

Encoder_Read::Encoder_Read()
{
  //Initialize all variables to be 0
  prev_ms = 0;
  radius = 0.033; //radius of wheel in meter
}

//Pretend this is functions you have written

bool Encoder_Read::noIntrFound(long dtime)
{
  if(millis() - dtime > 500){return true;}
}

// int Encoder_Read::rpm_cal(int count)
// {
//   int rpm = 0;
//   cur_ms = millis();
//   //if the wheel rotates in 1 sec
//   if(cur_ms - prev_ms >= 1000)
//   {
//     rpm = (count/20)*60;
//     prev_ms = cur_ms;
//     count = 0;
//   }
//   return rpm;
// }

float Encoder_Read::velo_cal(int RPM)
{
  //Velocity = 2π × radius × RPS 
  float v = (2*3.14*radius) * (RPM/60);
  return v;
}

float Encoder_Read::dist_cal(int count)
{
  float dist = (2*3.14*radius) * (count/20);
  return dist;
}

float Encoder_Read::angle_cal(int leftCount, int rightCount)
{
  float angle_left = (leftCount % 360) * (90/40);
  float angle_right = (rightCount % 360) * (90/40);
  float angle = angle_right - angle_left;
  return angle;
}

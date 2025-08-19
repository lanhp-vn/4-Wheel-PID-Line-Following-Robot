#include "Arduino.h"
#include "Encoder_Read.h"

Encoder_Read::Encoder_Read()
{
  //Anything you need when initiating your object goes here
  //pinMode(enLeft, INPUT);
  //pinMode(enLeft, INPUT);

  //Initialize all variables to be 0
  left_count = right_count = angle = rpm = prev_ms = 0;
  dtime = 0;
  radius = 0.033; //radius of wheel in meter
  cur_ms = millis();

  //_enLeft = enLeft;
  //_enRight = enRight;

  //attachInterrupt(digitalPinToInterrupt(_enLeft), left_ISR, RISING);
  //attachInterrupt(digitalPinToInterrupt(_enRight), right_ISR, RISING);
}

//Pretend this is functions you have written
void Encoder_Read::left_ISR()
{
  left_count ++;
  delay(10);
  return left_count;
}

void Encoder_Read::right_ISR()
{
  right_count ++;
  delay(10);
  dtime = cur_ms;
  return right_count;
}

void Encoder_Read::noIntrFound()
{
  if(cur_ms - dtime > 2000)
  {
    rpm = v = angle = 0;
    dtime = cur_ms;
  }
  return true;
}

void Encoder_Read::rpm_cal(int count)
{
  //if the wheel rotates in 1 sec
  if(cur_ms - prev_ms >= 1000)
  {
    prev_ms = millis();
    rpm = (count/20)*60;
    count = 0;
  }
  return rpm;
}

void Encoder_Read::velo_cal()
{
  //Velocity = 2π × radius × RPS 
  v = (2*3.14*radius) * (rpm/60);
  return v;
}

void Encoder_Read::dist_cal(int count)
{
  dist = (2*3.14*radius) * (count/20);
  return dist;
}

void Encoder_Read::deg90_cal(int leftCount, int rightCount)
{
  int angle_left = (leftCount % 360) * (90/40);
  int angle_right = (rightCount % 360) * (90/40);
  angle = angle_right - angle_left;
  return angle;
}

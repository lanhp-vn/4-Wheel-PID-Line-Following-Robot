#include "PIDcal.h"

PIDcal::PIDcal(int ENA, int ENB){
  //Anything you need when initiating your object goes here
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT); 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH); 
  _ENA = ENA;
  _ENB = ENB;
  Kp = 50;
  Ki = 0;
  Kd = 0;
  P = I = D = 0;
}

//-------------------------------------------------------------//
//Pretend this is one or more complex and involved functions you have written

float PIDcal::PID_cal(float error, float previousError)
{
  P = error;
  I = I + error;
  D = error-previousError;
  float PIDvalue = (Kp*P) + (Ki*I) + (Kd*D);
  previousError = error;
  return PIDvalue;
}

void PIDcal::setPIDspeed(float PIDval, int left_speed, int right_speed, int init_speed)
{
  left_speed = init_speed - PIDval;
  right_speed = init_speed + PIDval;
  // The motor speed should not exceed the max PWM value
  left_speed = constrain(left_speed, 130, 255);
  right_speed = constrain(right_speed, 130, 255);
  analogWrite(_ENA, left_speed);
  analogWrite(_ENB, right_speed);
}

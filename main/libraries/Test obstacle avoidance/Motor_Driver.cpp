#include "Arduino.h"
#include "Motor_Driver.h"

Motor_Driver::Motor_Driver(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4)
{
  //Anything you need when initiating your object goes here
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  _ENA = ENA;
  _ENB = ENB;
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  _IN4 = IN4;
}

//Pretend this is functions you have written
void Motor_Driver::setSpeed(int leftVal, int rightVal)
{
  analogWrite(_ENA,leftVal);
  analogWrite(_ENB,rightVal);
}

void Motor_Driver::stopCar()
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,LOW);
}

void Motor_Driver::forward()
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH);
  digitalWrite(_IN3,HIGH);
  digitalWrite(_IN4,LOW);
}

void Motor_Driver::backward(int speed)
{
  setSpeed(speed,speed);
  digitalWrite(_IN1,HIGH);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH);
}

void Motor_Driver::turnRight(int deg)
{
  float t;
  int speed = 150;
  stopCar();
  delay(100);
  setSpeed(speed, speed);
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH);
  t=(deg+6)/136.29*1000.;
  delay(t);
  stopCar();
}

void Motor_Driver::turnLeft(int deg)
{
  float t;
  int speed = 150;
  stopCar();
  delay(100);
  setSpeed(speed, speed);
  digitalWrite(_IN1,HIGH);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,HIGH);
  digitalWrite(_IN4,LOW);
  t=(deg+6)/136.29*1000.;
  delay(t);
  stopCar();
}
#include "Arduino.h"
#include "Motor_Driver.h"

Motor_Driver::Motor_Driver(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4)
{
  //Anything you need when initiating your object goes here

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  _ENA = ENA;
  _ENB = ENB;
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  _IN4 = IN4;
}

//Set robot's speed
void Motor_Driver::setSpeed(int left_speed, int right_speed)
{
  analogWrite(_ENA, left_speed);
  analogWrite(_ENB, right_speed);
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

void Motor_Driver::backward()
{
  digitalWrite(_IN1,HIGH);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH);
}

//Robot ROTATES to the right
void Motor_Driver::turnRight()
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,HIGH);
}

//Robot ROTATES to the left
void Motor_Driver::turnLeft()
{
  digitalWrite(_IN1,HIGH);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,HIGH);
  digitalWrite(_IN4,LOW);
}

void Motor_Driver::shiftRight()
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,HIGH);
  digitalWrite(_IN3,LOW);
  digitalWrite(_IN4,LOW);
}

void Motor_Driver::shiftLeft()
{
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,LOW);
  digitalWrite(_IN3,HIGH);
  digitalWrite(_IN4,LOW);
}

//Robot ROTATES 90 degree
void Motor_Driver::turn_90deg(int direction, int delay_90deg)
{
  //Right road --> direction = 0
  //Left road --> direction = 1
  switch(direction)
  {
    case 0:
      turnRight();
      delay(delay_90deg);
      stopCar();
      delay(500);
      break;
    case 1:
      turnLeft();
      delay(delay_90deg);
      stopCar();
      delay(500);
      break;
  }
}
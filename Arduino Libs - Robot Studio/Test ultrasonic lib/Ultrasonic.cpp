#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin){
  //Anything you need when initiating your object goes here
  pinMode(trigPin, OUTPUT);
  trig_pin = trigPin;
}

//Pretend this is one or more complex and involved functions you have written
float Ultrasonic::measDist(int echoPin){
  int pingTravelTime;

  digitalWrite(trig_pin, LOW);   
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);  
  delayMicroseconds(20);
  digitalWrite(trig_pin, LOW);   

  pingTravelTime = pulseIn(echoPin, HIGH);

  float Dist;
  Dist = pingTravelTime * 0.034 / 2;

  return Dist;
}
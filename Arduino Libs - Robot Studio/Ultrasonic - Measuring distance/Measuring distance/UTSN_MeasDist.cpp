#include "Arduino.h"
#include "UTSN_MeasDist.h"

UTSN_MeasDist::UTSN_MeasDist(int trigPin){
  //Anything you need when initiating your object goes here
  pinMode(trigPin, OUTPUT);
  trig_Pin = trigPin;
}

//Pretend this is one or more complex and involved functions you have written
float UTSN_MeasDist::measDist(int echoPin){
  int pingTravelTime;

  digitalWrite(trig_Pin, LOW);   
  delayMicroseconds(2);
  digitalWrite(trig_Pin, HIGH);  
  delayMicroseconds(20);
  digitalWrite(trig_Pin, LOW);   

  pingTravelTime = pulseIn(echoPin, HIGH);

  float Dist;
  Dist = pingTravelTime * 0.034 / 2;

  return Dist;
}
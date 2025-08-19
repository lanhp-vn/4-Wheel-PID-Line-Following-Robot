#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin){
  //Anything you need when initiating your object goes here
  pinMode(trigPin, OUTPUT);
  trig_pin = trigPin;
}

//Measure object ahead using a specified ultrasonic sensor
float Ultrasonic::measDist(int echoPin){
  int pingTravelTime = 0;

  digitalWrite(trig_pin, LOW);   
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);  
  delayMicroseconds(20);
  digitalWrite(trig_pin, LOW);   

  pingTravelTime = pulseIn(echoPin, HIGH);

  float Dist = 0;
  Dist = pingTravelTime * 0.034 / 2;

  return Dist;
}

//Detect object ahead at specified distance
bool Ultrasonic::no_obstacle(int meas_pin, float dist){
  if (meas_pin > dist)
  {return true;}
  else {return false;}
}
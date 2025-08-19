#include "UTSN_MeasDist.h"

int Trig=A2;
int Front=A3;
int Right=A4;
int Left=A5;
float targetDist_Front;
float targetDist_Right;
float targetDist_Left;

UTSN_MeasDist trigPin = UTSN_MeasDist(Trig);

void setup() {
  // put your setup code here, to run once:
  pinMode(Front,INPUT);
  pinMode(Right,INPUT);
  pinMode(Left,INPUT);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  targetDist_Front=trigPin.measDist(Front);
  Serial.print("Front: ");
  Serial.print(targetDist_Front);
  Serial.println(" cm");

  targetDist_Right=trigPin.measDist(Right);
  Serial.print("Right: ");
  Serial.print(targetDist_Right);
  Serial.println(" cm");

  targetDist_Left=trigPin.measDist(Left);
  Serial.print("Left: ");
  Serial.print(targetDist_Left);
  Serial.println(" cm");
  delay(2000);
}
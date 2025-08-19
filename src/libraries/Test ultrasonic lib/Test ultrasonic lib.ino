
#include "Ultrasonic.h"


#define Trig A2
#define Front A3
#define Right A4
#define Left A5
float targetDist_Front; 
float front_noFilter;
float targetDist_Right;
float targetDist_Left;

Ultrasonic UTSN = Ultrasonic(Trig);

void setup() {
  // put your setup code here, to run once:
  pinMode(Front,INPUT);
  pinMode(Right,INPUT);
  pinMode(Left,INPUT);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  targetDist_Front=UTSN.measDist(Front);
  Serial.print("Front: ");
  Serial.print(targetDist_Front);
  Serial.print(",  ");
  Serial.print(front_noFilter);
  Serial.println(" cm");

  /*targetDist_Right=UTSN.measDist(Right);
  Serial.print("Right: ");
  Serial.print(targetDist_Right);
  Serial.println(" cm");

  targetDist_Left=UTSN.measDist(Left);
  Serial.print("Left: ");
  Serial.print(targetDist_Left);
  Serial.println(" cm");*/
  delay(100);
}
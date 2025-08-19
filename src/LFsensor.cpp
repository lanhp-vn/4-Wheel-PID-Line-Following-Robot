#include "LFsensor.h"

LFsensor::LFsensor(int S1, int S2, int S3, int S4, int S5){
  //Anything you need when initiating your object goes here
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  _s1 = S1;
  _s2 = S2;
  _s3 = S3;
  _s4 = S4;
  _s5 = S5;
  FINISH = 0;
  FOLLOWING_LINE = 1;
  STOP = 2;
  TURNING_left = 3;
  TURNING_right = 4;
  error = 0;
  mode = 0;
}

//-------------------------------------------------------------//
/* read line sensors values
LINE_FOLLOWING 	Error Value
1 1 1 0 0  e=3
0 1 0 0 0  e=3
0 1 1 0 0  e=2
1 1 1 1 0  e=1
0 1 1 1 0  e=0
0 0 1 0 0  e=0
0 1 1 1 1  e=-1
0 0 1 1 0  e=-2
0 0 0 1 0  e=-3
0 0 1 1 1  e=-3          

TURNING_left
1 0 0 0 0
1 1 0 0 0

TURNING_right
0 0 0 0 1
0 0 0 1 1

1 1 1 1 1        0 Robot found continuous line: FINISH
0 0 0 0 0        0 Robot found no line: STOP
*/
void LFsensor::readLFsensor()
{
  LFS1 = digitalRead(_s1);
  LFS2 = digitalRead(_s2);
  LFS3 = digitalRead(_s3);
  LFS4 = digitalRead(_s4);
  LFS5 = digitalRead(_s5);

  //MODE = TURNING
  if((LFS1 == 1) && (LFS2 == 0) && (LFS3 == 0) && (LFS4 == 0) && (LFS5 == 0))  
  {mode = TURNING_left;} 
  else if((LFS1 == 1) && (LFS2 == 1) && (LFS3 == 0) && (LFS4 == 0) && (LFS5 == 0))  
  {mode = TURNING_left;}

  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 0) && (LFS4 == 1) && (LFS5 == 1)) 
  {mode = TURNING_right;}
  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 0) && (LFS4 == 0) && (LFS5 == 1)) 
  {mode = TURNING_right;}
  
  //MODE = FOLLOWING_LINE

  else if((LFS1 == 1) && (LFS2 == 1) && (LFS3 == 1) && (LFS4 == 0) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = 3;}

  else if((LFS1 == 0) && (LFS2 == 1) && (LFS3 == 0) && (LFS4 == 0) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = 3;}

  else if((LFS1 == 0) && (LFS2 == 1) && (LFS3 == 1) && (LFS4 == 0) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = 2;}

  else if((LFS1 == 1) && (LFS2 == 1) && (LFS3 == 1) && (LFS4 == 1) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = 1;}

  else if((LFS1 == 0) && (LFS2 == 1) && (LFS3 == 1) && (LFS4 == 1) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = 0;}

  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 1) && (LFS4 == 0) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = 0;}

  else if((LFS1 == 0) && (LFS2 == 1) && (LFS3 == 1) && (LFS4 == 1) && (LFS5 == 1)) 
  {mode = FOLLOWING_LINE; error = -1;}

  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 1) && (LFS4 == 1) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = -2;}

  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 0) && (LFS4 == 1) && (LFS5 == 0)) 
  {mode = FOLLOWING_LINE; error = -3;}

  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 1) && (LFS4 == 1) && (LFS5 == 1)) 
  {mode = FOLLOWING_LINE; error = -3;}

  //MODE = FINISH
  else if((LFS1 == 1) && (LFS2 == 1) && (LFS3 == 1) && (LFS4 == 1) && (LFS5 == 1)) 
  {mode = FINISH; error = 0;}
  
  //MODE = STOP
  else if((LFS1 == 0) && (LFS2 == 0) && (LFS3 == 0) && (LFS4 == 0) && (LFS5 == 0)) 
  {mode = STOP; error = 0;}
}

//To get the error value in the main program
float LFsensor::errorVal(){return error;}

//To get the mode value in the main program
float LFsensor::modeVal(){return mode;}

//To test the correctness of line following sensors in the main program
void LFsensor::testLineFollowSensor()
{ 
  LFS1 = digitalRead(_s1);
  LFS2 = digitalRead(_s2);
  LFS3 = digitalRead(_s3);
  LFS4 = digitalRead(_s4);
  LFS5 = digitalRead(_s5);
  Serial.print ("LFS: S1 S2 S3 S4 S5  R ==> "); 
  Serial.print (LFS1); 
  Serial.print (" ");
  Serial.print (LFS2); 
  Serial.print (" ");
  Serial.print (LFS3); 
  Serial.print (" ");
  Serial.print (LFS4);
  Serial.print (" "); 
  Serial.println (LFS5); 
  Serial.print ("  ==> ");
}
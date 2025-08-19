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
  int LFSensor[5] = {0, 0, 0, 0, 0};
  STOPPED = 0;
  FOLLOWING_LINE = 1;
  NO_LINE = 2;
}

//-------------------------------------------------------------
/* read line sensors values 
Sensor Array 	Error Value
0 0 0 0 1	 4              
0 0 0 1 1	 3              
0 0 0 1 0	 2              
0 0 1 1 0	 1              
0 1 1 1 0	 0              
0 1 1 0 0	-1              
0 1 0 0 0	-2              
1 1 0 0 0	-3              
1 0 0 0 0	-4              

1 1 1 1 1        0 Robot found continuous line : STOPPED
0 0 0 0 0        0 Robot found no line
*/
void LFsensor::readLFsensor(int mode, float error)
{
  LFSensor[0] = digitalRead(_s1);
  LFSensor[1] = digitalRead(_s2);
  LFSensor[2] = digitalRead(_s3);
  LFSensor[3] = digitalRead(_s4);
  LFSensor[4] = digitalRead(_s5);
  
  if(( LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 1 ))  
  {mode = FOLLOWING_LINE; error = 4;}

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 ))  
  {mode = FOLLOWING_LINE; error = 3;}

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 ))  
  {mode = FOLLOWING_LINE; error = 2;}

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 ))  
  {mode = FOLLOWING_LINE; error = 1;}

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 0 ))  
  {mode = FOLLOWING_LINE; error = 0;}

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 )) 
  {mode = FOLLOWING_LINE; error =- 1;}

  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  
  {mode = FOLLOWING_LINE; error = -2;}

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  
  {mode = FOLLOWING_LINE; error = -3;}

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  
  {mode = FOLLOWING_LINE; error = -4;}

  else if((LFSensor[0]== 1 )&&(LFSensor[1]== 1 )&&(LFSensor[2]== 1 )&&(LFSensor[3]== 1 )&&(LFSensor[4]== 1 ))  
  {mode = STOPPED; error = 0;}
  
  else if((LFSensor[0]== 0 )&&(LFSensor[1]== 0 )&&(LFSensor[2]== 0 )&&(LFSensor[3]== 0 )&&(LFSensor[4]== 0 ))  
  {mode = NO_LINE; error = 0;}
}
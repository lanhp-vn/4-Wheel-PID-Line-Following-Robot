//**********Include libraries**********//
#include "Motor_Driver.h"
#include "Encoder_Read.h"
#include "Ultrasonic.h"
#include "LFsensor.h"
#include "SimpleKalmanFilter.h"


//**********4 Channels Ultrasonic Sensors**********//
#define Trig 8
#define Front A2
#define Right A4
#define Left A5

//**********6 Channels L298N Motor Driver**********//
#define ENA A0
#define ENB A1
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
//**********5 Channels BFD1000 LF Sensor**********//
#define S1 9
#define S2 10
#define S3 11
#define S4 12
#define S5 13
//**********2 Channels H206 Encoders**********//
#define leftEncoder 2
#define rightEncoder 3


//------Declare SWITCH-CASE MODES------//
const int FINISH = 0;
const int FOLLOWING_LINE = 1;
const int STOP = 2;
const int TURNING_left = 3;
const int TURNING_right = 4;
const int AVOIDING_OBSTACLE = 5;
int obstacle;
float front_obstacle = 20; //in centimeters

//------Declare variables for Encoder_Read------//
volatile int left_count, right_count, rotation, rpm;
unsigned long timetaken, pevtime, dtime, finishtime; //to store millis()
float v, angle, dist, left_count_temp, right_count_temp;

//------Declare variables for rotating direction------//
const int right = 0;
const int left = 1;

//------Declare variables for calculatePID------//
float P, I, D, PIDval;
const float Kp = 40;
const float Ki = 0;
const float Kd = 45;
const int init_speed = 200;
const int min_speed = 0;
const int max_speed = 240;
const int turn_speed = 170;
const int delay_90deg = 450;

//------Declare variables for Ultrasonic------//
float meas_front, meas_left, meas_right;
const float detect_obstacle = 20; //in cm

//------Declare variables for LFsensor------//
int mode;
float error, prev_error;

//------Declare variables for LFsensor------//
const float mea_e = 2; //Measurement uncertainty
const float est_e = 2; //Estimation uncertainty
const float q = 0.07; //Process variance


//------DECLARE CLASSES FOR INCLUDED LIBRARIES------//
SimpleKalmanFilter kf = SimpleKalmanFilter(mea_e, est_e, q);
Motor_Driver driver = Motor_Driver(ENA, ENB, IN1, IN2, IN3, IN4);
Encoder_Read encoder = Encoder_Read();
Ultrasonic UTSN = Ultrasonic(Trig);
LFsensor LFS = LFsensor(S1, S2, S3, S4, S5);



//---------------------------VOID SETUP---------------------------//
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //------PINMODE------//
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(Trig, OUTPUT);
  pinMode(Front, INPUT);
  pinMode(Right, INPUT);
  pinMode(Left, INPUT);

  pinMode(leftEncoder, INPUT);
  pinMode(rightEncoder, INPUT);
  digitalWrite(leftEncoder, HIGH);
  digitalWrite(rightEncoder, HIGH);

  //------VARIABLES------//
  P = I = D = PIDval = 0;
  left_count = right_count = pevtime = dtime = 0;
  left_count_temp = right_count_temp = 0;

  obstacle = 0;

  //------ATTACH INTERRUPTIONS------//
  attachInterrupt(digitalPinToInterrupt(leftEncoder), left_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rightEncoder), right_ISR, CHANGE);
}



//---------------------------INTERRUPTION FUNCTIONS---------------------------//
void left_ISR()
{
  left_count++;
}

void right_ISR()
{
  right_count++;
  rotation++;
  dtime = millis();
  if(rotation>=40)
  {
    timetaken = millis() - pevtime  ;
    rpm = (1000/timetaken)*60; //rps = 1000/timetaken
    rpm = kf.updateEstimate(rpm);
    pevtime = millis();
    rotation = 0;
  }
}


//---------------------------FUNCTIONS---------------------------//
void setPIDspeed()
{
  P = error;
  I = I + error;
  D = error - prev_error;

  PIDval = (Kp * P) + (Ki * I) + (Kd * D);
  prev_error = error;

  int left_speed = init_speed - PIDval; 
  int right_speed = init_speed + PIDval;

  // The motor speed should not exceed the max PWM value
  left_speed = constrain(left_speed, min_speed, max_speed);
  right_speed = constrain(right_speed, min_speed, max_speed);

  driver.setSpeed(left_speed, right_speed);
}

//*****Allow robot to rotate at specified angle*****//
void turn(float aim_deg, int direction)
{

  float cur_angle = 0;
  float going_angle = 0;

  Serial.println(left_count);
  Serial.println(right_count);

  if (left_count_temp == 0 && right_count_temp == 0)
  {
    left_count_temp = left_count;
    right_count_temp = right_count;
  }
  
  cur_angle = encoder.angle_cal(left_count_temp, right_count_temp);
  Serial.print("cur angle: ");
  Serial.println(cur_angle);

  //Rotate right --> direction = 0
  //Rotate left --> direction = 1
  if (direction == 0)
  {driver.shiftRight();}
  if (direction == 1)
  {driver.shiftLeft();}

  going_angle = encoder.angle_cal(left_count, right_count) - cur_angle;
  Serial.print("going angle: ");
  Serial.println(going_angle);

  if (going_angle >= aim_deg)
  {
    driver.stopCar();
    delay(1000);
    left_count_temp = 0;
    right_count_temp = 0;
  }
}

//*****Allow robot to move at specified distance*****//
void move(float aim_dist) //aim_dist in meters
{
  float cur_dist = 0;
  float going_dist = 0;  

  if (right_count_temp == 0)
  {right_count_temp = right_count;}

  cur_dist = encoder.dist_cal(right_count_temp);
  Serial.print("current dist: "); 
  Serial.println(cur_dist);

  driver.forward();

  going_dist = encoder.dist_cal(right_count) - cur_dist;
  Serial.print("going distance: "); 
  Serial.println(going_dist);

  if (going_dist >= aim_dist)
  {
    driver.stopCar();
    delay(1000);
    right_count_temp = 0;
  }
}


//*****Reach finish line by brute-force testing*****//
void BForce_finish(int direction)
{
  int speed = 150;

  driver.setSpeed(speed, speed);

  driver.stopCar();
  delay(1000);

  //Right road --> direction = 0
  //Left road --> direction = 1
  switch(direction)
  {
    case right:
      driver.forward();
      delay(1800);
      driver.stopCar();
      delay(500);
      driver.turn_90deg(right, delay_90deg);
      driver.forward();
      delay(2770);
      driver.stopCar();
      delay(10000);
      break;

    case left:
      driver.forward();
      delay(1500);
      driver.stopCar();
      delay(500);
      driver.turn_90deg(left, delay_90deg);
      driver.forward();
      delay(2770);
      driver.stopCar();
      delay(10000);
      break;
  }
}

//*****Procedure for robot to avoid the obstacle ahead*****//
void obstacle_avoid(int meas_pin)
{
  int speed = 150;
  int X = 500;
  int Z = 1000;
  int Y = 0;
  bool obstacle_ahead = 30;
  bool no_obstacle;

  driver.setSpeed(speed, speed);

  driver.stopCar();
  delay(1000);

  driver.turn_90deg(right, delay_90deg);

  driver.forward();
  delay(X);
  Y += X;
  driver.stopCar();
  delay(1000);

  driver.turn_90deg(left, delay_90deg);

  no_obstacle = UTSN.no_obstacle(meas_front, obstacle_ahead);
  if (no_obstacle == false)
  {
    driver.turn_90deg(right, delay_90deg);
    driver.forward();
    delay(X);
    Y += X;
    driver.stopCar();
    delay(1000);
  }

  driver.forward();
  delay(Z);
  driver.stopCar();
  delay(1000);

  driver.turn_90deg(left, delay_90deg);

  no_obstacle = UTSN.no_obstacle(meas_front, obstacle_ahead);
  if (no_obstacle == false)
  { 
    driver.turn_90deg(right, delay_90deg);
    driver.forward();
    delay(Z/2);
    driver.stopCar();
    delay(1000);
  }

  driver.forward();
  delay(Y+500);
  driver.stopCar();
  delay(1000);

  driver.turn_90deg(right, delay_90deg);
  driver.stopCar();
  delay(1000);
}

//---------------------------FUNCTIONS for TESTING---------------------------//
//*****To test the correctness of rpm's calculation*****//
void test_rpm()
{
  driver.stopCar();
  delay(5000);

  driver.forward();
  delay(60000);

  int RPM = rpm;
  int rpm_compare = right_count/40;

  Serial.print("rpm: ");
  Serial.println(RPM);
  Serial.print("rpm_compare: ");
  Serial.println(rpm_compare);
  Serial.print("right count: ");
  Serial.println(right_count);
}

//*****To test the correctness of distance measured by ultrasonic sensors*****//
void test_UTSN()
{
  meas_front = kf.updateEstimate(UTSN.measDist(Front));
  Serial.print("front:"); Serial.print(meas_front); Serial.println();
  delay(50);
  
  meas_right = kf.updateEstimate(UTSN.measDist(Right));
  Serial.print("right:"); Serial.print(meas_right); Serial.println();
  delay(50);
  
  meas_left = kf.updateEstimate(UTSN.measDist(Left));
  Serial.print("left:"); Serial.print(meas_left); Serial.println();

  Serial.println();

  delay(200);
}

//---------------------------VOID LOOP---------------------------//
void loop() {
  //put your main code here, to run repeatedly:

  //Kalman filter is applied to stabilize the variance of distance measured by the ultrasonic sensor
  meas_front = UTSN.measDist(Front); 

  if (obstacle == 0) //If there is no obstacle ahead
  {
    LFS.readLFsensor();
    error = LFS.errorVal();
    mode = LFS.modeVal();
    Serial.println(mode);
  }
  else if (obstacle == 1) //If obstacle is detected ahead
  {
    mode = AVOIDING_OBSTACLE;
  }

  switch(mode)
  {
    case FINISH: //Go to the finish line
      // BForce_finish(left);
      driver.stopCar();
      prev_error = error;
      break;

    case FOLLOWING_LINE: //Robot moves forward following the PID algorithm
      setPIDspeed();
      driver.forward();
      if (meas_front <= detect_obstacle)
      {obstacle = 1;}
      break;

    case STOP: //Robot detects no line underneath
      driver.stopCar();
      prev_error = error;
      break;
    
    case TURNING_left: //Forcing the robot to not move out of underneath line
      driver.setSpeed(turn_speed, turn_speed);
      driver.turnLeft();
      delay(100);
      driver.stopCar();
      delay(50);
      prev_error = error;
      break;

    case TURNING_right: //Forcing the robot to not move out of underneath line
      driver.setSpeed(turn_speed, turn_speed);
      driver.turnRight();
      delay(100);
      driver.stopCar();
      delay(50);
      prev_error = error;
      break;
    
    case AVOIDING_OBSTACLE: //Robot detects obstacle ahead
      driver.stopCar();
      // delay(1000);
      // obstacle_avoid(meas_front);
      // obstacle = 0;
      prev_error = error;
      break;
  }
}





  
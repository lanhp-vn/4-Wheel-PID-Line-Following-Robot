#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 7  //Left Motor MB1
#define m4 6  //Left Motor MB2
#define echoPin1 A2 // Echo Pin
#define echoPin2 A1 // Echo Pin
#define echoPin3 A3// Echo Pin
#define trigPin A0 // Trigger Pin
#define ENA  A1
#define ENB  A0
//**********5 Channel IR Sensor Connection**********//
#define ir1 8
#define ir2 9
#define ir3 10
#define ir4 11
#define ir5 12
//*************************************************//
int initial_motor_speed = 130;

// PID Constants
float Kp = 100;
float Ki = 0;
float Kd = 0;

float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;

int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}



void move()
{
    calculate_pid();
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);  
}
void stopline(){
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
    digitalWrite(m3, 0);
    digitalWrite(m4, 0);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  //if only middle sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0))

  {
    //going forward with full speed 
    error = 0;
    move();
  }
  
  //if only left sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going right with full speed
    error = 3;
    move();
  }
  
  //if only left most sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going right with full speed
    error = 6; 
    move();
  }

  //if only right sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0))
  {
    //going left with full speed
    error = -3; 
    move();
  }

  //if only right most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  { 
    //going left with full speed 
    error = -6;
    move();
  }

  //if middle and right sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    error = -2;
    move();
  }

  //if middle and left sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0))
  {
    error = 2;
    move();
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going right with full speed 
    error = 4;
    move();
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    error = -4;
    move();
  }
    if((s1 == 0) && (s3 == 1) && (s5 == 0) && (s2 == 1) && (s4 ==1))
  {
    error = 0;
    move();
  }
    if((s1 == 1) && (s3 == 0) && (s5 == 0) && (s2 == 1) && (s4 ==0))
  {
    error = 3;
    move();
  }
    if((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    error = -3;
    move();
  }
  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //stop
    stopline();
  }
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    error = 1;
    move();
  }
    if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    error = -1;
    move();}
}

void calculate_pid()
{
  P = error;
  I = I + error;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D); // er =3; PID = 120 motor phải chay nhanh hơn

  previous_error = error;
  
  int left_motor_speed = initial_motor_speed - PID_value;   //-30
  int right_motor_speed = initial_motor_speed + PID_value;  //210

  // The motor speed should not exceed the max PWM value
  left_motor_speed = constrain(left_motor_speed, 0, 255);   //0
  right_motor_speed = constrain(right_motor_speed, 0, 255); //210

  analogWrite(ENA, left_motor_speed); //Left Motor Speed    //0
  analogWrite(ENB, right_motor_speed); //Right Motor Speed  //120
}
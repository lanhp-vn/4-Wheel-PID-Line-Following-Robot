/*
 * Arduino Vehicle Speed, Distance and Angle calculator 
 */
/*-------defining pins------*/

#define ENA A1
#define ENB A0
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define encode_left 2
#define encode_right 3


volatile byte rotation;
float radius = 0.033;
float timetaken;
float rpm;
float dtime;
float v;
unsigned long pevtime;
float t;
int left_intr = 0;
int right_intr = 0;
int angle = 0;
int dist;
int speed = 150;



//turn left 90deg
void turnLeft()
{
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  t=(90+6)/136.29*1000.;

  delay(t);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void setup()
{
  rotation = rpm = pevtime = 0; //Initialize all variable to zero

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(encode_left), Left_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encode_right), Right_ISR, CHANGE);
}


void loop()
// put your main code here, to run repeatedly:
{
  turnLeft();

/*To drop to zero if vehicle stopped*/
  if(millis()-dtime > 500) //no inetrrupt found for 500ms
  {
    rpm = v = 0; // make rpm and velocity as zero
    dtime=millis();
  }

  v = radius * rpm * 0.104;

  dist = (2*3.141*radius) * (left_intr/40);

  int angle_left = (left_intr % 360) * (90/80) ;
  int angle_right = (right_intr % 360) * (90/80) ;
  angle = angle_right - angle_left;
  delay(5000);

}

/* ISR functions*/
void Left_ISR()
{
  left_intr++;
  delay(10);
}

void Right_ISR()
{
  right_intr++; delay(10);
  rotation++;
  dtime=millis();
  if(rotation>=40)
  {
    timetaken = millis()-pevtime; 
    rpm=(1000/timetaken)*60;
    pevtime = millis();
    rotation=0;
  }
}


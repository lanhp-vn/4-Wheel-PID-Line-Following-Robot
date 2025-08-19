#define ENA A1
#define ENB A0
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define encode_left 2
#define encode_right 3
 
volatile unsigned int counter;
int rpm = 0;
int speed = 130;
float t;
 
void setup() {
  Serial.begin(9600);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(encode_left,INPUT);
  pinMode(encode_right,INPUT);

  digitalWrite(encode_left,HIGH);
  digitalWrite(encode_right,HIGH);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);


  attachInterrupt(digitalPinToInterrupt(encode_left),countpulse,RISING);
  //attachInterrupt(digitalPinToInterrupt(encode_right), countpulse,RISING);
}
 
void countpulse(){
  counter++;
  Serial.println(counter);
}

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

void forward()
{
  analogWrite(ENA,speed);
  analogWrite(ENB,speed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void loop()
{
  counter = 0;
  forward();
  delay(2000);
  stop();
  delay(3000);

  static uint32_t previousMillis;
  if (millis() - previousMillis >= 1000) {
    rpm = (counter/20)*60;        
    previousMillis += 1000;
  }

  Serial.print("Speed: ");
  Serial.print(rpm);
  Serial.println(" rpm");
  delay(5000);
}

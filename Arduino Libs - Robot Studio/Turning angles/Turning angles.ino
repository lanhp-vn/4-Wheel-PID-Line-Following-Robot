int ENA=A1;
int ENB=A0;
int IN1=4;
int IN2=5;
int IN4=6;
int IN3=7;
float d;
int degRot;
int left;
int right;
float v;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);
}

void loop() {
int wv;
v=1.2;
wv=(v-.35)/.0075;
left=wv;
right=wv;
setSpeed(left,right);
forward(5, v);
turnRight(180, wv);
forward(5, v);
//calR(wv);
//forward(8,v);
//v=1.5;
//wv=(v-.35)/.0075;
//left=wv;
//right=wv;
//setSpeed(left,right);
//backward(8,v);
  while(1==1){

  }
}
void setSpeed(int leftVal,int rightVal){
  analogWrite(ENA,leftVal);
  analogWrite(ENB,rightVal);
}
void forward(float d, float v){
float t;
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
t=d/v*1000;
delay(t);
stopCar();
}
void backward(float d, float v){
float t;
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
t=d/v*1000;
delay(t);
stopCar();
}

void turnRight(int deg, int wv){
  float t;
stopCar();
delay(100);
analogWrite(ENA,125);
analogWrite(ENB,125);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
t=(deg+6)/136.29*1000.;
Serial.println(deg);
delay(t);
stopCar();
analogWrite(ENA,wv);
analogWrite(ENB,wv);
}

void turnLeft(int deg, int wv){
float t;
analogWrite(ENA,125);
analogWrite(ENB,125);
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
t=(deg+6)/136.29*1000.;
Serial.println(deg);
Serial.println(deg);
delay(t);
stopCar();
analogWrite(ENA,wv);
analogWrite(ENB,wv);
}

void stopCar(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}

void calF(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
delay(5000);
stopCar();
}
void calB(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
delay(5000);
stopCar();
}
void calR(int wv){
stopCar();
analogWrite(ENA,125);
analogWrite(ENB,125);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
delay(3000);
analogWrite(ENA,wv);
analogWrite(ENB,wv);
stopCar();
}
void calL(int wv){
analogWrite(ENA,125);
analogWrite(ENB,125);
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
delay(5000);
analogWrite(ENA,wv);
analogWrite(ENB,wv);
stopCar();
}
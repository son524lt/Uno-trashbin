#include <Arduino.h>
#include <Servo.h>
#define TOUCH 12
#define SERVO_1 A4
#define SERVO_2 A5
#define TRIG 9
#define ECHO 10


Servo servo1, servo2;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TOUCH, INPUT);
  servo1.attach(SERVO_1);
  servo2.attach(SERVO_2);
  Serial.begin(9600);
}

float getDistance() {
  float dis;
  digitalWrite(TRIG, HIGH);
  // delayMicroseconds(10);
  delay(1);
  digitalWrite(TRIG, LOW);
  long int duration = pulseIn(ECHO, HIGH);
  dis = (float)duration*0.034/2;
  Serial.println(dis);
  return dis;
}


void loop() {
  Serial.println(getDistance());
  while (getDistance()<20) {
      servo1.write(180);
      servo2.write(0);
  }
  // delay(1000);
  servo1.write(0);
  servo2.write(180);
  // delay(2000);
  // servo1.write(180);
  // servo2.write(0);
}
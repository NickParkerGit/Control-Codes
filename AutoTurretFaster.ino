/*
HC-SR04 Ping distance sensor
VCC to Arduino 5V
GND to Arduino GND
Echo to Arduino pin 13
Trig to Arduino pin 12
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
Modified by Tolson Winters (Aug 27, 2014) for simplified serial monitor reading.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;   // variable to read the value from the analog pin
float error = 0.2;

#define LefttrigPin 12
#define LeftechoPin 13
#define RighttrigPin 6
#define RightechoPin 7

void setup() {
  Serial.begin (9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(LefttrigPin, OUTPUT);
  pinMode(LeftechoPin, INPUT);
  pinMode(RighttrigPin, OUTPUT);
  pinMode(RightechoPin, INPUT);
  myservo.write(90);
}

void loop() {
  long Leftduration, Leftdistance;
  digitalWrite(LefttrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(LefttrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(LefttrigPin, LOW);
  Leftduration = pulseIn(LeftechoPin, HIGH);
  Leftdistance = Leftduration/(2*29.1);
  Serial.print(Leftdistance);
  delay(20);
  
  long Rightduration, Rightdistance;
  digitalWrite(RighttrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(RighttrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(RighttrigPin, LOW);
  Rightduration = pulseIn(RightechoPin, HIGH);
  Rightdistance = Rightduration/(2*29.1);
  Serial.print(Rightdistance);
  delay(20);
//Motor Movement  
  
  if (Rightduration > Leftduration + Leftduration*error){
  //val = 60-atan(Rightdistance)/6;
  myservo.write(val);
  val = val + 10;
  delay(10);
  }
  if (Rightduration < Leftduration - Leftduration*error){
  myservo.write(val);
  //val = 60-atan(Leftdistance)/6;
  val = val - 10;
  delay(10);
  }
}

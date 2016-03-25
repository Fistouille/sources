#include <ArduinoUnit.h>
#include <Servo.h>

Servo myServo;
Servo myServo2;

void setup()
{
  myServo.attach(12);
  myServo2.attach(13);
  myServo.write(130);
  myServo.write(53);  
  Serial.begin(9600);
}

void loop()
{
  if(isColision(&recupererDistanceCapteur, 0){
    myServo.write(90);
    myServo2.write(90);
  }
}

int recupererDistanceCapteur(int numeroPin) {
  int val = analogRead(numeroPin);
  return val;
}

//typedef int (*PtrFonct)(int);

bool isColision(int (*pt)(int),int numeroPin) {
  if((*pt)(numeroPin) > 660) {
    return true;
  }
  else {
    return false;
  }
}

#include "DetectionMur.h"

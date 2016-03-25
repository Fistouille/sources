#include <ArduinoUnit.h>
#include <Servo.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2603b8b0a9ac4be5a9b8c8f04ceffecb";
// Your WiFi credentials
char ssid[] = "Wifi_Arduino";
char pass[] = "aarduino";

BLYNK_WRITE(V2)
{
  if(param.asInt()== 1){
    servo2.write(90);
    servo.write(90);
  }
  else{
    servo.write(53);
    servo2.write(130);
  }
}

void setup()
{
  myServo.attach(12);
  myServo2.attach(13);
  myServo.write(130);
  myServo.write(53);
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
}

void loop()
{
  Blynk.run();
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

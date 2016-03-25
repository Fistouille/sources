#include <ArduinoUnit.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while (true) {
    Test::run();
  }
}

int recupererDistanceCapteur(int numeroPin) {
  int val = analogRead(numeroPin);
  Serial.println(val);
  return val;
}

bool isColision(int numeroPin) {
  if(recupererDistanceCapteur(numeroPin) > 660) {
    return true;
  }
  else {
    return false;
  }
}

#include "DetectionMur.h"

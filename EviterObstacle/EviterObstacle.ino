#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <Servo.h>

Servo servo;
Servo servo2;

void setup()
{
  Serial.begin(9600);
  servo.attach(13);
  servo2.attach(12);
  servo.write(50);
  servo2.write(130);
}

void loop() {
  lireValeur(0);
}

void lireValeur(int numeroPin) {
  int pin = analogRead(numeroPin);
  if(pin > 660) {
    Serial.println("alerte!");
    delay(200);
  }
  else {
    Serial.println("tout va bien");
    delay(200);
  }
}

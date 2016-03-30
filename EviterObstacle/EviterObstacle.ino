   // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <Servo.h>
#include <BlynkSimpleWiFiShield101.h>

#define BLYNK_PRINT Serial
char auth[] = "2603b8b0a9ac4be5a9b8c8f04ceffecb";
char ssid[] = "AndroidHotspot3395"; //"Wifi_Arduino";
char pass[] = "1234aaaa"; //"aarduino";  

bool Stop = false;
Servo servo;
Servo servo2;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(13);
  servo2.attach(12);
  servo2.write(50);
  servo.write(130);
}

BLYNK_WRITE(V2)
{
  if(param.asInt()== 1){
    servo2.write(90);
    servo.write(90);
    Stop = true;
  }
  else{
    servo2.write(53);
    servo.write(130);
    Stop = false;
  }
}

void loop() {
  Blynk.run();
  if (!Stop)
    lireValeur(0);
}

void lireValeur(int numeroPin) {
  int pin = analogRead(numeroPin);
  if(pin > 660) {
    Serial.println("alerte!");
    servo2.write(109);    // vitesse tournant
    servo.write(110); 
    delay(200);
  }
  
  else {
    servo2.write(53);
    servo.write(130);
    delay(200);
  }
}

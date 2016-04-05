#include <Servo.h>
//#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
//#include <WiFi101.h>
//#include <BlynkSimpleWiFiShield101.h>
#include <ArduinoUnit.h>


char auth[] = "2603b8b0a9ac4be5a9b8c8f04ceffecb";
char ssid[] = "Wifi_Arduino";
char pass[] = "aarduino";
Servo myservoG;  // create servo object to control a servo
Servo myservoD;  // create servo object to control a servo

int sigAvant;
int sigDroite;

void setup() {

 // Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  myservoG.attach(12);  // attaches the servo on pin 12 to the servo object
  myservoD.attach(13);  // attaches the servo on pin 13 to the servo object
}

// Droite de 0 a 90 pour avancer
// Droite de 180 a 90 pour avancer
/*
  BLYNK_WRITE(V2)
  {
  if(param.asInt()== 1){
    myservoD.write(90);
    myservoG.write(90);
  }
  else{
    myservoG.write(53);
    myservoD.write(130);
  }
  }
*/

void loop() {
  //Blynk.run();
  Test::run();
  //doTurn(&recupererSignalCapteurAvant, &recupererSignalCapteurDroite, 0, 1);
  
}

int recupererSignalCapteurAvant(int numeroPin){
  int sigAvant = analogRead(numeroPin);
  return sigAvant;
}

int recupererSignalCapteurDroite(int numeroPin){
  int sigDroite = analogRead(numeroPin);
  return sigDroite;
}

char* doTurn(int(*pt1)(int), int(*pt2)(int), int numeroPinAvant, int numeroPinDroite){
  int valeurAvant = (*pt1)(numeroPinAvant);
  int valeurDroite = (*pt2)(numeroPinDroite);

  Serial.print("capteur avant : ");
  Serial.println(valeurAvant);
  Serial.print("capteur droite : ");
  Serial.println(valeurDroite);
  
  if(valeurAvant < 660 &&/*rien devant et distance Droite compris entre xx et yy*/ valeurDroite < 710 && valeurDroite > 610){
    avancer();
    return "avancer";
  }
  else if(valeurAvant < 660 &&/* rien devant et distance Droite inférieure à xx*/ valeurDroite <= 610 && valeurDroite >= 450){
    droite();
    return "droite";
  }
   else if(valeurAvant < 660 &&/* rien devant et distance Droite inférieure à xx*/ valeurDroite <= 610 && valeurDroite < 450){
    TourneDroite();
    return "droite";
  }
  else if(valeurAvant < 660 &&/* rien devant et distance Droite supérieure à yy*/ valeurDroite >= 710){
    gauche();
    return "gauche";
  }
  else if(valeurAvant >= 660){
    gauche();  
    return "gauche";
  }

  delay(100);
}

/* ajouter le programme qui converti le signal en cm */
// avancer
void avancer() {
  myservoG.write(78);    // vitesse en avancant
  myservoD.write(110);
}


// tourner à droite
void TourneDroite() {
   myservoG.write(0);    // vitesse tournant
   myservoD.write(0);
    delay(100);
   avancer();
   delay(100);
 
}

void droite() {
   myservoG.write(0);    // vitesse tournant
   myservoD.write(0);
}

// tourner à gauche
void gauche() {
  myservoG.write(180);    // vitesse tournant
  myservoD.write(180);
}

// arret
void arreter() {
  myservoG.write(90);    // vitesse tournant
  myservoD.write(90);
}




/* ajouter le programme qui converti le signal en cm */

#include "SuiveurMur.h"

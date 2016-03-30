#include <Servo.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>

char auth[] = "2603b8b0a9ac4be5a9b8c8f04ceffecb";
char ssid[] = "Wifi_Arduino";
char pass[] = "aarduino"; 
Servo myservoG;  // create servo object to control a servo
Servo myservoD;  // create servo object to control a servo

int sigAvant;
int sigDroite;
int sigGauche;
int sigArriere;
  
void setup() {
 // Blynk.begin(auth, ssid, pass);
  Serial.begin(115200);
  myservoG.attach(12);  // attaches the servo on pin 12 to the servo object
  myservoD.attach(13);  // attaches the servo on pin 13 to the servo object
}

// Gauche de 0 a 90 pour avancer
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
  sigAvant = analogRead(0); 
  sigGauche = analogRead(1);

  if(sigAvant < 660 &&/*rien devant et distance gauche compris entre xx et yy*/ sigGauche < 700 && sigGauche > 600)
    avancer();
  else if(sigAvant < 660 &&/* rien devant et distance gauche inférieure à xx*/ sigGauche <= 600)
    droite();
  else if(sigAvant < 660 &&/* rien devant et distance gauche supérieure à yy*/ sigGauche >= 700)
    gauche();
  else if(sigAvant >= 660)
    droiteObstacle();  

  delay(100);
  
}

/* ajouter le programme qui converti le signal en cm */

// avancer
void avancer() {
   myservoG.write(78);    // vitesse en avancant                           
   myservoD.write(110); 
}

//reculer
void reculer() {
   myservoG.write(109);    // vitesse en reculant                          
   myservoD.write(78); 
}

// tourner à droite
void droite() {
   myservoG.write(75);    // vitesse tournant                           
   myservoD.write(150); 
}

// tourner en cas d'obstacle
void droiteObstable() {
   myservoG.write(80);    // vitesse tournant                           
   myservoD.write(90); 
}

 // tourner à gauche
void gauche() {
   myservoG.write(40);    // vitesse tournant
   myservoD.write(105); 
}

 // arret
void arreter() {
   myservoG.write(90);    // vitesse tournant
   myservoD.write(90); 
}

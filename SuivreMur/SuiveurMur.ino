#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int sigAvant;
int sigDroite;
int sigGauche;
int sigArriere;
  
void setup() {
  Serial.begin(115200);
  myservo.attach(12);  // attaches the servo on pin 12 to the servo object
  myservo2.attach(13);  // attaches the servo on pin 13 to the servo object
}

void loop() {
  sigAvant = analogRead(0); 
  /*
  sigDroite = analogRead(?);
  sigGauche = analogRead(?);
  sigArriere = analogRead(?);
  */

  if(sigAvant < 660 &&/*rien devant et distance gauche compris entre xx et yy*/ sigGauche < 700 && sigGauche > 600)
    avancer();
  else if(sigAvant < 660 &&/* rien devant et distance gauche inférieure à xx*/ sigGauche <= 600)
    droite();
  else if(sigAvant < 660 &&/* rien devant et distance gauche supérieure à yy*/ sigGauche >= 700)
    gauche();
  else if(sigAvant >= 660)
    droite();  

  delay(300);
  
}

/* ajouter le programme qui converti le signal en cm */

// avancer
void avancer() {
   myservo.write(78);    // vitesse en avancant                           
   myservo2.write(110); 
}

//reculer
void reculer() {
   myservo.write(109);    // vitesse en reculant                          
   myservo2.write(78); 
}

// tourner à droite
void droite() {
   myservo.write(109);    // vitesse tournant                           
   myservo2.write(110); 
}

 // tourner à gauche
void gauche() {
   myservo.write(77);    // vitesse tournant
   myservo2.write(78); 
}

 // arret
void arreter() {
   myservo.write(90);    // vitesse tournant
   myservo2.write(90); 
}


#include <ArduinoUnit.h>

  
void setup() {
  Serial.begin(9600);
}

void loop() {
  while(true) {
    Test::run();
  }
}

String testDirection(int sigAvant, int sigGauche) {
  if(sigAvant < 660 &&/*rien devant et distance gauche compris entre xx et yy*/ sigGauche < 700 && sigGauche > 600)
    return "avancer";
  else if(sigAvant < 660 &&/* rien devant et distance gauche inférieure à xx*/ sigGauche <= 600)
    return "gauche";
  else if(sigAvant < 660 &&/* rien devant et distance gauche supérieure à yy*/ sigGauche >= 700)
    return "droite";
  else if(sigAvant >= 660)
    return "droite";  
}

#include "testSuiveurMur.h";


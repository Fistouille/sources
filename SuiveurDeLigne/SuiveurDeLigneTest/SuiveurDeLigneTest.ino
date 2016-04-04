  /* MOTEUR */
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

 /* CAPTEUR NIVEAU DE GRIS */
int valeurCapteur;
int valeurRetour;
int palierCouleurBlanc = 130;
int temps = 900;

void setup() {
  /* CAPTEUR NIVEAU DE GRIS */
  Serial.begin(9600);

  /* MOTEUR */
  Serial.begin(115200);
  
  myservo.attach(12);  // attaches the servo on pin 12 to the servo object
  myservo2.attach(13);  // attaches the servo on pin 13 to the servo object
}


 
void loop() {
  valeurRetour = ligneBlanche();
  if(valeurRetour == 1){
    Serial.println("1");
    avancer();
    /*MOTEUR Avancer*/
    
  }else{
    Serial.println("0");

    /*Retrouver ligne*/
    reculer();
    arreter();
    gauche();
    for(int i = 0; i < 5 ; ++i){
      avancer();
    }

    delay(temps);
    valeurRetour = ligneBlanche();
    if(valeurRetour == 1){
      avancer();
    }else{
      arreter();
      droite();
      droite();
      for(int i = 0; i < 10 ; ++i){
          avancer();
      }

      delay(temps);
      valeurRetour = ligneBlanche();
      if(valeurRetour == 1){
        avancer(); 
      }else{
  
        arreter();
        gauche();
        gauche();
        for(int i = 0; i < 5 ; ++i){
          avancer();
        }

        arreter();
        droite();
        for(int i = 0; i < 5 ; ++i){
          avancer();
        }

        delay(temps);
        valeurRetour = ligneBlanche();
        if(valeurRetour == 1){
          avancer();
        }else{
          arreter();
          gauche();
          gauche();
          for(int i = 0; i < 5 ; ++i){
             avancer();
          }

          delay(temps);
          valeurRetour = ligneBlanche();
          if(valeurRetour == 1){
            avancer();
          }else{
            arreter();
          }
        }
      }
    }
  }
}

int ligneBlanche(){
  valeurCapteur = analogRead(2);
  
  if(palierCouleurBlanc < valeurCapteur){
    return 0;
  }else if( palierCouleurBlanc > valeurCapteur){
    return 1;
  }
}

// reculer
void reculer() {
   myservo.write(78);    // vitesse en avancant                           
   myservo2.write(110); 
}

//avancer
void avancer() {
   myservo.write(109);    // vitesse en reculant                          
   myservo2.write(78); 
}

// tourner à droite
void droite() {
   myservo.write(77);    // vitesse tournant
   myservo2.write(78); 
}

 // tourner à gauche
void gauche() {
   myservo.write(109);    // vitesse tournant                           
   myservo2.write(110); 
}

 // arret
void arreter() {
   myservo.write(90);    // vitesse tournant
   myservo2.write(90); 
}

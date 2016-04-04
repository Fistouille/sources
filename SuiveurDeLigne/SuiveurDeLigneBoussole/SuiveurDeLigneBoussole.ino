  /* MOTEUR */
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

 /* CAPTEUR NIVEAU DE GRIS */
int valeurCapteur;
int valeurRetour;
int palierCouleurBlanc = 160;
int temps = 1;

/* BOUSSOLE */
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
Adafruit_BNO055 bno = Adafruit_BNO055(55);
sensors_event_t event; 
int tabValeursOrientationBoussole[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,180};

void setup() {
  /* CAPTEUR NIVEAU DE GRIS */
  Serial.begin(9600);
  
  myservo.attach(8);  // attaches the servo on pin 12 to the servo object
  myservo2.attach(9);  // attaches the servo on pin 13 to the servo object
}

//avancer
void avancer() {
    myservo2.write(109);    // vitesse en reculant
     myservo.write(78);
}

 // tourner Ã  gauche
void gauche() {
   myservo.write(109);    // vitesse tournant                           
   myservo2.write(110); 
}

 // arret
void arreter() {
   myservo.write(90);    // vitesse tournant
   myservo2.write(90); 
}

 
void loop() {
  
  Serial.println("A");
  delay(1);
  valeurCapteur = analogRead(2);
  
  if(palierCouleurBlanc < valeurCapteur){
    
    Serial.println("PB");
    
    bno.getEvent(&event);
    int orientation = event.orientation.x;

    for(int i = 0 ; i <= 35 ; ++i){
      bno.getEvent(&event);
      while(event.orientation.x != orientation + tabValeursOrientationBoussole[i]){
        gauche();
        Serial.println("G");
        bno.getEvent(&event);
      }
      arreter();
      
      if(palierCouleurBlanc < valeurCapteur){
        valeurRetour = 0;
      }else if( palierCouleurBlanc > valeurCapteur){
        valeurRetour =  1;
      }
      
      if(valeurRetour == 1){
        break;
      }
    }
    
  }else if(palierCouleurBlanc > valeurCapteur){
    Serial.println("B");
    avancer();
    /*MOTEUR Avancer*/
  }
 }



  /* MOTEUR */
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

 /* CAPTEUR NIVEAU DE GRIS */
int valeurCapteur;
int valeurRetour;
int palierCouleurBlanc = 130;
int temps = 900;

/* BOUSSOLE */
int tabValeursOrientationBoussole[] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,180};

void setup() {
  /* CAPTEUR NIVEAU DE GRIS */
  Serial.begin(9600);

  /* MOTEUR */
  Serial.begin(115200);
  
  myservo.attach(12);  // attaches the servo on pin 12 to the servo object
  myservo2.attach(13);  // attaches the servo on pin 13 to the servo object
}

int ligneBlanche(){
  valeurCapteur = analogRead(2);
  
  if(palierCouleurBlanc < valeurCapteur){
    return 0;
  }else if( palierCouleurBlanc > valeurCapteur){
    return 1;
  }
}

//avancer
void avancer() {
   myservo.write(109);    // vitesse en reculant                          
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

 
void loop() {
  valeurRetour = ligneBlanche();
  if(valeurRetour == 1){
    Serial.println("1");
    avancer();
    /*MOTEUR Avancer*/
    
  }else{
    Serial.println("0");

    int orientation = Boussole.valeurOrientation();

    for(int i = 0 ; i <= 35 ; ++i){
      while(Boussole.valeurOrientation() != orientation + tabValeursOrientationBoussole[i]){
        gauche();
      }
      arreter();
      valeurRetour = ligneBlanche();
      if(valeurRetour == 1){
        break;
      }
      
    }
  }
 }


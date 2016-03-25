void setup() {
  /* CAPTEUR NIVEAU DE GRIS */
  Serial.begin(9600);
}

int valeurCapteur;
int palierCouleurBlanc = 130;
 
void loop() {
  // put your main code here, to run repeatedly:
  
  int a = ligneBlanche();
  if(a == 1){
    Serial.println("1");

    /*MOTEUR Avancer*/
    
  }else if(a == 0){
    Serial.println("0");

    /*Retrouver ligne*/

    /*
  
    //arret
    //Tourner à gauche
    //avancer 25cm
    //Si pas 1
    //arret
    //demi-tour
    //avancer 50cm
    //Si pas 1
    //arret
    //demi tour
    // avancer 25 cm
    // arret
    // Tourner a droite
    // avancer 25 cm
    // Si pas 1
    // arret 
    // demi tour
    // Avancer

    */
  }
  
  delay(900);
}

int ligneBlanche(){
  valeurCapteur = analogRead(2);
  Serial.println(valeurCapteur);
  
  if(palierCouleurBlanc < valeurCapteur){
    return 0;
  }else if( palierCouleurBlanc > valeurCapteur){
    return 1;
  }
}

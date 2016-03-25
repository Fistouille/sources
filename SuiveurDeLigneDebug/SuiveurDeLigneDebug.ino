 /* CAPTEUR NIVEAU DE GRIS */
int valeurCapteur;
int valeurRetour;
int palierCouleurBlanc = 130;
int temps = 1500;

void setup() {
  /* CAPTEUR NIVEAU DE GRIS */
  Serial.begin(9600);
}


 
void loop() {
  
  delay(temps);
  
  valeurRetour = ligneBlanche();
  if(valeurRetour == 1){
    Serial.println("1");
    Serial.println("avancer");
    /*MOTEUR Avancer*/
    
  }else{
    Serial.println("0");

    /*Retrouver ligne*/
    Serial.println("reculer");
    Serial.println("arreter");
    Serial.println("gauche");
    for(int i = 0; i < 5 ; ++i){
      Serial.println("avancer");
    }

    delay(temps);
    valeurRetour = ligneBlanche();
    if(valeurRetour == 1){
      Serial.println("avancer");
    }else{
    
      Serial.println("arreter");
      Serial.println("droite");
      Serial.println("droite");
      for(int i = 0; i < 10 ; ++i){
        Serial.println("avancer");
      }

      delay(temps);
      valeurRetour = ligneBlanche();
      if(valeurRetour == 1){
        Serial.println("avancer"); 
      }else{
  
        Serial.println("arreter");
        Serial.println("gauche");
        Serial.println("gauche");
        for(int i = 0; i < 5 ; ++i){
          Serial.println("avancer");
        }

        Serial.println("arreter");
        Serial.println("droite");
        for(int i = 0; i < 5 ; ++i){
           Serial.println("avancer");
        }

        delay(temps);
        valeurRetour = ligneBlanche();
        if(valeurRetour == 1){
          Serial.println("avancer");
        }else{
          Serial.println("arreter");
          Serial.println("gauche");
          Serial.println("gauche");
          for(int i = 0; i < 5 ; ++i){
            Serial.println("avancer");
          }
          delay(temps);
          valeurRetour = ligneBlanche();
          if(valeurRetour == 1){
            Serial.println("avancer");
          }else{
            Serial.println("arreter");
            exit(1);
          }
        }
      }
    }
  }
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

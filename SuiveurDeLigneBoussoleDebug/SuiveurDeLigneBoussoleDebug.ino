
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
}

int ligneBlanche(){
  valeurCapteur = analogRead(2);
  
  if(palierCouleurBlanc < valeurCapteur){
    return 0;
  }else if( palierCouleurBlanc > valeurCapteur){
    return 1;
  }
}
 
void loop() {
  valeurRetour = ligneBlanche();
  if(valeurRetour == 1){
    Serial.println("1");
    Serial.println("avancer");
    /*MOTEUR Avancer*/
    
  }else{
    Serial.println("0");

    int orientation = Boussole.valeurOrientation();

    for(int i = 0 ; i <= 35 ; ++i){
      while(Boussole.valeurOrientation() != orientation + tabValeursOrientationBoussole[i]){
        Serial.println("gauche");
        Serial.println(tabValeursOrientationBoussole[i]);
      }
      Serial.println("arret");
      valeurRetour = ligneBlanche();
      if(valeurRetour == 1){
        break;
        Serial.println("1");
      }
      
    }
  }
 }


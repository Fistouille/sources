int pin;

void setup() {
  Serial.begin(115200);
  int sigAvant;
  int sigDroite;
  int sigGauche;
  int sigArriere;

 
}

void loop() {
  sigAvant = analogRead(0); 
  /*
  sigDroite = analogRead(?);
  sigGauche = analogRead(?);
  sigArriere = analogRead(?);
  */

  if(/* rien devant et distance gauche compris entre xx et yy*/)
    avancer();
  else if(/* rien devant et distance gauche inférieure à xx*/)
    tournerGauche();
  else if(/* rien devant et distance gauche supérieure à yy*/)
    tournerDroite();
  else if(/*mur devant*/)
    tournerDroite();  

  // convert 
  delay(200);
  
}

/* ajouter le programme qui converti en cm le signal*/




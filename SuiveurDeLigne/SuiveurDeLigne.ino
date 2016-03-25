void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int val;
int moyenne;
int somme;
 
void loop() {
  // put your main code here, to run repeatedly:
  moyenne = 0;
  somme = 0;

  for(int i = 1; i < 10 ; ++i){
    val=analogRead(2);

    somme = somme + val;
    
    
  }
  moyenne = somme / 9;
  Serial.println(moyenne);
  if(365 < moyenne){
    Serial.println("NOIR");
  }else if( 365 > moyenne){
    Serial.println("BLANC");
  }
    
  delay(900);
}

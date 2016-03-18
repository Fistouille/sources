void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int nb = 0;
int moyenne = 0;
int somme = 0;
int min = 999999;
int max = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int val;
  
  val=analogRead(2);
  Serial.println("----------------------");
  Serial.println("----------------------");
  Serial.println("valeur : ");
  Serial.println(val,DEC);
  delay(900);

  nb = nb +1;
  somme = somme + val;
  moyenne = somme / nb;

  Serial.println("----------------------");
  Serial.println("----------------------");
  Serial.println("moyenne =");
  Serial.println(moyenne);

  if(val < min){
    min = val;
  }

  Serial.println("min =");
  Serial.println(min);

  if(val > max){
    max = val;
  }

  Serial.println("max =");
  Serial.println(max);
  Serial.println("----------------------");
}

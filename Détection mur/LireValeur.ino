void setup() {
  Serial.begin(9600);
}
void loop() {
  lireValeur(0);
}

void lireValeur(int numeroPin) {
  int pin = analogRead(numeroPin);
  if(pin > 660) {
    Serial.println("alerte!");
    delay(200);
  }
  else {
    Serial.println("tout va bien");
    delay(200);
  }
}

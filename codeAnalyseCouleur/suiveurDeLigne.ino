void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int val=analogRead(2);
 
void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(couleur());
   
  delay(900);
}

int couleur(){
  if(316 <val < 335){
    continue;
  }else if( 316 < val){
    return 0;
  }else if( val > 335){
    return 1;
  }
}

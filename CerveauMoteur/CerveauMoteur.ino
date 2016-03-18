/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
  
  myservo2.attach(13);  // attaches the servo on pin 9 to the servo object
  
}

void loop() {
 /*int j = 85;
for(pos = 85; pos<=105; pos+=1)     // goes from 180 degrees to 0 degrees 
  { 
    myservo.write(j);                               
    myservo2.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(1000);      // waits 15ms for the servo to reach the position 
    j = j + 1;  
  } */
   myservo2.write(0);
   myservo.write(180);                               
 
  
}
 
/*
void loop() {
    myservo.write(80);
    myservo2.write(100);// waits 15ms for the servo to reach the position
  }
*/

/*
void loop() {
  // récupérer signal

  switch(signal) {
    case 'haut' :
      avancer()
      break;
    case 'bas' :
      reculer()
      break;
    case 'droite' :
      droite()
      break;
    case 'gauche' :
      gauche()
      break;
    case 'stop' :
      arreter()
      break;
    default :
      arreter();
  }
}
 
// avancer
void avancer() {
   myservo.write(78);    // vitesse en avancant                           
   myservo2.write(110); 
}

//reculer
void reculer() {
   myservo.write(109);    // vitesse en reculant                          
   myservo2.write(78); 
}

// tourner à gauche
void droite() {
   myservo.write(109);    // vitesse tournant                           
   myservo2.write(110); 
}

 // tourner à gauche
void gauche() {
   myservo.write(77);    // vitesse tournant
   myservo2.write(78); 
}

 // arret
void arreter() {
   myservo.write(90);    // vitesse tournant
   myservo2.write(90); 
}
 
 */


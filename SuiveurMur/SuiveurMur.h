int retourSansObstacle(int pin){
  return 500;
}

int retourObstacle(int pin){
  return 700;
}

int bonneDistance(int pin){
  return 650;
}

int mauvaiseDistanceDroite(int pin){
  return 550;
}

int mauvaiseDistanceGauche(int pin){
  return 750;
}

test(Avancer){
  assertEqual((char*)doTurn(&retourSansObstacle, &bonneDistance, 0, 1),(char*)"avancer");
}

test(TournerDroite){
  assertEqual((char*)doTurn(&retourSansObstacle, &mauvaiseDistanceDroite, 0, 1),(char*)"droite");
}

test(TournerGauche){
  assertEqual((char*)doTurn(&retourSansObstacle, &mauvaiseDistanceGauche, 0, 1),(char*)"gauche");
}

test(FauxTournerGauche){
  assertNotEqual((char*)doTurn(&retourSansObstacle, &mauvaiseDistanceDroite, 0, 1),(char*)"gauche");
}

test(TournerObstacle){
  assertEqual((char*)doTurn(&retourObstacle, &mauvaiseDistanceDroite, 0, 1),(char*)"droiteObstacle");
}

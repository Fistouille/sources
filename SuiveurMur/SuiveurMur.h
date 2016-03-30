int retourSansObstacle(int pin){
  return 700;
}

int retourObstacle(int pin){
  return 500;
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
  assertTrue(doTurn(&retourSansObstacle, &bonneDistance, 0, 1));
}

test(TournerDroite){
  assertTrue(doTurn(&retourSansObstacle, &mauvaiseDistanceDroite, 0, 1));
}


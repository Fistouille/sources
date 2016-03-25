test(Avancer)
{
  assertTrue(testDirection(600 , 650) == "avancer");
}

test(Gauche)
{
  assertTrue(testDirection(600 , 550) == "gauche");
}

test(Droite)
{
  assertTrue(testDirection(600 , 700) == "droite");
}

test(ObstableDevant)
{
  assertTrue(testDirection(700 , 650) == "droite");
}

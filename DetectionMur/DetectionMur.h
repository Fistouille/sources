int return500 (int x) {
  return 500;
}

int return700 (int x) {
  return 700;
}

test(Colision)
{
  assertTrue(isColision(&return700,0));
}

test(NoColision)
{
  assertFalse(isColision(&return500,0));
}



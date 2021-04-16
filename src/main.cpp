// Copyright 2021 by idpas
#include <iostream>
#include "TimedDoor.h"

int main() {
  TimedDoor tDoor(5);
  tDoor.lock();
  tDoor.throwState();
  tDoor.unlock();
  tDoor.throwState();
  return 0;
}

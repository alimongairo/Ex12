// Copyright 2021 by idpass
#include "TimedDoor.h"
#include <iostream>
#include <string>
#include <time.h>

/* DOOR TIMER ADAPTER */

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& d) : door(d) {}

void DoorTimerAdapter::Timeout() {
  Timer tr;
  tr.tregister(door.get_time(), this);
  door.DoorTimeOut();
}

/* TIMED DOOR */

TimedDoor::TimedDoor(int t)
    : iTimeout(t), opened(false), adapter(new DoorTimerAdapter(*this)) {}

bool TimedDoor::isDoorOpened() { return opened; }

void TimedDoor::unlock() {
  opened = true;
  adapter->Timeout();
}

void TimedDoor::lock() { opened = false; }

void TimedDoor::DoorTimeOut() { throw std::string("close the door!"); }

void TimedDoor::throwState() {
  if (opened == true) {
    throw std::string("Opened");
  } else {
    throw std::string("Closed");
  }
}

int TimedDoor::get_time() { return iTimeout; }

/* TIMER */

void Timer::sleep(int t) { time_t st = time(nullptr);
  while ((time(nullptr) - st) <= t) {
    continue;
  }
}

void Timer::tregister(int t, TimerClient* cl) {
  client = cl;
  sleep(t);
}

// Copyright 2021 by idpass
#include "TimedDoor.h"
#include <iostream>

// TIMER CLIENT
// virtual void Timeout() = 0;

// DOOR
// virtual void lock() = 0;
// virtual void unlock() = 0;
// virtual bool isDoorOpened() = 0;

// DOOR TIMER ADAPTER
// TimedDoor& door;
// explicit DoorTimerAdapter(TimedDoor&);
// void Timeout();

/* TIMED DOOR */

TimedDoor::TimedDoor(int t)
    : iTimeout(t), opened(false), adapter(new DoorTimerAdapter(*this)) {}

bool TimedDoor::isDoorOpened() {
	return opened;
}

void TimedDoor::unlock() {
  opened = true;
  adapter->Timeout();
}

void TimedDoor::lock() {
	opened = false;
}

void TimedDoor::DoorTimeOut() {
	throw std::string("Close the door!");
}

void TimedDoor::throwState() {
  if (opened == true) {
    throw std::string("Opened");
  } else {
    throw std::string("Closed");
  }
}

// TIMER
// TimerClient* client;
// void sleep(int);
// void tregister(int, TimerClient*);

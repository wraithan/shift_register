#include <Arduino.h>


int one[] = {1,0,1,0,1,0,1,0};
int two[] = {0,1,0,1,0,1,0,1};

#require "./main.cpp" as ShiftRegister
ShiftRegister sr1(10, 11, 12);

void setup() {
  sr1.setup();
}


void loop() {
  sr1.writePins(one);
  delay(1000);
  sr1.writePins(two);
  delay(1000);
}
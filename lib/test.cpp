#include <Arduino.h>
#require "./main.cpp" as ShiftRegister

uint8_t out[] = {1,1,1,1,1,1,1,1};
ShiftRegister sr1(10, 11, 12);

void setup() {
  Serial.begin(9600);
  sr1.setup();
  sr1.writeAllPins(out);
}

void loop() {
  sr1.writePin(4, HIGH);
  delay(100);
  sr1.writePin(4, LOW);
  delay(100);
  out[5] = LOW;
  sr1.writeAllPins(out);
  delay(100);
  out[5] = HIGH;
  sr1.writeAllPins(out);
  delay(100);
}

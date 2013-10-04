#ifndef Arduino_h
#include "Arduino.h"
#endif

#export= ShiftRegister
class ShiftRegister {
    char SH, ST, data;
  public:
    ShiftRegister(char sh, char st, char dpin) {
      SH = sh;
      ST = st;
      data = dpin;
    }
    void setup() {
      pinMode(SH, OUTPUT);
      pinMode(ST, OUTPUT);
      pinMode(data, OUTPUT);
    }
    void writePins(int pins[]) {
      pins = one;
      for (int i = 7; i >= 0; --i) {
        digitalWrite(data, pins[i]);
        digitalWrite(SH, HIGH);
        digitalWrite(data, LOW);
        digitalWrite(SH, LOW);
      }
      digitalWrite(ST, HIGH);
      digitalWrite(ST, LOW);
    }
};
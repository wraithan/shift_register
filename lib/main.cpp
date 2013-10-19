#include "Arduino.h"

#export= ShiftRegister
class ShiftRegister {
    uint8_t SRCLK, RCLK, SER;
    uint8_t * pins;
  public:
    ShiftRegister(uint8_t srclk, uint8_t rclk, uint8_t ser) {
      SRCLK = srclk;
      RCLK = rclk;
      SER = ser;
      pins = new uint8_t[8];
      for (uint8_t i = 0; i < 8; i++) {
         pins[i] = 0;
      }
    }
    void setup() {
      pinMode(SRCLK, OUTPUT);
      pinMode(RCLK, OUTPUT);
      pinMode(SER, OUTPUT);
    }
    void writePin(uint8_t pin, uint8_t value) {
      pins[pin] = value;
      writeAllPins(pins);
    }
    void writeAllPins(uint8_t output[]) {
      for (int8_t i = 7; i >= 0; i--) {
        pins[i] = output[i];
        digitalWrite(SER, pins[i]);
        digitalWrite(SRCLK, HIGH);
        digitalWrite(SER, LOW);
        digitalWrite(SRCLK, LOW);
      }
      digitalWrite(RCLK, HIGH);
      digitalWrite(RCLK, LOW);
    }
};

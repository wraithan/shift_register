# Shift Register (74HC595)

This is a [dotc](https://github.com/substack/dotc) enabled C++ module for using the 74HC595 shift register.

## Installation

```bash
npm install shift_register.cpp
```

## Usage

```cpp

#require "shift_register.cpp" as ShiftRegister

ShiftRegister sr(10,11,12);

void setup() {
  sr.setup();
}

uint8_t pattern = {HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW};

void loop() {
  sr.writeAllPins(pattern);
  sr.writePin(3, HIGH);
}
```

## API

### `ShiftRegister(uint8_t srclk, uint8_t rclk, uint8_t ser)`

These are the pins as they corospond to the [datasheet](https://www.sparkfun.com/datasheets/IC/SN74HC595.pdf).

### `void ShiftRegister::setup()`

This simply sets the pin mode on each of the pins passed to the constructor to output so the class can write to them safely.

### `void ShiftRegister::writeAllPins(uint8_t[8] output)`

This takes an array of 8 values and writes them out to the output pins. It replaces whatever is already in the shift register at the time.

### `void ShiftRegister::writePin(uint8_t pin, uint8_t value)`

This takes the 0 indexed pin to write to, and the value to write to it, then it immediately writes it out. It leaves all other pins in the state they were in before writing.

#include "melody.hpp"

constexpr int melodyPin = 2;
constexpr int switchPin = 7;

Melody mel(false, melodyPin);

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(melodyPin, INPUT);
}

void loop() {
  static int start = 0;
  static bool wasPressed = digitalRead(switchPin);
  bool isPressed = digitalRead(switchPin);
  if (isPressed != wasPressed && isPressed) {
    start = millis();
    mel.toggle();
  }
  if (!mel.getTone(millis() - start)) {
    start = millis();
  }
  wasPressed = isPressed;
}
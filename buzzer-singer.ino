#include "Melody.hpp"
#include "Toggle.hpp"

constexpr int melodyPin = 2;
constexpr int switchPin = 7;

// Melody mel(false, melodyPin);

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(melodyPin, INPUT);
}

void loop() {
  static Toggle songToggle(switchPin);

  if (songToggle.update() && songToggle.isHigh()) {
    // code when press switch has toggled
    // restart timer of Melody and switch song
  }
  // update melody
}
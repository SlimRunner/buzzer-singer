#include "melody.hpp"

Melody mel(false, 7);

void setup() {
  Serial.begin(9600);
  mel.toggle();
}

void loop() {
  static unsigned long start = 0;
  if (!mel.getTone(millis() - start)) {
    start = millis();
  }
}
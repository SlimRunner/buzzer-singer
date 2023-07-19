#include "melody.hpp"

Melody mel(false, 7);

void setup() {
  Serial.begin(9600);
}

void loop() {
  mel.getTone(millis());
}
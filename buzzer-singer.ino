#include "melody.hpp"

const int duration = getDuration();

void setup() {
  Serial.begin(9600);
  initFrequencies();
  initCumulative();
}

void loop() {
  constexpr double conversion = 32 * 128.0 / 60000.0;
  unsigned long timer = millis() * conversion;
  int index = findTiming(timer);
  if (notRests[index]) {
    tone(7, eqlTemp(notes[index]));
  } else {
    noTone(7);
  }
}
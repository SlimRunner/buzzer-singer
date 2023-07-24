#include "Melody.hpp"
#include "Playlist.hpp"
#include "Toggle.hpp"

constexpr int melodyPin = 2;
constexpr int switchPin = 7;

Melody melodies[2] = {
    {melodyPin, zelda2, sizeof(zelda2) / sizeof(zelda2[0]), true, 128, 32},
    {melodyPin, passcg, sizeof(passcg) / sizeof(passcg[0]), true, 180, 32}};
    // {melodyPin, rv443c1, sizeof(rv443c1) / sizeof(rv443c1[0]), false, 120, 32}};
    // {melodyPin, rv443c2, sizeof(rv443c2) / sizeof(rv443c2[0]), false, 120, 32}};

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(melodyPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  constexpr int PLSIZE =
      static_cast<int>(sizeof(melodies) / sizeof(melodies[0]));
  static Toggle songToggle(switchPin);
  static int songIndex = PLSIZE;
  if (songToggle.isToggled() && songToggle.isHigh()) {
    if (songIndex < PLSIZE) {
      melodies[songIndex].reset();
    }
    songIndex = (songIndex + 1) % (PLSIZE + 1);
  }
  if (songIndex < PLSIZE) {
    melodies[songIndex].advance();
  }
}

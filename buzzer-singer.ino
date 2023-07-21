#include "Melody.hpp"
#include "Playlist.hpp"
#include "Toggle.hpp"

constexpr int melodyPin = 2;
constexpr int switchPin = 7;

Melody melodies[2] = {
    {melodyPin, song1, sizeof(song1) / sizeof(song1[0]), true},
    {melodyPin, song2, sizeof(song2) / sizeof(song2[0]), true}};

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
  if (songToggle.update() && songToggle.isHigh()) {
    if (songIndex < PLSIZE) {
      melodies[songIndex].reset();
    }
    songIndex = (songIndex + 1) % (PLSIZE + 1);
  }
  if (songIndex < PLSIZE) {
    melodies[songIndex].play();
  }
}

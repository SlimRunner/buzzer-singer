#include "Melody.hpp"
#include "Playlist.hpp"
#include "Toggle.hpp"

constexpr int melodyPin = 2;
constexpr int switchPin = 7;

Melody melodies[1] = {
    // {melodyPin, zelda2, sizeof(zelda2) / sizeof(zelda2[0]), true, 128, 32},
    // {melodyPin, passcg, sizeof(passcg) / sizeof(passcg[0]), true, 180, 32}};
    {melodyPin, rv443c1, sizeof(rv443c1) / sizeof(rv443c1[0]), false, 120, 120}};
    // {melodyPin, rv443c2, sizeof(rv443c2) / sizeof(rv443c2[0]), false, 120, 120}};
    // {melodyPin, rv443c3, sizeof(rv443c3) / sizeof(rv443c3[0]), false, 120, 120}};

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(melodyPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  constexpr int PLAYLIST_SIZE =
      static_cast<int>(sizeof(melodies) / sizeof(melodies[0]));

  static Toggle songToggle(switchPin);
  static int songIndex = PLAYLIST_SIZE;

  if (songToggle.isToggled() && songToggle.isHigh()) {
    if (songIndex < PLAYLIST_SIZE) {
      melodies[songIndex].reset();
    }
    songIndex = (songIndex + 1) % (PLAYLIST_SIZE + 1);
  }

  if (songIndex < PLAYLIST_SIZE) {
    melodies[songIndex].advance();
  }
}

#pragma once

#include "Note.hpp"

class Melody {
private:
  const Note *m_song;
  uint8_t m_pin;
  int m_time;
  int m_size;
  bool m_repeat;
  bool m_reset;

  inline double eqlTemp(int note) { return pow(2, note / 12.0) * 440; }

public:
  Melody() = delete;
  Melody(const int pin, const Note *song, int size);
  Melody(const int pin, const Note *song, int size, bool repeat);
  // default destructor

  void play();

  void pause();

  void reset();

  int time() { return m_time; }
};

Melody::Melody(const int pin, const Note *song, int size)
    : m_pin(pin), m_song(song), m_size(size), m_repeat(true), m_time(0),
      m_reset(true) {}

Melody::Melody(const int pin, const Note *song, int size, bool repeat)
    : m_pin(pin), m_song(song), m_size(size), m_repeat(repeat), m_time(0),
      m_reset(true) {}

inline void Melody::play() {
  constexpr double BEAT_UNIT = 32 * 128.0 / 60000.0;
  static int prevTime = millis();
  // might want to consider making noteIndex and nextTiming into member
  // variables?
  static int prevPitch = -55;
  static int noteIndex = 0;
  static int nextTiming = m_song[noteIndex].duration();

  if (m_reset) {
    noteIndex = 0;
    nextTiming = m_song[noteIndex].duration();
    m_reset = false;
  } else {
    int now = millis();
    int timeDelta = now - prevTime;
    prevTime = now;
    m_time += timeDelta;
    // Serial.print("serial: ");
    // Serial.println(m_song[noteIndex].serial());

    if (BEAT_UNIT * m_time <= nextTiming) {
      if (m_song[noteIndex].isPitch()) {
        int pitch = m_song[noteIndex].pitch();
        Serial.println(pitch);
        if (pitch != prevPitch) {
          tone(m_pin, eqlTemp(pitch));
        }
        prevPitch = pitch;
      } else {
        noTone(m_pin);
      }
    } else if (m_size - noteIndex > 1) {
      nextTiming += m_song[++noteIndex].duration();
    } else {
      noteIndex = 0;
      nextTiming = m_song[noteIndex].duration();
    }
  }
}

inline void Melody::pause() {
  m_reset = true;
  noTone(m_pin);
}

inline void Melody::reset() {
  m_reset = true;
  m_time = 0;
  noTone(m_pin);
}

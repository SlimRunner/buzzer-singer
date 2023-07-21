#pragma once

#include "Note.hpp"

/**
 * @brief Tracks and manages a collection of Notes to play in a melody
 *
 */
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
  /**
   * @brief Default constructor is disallowed
   *
   */
  Melody() = delete;

  /**
   * @brief Construct a new Melody object
   *
   * @param pin pin id where buzzer is connected
   * @param song pointer to first element of an array of Notes
   * @param size size of the given collection of Notes
   */
  Melody(const int pin, const Note *song, int size);

  /**
   * @brief Construct a new Melody object
   *
   * @param pin pin id where buzzer is connected
   * @param song pointer to first element of an array of Notes
   * @param size size of the given collection of Notes
   * @param repeat determines if the song will repeat or stop upon reaching the
   * end
   */
  Melody(const int pin, const Note *song, int size, bool repeat);
  // default destructor

  /**
   * @brief play the corresponding note and updates time
   *
   */
  void play();

  /**
   * @brief pause current execution so that when play is executed next the time
   * delta gets reset
   *
   */
  void pause();

  /**
   * @brief reset the current playing song to the beginning
   *
   */
  void reset();

  /**
   * @brief get current time
   *
   * @return int representing beat relative to melody rhythm
   */
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

    if (BEAT_UNIT * m_time <= nextTiming) {
      if (m_song[noteIndex].isPitch()) {
        int pitch = m_song[noteIndex].pitch();
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

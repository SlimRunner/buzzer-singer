/**
 * @brief Manages a note and its attributes (type, duration, and pitch) within
 * an int with the following memory structure (little endian): 0-15 [duration],
 * 16-22 [pitch offset +54], 23 [type 1: note, 0: rest], 24-31 [reserved]
 *
 */
class Note {
private:
  int m_serial;

public:
  /**
   * @brief Default constructor is disallowed
   *
   */
  Note() = delete;
  /**
   * @brief Construct a new Note object
   *
   * @param serial serialized bitfield of properties (see class description).
   */
  Note(int serial);
  // default destructor

  /**
   * @brief Get the duration of this note
   *
   * @return int value that represents the duration of a note where a whole is
   * equal to 2 ^ 6 * 3 ^ 6. That way there is almost always an exact way to
   * convert to triplets.
   */
  int duration() { return (m_serial & 0xffff); }

  /**
   * @brief Determine if this note is rest or pitch
   *
   * @return true if the note is not a pitch,
   * @return otherwise the note is a rest
   */
  bool isPitch() { return (m_serial >> 23 & 0x800000); }

  /**
   * @brief Get the pitch of this note
   *
   * @return int value between -54 and 73 where 0 represents 440 hz in equal
   * temperament
   */
  int pitch() { return (m_serial >> 16 & 0x7f) - 54; }
};

Note::Note(int serial) : m_serial(serial) {}

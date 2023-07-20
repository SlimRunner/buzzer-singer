#pragma once

/**
 * @brief Keeps track of the press state of a press switch, so that it can
 * simulate a toggle switch
 *
 */
class Toggle {
private:
  int m_switchState;
  int m_pin;

public:
  /**
   * @brief Default constructor is disallowed
   * 
   */
  Toggle() = delete;
  /**
   * @brief Construct a new Toggle object with a given initial state
   *
   * @param pin initial state of the switch
   */
  Toggle(uint8_t m_pin);
  // default destructor

  /**
   * @brief Update the current stored value of the switch
   * 
   * @return a bool value that is true when the state has changed
   * @return true if switch state has changed
   * @return false otherwise
   */
  bool update() {};
  /**
   * @brief Determine the state of the last update
   * 
   * @return true if last update recorded HIGH,
   * @return false otherwise
   */
  bool isHigh() {};
  /**
   * @brief Determine the state of the last update
   * 
   * @return true if last update recorded LOW,
   * @return false otherwise
   */
  bool isLow() {};
};

Toggle::Toggle(uint8_t pin) : m_pin(pin) {
  m_switchState = digitalRead(m_pin);
}

bool Toggle::update() {
  int newState = digitalRead(m_pin);
  bool changed = m_switchState != newState;
  m_switchState = newState;
  return changed;
}

bool Toggle::isHigh() {
  return m_switchState == HIGH;
}

bool Toggle::isLow() {
  return m_switchState == LOW;
}

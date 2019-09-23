/*
 * *****************************************************************************
 * Debounce.cpp
 * Library to debounce a mechanical push-button
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 */

#include "Arduino.h"
#include "Debounce.h"

Debounce::Debounce(const byte BUTTON_PIN) {
  _BUTTON_PIN = BUTTON_PIN;
}
//***************************************************************************
//LIBRARY FUNCTIONS:
//***************************************************************************

void Debounce::setDebounceTime(int debounceTime) {
  _debounceTime = debounceTime;
}

bool Debounce::requestButtonState() {

  _currentButtonState = digitalRead(_BUTTON_PIN);

  // DETECT IF THE BUTTON STATE HAS CHANGED:
  if (_currentButtonState != _debouncedButtonState && _debounceTimerSet == false) {
    // IN THE FIRST RUNG,SET THE DEBOUNCE TIMER:
    _prevTime = millis();
    _debounceTimerSet = true;
  }
  // IF THE DEBOUNCE TIME'S UP AND THE SWITCH HAS STILL THE SAME (CHANGED) BUTTON STATE,
  // THEN THE CHANGED BUTTON STATE IS VALID:
  if (millis() - _prevTime > _debounceTime) {
    _debounceTimerSet = false;
    if (_currentButtonState != _debouncedButtonState) {
      _debouncedButtonState = _currentButtonState;

      // IF THE VALID NEW BUTTON STATE IS HIGH, THEN A SWITCH TO HIGH HAS HAPPEND:
      if (_debouncedButtonState == HIGH) {
        _buttonSwitchedHigh = true;
        _buttonSwitchedLow = false;
      }

      // IF THE VALID NEW BUTTON STATE IS LOW; THEN A SWICH TO LOW HAS HAPPEND:
      if (_debouncedButtonState == LOW) {
        _buttonSwitchedLow = true;
        _buttonSwitchedHigh = false;
      }

    }
  }
  return _currentButtonState;
}

bool Debounce::switchedHigh() {
  //RETURN THE INFORMATION IF THE BUTTON HAS SWITCHED HIGH, AND RESET IT:
  bool switchedHigh = _buttonSwitchedHigh;
  _buttonSwitchedHigh = false;
  return switchedHigh;
}
bool Debounce::switchedLow() {
  //RETURN THE INFORMATION IF THE BUTTON HAS SWITCHED LOW, AND RESET IT:
  bool switchedLow = _buttonSwitchedLow;
  _buttonSwitchedLow = false;
  return switchedLow;
}

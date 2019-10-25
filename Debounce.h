/*
 * *****************************************************************************
 * Debounce.h
 * Library to debounce a mechanical push-button
 * Michael Wettstein
 * September 2019, Zürich
 * *****************************************************************************
 */

#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"

class Debounce {
public:
  // FUNCTIONS:
  Debounce(const byte BUTTON_PIN);
  bool requestButtonState();
  bool switchedHigh();
  bool switchedLow();
  void setDebounceTime(int debounce_time);

  // VARIABLES:
  // n.a.

private:
  // FUNCTIONS:
  // n.a.

  // VARIABLES:
  byte _BUTTON_PIN;
  bool _buttonSwitchedHigh = false;
  bool _buttonSwitchedLow = false;
  bool _debounceTimerSet = false;
  bool _debouncedButtonState = 0;
  bool _currentButtonState = 0;
  unsigned int _debounceTime = 10;
  unsigned long _prevTime = 0;

};

#endif

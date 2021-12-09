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
  bool get_button_state();
  bool switched_high();
  bool switched_low();
  void set_debounce_time(int debounce_time);

  // VARIABLES:
  // n.a.

private:
  // FUNCTIONS:
  // n.a.

  // VARIABLES:
  byte _BUTTON_PIN;
  bool _button_siwtched_high = false;
  bool _button_switched_low = false;
  bool _debounce_timer_set = false;
  bool _debounced_button_state = 0;
  bool _current_button_state = 0;
  unsigned int _debounce_time = 10;
  unsigned long _prev_time = 0;

};

#endif

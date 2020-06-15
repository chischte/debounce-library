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

void Debounce::set_debounce_time(int debounce_time) {
  _debounce_time = debounce_time;
}

bool Debounce::get_button_state() {

  _current_button_state = digitalRead(_BUTTON_PIN);

  // DETECT IF THE BUTTON STATE HAS CHANGED:
  if (_current_button_state != _debounced_button_state && _debounce_timer_set == false) {
    // IN THE FIRST RUN,SET THE DEBOUNCE TIMER:
    _prev_time = millis();
    _debounce_timer_set = true;
  }
  // IF THE DEBOUNCE TIME'S UP AND THE SWITCH HAS STILL THE SAME (CHANGED) BUTTON STATE,
  // THEN THE CHANGED BUTTON STATE IS VALID:
  if (millis() - _prev_time > _debounce_time) {
    _debounce_timer_set = false;
    if (_current_button_state != _debounced_button_state) {
      _debounced_button_state = _current_button_state;

      // IF THE VALID NEW BUTTON STATE IS HIGH, THEN A SWITCH TO HIGH HAS HAPPEND:
      if (_debounced_button_state == HIGH) {
        _button_siwtched_high = true;
        _button_switched_low = false;
      }

      // IF THE VALID NEW BUTTON STATE IS LOW; THEN A SWICH TO LOW HAS HAPPEND:
      if (_debounced_button_state == LOW) {
        _button_switched_low = true;
        _button_siwtched_high = false;
      }

    }
  }
  return _current_button_state;
}

bool Debounce::switched_high() {
  Debounce::get_button_state();

  //RETURN THE INFORMATION IF THE BUTTON HAS SWITCHED HIGH, AND RESET IT:
  bool switched_high = _button_siwtched_high;
  _button_siwtched_high = false;
  return switched_high;
}

bool Debounce::switched_low() {
  Debounce::get_button_state();

  //RETURN THE INFORMATION IF THE BUTTON HAS SWITCHED LOW, AND RESET IT:
  bool switched_low = _button_switched_low;
  _button_switched_low = false;
  return switched_low;
}

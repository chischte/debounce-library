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

Debounce::Debounce(const byte BUTTON_PIN)
{
  _BUTTON_PIN = BUTTON_PIN;
}
//***************************************************************************
//LIBRARY FUNCTIONS:
//***************************************************************************

bool Debounce::requestButtonState()
{

  _currentButtonState = digitalRead(_BUTTON_PIN);

  if (_currentButtonState != _debouncedButtonState && _debounceTimerSet == false)
  {
    _prevTime = millis();
    _debounceTimerSet = true;
  }

  if (millis() - _prevTime > _debounceTime)
  {
    _debounceTimerSet = false; // debouncetimer can be reset
    if (_currentButtonState != _debouncedButtonState)
    {
      _debouncedButtonState = _currentButtonState;
    }
    return _currentButtonState;
  }
}

void Debounce::setDebounceTime(int debounceTime){
    _debounceTime=debounceTime;
}

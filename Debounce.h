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

class Debounce
{
public:
  Debounce(int BUTTON_PIN);
  bool requestButtonState();
 

private:
  bool _debouncedButtonState;
  bool _currentButtonState;
  bool _debounceTimerSet=0; 
 
  int _debounceTime = 10;
  unsigned long _prevTime;
 
};

#endif

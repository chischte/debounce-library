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

void Debounce::Debounce(int BUTTON_PIN)
{
  pinMode(BUTTON_PIN, INPUT);
 }
//***************************************************************************
//LIBRARY FUNCTIONS:
//***************************************************************************
 

  
  bool Debounce::requestButtonState()
  {
  _currentButtonState = digitalRead(BUTTON_PIN);
   
   if (_currentButtonState != _debouncedButtonState && _debounceTimerSet == false)
  {
      _prevTime = millis()
	  _debounceTimerSet = true;
  }

  if (millis() -_prevTime > _debounceTime )
  {
    debounceTimerSet = false;// debouncetimer can be reset
    if (_currentButtonState != _debouncedButtonState)
    {
          _debouncedButtonState = _currentButtonState;
    }
	return _currentButtonState;
	//return 1;
	
  }
  }


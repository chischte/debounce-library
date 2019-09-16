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
    void setDebounceTime(int debounce_time);

    // VARIABLES:
    // n.a.

private:
    // FUNCTIONS:
    // n.a.

    // VARIABLES:
    byte _BUTTON_PIN;
    bool _debouncedButtonState;
    bool _currentButtonState;
    bool _debounceTimerSet = false;
    int _debounceTime = 10;
    unsigned long _prevTime;

};

#endif

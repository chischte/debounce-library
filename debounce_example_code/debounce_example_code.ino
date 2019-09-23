#include <Debounce.h> // https://github.com/chischte/debounce-library.git
const byte PIN = 2;
Debounce testSwitch(PIN); // create an instance of the library class

void setup() {

  pinMode(PIN, INPUT_PULLUP);
  testSwitch.setDebounceTime(100); // optional command, default debounce time is 10ms
  Serial.begin(9600);
}

void loop() {

  bool debouncedButtonState;

  debouncedButtonState = testSwitch.requestButtonState(); // request the debounced button state

  Serial.println(debouncedButtonState);

  if (testSwitch.switchedHigh()) {
    // do stuff if a switch on has been detected
  Serial.println("SWITCHED HIGH!");
  }
  if (testSwitch.switchedLow()) {
    // do stuff if a switch off has been detected
    Serial.println("SWITCHED LOW!");
  }
  delay(200);
}

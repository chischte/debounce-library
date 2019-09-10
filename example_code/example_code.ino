#include <Debounce.h>
const byte PIN = 4;
Debounce testSwitch(PIN); // create an instance of the library class


void setup() {

  pinMode(PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool debouncedButtonState;
  debouncedButtonState = testSwitch.requestButtonState(); // request the debounced button state
  Serial.println(debouncedButtonState);
}
#include <Debounce.h> // https://github.com/chischte/debounce-library.git
const byte PIN = 2;
Debounce test_switch(PIN); // create an instance of the library class

void setup() {

  pinMode(PIN, INPUT_PULLUP);
  test_switch.set_debounce_time(100); // optional command, default debounce time is 10ms
  Serial.begin(9600);
}

void loop() {

  bool debounced_button_state;

  debounced_button_state = test_switch.get_button_state(); // request the debounced button state

  Serial.println(debounced_button_state);

  if (test_switch.switched_high()) {
    // do stuff if a switch on has been detected
  Serial.println("SWITCHED HIGH!");
  }
  if (test_switch.switched_low()) {
    // do stuff if a switch off has been detected
    Serial.println("SWITCHED LOW!");
  }
  delay(200);
}

# debounce-library 

**Library to debounce mechanical switches and push buttons, detect button state changes**


Library Functions
-----------------

	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS:
	Debounce test_switch(PIN);

	// SET DEBOUNCE TIME:
	test_switch.set_debounce_time(100); // default is 10ms

	// FIND OUT WHAT STATE THE BUTTON HAS:
	test_switch.get_button_state(); // returns 0 for low and 1 for high

	// FIND OUT IF THE BUTTON HAS SWITCHED TO HIGH
	test_switch.switched_high(); // returns 1 if a switch to high has happened
	// the high flag will be reset after one inquiry

	// FIND OUT IF THE BUTTON HAS SWITCHED TO LOW
	test_switch.switched_low(); // returns 1 if a switch to low has happened
	// the low flag will be reset after one inquiry
 

**An example of how the functions can be used can be found in the example code.**	
  

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.


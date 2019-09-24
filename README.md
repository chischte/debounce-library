# debounce-library 

**Library to debounce mechanical switches and push buttons and detect button state changes.**


Library Functions
-----------------

	
	// CREATE AN INSTANCE OF THE LIBRARY CLASS:
	Debounce testSwitch(PIN);

	// SET DEBOUNCE TIME:
	testSwitch.setDebounceTime(100); // default is 10ms

	// FIND OUT WHAT STATE THE BUTTON HAS:
	testSwitch.requestButtonState(); // returns 0 for low and 1 for high

	// FIND OUT IF THE BUTTON HAS SWITCHED TO HIGH
	testSwitch.switchedHigh(); // returns 1 if a switch to high has happened
	
	// FIND OUT IF THE BUTTON HAS SWITCHED TO LOW
	testSwitch.switchedLow(); // returns 1 if a switch to low has happened
 

**An example of how the functions can be used can be found in the example code "debounce_example_code".**	
  

Installation
------------
The Library can be installed by cloning or downloading it to Arduinos default library location, e.g. user/documents/Arduino/libraries/.

# touchDebounce
A debounce for esp32 touch inputs.

If you use the touch inputs on the esp32 you will notice that the touch inputs are not very stable. 
This is because the touch inputs are not very precise. 
This library tries to solve this problem by debouncing the touch inputs.


## Usage
Include the library

`#include <touchdbc.h>`

Create an object, i've called mine "touchSig01".
Create a new object for each touch input you want to use.

`touchBounce touchSig01`

Place the following code in the setup function

`touchSig01.setup(pin, threshold, time)`

* pin: the pin you want to use
* threshold: the threshold for the state change you want to use
* time: the debounce time you want to use

Then run it in your loop function. 

`touchSig01.touchRun()`

touchRun() returns a boolean value. 
True if the touch input is pressed, false if it is not pressed.

So you could print the value or use it in an if statement, for example:

`if(touchSig01.touchRun()) {`

`//do something`

`}`

## Notes
The function call 

`touchRead(touchPin)`

Returns a higher value for a lower capative touch input.

So "pressed" is a lower value than "not pressed".

This is then reversed in the touchRun() function.

Such that "pressed" = 1 and "not pressed" = 0.



#include <Arduino.h>
#include <touchdbc.h>
#include <Timer.h>

touchBounce::touchBounce() {}

void touchBounce::setup(int touchPin, int threshold, int delay) {
    this->touchPin = touchPin;
    this->threshold = threshold;
    this->delay = delay;
    outState = 0;
    pinMode(touchPin, INPUT);

    highTimer.stop();
    lowTimer.stop();

    Serial.println("touch debounce setup on pin: " + String(touchPin) + " with threshold: " + String(threshold) + " and delay: " + String(delay) + "ms");
    
}

//the idea is that a state change triggers a timer to start counting
// so long as no further state changes are detected that timer keeps counting
//eventually it reaches a pre set tim and changes the state of the output.


int touchBounce::touchRun() {
    int touchVal = touchRead(touchPin);
    
    if (touchVal >= threshold && highTimer.state() == STOPPED)
    {
        highTimer.start();
        lowTimer.stop();
        //Serial.println("high timer started" + String(touchPin));
    }

    if (touchVal < threshold && lowTimer.state() == STOPPED)
    {
        lowTimer.start();
        highTimer.stop();
        //Serial.println("low timer started" + String(touchPin));
    }

    if (highTimer.state() == RUNNING && highTimer.read() > delay)
    {
        highTimer.stop();
        outState = 0;
        //Serial.println("high output set");
    }

    if (lowTimer.state() == RUNNING && lowTimer.read() > delay)
    {
        lowTimer.stop();
        outState = 1;
        //Serial.println("low output set");
    }


    //Serial.println("touchVal: " + String(touchVal) + " state: " + String(state));
    //Serial.println("pin: " + String(touchPin) + "hightimer state: " + String(highTimer.state()) + " lowtimer state: " + String(lowTimer.state()) + " outState: " + String(outState));
//Serial.println("hightimer read: " + String(highTimer.read()) + " lowtimer read: " + String(lowTimer.read()) + " outState: " + String(outState));

    return outState;
}


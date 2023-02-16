#include <Arduino.h>
#include <touchdbc.h>
#include <Timer.h>

touchBounce::touchBounce() {}

Timer highTimer;
Timer lowTimer;

void touchBounce::setup(int touchPin, int threshold, int delay) {
    this->touchPin = touchPin;
    this->threshold = threshold;
    this->delay = delay;
    pinMode(touchPin, INPUT);
    Serial.println("touch debounce setup on pin: " + String(touchPin) + " with threshold: " + String(threshold) + " and delay: " + String(delay) + "ms");
}

//the idea is that a state change triggers a timer to start counting
// so long as no further state changes are detected that timer keeps counting
//eventually it reaches a pre set tim and changes the state of the output.


int touchBounce::touchRun() {
    int touchVal = touchRead(touchPin);
    
    if (touchVal > threshold && highTimer.state() == STOPPED)
    {
        highTimer.start();
        lowTimer.stop();
        Serial.println("high timer started");
    }

    if (touchVal < threshold && lowTimer.state() == STOPPED)
    {
        lowTimer.start();
        highTimer.stop();
        Serial.println("low timer started");
    }

    if (highTimer.state() == RUNNING && highTimer.read() > delay)
    {
        highTimer.stop();
        state = 0;
        Serial.println("high output set");
    }

    if (lowTimer.state() == RUNNING && lowTimer.read() > delay)
    {
        lowTimer.stop();
        state = 1;
        Serial.println("low output set");
    }


    Serial.println("touchVal: " + String(touchVal) + " state: " + String(state));
    
    return state;
}
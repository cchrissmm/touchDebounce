#ifndef TOUCHDBC_H_
#define TOUCHDBC_H_

#include <Arduino.h>
#include <Timer.h>

class touchBounce {
public:
    touchBounce();
    void setup(int touchPin, int threshold, int delay);
    int touchRun();

private:
    int touchPin;
    int threshold;
    int delay;
    int outState;

    Timer highTimer;
    Timer lowTimer;
};
#endif
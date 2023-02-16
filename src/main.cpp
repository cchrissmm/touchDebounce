#include <Arduino.h>
#include <touchdbc.h>

touchBounce touchSig01;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // initialise USB serial
  touchSig01.setup(14, 40, 2000);

  Serial.println("setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchVal = touchSig01.touchRun();
  Serial.println(touchVal);
  delay(1000);
}
#include <Arduino.h>
#include <touchdbc.h>

touchBounce touchSig01;
touchBounce touchSig03;
touchBounce touchSig02;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // initialise USB serial
 
 touchSig01.setup(14, 30, 2000);
  touchSig03.setup(4, 30, 2000);
  touchSig02.setup(12, 30, 2000);

  Serial.println("setup done");
}

void loop() {
  touchSig01.touchRun();
  touchSig02.touchRun();
  touchSig03.touchRun();

  
  // put your main code here, to run repeatedly:
   Serial.println("touchSig01: " + String(touchSig01.touchRun()) + " touchSig02: " + String(touchSig02.touchRun()) + " touchSig03: " + String(touchSig03.touchRun()));
  // Serial.println("touchval01: " + String(touchRead(14)) + " touchval02: " + String(touchRead(12)) + " touchval03: " + String(touchRead(4)));
  delay(1000);
}
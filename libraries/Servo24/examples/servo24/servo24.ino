#include "Servo24.h"

void setup() {
  Serial.begin(115200);
  while(!Serial) {
  }
}

void loop() {
  Servo24 controller;
  controller.ready();
  controller.set(1, 0);
  controller.set(24, 0);
  controller.exec(1000);
  delay(1000);
  controller.ready();
  controller.set(1, 180);
  controller.set(24, 180);
  controller.exec(200);
  delay(1000);
}

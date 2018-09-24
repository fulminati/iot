/*
 File: rgb.ino
 <write description here>

 ArduinoDK
 https://git.io/fAF8y
 */

#include "rgb.h"

void setup() {
  pinMode(RGB_OUTPUT, OUTPUT);
}

void loop() {
  digitalWrite(RGB_OUTPUT, HIGH);
}

#include <Arduino.h>
#include "Button.h"

#define PUSHBUTTON_PIN 26

Button::Button() {
  pinMode(PUSHBUTTON_PIN, INPUT_PULLUP);
}

void Button::waitForPush() {
  while (digitalRead(PUSHBUTTON_PIN) == HIGH);
}

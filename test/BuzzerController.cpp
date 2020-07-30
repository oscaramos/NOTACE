#include <Arduino.h>
#include "./BuzzerController.h"

const int PIN_BUZZER = 8;

AmbulanceSound ambulanceSound(PIN_BUZZER);
SirenSound sirenSound(PIN_BUZZER);
BuzzerController buzzerController(&ambulanceSound);

void setup() {

}


void loop() {
  buzzerController.emitSound();
}
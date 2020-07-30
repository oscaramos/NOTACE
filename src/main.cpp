#include <Arduino.h>
#include "./BuzzerController.h"
#include "./PIRController.h"

/*----- PINES -----*/
const int PIN_BUZZER = 8;
const int PIR_PIN = 2;        

/*----- Buzzer -----*/

AmbulanceSound ambulanceSound(PIN_BUZZER);
SirenSound sirenSound(PIN_BUZZER);
BuzzerController buzzerController(&ambulanceSound);

/*----- PIR -----*/

bool isActived = false;

void onMovement() {
  Serial.println("Sensor activado");
  isActived = true;
}

void onStop() {
  Serial.println("Sensor desactivado");
  isActived = false;
}

PIRController pirController(PIR_PIN, onMovement, onStop);

/*----------*/



void setup() {
  Serial.begin(9600);
  pirController.start();
}

void loop() {
  pirController.checkPIR();

  if(isActived) {
    buzzerController.emitSound();
  }
}

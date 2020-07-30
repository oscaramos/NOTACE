#include <Arduino.h>
#include "./PIRController.h"

void onMovement() {
  Serial.println("Sensor activado");
}

void onStop() {
  Serial.println("Sensor desactivado");
}

const int PIRPin = 2;         // pin de entrada (for PIR sensor)

PIRController pirController(PIRPin, onMovement, onStop);
 
void setup() 
{
  Serial.begin(9600);
  pirController.start();
}
 
void loop()
{
  pirController.checkPIR();
}
#include <Arduino.h>

#include "./RemoteController.h"

const int RECV_PIN = 11;
const unsigned long BUTTON_PLAYPAUSE = 0xFFC23D;

void onButtonPressed() {
  Serial.println("the button play/pause was pressed");
}

RemoteController remoteController(RECV_PIN, BUTTON_PLAYPAUSE, onButtonPressed);

void setup() {
  Serial.begin(9600);
  remoteController.start();
}

void loop() {
  remoteController.checkIncomingSignal();
  delay(100);
}
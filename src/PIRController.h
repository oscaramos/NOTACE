#include <Arduino.h>

typedef void(*callback_function)(void);

class PIRController {
private:
    int PIRPin;
    int pirState = LOW;           // de inicio no hay movimiento
    callback_function onMovement;
    callback_function onStop;

public:
    PIRController(int PIRPin, callback_function onMovement, callback_function onStop): 
        PIRPin(PIRPin), onMovement(onMovement), onStop(onStop) {

    }


    void start() {
        pinMode(PIRPin, INPUT);
    }

    void checkPIR() {
        int val = digitalRead(PIRPin);
        if (val == HIGH)   //si está activado
        { 
            if (pirState == LOW)  //si previamente estaba apagado
            {
                onMovement();
                pirState = HIGH;
            }
        } 
        else   //si esta desactivado
        {
            if (pirState == HIGH)  //si previamente estaba encendido
            {
                onStop();
                pirState = LOW;
            }
        }
    }
};
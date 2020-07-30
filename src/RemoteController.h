#include <IRremote.h>

typedef void (*callback_function)(void); 

class RemoteController {
private:
    int RECV_PIN;
    unsigned long buttonToObserve;
    callback_function onPressButton;

    IRrecv irrecv;
    decode_results results;

    int debug;

public:
    RemoteController(int RECV_PIN, unsigned long buttonToObserve, callback_function onPressButton, int debug = false): 
        RECV_PIN(RECV_PIN),
        buttonToObserve(buttonToObserve),
        onPressButton(onPressButton),
        irrecv(RECV_PIN),
        debug(debug)
    {
        
    }

    void start() {
        if(this->debug) {
            // In case the interrupt driver crashes on setup, give a clue
            // to the user what's going on.
            Serial.println("Enabling IRin");

            irrecv.enableIRIn(); // Start the receiver
            
            Serial.println("Enabled IRin");
        } else {
            irrecv.enableIRIn(); // Start the receiver
        }
    }

    void checkIncomingSignal() {
        if(this->debug) {
            if (irrecv.decode(&results)) {            
                Serial.println(results.value, HEX);
                if(results.value == buttonToObserve) {
                    onPressButton();
                } 
                irrecv.resume(); // Receive the next value
            }
        } else {
            if (irrecv.decode(&results)) {            
                if(results.value == buttonToObserve) {
                    onPressButton();
                } 
                irrecv.resume(); // Receive the next value
            }
        }
    }
};
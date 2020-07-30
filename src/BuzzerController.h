#include <Arduino.h>
#include "./pitches.h"

class Sound {
protected:
    int PIN_BUZZER;
public:
    Sound(int PIN_BUZZER): PIN_BUZZER(PIN_BUZZER) {}
    virtual void sound() = 0;
};


class BuzzerController {
private:
    Sound* sound;

public:
    BuzzerController(Sound* sound): sound(sound) {
        ;
    }

    void emitSound() {
        sound->sound();
    }
};


struct Note {
    int note; // Notes in the melody
    int duration; // note durations: 4 = quarter note, 8 = eighth note, etc.:
};


class AmbulanceSound: public Sound {
private:
    int arrSize;
    Note* melody;
    int i = 0;
    
public:

    AmbulanceSound(int PIN_BUZZER): Sound(PIN_BUZZER) {
        arrSize = 2;
        melody = (Note*)malloc(sizeof(Note)*arrSize);
        melody[0] = Note{NOTE_B4, 3};
        melody[1] = Note{NOTE_C5, 5};
    }

    void sound() {
        int noteDuration = 1000 / melody[i].duration;
        tone(PIN_BUZZER, melody[i].note, noteDuration);
        delay(noteDuration * 1.01);
        noTone(PIN_BUZZER);
        i = (i+1)%arrSize;
    }
};

class SirenSound: public Sound {
public:
    SirenSound(int PIN_BUZZER): Sound(PIN_BUZZER) {

    }
    
    void sound() {
        for(int i=700; i<800; i++){
            tone(PIN_BUZZER,i);
            delay(15);
        }
        for(int i=800; i>700; i--){
            tone(PIN_BUZZER,i);
            delay(15);
        }  
    }
};


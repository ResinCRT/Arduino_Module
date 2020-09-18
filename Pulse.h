#pragma once
#include <Arduino.h>

typedef void (*pulse_callback_t)();
class Pulse{
protected:
    int onDelay;
    int offDelay;

    int value;
    unsigned long oldTime;
    bool state;
    pulse_callback_t callback;
public:
    Pulse(int onDelay,int offDelay);
    void setDelay(int onDelay, int offDelay);
    void run();
    void play();
    void stop();
    bool getState(){return state;}    
    int read(){ return value; };

    void setCallback(pulse_callback_t callback){this->callback = callback;}
};
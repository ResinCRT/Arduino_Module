#include "Pulse.h"

Pulse::Pulse(int onDelay, int offDelay)
    : onDelay(onDelay), offDelay(offDelay){

        value = HIGH;
        state = false;
        oldTime = millis();
    }

void Pulse::setDelay(int onDelay, int offDelay){
    this->onDelay = onDelay;
    this->offDelay = offDelay;
}
void Pulse::play(){
    state = true;
    value = HIGH;
    oldTime = millis();
}
void stop(){
    value = LOW;
    state = false;
}
void Pulse::run(){
    if(!state) return;

    unsigned long currentTime = millis();
    unsigned long diff = currentTime - oldTime;
    long interval = value ? onDelay : offDelay;

    if(diff>=interval){
        oldTime = currentTime;
        value = !value;
    }
    if(callback != NULL){
        callback(value);
    }
}
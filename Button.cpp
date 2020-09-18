#include "Button.h"


Button::Button(int pin){
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}

int Button::read(){
    return !digitalRead(pin);
}
void Button::setCallback(button_callback_t callback){
    this->callback = callback;
}
void Button::check(){
    state_current = digitalRead(pin);
    if(!state_current)  {
        if(state_previous == true){
            state_previous = false;
            if(callback !=NULL){
                callback();
            }
        }
        delay(10);
    }
    else{
        state_previous = true;
    }
}
#pragma once
typedef void (*button_callback_t)();
#include <Arduino.h>

class Button{
    int pin;
    bool state_current;
    bool state_previous;
    button_callback_t callback;
    public:
    Button(int pin);
    int read();
    void check();
    void setCallback(button_callback_t callback);

};  
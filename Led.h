#pragma once
//헤더 인클루드시 한번만
#include <Arduino.h>

class Led{


    int pin;
    int state;

    public:
    Led(int pin);
    void set(int num);
    void off();
    void on();
    void toggle();
    void blink(int time=0);

};


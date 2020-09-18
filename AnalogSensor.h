#pragma once

#include <Arduino.h>

class AnalogSensor{
    protected:
        int pin;
        int toMin;
        int toMax;

    public:
        AnalogSensor(int pin, int toMin, int toMax);
        AnalogSensor(int pin);
        void setRange(int toMin, int toMax);
        int read();

};
#pragma once

#include <Arduino.h>
#include <Button.h>
#include <AnalogSensor.h>

typedef struct{
    int x;
    int y;
    int z;
}joystick_value_t;

class Joystick{
    protected:
        AnalogSensor jX;
        AnalogSensor jY;
        Button btn;

    public:
        Joystick(int x, int y, int z);

        int readX();
        int readY();
        void setRangeX(int toMin, int toMax);
        void setRangeY(int toMin, int toMax);
        
        int readZ();
        void setCallback(button_callback_t callback);
        void check();

        joystick_value_t read();


};

#pragma once

#include <Arduino.h>

class Motor {
protected:
    int in1;
    int in2;
    int en;

public:
    Motor(int in1, int in2, int en);
    void forward(int speed=200);
    void backward(int speed=200);
    void stop();
    void setSpeed(int speed=200);
};
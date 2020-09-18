#include "AnalogSensor.h"

AnalogSensor::AnalogSensor(int pin ,int toMax,int toMin) 
    : pin(pin), toMax(toMax), toMin(toMin){

}
AnalogSensor::AnalogSensor(int pin) 
    : pin(pin){
        this->toMin = 0;
        this->toMax = 1023;
}


int AnalogSensor::read(){
    int val = analogRead(pin);
    return map(val, 0, 1023, toMin, toMax);
}

void AnalogSensor::setRange(int toMin, int toMax){
    this->toMin = toMin;
    this->toMax = toMax;
}
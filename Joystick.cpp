#include "Joystick.h"

Joystick::Joystick(int x, int y, int z) : jX(x), jY(y), btn(z){

}

int Joystick::readX(){
    return jX.read();
}
int Joystick::readY(){
    return jY.read();
}
void Joystick::setRangeX(int toMin, int toMax){
    jX.setRange(toMin, toMax);
}

void Joystick::setRangeY(int toMin, int toMax){
    jY.setRange(toMin, toMax);
}
int Joystick::readZ(){
    return btn.read();
}

void Joystick::setCallback(button_callback_t callback){
    btn.setCallback(callback);
}
void Joystick::check(){
    btn.check();
}

joystick_value_t Joystick::read(){
    joystick_value_t value;
    value.x = readX();
    value.y = readY();
    value.z = readZ();
    return value;
}
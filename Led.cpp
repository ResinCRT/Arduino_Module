#include "Led.h"

Led::Led(int pin){
    this->pin = pin;
    state = LOW;
    pinMode(pin, OUTPUT);
}
void Led::set(int num){
    state = num;
    if(num != LOW)
        Serial.println("set ");
    digitalWrite(pin, state);
}
void Led::off(){
    state = LOW;
    digitalWrite(pin,state);
}
void Led::on(){
    state = HIGH;
    digitalWrite(pin,state);
}

void Led::toggle(){
    state = !state;
    digitalWrite(pin,state);
}
void Led::blink(int time){
    digitalWrite(pin,HIGH);
    delay(time/2);
    digitalWrite(pin,LOW);
    delay(time/2);
}


#include "TrafficLight.h"

TrafficLight::TrafficLight(int greenLED, int yellowLED, int redLED) : greenLED(greenLED), yellowLED(yellowLED),redLED(redLED){
    pinMode(greenLED,OUTPUT);
    pinMode(redLED,OUTPUT);
    pinMode(yellowLED,OUTPUT);
}

void TrafficLight::go(int time){
    digitalWrite(yellowLED,LOW);
    digitalWrite(greenLED,HIGH);
    digitalWrite(redLED,LOW);
    if(time != 0)
        delay(time);
}
void TrafficLight::leftTurn(int time){
    digitalWrite(yellowLED,HIGH);
    digitalWrite(greenLED,HIGH);
    digitalWrite(redLED,LOW);
    if(time != 0)
        delay(time);    
}
void TrafficLight::leftTurnWarning(int time){
    digitalWrite(yellowLED,HIGH);
    digitalWrite(greenLED,LOW);
    digitalWrite(redLED,LOW);
    long interval = time/5;
    for(int i=0; i<5;i++){
        blink(greenLED, interval);
    } 
}
void TrafficLight::stop(int time){
    digitalWrite(yellowLED,HIGH);
    digitalWrite(greenLED,HIGH);
    digitalWrite(redLED,HIGH);
    delay(time);
    digitalWrite(yellowLED,LOW);
    digitalWrite(greenLED,LOW);
    digitalWrite(redLED,LOW);
}
void TrafficLight::blink(int pin, int time){
    digitalWrite(pin,HIGH);
    delay(time/2);
    digitalWrite(pin,LOW);
    delay(time/2);
}

void TrafficLight::run(){
    go(2000);
    leftTurn(1000);
    leftTurnWarning(3000);
    stop(2000);
}
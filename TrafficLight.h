#ifndef __TRAFFIC_LIGHT_H__
#define __TRAFFIC_LIGHT_H__
//헤더 인클루드시 한번만
#include <Arduino.h>
class TrafficLight{

private:
int yellowLED;
int greenLED;
int redLED;

public:
    TrafficLight(int greenLED,int yellowLED, int redLED);
    void go(int time=0);
    void leftTurn(int time);
    void leftTurnWarning(int time);
    void stop(int time);
    void blink(int pin,  int time);

    void run();

};






#endif
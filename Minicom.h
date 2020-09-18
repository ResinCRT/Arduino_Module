#pragma once

#include <Arduino.h>
#include <SimpleTimer.h>
#include <LiquidCrystal_I2C.h>

class Minicom{
protected:
    LiquidCrystal_I2C lcd;
    SimpleTimer timer;
public:
    Minicom();
    void init();
    int setInterval(unsigned long d, timer_callback callback);
    void run();

    void print(int col, int row, const char *pMsg);
    void print(int row, const char* pMsg);
    void print(int row,const char *pTitle, int value);
    void print(int row,const char *pTitle, double value, int width);
    void print(int row, const char *pTitle1,const char *pTitle2, int value1, int value2); // 추가
};
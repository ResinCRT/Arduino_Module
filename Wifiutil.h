#pragma once

#include <SoftwareSerial.h>
#include <WiFiEsp.h>


class Wifiutil{
private:
    const char *ssid;
    const char *password;
    SoftwareSerial softSerial;
    int status = WL_IDLE_STATUS;

public:
    Wifiutil(int rx, int tx);
    void init(const char *ssid, const char *password);
    void checkShield();
    void printInfo();

    int check();
};
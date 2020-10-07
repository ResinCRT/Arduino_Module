#pragma once

#include <Arduino.h>
#include <Minicom.h>
#include <SoftwareSerial.h>

typedef void (*bt_callback_t)(String line);

class BtMinicom : public Minicom{
protected:    
    SoftwareSerial btSerial;
    bt_callback_t callback;

public:
    BtMinicom(int rx, int tx,  bt_callback_t callback=NULL);
    void init();
    void send(const char *msg);
    String readLine();
    void run();    

};
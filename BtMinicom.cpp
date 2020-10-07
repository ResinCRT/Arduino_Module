#include "BtMinicom.h"

BtMinicom::BtMinicom(int rx, int tx,  bt_callback_t callback) 
    : Minicom(), btSerial(rx, tx){
    this->callback = callback;   
}

void BtMinicom::init() {
    btSerial.begin(9600);
    Minicom::init();
}


void BtMinicom::send(const char *msg) {
    btSerial.println(msg);
}

String BtMinicom::readLine() {
    String line = "";
    while(btSerial.available()) {
        char ch = btSerial.read();
        if(ch == '\r') continue;
        if(ch == '\n') break;
        line += ch;
        delay(15);
    }
    return line;
}

void BtMinicom::run() {
    String line = readLine();
    if(line != "" && callback != NULL) {
        callback(line);
    }
    Minicom::run();
}
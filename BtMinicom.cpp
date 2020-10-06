#include "BtMiniCom.h"

BtMiniCom::BtMiniCom(int rx, int tx,  bt_callback_t callback) 
    : MiniCom(), btSerial(rx, tx){
    this->callback = callback;   
}

void BtMiniCom::init() {
    btSerial.begin(9600);
    MiniCom::init();
}


void BtMiniCom::send(const char *msg) {
    btSerial.println(msg);
}

String BtMiniCom::readLine() {
    String line = "";
    while(btSerial.available()) {
        char ch = btSerial.read();
        if(ch == '\r') continue;
        if(ch == '\n') break;
        line += ch;
        delay(5);
    }
    return line;
}

void BtMiniCom::run() {
    String line = readLine();
    if(line != "" && callback != NULL) {
        callback(line);
    }
    MiniCom::run();
}
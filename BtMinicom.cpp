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

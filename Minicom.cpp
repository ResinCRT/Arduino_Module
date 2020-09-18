#include "Minicom.h"

Minicom::Minicom() : lcd(0x27,16,2){

}

void Minicom::init(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.clear();
}
int Minicom::setInterval(unsigned long d, timer_callback callback){
    return timer.setInterval(d,callback);
}

void Minicom::run(){
    timer.run();
}

void Minicom::print(int col, int row, const char *pMsg){
    lcd.setCursor(col,row);
    char buf[17];
    sprintf(buf, "%-16s", pMsg);
    lcd.print(buf);
}
void Minicom::print(int row, const char* pMsg){
    print(0, row, pMsg);
}
void Minicom::print(int row, const char *pTitle, int value){
    char buf[17];
    sprintf(buf, "%s: %d", pTitle, value);
    print(0, row, buf);
}
void Minicom::print(int row, const char *pTitle1, const char *pTitle2, int value1, int value2){
    char buf[17];
    sprintf(buf, "%s: %d/ %s: %d", pTitle1, value1, pTitle2, value2);
    print(0, row, buf);
}
void Minicom::print(int row,const char *pTitle, double value, int width){
    char buf[17];
    char temp[10];
    dtostrf(value, width, 2, temp);
    sprintf(buf, "%s: %s",temp);
    print(0, row, buf);
}


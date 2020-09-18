#include "Wifiutil.h"

Wifiutil::Wifiutil(int rx, int tx): softSerial(rx,tx){

}

void Wifiutil::checkShield(){
    if (WiFi.status() == WL_NO_SHIELD){
        Serial.println("WiFi shield not present");
        while(true);
    }
}

int Wifiutil::check(){
    while(WiFi.status() != WL_CONNECTED){
        Serial.print("Attempting to connect to WPA SSID");
        Serial.println(ssid);
        status = WiFi.begin(ssid,password);
        if (status == WL_CONNECTED){
            printInfo();
            return 1;
        }
    }
    return 0;
}
void Wifiutil::init(const char *ssid, const char *password){
    this->ssid = ssid;
    this->password = password;

    softSerial.begin(9600);
    WiFi.init(&softSerial);
    checkShield();
    check();
}
void Wifiutil::printInfo(){
    Serial.println("You're connected to the network");
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    long rssi = WiFi.RSSI();
    Serial.print("Signal strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");
    Serial.println();
}
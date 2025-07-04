//https://www.hobbyhappyblog.jp/esp32-lolind32-bluetooth-keyboard

#include <BleKeyboard.h>
// https://github.com/T-vK/ESP32-BLE-Keyboard
// Remove comment out #define USE_NIMBLE
// Install NimBLE-Arduino library
// ※Choose NimBLE-Arduino ver,1.x 

#define swPin 3 //3:ConnectorA 4:ConnectorB

BleKeyboard bleKeyboard("TTT ESP32 Keyboard"); // Can be renamed to any device name you like.

void setup() {
  bleKeyboard.begin();
  pinMode(swPin, INPUT);
}

void loop() {
  if(bleKeyboard.isConnected()) {
    if(digitalRead(swPin) == HIGH){
      bleKeyboard.print("hello");
      delay(200);
    }
  }
}
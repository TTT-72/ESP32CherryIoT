#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>  //シリアル通信規格　本センサ基盤の搭載規格

DHT20 DHT;

void setup() {
  Serial.begin(115200);
  Wire.begin(1, 3); //1,3:ConnectorA 5,4:ConnectorB　3はクロックシンクロ用、1は実データ信号用
}

void loop() {
  DHT.read();
  float Temperature = DHT.getTemperature();
  float Humidity = DHT.getHumidity();
  //Look at the serial monitor
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "％");
  delay(500);
}
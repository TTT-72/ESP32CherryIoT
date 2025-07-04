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



// #define BLYNK_PRINT Serial

// #define BLYNK_TEMPLATE_ID "xxx"
// #define BLYNK_TEMPLATE_NAME "xxx"
// #define BLYNK_AUTH_TOKEN "xxx"

// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>

// char ssid[] = "xxxx";
// char pass[] = "xxxx";

// const int ledPin = 3; //3:ConnectorA 4:ConnectorB 10:Builtin

// void setup()
// {
//   Serial.begin(115200);
//   pinMode(ledPin, OUTPUT);
//   Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
// }

// BLYNK_WRITE(V0)
// {
//   int value = param.asInt();
//   digitalWrite(ledPin, value);
//   Serial.println(value ? "LED ON" : "LED OFF");
// }

// void loop()
// {
//   Blynk.run();
// }


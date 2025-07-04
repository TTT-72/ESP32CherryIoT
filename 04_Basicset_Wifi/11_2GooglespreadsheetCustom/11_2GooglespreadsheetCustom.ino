#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>  //シリアル通信規格　本センサ基盤の搭載規格
#include <WiFi.h>
#include <WiFiClientSecure.h>

DHT20 DHT; //インスタンス

// WiFi Setting
const char* ssid = "XXXX";
const char* password = "XXXX";

void setup() {
  Serial.begin(115200);
  Wire.begin(1, 3); //1,3:ConnectorA 5,4:ConnectorB　3はクロックシンクロ用、1は実データ信号用
}

void loop() {
  sendData();
  delay(10000);
}

void connectWiFi(){
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  //Start WiFi connection
  WiFi.begin(ssid, password);

  //Check WiFi connection status
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void sendData(){
  delay(1000);
  DHT.read();
  float Temperature;
  float Humidity;
  Temperature = DHT.getTemperature();
  Humidity = DHT.getHumidity();
  Serial.println(String(Temperature) + "℃");
  Serial.println(String(Humidity) + "％");

  WiFiClientSecure sslclient;

  const char* server = "script.google.com";
  String url = "https://script.google.com/macros/s/AKfycbyqhEOrbBPlz_4mSmmdTgpLLTptASFFbm23bw8ZMLFb9oJaiJjrqE8qhHbKRJyeFqsK/exec";  //googlescript web appのurlを入力

  //Prepare measurements


  //Connect WiFi
  connectWiFi();

  //Add measurement value to the end of the URL
  url += "?";
  url += "&1_cell=";
  url += Temperature;
  url += "℃";
  url += "&2_cell=";
  url += Humidity;
  url += "％";

  // Access server
  Serial.println("Access server...");
  sslclient.setInsecure(); //skip verification
  
  //Send data
  if (!sslclient.connect(server, 443)) {
    Serial.println("Connection failed!");
    Serial.println("");
    return;
  }

  Serial.println("Connected to server");

  sslclient.println("GET " + url);
  delay(1000); //Waiting for stabilization
  sslclient.stop();

  Serial.println("Data transmission completed");
  Serial.println("");//改行

  //Disconnect WiFi
  WiFi.mode(WIFI_OFF);
}


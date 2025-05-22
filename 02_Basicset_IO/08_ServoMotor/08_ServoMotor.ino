#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington

const int motorPin = 3; //3:ConnectorA 4:ConnectorB

Servo myservo;

void setup() {
  myservo.attach(motorPin);
}

void loop() {
  //3拍子*2
  for(int count = 0; count <= 1; count++){
    myservo.write(0);
    delay(500); 
    myservo.write(90);
    delay(500);
    myservo.write(180);
    delay(500);
    myservo.write(0);
    delay(500);
  }
  // 7拍子
  for(int count = 0; count <= 3; count++) {                        
    myservo.write(0);
    delay(500);
    myservo.write(90);
    delay(500);
  }
  delay(1000);
  // 運動後マッサージ
  for(int angle = 180; angle >= 0; angle--) {                 
    myservo.write(angle);  
    delay(15);      
  }
}

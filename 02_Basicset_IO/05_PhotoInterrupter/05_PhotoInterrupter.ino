const int ruptPin = 3; //3:ConnectorA 4:ConnectorB

void setup(){
  Serial.begin(115200);
  pinMode(ruptPin, INPUT);
}

void loop(){
  //Look at the serial monitor
  if (digitalRead(ruptPin)==LOW) {
    Serial.println("Interrupt!");
  } else {
    Serial.println("...");
  }
  delay(500);
}

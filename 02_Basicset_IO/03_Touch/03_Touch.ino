const int touchPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
}

void loop() {
  //Look at the serial monitor
  if (digitalRead(touchPin) == HIGH) {
    Serial.println("Touch!");
    delay(100);
  } else {
    Serial.println("...");
    delay(100);
  }
  delay(0);
}
const int motorPin = 3; //3:ConnectorA 4:ConnectorB

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, HIGH);
  delay(3000);
  digitalWrite(motorPin, LOW);
  delay(1000);
}

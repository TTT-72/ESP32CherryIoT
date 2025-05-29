const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB 10:Builtin
bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() { 
  if (digitalRead(swPin) == HIGH) {
    swState = !swState;
  }

  if (swState == 1) {
    digitalWrite(motorPin, HIGH); //on
    Serial.println("on");
    delay(500);
  } else {
    digitalWrite(motorPin, LOW); //off
    Serial.println("off");
    delay(500);
  }
}
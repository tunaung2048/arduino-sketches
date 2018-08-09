void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0); // analog value from A0

  // dimmer through preset
  analogWrite(6, map(analogRead(A0), 0, 1023, 0, 255));

  digitalWrite(12, HIGH);
  delay(analogValue + 50); // analogValue == 1023
  digitalWrite(12, LOW);
  delay(analogValue + 50);
  
  
  /*
  digitalWrite(13, HIGH);
  delay(analogValue + 50); // analogValue == 1023
  digitalWrite(13, LOW);
  delay(analogValue + 50);
  */ 
}

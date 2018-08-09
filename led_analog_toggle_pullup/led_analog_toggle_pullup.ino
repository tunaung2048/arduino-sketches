boolean ledState = false;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(11, INPUT_PULLUP);

}

void loop() {
  int analogValue = analogRead(A0);
  analogValue = map(analogValue, 0, 1023, 0, 255);

  if(digitalRead(11) == LOW) {
    ledState = !ledState;
  }
  
  if(ledState) {
    analogWrite(9, analogValue);
  }
  else {
    analogWrite(9, 0);
  }

  delay(200);
}

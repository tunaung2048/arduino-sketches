void setup() {
  pinMode(13, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

}

void loop() {
  if((digitalRead(9) == LOW) && (digitalRead(11) == LOW)) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }

}

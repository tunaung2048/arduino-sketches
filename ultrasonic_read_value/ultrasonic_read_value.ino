void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  int receivedData = analogRead(10);

  if (receivedData > 70) {
    digitalWrite(13, LOW);
  }
  else if (receivedData < 50) {
    digitalWrite(13, HIGH);
  }
  
}


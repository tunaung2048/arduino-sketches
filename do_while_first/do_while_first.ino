void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  int analogValue = analogRead(A0);
  
  do {  
    analogValue = map(analogRead, 0, 1023, 0, 255);
    digitalWrite(13, HIGH);
  } while(analogValue > 100);
  

  digitalWrite(13, LOW);
}

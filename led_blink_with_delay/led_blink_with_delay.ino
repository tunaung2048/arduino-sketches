// LED blink

void setup() {
  for (int i=0; i<10; i++) {
    pinMode(i+2, OUTPUT);
  }
}

void loop() {
  int delayTime = analogRead(A0);
  delayTime = map(delayTime, 0, 1023, 1, 1000);

  for(int i=0; i<10; i++) {
    digitalWrite(i+2, HIGH);
    delay(delayTime);
    digitalWrite(i+2, LOW);
  }
  for(int i=10; i>0; i--) {
    digitalWrite(i+2, HIGH);
    delay(delayTime);
    digitalWrite(i+2, LOW);
  }
  

}

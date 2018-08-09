

void setup() {
  for (int i=0; i<10; i++) {
    pinMode(i+2, OUTPUT);
  }
  pinMode(12, INPUT_PULLUP);
}

void loop() {
  int delayTime = analogRead(A0);
  delayTime = map(delayTime, 0, 1023, 1, 1000);

  for(int i=0; i<10; i++) {
    digitalWrite(i+2, HIGH);
    delay(delayTime);
    
    while(!digitalRead(12)) {
      delay(1);
    }
    
    digitalWrite(i+2, LOW);
  }
  /*
  for(int i=10; i>0; i--) {
    digitalWrite(i+2, HIGH);
    delay(delayTime);
    digitalWrite(i+2, LOW);
  }*/
  

}

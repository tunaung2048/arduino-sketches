boolean previousState = false;
boolean currentState = false;

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(i + 2, OUTPUT);
  }
  pinMode(12, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  int delayTime = analogRead(A0);
  delayTime = map(delayTime, 0, 1023, 1, 1000);
  
  
  digitalWrite(13, HIGH);

  
  while (!digitalRead(12)) {
    currentState == !previousState;
  }

  digitalWrite(13, currentState);
  previousState = currentState;

  /*
  for (int i = 0; i < 10; i++) {
    digitalWrite(i + 2, HIGH);
    delay(delayTime);
    digitalWrite(i + 2, LOW);
  }
  */
  
  /*
    while (!sts) {
    for (int i = 10; i > 0; i--) {
    digitalWrite(i + 2, HIGH);
    delay(delayTime);
    digitalWrite(i + 2, LOW);
    }
    }*/

}

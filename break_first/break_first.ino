void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, INPUT_PULLUP);  // --> pinMode(11, INPUT); pinMode(11, OUTPUT);
  pinMode(10, INPUT_PULLUP);
}

int currentMillis = 0;
int previousMillis = 0;
int interval = 500;
boolean ledState = false;

void loop() {
  Serial.println(millis());
  int i = 0;

  if (!digitalRead(11)) {
    while (i < 20) {
      currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
        ledState = !ledState;
        previousMillis = currentMillis;
        i++;
      }
      digitalWrite(13, ledState);
      if (!digitalRead(10)) {
        digitalWrite(13, LOW);
        break;
      }
    }
  }
  digitalWrite(13, LOW);
}

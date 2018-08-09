int ledPins[] = { 2, 3, 4, 5, 6, 7};
int ledCount = 6;
int AnalogPin = A0;


void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  int ledLevel = map(analogRead(AnalogPin), 0, 1023, 1, ledCount);

  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }

}

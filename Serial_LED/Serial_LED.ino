char ledPins[] = { 3, 5, 6, 9, 10, 11 };


void setup() {
  Serial.begin(9600);
  for (int i=0; i<6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned char brightness[6];
  while (Serial.available()) {
    for (int i=0; i<6; i++) {
      brightness[i] = Serial.parseInt();
      analogWrite(ledPins[i], brightness[i]);
    }
  }
}

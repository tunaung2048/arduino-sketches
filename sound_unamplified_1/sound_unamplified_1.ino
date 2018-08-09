const int soundPin = 11;

void setup() {
  pinMode(soundPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter frequency");

}

void loop() {
  if(Serial.available()) {
    int f = Serial.parseInt();
    tone(soundPin, f);
    delay(2000);
    noTone(soundPin);
  }

}

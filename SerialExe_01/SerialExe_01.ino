void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  while(Serial.available()) {
    unsigned char c = Serial.parseInt();
    analogWrite(9, c);
  }

}

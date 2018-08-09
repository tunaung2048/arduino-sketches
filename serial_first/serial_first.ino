unsigned char a;

void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    a = Serial.parseInt();
    analogWrite(11, a);
  }
}

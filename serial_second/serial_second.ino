char a, b, c;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    a = Serial.parseInt();
    b = Serial.parseInt();
    c = Serial.parseInt();
    analogWrite(9, a);
    analogWrite(10, b);
    analogWrite(11, c);
  }
}

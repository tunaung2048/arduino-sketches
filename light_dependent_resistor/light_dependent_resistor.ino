int LDR_VALUE = 0;

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  //analogWrite(9, analogRead(A0));
  Serial.println(analogRead(A0));
  LDR_VALUE = analogRead(A0);
  // normal (room)
  if (LDR_VALUE >= 800 && LDR_VALUE <= 1000) {
    digitalWrite(9, HIGH);
  }
  // lighter (daytime/overexpose)
  else if (LDR_VALUE < 800) {
    digitalWrite(9, LOW);
  }
  // darker
  else {
    digitalWrite(9, HIGH);
  }

  delay(10);

}

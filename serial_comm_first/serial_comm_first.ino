void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Hello from Arudino UNO ");
  Serial.println(analogRead(A0));

  for ( int i = 0; i < 5; i++) {
    Serial.println(i);
  }
  delay(2000);
}

/*
   KeyesIR Sensor Module
*/



void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}
int c = 0;
void loop() {

  Serial.print(digitalRead(7));
  c = c + 1;
  if (c >= 19) {
    Serial.println();
  }
  delay(500);
}

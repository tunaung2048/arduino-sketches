

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  //Serial.println(digitalRead(7));
  digitalWrite(13, !digitalRead(7));

  if(Serial.available()) {
    
  }
  
  
  delay(100);
}

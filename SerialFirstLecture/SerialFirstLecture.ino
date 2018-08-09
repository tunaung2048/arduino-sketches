// 

void setup() {
  Serial.begin(9600);

}

void loop() {
  int value = analogRead(A0);
  //Serial.print(value);
  //Serial.print("\n");
  
  while(Serial.available()) {
    //char c = Serial.read();
    //Serial.write(c);

    //char c = Serial.read();
    //Serial.write(c);

    //int i = Serial.parseInt();
    unsigned int i = Serial.parseInt();
    Serial.println(i);
    
  }
}

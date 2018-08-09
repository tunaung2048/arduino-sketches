/**

*/

byte image[] = {
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00011000,s

};

void setup() {
  DDRD = 0xFF; // output all pins
  DDRC = 0x0F;
  DDRB = 0x0F;
}

void loop() {
  /*
    byte bitChange = 1;
    for (int i = 0; i < 8; i++) {
    PORTB = bitChange & 0x0F;
    PORTC = (bitChange >> 4) & 0x0F;
    PORTD = B11111111;
    delay(2);
    bitChange <<= 1;
    PORTD = 0;
    }
  */
  int speedValue = analogRead(A4);
  speedValue = map(speedValue, 0, 1023, 0, 80);
  
  for (int k = 0; k < 24; k++) {
    for (int m = 0; m < speedValue; m++) {
      byte bitChange = 1;
      for (int i = 0; i < 8; i++) {
        PORTB = bitChange & 0x0F;
        PORTC = (bitChange >> 4) & 0x0F;
        PORTD = image[i];
        //PORTD = image[(i+k)%24];
        delay(2);
        bitChange <<= 1;
        bitChange >>= 1;
        PORTD = 0;

      }
    }
  }

}

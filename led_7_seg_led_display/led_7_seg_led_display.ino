/**



   BIN    HEX
   0001   01
   0010   02
   0011   03
   0100   04
   0101   05
   0110   06
   0111   07
*/

void setup() {
  // data direction for PORTC (A0 to A5)
  DDRC = 0x0F; // binary -> 0b00001111
  DDRB = 0x0F;
}

void loop() {
  int value = analogRead(A4);
  value = map(value, 0, 1023, 0, 200);

  int number[3] = { 0, 0, 0 };

  for (int i = 2; i >= 0 ; i--) {
    number[i] = value % 10;
    value /= 10;
  }

  displaySevenSegment(number);
  /*
    number[2] = value % 10;
    value = value / 10;
    number[1] = value % 10;
    value = value / 10;
    number[0] = value % 10;
    value = value / 10;
  */
}

void displaySevenSegment(int numbers[]) {
  int delayTime = 5;
  int bitChange = 0x01;

  for (int i = 0; i < 3; i++) {
    PORTC = 0x0F;
    PORTB = bitChange;
    PORTC = numbers[i] & 0x0F;

    delay(delayTime);

    bitChange <<= 1;
  }
}


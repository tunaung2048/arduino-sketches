/*
 * read value from EEPROM
 * set led value from EEPROM
 * 
 */

#include <EEPROM.h>

#define ledPin 9
#define pullupPin 7

int addr = 0;


void setup() {
  /** Empty setup. **/
  pinMode(ledPin, OUTPUT);
  pinMode(pullupPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  int ledValue = analogRead(A0);
  int ptnValue = map(ledValue, 0, 1023, 0, 255);


  analogWrite(ledPin, EEPROM.read(addr));
  
  analogWrite(ledPin, ptnValue);
  //int val = analogRead(0) / 4;
  //EEPROM.write(addr, val);

  // store Potentionmeter Value to EEPROM
  if (digitalRead(pullupPin) == LOW) {
    EEPROM.write(addr, ptnValue);
  }

  

  delay(100);
}

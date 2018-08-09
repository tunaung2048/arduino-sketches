/**
   Bluetooth (HC06) Software Serial
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);


void setup() {
  mySerial.begin(9600);
  DDRD = 0xFF;
}


void loop() {
  byte data;

  if (mySerial.available()) {
    //data = (byte)mySerial.read();
    data = (byte)mySerial.parseInt();
    
    mySerial.println(data);
    PORTD = data  ;
  }
}

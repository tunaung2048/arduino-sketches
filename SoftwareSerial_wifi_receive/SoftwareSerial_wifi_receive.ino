/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  Serial.println("Serial Port Ready !");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello from mySerial");
}


String msg = "";
String data = "";
char a;

void loop() { // run over and over
  while (mySerial.available()) {
    a = (char)mySerial.read();
    if (a != '\n') {
      msg += a;
    }
    else {
      msg.trim();
      data = msg;
      msg = "";
    }

    if (data.substring(0, 3) == "ABC") {
      Serial.print(data.substring(3, data.length()));
    }
  }
}


/*
   IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
   An IR detector/demodulator must be connected to the input RECV_PIN.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
}



void loop() {

  if (irrecv.decode(&results)) {  
    Serial.println("HEX : ");
    Serial.println(results.value, HEX);
    Serial.println("DEC : ");
    Serial.println(results.value, DEC);

    
    unsigned long data = results.value;
    Serial.println("data : ");
    Serial.println(data);


    if (data == 4294967295) {
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
    }
    else {
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
    }


  }
  irrecv.resume(); // Receive the next value








  delay(100);
}

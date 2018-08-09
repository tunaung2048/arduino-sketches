/* Date : 13-Dec-2016
   IR Remote Control Home Switches using Relay
   Library: IRremote https://github.com/shirriff/Arduino-IRremote
   Pin 8 -> IR Receiver data
   Pin 9 -> Relay Data

*/

#include <IRremote.h>

int IR_RECV_PIN = 8;
int MAIN_RELAY_PIN = 9;

IRrecv irRecv(IR_RECV_PIN);
decode_results results;
boolean relay_1_status = false;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  irRecv.enableIRIn();
}

void loop() {
  if(irRecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if(results.value == 0xFFA25D) {
      relay_1_status = !relay_1_status;
      digitalWrite(MAIN_RELAY_PIN, relay_1_status);
    }
    irRecv.resume(); // receive next value
  }
  delay(100);
}

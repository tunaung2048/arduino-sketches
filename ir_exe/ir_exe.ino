#define ledPin 13
#define irLedPin 7
#define irRecvPin 3

#include <IRremote.h>
#include <IRLib.h>
IRrecv irrecv(irRecvPin);
decode_results results;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("HEX : ");
    Serial.println(results.value, HEX);
    Serial.println("DEC : ");
    Serial.println(results.value, DEC);
  }

  irrecv.resume();

  delay(100);

}

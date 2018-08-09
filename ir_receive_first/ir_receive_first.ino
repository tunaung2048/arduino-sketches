#define GREEN_PIN 2
#define RED_PIN 3
#define YELLOW_PIN 4

#include <IRremote.h>
//#include <IRremoteInt.h>

int RECV_PIN = 8;
long recvData;
IRrecv irrecv(RECV_PIN);
decode_results results;
//IRsend irsend;
boolean sts_green = false;
boolean sts_red = false;
boolean sts_yellow = false;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
}



void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    switch (results.value) {
      case 0xFFA25D:
        Serial.println("Power Button");
        sts_green = !sts_green;
        break;
      case 0xFF629D:
        Serial.println("Return Button");
        sts_red = !sts_red;
        break;
      case 0xFFE21D:
        Serial.println("Mode Button");
        sts_yellow = !sts_yellow;
        break;
    }

    digitalWrite(GREEN_PIN, sts_green);
    digitalWrite(RED_PIN, sts_red);
    digitalWrite(YELLOW_PIN, sts_yellow);

    irrecv.resume(); // receive next value
  }
  delay(100);
}

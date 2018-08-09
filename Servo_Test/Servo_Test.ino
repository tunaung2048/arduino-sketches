/**
 * Control servo from serial input (serial monitor)
 */

#include <Servo.h>
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  
  
  while(Serial.available()) {
    // alternative
    // Serial.begin(9600);
    
    int data = Serial.parseInt();
    
    if(data < 170) {
      myServo.write(data);
    }

    // alternative
    // Serial.end();
  }

}

/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    int dg = Serial.parseInt();
    if (dg <= 180 && dg >= 0) {
      myservo.write(dg);
    }
  }
}


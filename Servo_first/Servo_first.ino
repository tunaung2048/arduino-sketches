#include <Servo.h>

Servo myServo;


void setup() {
  myServo.attach(9);
}

void loop() {
  int servoAngle = analogRead(A0);
  servoAngle = map(servoAngle, 0, 1023, 0, 180);

  myServo.write(servoAngle);
}

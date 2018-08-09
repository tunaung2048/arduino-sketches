/* Modification of Sweep
 *  
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(2, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    
    
    delay(20);                       // waits 15ms for the servo to reach the position
  }

  
  
  for (pos = 180; pos >= 0; pos -= 2) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    if (pos == 180) {
      //digitalWrite(2, HIGH);
    }

    delay(20);                       // waits 15ms for the servo to reach the position
  }
}


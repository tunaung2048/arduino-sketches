/*
   Bluetooth Exercise 1
   Modules:
          HC-06 bluetooth (master)
   Description:
          Control led pin 2 with android app through android app
*/
#define pinLed 2

byte commands[1] = { 0x00 };
byte prevCommands[1] = { 0x01 };

unsigned long time1 = 2000;  //Stores the time (in millis since execution started)
unsigned long time2 = 0;  //Stores the time when the last command was received from the phone

int i = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  if (Serial.available() == 1) {
    time2 = millis();  //Store the time when last command was received
    memcpy(prevCommands, commands, 1); //Storing the received commands
    commands[0] = Serial.read();  //Lights and buttons states


    //Check the front/back lights and other toggles
    if (prevCommands[3] != commands[3]) {
      //Serial.println(commands[3],BIN);
      //Change the light/button states
      //               _______________________________________________
      //command[3] =  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  binary
      //              |_____|_____|_____|_____|_____|_____|_____|_____|
      //Buttons ---->  Front  Back  Horn   A     B     C     D     E
      //                 7     6     5     4     3     2     1     0

      //Front lights
      if ((bitRead(prevCommands[3], 7)) != (bitRead(commands[3], 7))) {
        if (bitRead(commands[3], 7)) {
          digitalWrite(pinLed, HIGH);
        }
        else {
          digitalWrite(pinLed, LOW);
        }
      }
    }

    else {
      //Resetting the Serial port (clearing the buffer) in case the bytes are not being read in correct order.
      Serial.end();
      Serial.begin(9600);
    }
  }
  else {
    time1 = millis();  //Get the current time (millis since execution started)
    if ((time1 - time2) > 400) { //Check if it has been 400ms since we received last command
      digitalWrite(pinLed, LOW);
    }
    if ((time1 - time2) >= 477) {
      time1 = millis();
    }
  }
}

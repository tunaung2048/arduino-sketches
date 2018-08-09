#include <L293.h>
#include <Servo.h>
#include <NewPing.h>

#define pinForward 8     //input pin for motor driver
#define pinBack 7       //input pin for motor driver
#define pinSpeedForwardBack 6 //speed pin, connect to enable pin of motor driver
#define pinFrontLights 4
#define pinBackLights 18  //A4 pin 
#define pinSignalR 19 //A5 pin
#define pinSignalL 2
int signalRState = LOW;
int currentRState = LOW;
int signalLState = LOW;
int currentLState = LOW;
int signalInterval = 400;
unsigned long previousMillis = 0;
#define pinHorn 5
#define pinFrontSteering 10 //servo pin for steering

#define SONAR_NUM     2 // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 100
#define stopDistance 60 //distance in cm to stop
int distance[2] {0, 0};

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.

NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(13, 9, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(12, 11, MAX_DISTANCE)
};

L293 redCar(pinForward, pinBack, pinSpeedForwardBack);
Servo leftRight;
byte commands[4] = {0x00, 0x00, 0x00, 0x00};
byte prevCommands[4] = {0x01, 0x01, 0x01, 0x01};
//Variables will be used to determine the frequency at which the sensor readings are sent
//to the phone, and when the last command was received.

unsigned long timer0 = 2000;  //Stores the time (in millis since execution started)
unsigned long timer1 = 0;  //Stores the time when the last sensor reading was sent to the phone
unsigned long timer2 = 0;  //Stores the time when the last command was received from the phone

//14 byte payload that stores the sensor readings
byte three[14] = {0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc};

//Constant used to caculate the 9V battery voltage (9.04 mV per step)
float stepSize = 9.04;

//The union allows you to declare a customized data type, in this case it can be either
//a float or a byte array of size 4. What we need is to store a float which is 4
//bytes long and retrieve each of the 4 bytes separately.
union u_sensor0 {
  byte a[4];
  float b;
} sensor0;
union u_sensor1 {
  byte c[4];
  float d;
} sensor1;

int i = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(pinFrontLights, OUTPUT);
  pinMode(pinBackLights, OUTPUT);
  digitalWrite(pinBackLights, HIGH);
  pinMode(pinHorn, OUTPUT);
  pinMode(pinSignalR, OUTPUT);
  pinMode(pinSignalL, OUTPUT);
  leftRight.attach(pinFrontSteering);
  leftRight.write(100);
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) { // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
  }
}

void loop()
{
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == SONAR_NUM - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }

  //Blinking Part

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= signalInterval) {
    previousMillis = currentMillis;
    if (currentLState == LOW && signalLState == HIGH) {
      currentLState = HIGH;
    } else {
      currentLState = LOW;
    }
    digitalWrite(pinSignalL, currentLState);

    if (currentRState == LOW && signalRState == HIGH) {
      currentRState = HIGH;
    }
    else {
      currentRState = LOW;
    }
    digitalWrite(pinSignalR, currentRState);
  }

  //Reveicing Signal form bluetooth
  if (Serial.available() == 4) {
    timer2 = millis();  //Store the time when last command was received
    memcpy(prevCommands, commands, 4); //Storing the received commands
    commands[0] = Serial.read();  //Direction
    commands[1] = Serial.read();  //Speed
    commands[2] = Serial.read();  //Angle
    commands[3] = Serial.read();  //Lights and buttons states
    /*
      Since the last byte yields the servo's angle (between 0-180), it can never be 255. At times, the two
      previous commands pick up incorrect values for the speed and angle. Meaning that they get the direction
      correct 100% of the time but sometimes get 255 for the speed and 255 for the angle.
    */
    if ((commands[2] <= 0xb4) && ((commands[0] <= 0xf5) && (commands[0] >= 0xf1))) {
      //Make sure that the command received involves controlling the car's motors (0xf1,0xf2,0xf3)
      if (commands[0] <= 0xf3) {
        if (commands[0] == 0xf1) { //Check if the move forward command was received
          //if (prevCommands[0] != 0xf1) { //Change pin state to move forward only if previous state was not move forward
          if (distance[0] >= stopDistance || distance[0] == 0) {
            redCar.forward_1W(commands[1]);
          }
          else {
            //redCar.forward_1W(commands[1]);
            redCar.stopped_1W();
          }
        }

        else if (commands[0] == 0xf2) { //Check if the move back command was received
          //if (prevCommands[0] != 0xf2) { //Change pin state to move back only if previous state was not move back
          if (distance[1] >= stopDistance || distance[1] == 0) {
            redCar.back_1W(commands[1]);
          }
          else {
            redCar.stopped_1W();
          }
        }

        else { //Check if the stop command was received
          if (prevCommands[0] != 0xf3) { //Change pin state to stop only if previous state was not stop
            redCar.stopped_1W();
            //Serial.println("Updated direction STP");
          }
        }
        //Change speed only if new speed is not equal to the previous speed
        if (prevCommands[1] != commands[1]) {
          redCar.setSpeed_1W(commands[1]);
          //Serial.println("Updated speed");
        }
        //Steer front wheels only if the new angle is not equal to the previous angle
        if (prevCommands[2] != commands[2]) {
          leftRight.write(commands[2]);
          //Serial.println("Updated angle");
        }
      }
      else if (commands[0] == 0xf5) {
        if (prevCommands[0] != 0xf5) {
          //Stop everything
          redCar.stopped_1W();
          digitalWrite(pinFrontLights, LOW);
          digitalWrite(pinBackLights, LOW);
        }
      }
      else {
        //Here you put the code that will control the tilt pan (commands[0] == 0xf4)
      }
      //Check the front/back lights and other toggles
      if (prevCommands[3] != commands[3]) {
        //Serial.println(commands[3],BIN);
        //Change the light/button states
        //               _______________________________________________
        //command[3] =  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  binary
        //              |_____|_____|_____|_____|_____|_____|_____|_____|
        //Buttons ---->  Front  Back  Horn   A     B     C     D     E
        //               7      6     6      4     3     2     1     0
        //Front lights
        if ((bitRead(prevCommands[3], 7)) != (bitRead(commands[3], 7))) {
          if (bitRead(commands[3], 7)) {
            digitalWrite(pinFrontLights, HIGH);
          }
          else {
            digitalWrite(pinFrontLights, LOW);
          }
        }
        //Back lights
        if ((bitRead(prevCommands[3], 6)) != (bitRead(commands[3], 6))) {
          if (bitRead(commands[3], 6)) {
            digitalWrite(pinBackLights, HIGH);
          }
          else {
            digitalWrite(pinBackLights, LOW);
          }
        }
        //Horn (using front lights to test)
        if ((bitRead(prevCommands[3], 5)) != (bitRead(commands[3], 5))) {
          if (bitRead(commands[3], 5)) {
            digitalWrite(pinHorn, HIGH);
          }
          else {
            digitalWrite(pinHorn, LOW);
          }
        }

        //Left Signal
        if ((bitRead(prevCommands[3], 4)) != (bitRead(commands[3], 4))) {
          if (bitRead(commands[3], 4)) {
            signalLState = HIGH;
            //digitalWrite(pinSignalL, HIGH);
          }
          else {
            signalLState = LOW;
            //digitalWrite(pinSignalL, LOW);
          }
        }

        //Right Signal
        if ((bitRead(prevCommands[3], 3)) != (bitRead(commands[3], 3))) {
          if (bitRead(commands[3], 3)) {
            signalRState = HIGH;
          }
          else {
            signalRState = LOW;
          }
        }
        //Both Signal
        if ((bitRead(prevCommands[3], 2)) != (bitRead(commands[3], 2))) {
          if (bitRead(commands[3], 2)) {
            signalRState = HIGH;
            signalLState = HIGH;
          }
          else {
            signalRState = LOW;
            signalLState = LOW;
          }
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
    timer0 = millis();  //Get the current time (millis since execution started)
    if ((timer0 - timer2) > 400) { //Check if it has been 500ms since we received last command
      //More tan 400ms have passed since last command received, car is out of range. Therefore
      //Stop the car and turn lights off
      redCar.stopped_1W();
      digitalWrite(pinFrontLights, LOW);
      digitalWrite(pinBackLights, LOW);
    }
    if ((timer0 - timer1) >= 477) { //Check if it has been 477ms since sensor reading were sent
      //Calculate the 9V's voltage by multiplying the step size by the step number (analogRead(0))
      //This value will be in mV, which is why it's multiplied by 0.001 to convert into Volts.
      sensor0.b = (analogRead(0) * stepSize) * 0.001;
      //Break the sensor0 float into four bytes for transmission
      three[1] = sensor0.a[0];
      three[2] = sensor0.a[1];
      three[3] = sensor0.a[2];
      three[4] = sensor0.a[3];
      //Get sensor 2's reading
      sensor1.d = analogRead(1);
      //Break the sensor1 float into four bytes for transmission
      three[5] = sensor1.c[0];
      three[6] = sensor1.c[1];
      three[7] = sensor1.c[2];
      three[8] = sensor1.c[3];
      //Get the remaining reading from the analog inputs
      three[9] = map(analogRead(2), 0, 1023, 0, 255);
      three[10] = map(analogRead(3), 0, 1023, 0, 255);
      three[11] = 100; //map(analogRead(4), 0, 1023, 0, 255);
      three[12] = 255; //map(analogRead(5), 0, 1023, 0, 255); analog pin 5 is used for digital output
      //Send the 4 sensor readings (0 - 3)
      //Sensor 4 & 5 are not usable!
      Serial.write(three, 14);
      //Store the time when the sensor readings were sent
      timer1 = millis();
    }
  }
}

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.
  for (int i = 0; i < SONAR_NUM; i++)
    distance[i] =  cm[i];
}







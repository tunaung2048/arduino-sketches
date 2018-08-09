#define led1 7
#define led2 8

char data = 0;                //Variable for storing received data
byte currentCmd[1] = { 0x00 };
byte previousCmd[1] = { 0x01 };


void setup() {
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0) { // Send data only when you receive data:
    data = Serial.read();      //Read the incoming data and store it into variable data
    currentCmd[0] = Serial.read();

    Serial.println("Printing Serial.Read() data:");
    Serial.println("currentCmd[0] : ");
    Serial.println((byte)currentCmd[0]);
    Serial.println("data :");
    Serial.println(data);        //Print Value inside data in Serial monitor
    Serial.println("\n") ;        //New line

    Serial.println(bitRead(currentCmd[0], 7));
    Serial.println(bitRead(currentCmd[0], 6));
    Serial.println(bitRead(currentCmd[0], 5));
    Serial.println(bitRead(currentCmd[0], 4));
    Serial.println(bitRead(currentCmd[0], 3));
    Serial.println(bitRead(currentCmd[0], 2));
    Serial.println(bitRead(currentCmd[0], 1));
    Serial.println(bitRead(currentCmd[0], 0));


    /*
      if (data == '1')           //Checks whether value of data is equal to 1
      digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
      else if (data == '0')      //Checks whether value of data is equal to 0
      digitalWrite(13, LOW);   //If value is 0 then LED turns OFF

      else if (data == 'b')
      digitalWrite(8, HIGH);
      else if (data == 'c')
      digitalWrite(8, LOW);
    */
  }
}

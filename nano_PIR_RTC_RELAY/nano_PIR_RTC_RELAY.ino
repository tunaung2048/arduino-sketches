/*
   LiquidCrystal https://www.arduino.cc/en/Reference/LiquidCrystal
   RTC DS3231 http://www.rinkydinkelectronics.com/library.php?id=74
*/
#include <DS3231.h>
#include <LiquidCrystal.h>


/* PINS DEFINE */
int pirPin = 9;    //the digital pin connected to the PIR sensor's output
int relayPin = 8;
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

/*
   PIR
*/
int calibrationTime = 30;
//the time when the sensor outputs a low impulse
long unsigned int lowIn;
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;

/*
   RTC
*/
//SoftwareSerial mySerial(10, 11); // RX, TX
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
int rtc_day = 0;
int rtc_month = 0;
int rtc_year = 0;
int rtc_hour, rtc_minute, rtc_second = 0;

/*
   LCD
*/


void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(pirPin, LOW);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello");

  rtc.begin();

  // SET DATE TIME
  //Serial.println("Setting RTC Date Time");
  //rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(3, 25, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(25, 5, 2016);   // Set the date to January 1st, 2014

  //Serial.print("Today: ");
  //Serial.println(rtc.getDateStr());

  Serial.print("calibrating sensor ");
  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println(" done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

void loop() {
  lcd.setCursor(0, 1);
  //lcd.print(rtc.getTimeStr());
  String strTime = rtc.getTimeStr();
  String strHour = strTime.substring(0, 2);
  int intHour = strHour.toInt();
  lcd.print(strHour);

  
  // Wait one second before repeating :)
  delay(1000);

  //if (rtc.getTimeStr(1) >= "14" || rtc.getTimeStr()) {
  if (intHour >= 19 || intHour <= 7) {
    if (digitalRead(pirPin) == HIGH) {
      digitalWrite(relayPin, HIGH);
      if (lockLow) {
        //makes sure we wait for a transition to LOW before any further output is made:
        lockLow = false;
        Serial.println("---");
        Serial.print("motion detected at ");
        Serial.print(millis() / 1000);
        Serial.println(" sec");
        delay(50);
      }
      takeLowTime = true;
      delay(10000);
    }

    else {
      digitalWrite(relayPin, LOW);  //the led visualizes the sensors output pin state

      if (takeLowTime) {
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
      }
      //if the sensor is low for more than the given pause,
      //we assume that no more motion is going to happen
      if (!lockLow && millis() - lowIn > pause) {
        //makes sure this block of code is only executed again after
        //a new motion sequence has been detected
        lockLow = true;
        Serial.print("motion ended at ");      //output
        Serial.print((millis() - pause) / 1000);
        Serial.println(" sec");
        delay(50);
      }
      delay(5000);
    }
  }
}
// lcd test
//lcd.clear();
//displayTime();
//delay(1000);
// Send Day-of-Week
//lcd.print(rtc.getDOWStr(1));
//lcd.println(rtc.getTimeStr());
// Send time
//lcd.setCursor(0, 1);
//lcd.print(rtc.getDateStr());
// Wait one second before repeating :)
//delay (1000);
/*
  //Serial.println(rtc.getTimeStr());
  //Serial.println(rtc.getDateStr());
  //Serial.println(rtc.getDOWStr);
  Serial.println(rtc.getTimeStr(FORMAT_LONG));
  //Serial.println(rtc.getTime());


*/





void displayTime() {
  lcd.setCursor(0, 1);
  lcd.print("Time ");
  lcd.setCursor(5, 1);
  lcd.print(rtc.getTimeStr(1));
}
// Gets date and time and prints out in "DD/MM/YYYY - HH:MM:SS" format.
void getTime() {
  //rtc.getTimeStr();
  //rtc.getDateStr();
  //rtc.getDOWStr(1);
  /*
    tmElements_t tm;
    if (rtc.getRTC.read(tm)){
    getFormattedValue(tm.Day);
    Serial.print("/");
    getFormattedValue(tm.Month);
    Serial.print("/");
    Serial.print(tm.Year);
    Serial.print(" - ");
    getFormattedValue(tm.Hour);
    Serial.print(":");
    getFormattedValue(tm.Minute);
    Serial.print(":");
    getFormattedValue(tm.Second);
    Serial.println();
    }
  */
}

// Formats the time value to two digits. Example: if hour is 7 it will be formatted as 07.
void getFormattedValue(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}

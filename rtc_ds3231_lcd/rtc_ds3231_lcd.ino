// DS3231_Serial_Easy
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A quick demo of how to use my DS3231-library to
// quickly send time and date information over a serial link
//
// To use the hardware I2C (TWI) interface of the Arduino you must connect
// the pins as follows:
//
// Arduino Uno/2009:
// ----------------------
// DS3231:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//          SCL pin   -> Arduino Analog 5 or the dedicated SCL pin
//
// Arduino Leonardo:
// ----------------------
// DS3231:  SDA pin   -> Arduino Digital 2 or the dedicated SDA pin
//          SCL pin   -> Arduino Digital 3 or the dedicated SCL pin
//
// Arduino Mega:
// ----------------------
// DS3231:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA pin
//          SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL pin
//
// Arduino Due:
// ----------------------
// DS3231:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA1 (Digital 70) pin
//          SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL1 (Digital 71) pin
//
// The internal pull-up resistors will be activated when using the
// hardware I2C interfaces.
//
// You can connect the DS3231 to any available pin but if you use any
// other than what is described above the library will fall back to
// a software-based, TWI-like protocol which will require exclusive access
// to the pins used, and you will also have to use appropriate, external
// pull-up resistors on the data and clock signals.
//

#include <DS3231.h>
#include <LiquidCrystal.h>



// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  // Initialize the rtc object
  rtc.begin();

  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(SUNDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(11, 55, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(12, 4, 2016);   // Set the date to January 1st, 2014
}

void loop()
{
  // Send Day-of-Week
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr(1));
  lcd.print("  ");
  lcd.print("   ");

  lcd.println(rtc.getTimeStr());




  // Send time
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDateStr());
  // Wait one second before repeating :)
  delay (1000);
}

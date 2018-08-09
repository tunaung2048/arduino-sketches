#include <DS3231.h>
#include <LiquidCrystal.h>



// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(12, 11, 6, 7, 8, 9);
void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  lcd.begin(16, 2);
  lcd.clear();
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

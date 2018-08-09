#include <CapacitiveSensor.h>


CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2);
CapacitiveSensor cs_4_6 = CapacitiveSensor(4,6);
CapacitiveSensor cs_4_8 = CapacitiveSensor(4,8);

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  

}

void loop() {
  long start = millis();
  long total1 = cs_4_2.capacitiveSensor(30);
  //long total2 = cs_4_6.capacitiveSensor(30);
  //long total3 = cs_4_8.capacitiveSensor(30);

  Serial.print(millis() - start);
  Serial.print("\t");
  Serial.print(total1);
  //Serial.print("\t");
  //Serial.print(total2);
  //Serial.print("\t");
  //Serial.print(total3);
  Serial.print("\n");

  //delay(3);

}

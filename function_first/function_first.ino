void setup() {
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  for (int i = 0; i < 10; i++) {
    blinkLed(13, 4, 50);
  }
  for (int j = 0; j < 10; j++) {
    blinkLed(13, 1, 90);
  }
}


void blinkLed(int pinNumber, int frequency, int dutyRatio) {
  int timePeriod = 1000/ frequency;
  int onTime = timePeriod * dutyRatio;
  int offTime = timePeriod - onTime;

  digitalWrite(pinNumber, HIGH);
  delayMicroseconds(onTime);
  digitalWrite(pinNumber, LOW);
  delayMicroseconds(offTime);
}


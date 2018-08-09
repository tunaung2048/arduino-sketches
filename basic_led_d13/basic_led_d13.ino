int ledPin = 11;
int delayTime;


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  /*
  digitalWrite(2, HIGH);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(8, HIGH);
  delay(500);
  */

  // ANALOG WRITE
  delayTime = 300;
  analogWrite(ledPin, 20);
  delay(delayTime);
  analogWrite(ledPin, 60);
  delay(delayTime);
  analogWrite(ledPin, 100);
  delayTime = 500;
  delay(delayTime);
  analogWrite(ledPin, 140);
  delay(delayTime);
  analogWrite(ledPin, 200);
  delay(delayTime);
}

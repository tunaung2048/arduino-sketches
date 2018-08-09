const int speedPin = 9;
const int motorPin1 = 10;
const int motorPin2 = 11;
const int btnPin = 2;
const int brkPin = 4;
const int potPin = A1;


void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(brkPin, INPUT_PULLUP);
  pinMode(speedPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT); 
}

void loop() {
  int speedValue = analogRead(potPin);
  speedValue = map(speedValue, 0, 1023, 0, 255);

  analogWrite(speedPin, speedValue);

  // HIGH / HIGH  -> stop immediate
  if (digitalRead(brkPin)) {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  else if (digitalRead(btnPin)) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
  else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
    
}

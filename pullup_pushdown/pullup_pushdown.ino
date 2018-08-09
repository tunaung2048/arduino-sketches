int inputPin5 = 5;
int inputPin7 = 7;
int ledPin11 = 11;
int ledPin13 = 13;


void setup() {
  pinMode(inputPin5, INPUT);
  pinMode(inputPin7, INPUT_PULLUP);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin13, OUTPUT);
}

void loop() {
  digitalWrite(ledPin11, digitalRead(inputPin5));
  digitalWrite(ledPin13, digitalRead(inputPin7));
}


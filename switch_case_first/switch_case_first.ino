// Display LED on binary mode

int ledPin[] = { 2, 3, 4 };


void setup() {
  for (int i = 0; i < sizeof(ledPin); i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  int sensorValue = map(analogRead(A0), 0, 1023, 0, 7);

  switch (sensorValue) {
    case 0:
      // all  LED off
      digitalWrite(ledPin[0], 0);
      digitalWrite(ledPin[1], 0);
      digitalWrite(ledPin[2], 0);
      break;
    case 1:
      digitalWrite(ledPin[0], 1);
      digitalWrite(ledPin[1], 0);
      digitalWrite(ledPin[2], 0);
      // optional
      /*
        digitalWrite(ledPin[0], 0);
        digitalWrite(ledPin[1], 0);
        digitalWrite(ledPin[2], 1);
      */
      break;
    case 2:
      digitalWrite(ledPin[0], 0);
      digitalWrite(ledPin[1], 1);
      digitalWrite(ledPin[2], 0);
      // optional
      /*
        digitalWrite(ledPin[0], 0);
        digitalWrite(ledPin[1], 1);
        digitalWrite(ledPin[2], 0);
      */
      break;
    case 3:
      digitalWrite(ledPin[0], 1);
      digitalWrite(ledPin[1], 1);
      digitalWrite(ledPin[2], 0);
      // optional
      /*
        digitalWrite(ledPin[0], 0);
        digitalWrite(ledPin[1], 1);
        digitalWrite(ledPin[2], 1);
      */
      break;
    case 4:
      digitalWrite(ledPin[0], 0);
      digitalWrite(ledPin[1], 0);
      digitalWrite(ledPin[2], 1);
      // optional
      /*
        digitalWrite(ledPin[0], 1);
        digitalWrite(ledPin[1], 0);
        digitalWrite(ledPin[2], 0);
      */
      break;
    case 5:
      digitalWrite(ledPin[0], 1);
      digitalWrite(ledPin[1], 0);
      digitalWrite(ledPin[2], 1);
      // optional
      /*
        digitalWrite(ledPin[0], 1);
        digitalWrite(ledPin[1], 0);
        digitalWrite(ledPin[2], 1);
      */
      break;
    case 6:
      digitalWrite(ledPin[0], 0);
      digitalWrite(ledPin[1], 1);
      digitalWrite(ledPin[2], 1);
      // optional
      /*
        digitalWrite(ledPin[0], 1);
        digitalWrite(ledPin[1], 1);
        digitalWrite(ledPin[2], 0);
      */
      break;
    case 7:
      digitalWrite(ledPin[0], 1);
      digitalWrite(ledPin[1], 1);
      digitalWrite(ledPin[2], 1);
      // optional
      /*
        digitalWrite(ledPin[0], 1);
        digitalWrite(ledPin[1], 1);
        digitalWrite(ledPin[2], 1);
      */
      break;
    default:
      break;
  }
}


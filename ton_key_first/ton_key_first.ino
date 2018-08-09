int inputPin[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int musicNote[8] = {523, 587, 659, 698, 784, 880, 988, 1047};
//int musicNote[8] = {65, 69, 73, 78, 82, 87, 93, 98};
//int musicNote[8] = {131, 147, 165, 175, 196, 220, 247, 262};
int speakerPin = 10;


void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(inputPin[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    while (!digitalRead(inputPin[i])) {
      tone(speakerPin, musicNote[i]);
      
    }
    noTone(speakerPin);
  }

}

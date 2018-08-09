#define Q 60000/120

int spk = 10;
int musicNote[8] = {523, 587, 659, 698, 784, 880, 988, 1047};

void setup() {
  for (int i = 0; i < 8; i++) {
    
    //tone(speakerPin, musicNote[i],12.8);
    delay(40);
  }

  
  tone(spk, musicNote[3], Q);
  delay(2);
  tone(spk, musicNote[2], Q);
  delay(2 + 4);
}

void loop() {

}

int number[10][7] = {
  {1, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 1, 0, 1, 1},
};

int anodePins[7] = {2, 3, 4, 5, 6, 7, 8};
int cathodePins[3] = {11, 12, 13};
int decimalPin = 9;


void setup() {
  for (int a = 2; a <= 12; a++) {
    pinMode(a, OUTPUT);
  }
}

void loop() {
  // RESET
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);

  for (int a = 2; a <= 9; a++ ) {
    digitalWrite(a, HIGH);
    delay(300);
  }
  


}

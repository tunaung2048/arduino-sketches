// One Dimentional Array
int arrayOne[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

// Multi Dimentional Array
int arrayTwo[4][4] = {
  { 2, 4, 6, 8 },
  { 1, 3, 5, 7 },
  { 1, 5, 9, 4 },
  { 2, 5, 3, 2 },
};


void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(50);

}

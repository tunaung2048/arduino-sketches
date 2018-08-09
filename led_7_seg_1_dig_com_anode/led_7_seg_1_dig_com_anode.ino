#define pinA 8
#define pinB 9
#define pinC 4
#define pinD 3
#define pinE 2
#define pinF 7
#define pinG 6
#define pinDP 5

// a  c  d  d  e  f  g  dp
int numOne[] = { 1, 0, 0, 1, 1, 1, 1, 1  };

int numArr[7][9] = {
  //a, b, c, d, e, f, g dp.
  { 0, 0, 1, 1, 1, 1, 1, 1 },
  //{ 0, 1, 0, 0, 1, 0, 0, 1 },
  //{ 0, 1, 0, 0, 1, 0, 0, 1 },
  //{ 0, 1, 0, 0, 1, 0, 0, 1 },
  //{ 0, 1, 0, 0, 1, 0, 0, 1 },
  //{ 0, 1, 0, 0, 1, 0, 0, 1 },
  //{ 0, 1, 0, 0, 1, 0, 0, 1 },
};

void setup() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // turn off all
  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
  }

  for (int n = 0; n <= 2; n++) {
    digitalWrite(n+2, LOW);
    for (int pin = 2; pin <= 9; pin++) {
      //digitalWrite(pin, numArr[n][pin - 2]);
    }
  }


  delay(1000);
}

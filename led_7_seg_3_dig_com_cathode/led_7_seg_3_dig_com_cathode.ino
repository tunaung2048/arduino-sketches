int number[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};

int anodePins[7] = { 2, 3, 4, 5, 6, 7, 8 };
int decimalPoint = 9;
int cathodePins[3] = {10, 11, 12};



void  setup() {
  for (int i=0; i<=12; i++)
    pinMode(i, OUTPUT);  
}

void loop() {
  int digit[3];
  int analogValue = analogRead(A0);
  analogValue = map(analogValue, 0, 1023, 0, 300);
  digit[2] = analogValue % 10;
  analogValue = analogValue / 10;
  digit[1] = analogValue % 10;
  digit[0] = analogValue / 10;

  for (int j=0; j<3; j++) {
    for (int k=0; k<3; k++)
      digitalWrite(cathodePins[k], LOW);
      for (int a=0; a<7; a++) digitalWrite(anodePins[a], LOW);
        digitalWrite(cathodePins[j], HIGH);
        for (int n=0; n<7; n++) {
            if ((j==2) || (j==1 && (digit[0] !=0 || digit[1] !=0)) || (j==0 && digit[0] !=0))
            digitalWrite(anodePins[n], number[digit[j]][n]);
        }
        delay(3);
      }
}


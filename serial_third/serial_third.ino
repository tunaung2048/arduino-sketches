String msg = "";
String data = "";
unsigned char r, g, b;
char a;


void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // map value
  //r = map(r, 0, 255, 255, 0);
  //g = map(g, 0, 255, 255, 0);
  //b = map(b, 0, 255, 255, 0);


  while (Serial.available()) {
    a = (char)Serial.read();
    //Serial.println(a);
    
    if (a == '\n' || a == ' ') {
      msg.trim(); // trim string
      data = msg; //
      msg = "";   // clear
    }
    else {
      msg += a ;
    }


    String value = "";
    char cArray[4];


    if (data.substring(0, 1) == "r" || data.substring(0, 1) == "R" ) {
      value = data.substring(1, data.length());
      //Serial.println("R ");
      //Serial.println(value);
      value.toCharArray(cArray, sizeof(cArray));
      //r = atoi(cArray);
      r = map(atoi(cArray), 0, 255, 255, 0);
    }
    else if (data.substring(0, 1) == "g" || data.substring(0, 1) == "G" ) {
      value = data.substring(1, data.length());
      //Serial.println(value);
      //Serial.println("G ");
      value.toCharArray(cArray, sizeof(cArray));
      g = map(atoi(cArray), 0, 255, 255, 0);
      //g = atoi(cArray);
    }
    else if (data.substring(0, 1) == "b" || data.substring(0, 1) == "B" ) {
      value = data.substring(1, data.length());
      //Serial.println("B ");
      //Serial.println(value);
      value.toCharArray(cArray, sizeof(cArray));
      b = map(atoi(cArray), 0, 255, 255, 0);
      //b = atoi(cArray);
    }
    else if (data.substring(0, 1) == "clr" || data.substring(0, 1) == "CLR") {
      r = 255;
      g = 255;
      b = 255;
    }



    analogWrite(9, r);
    analogWrite(10, g);
    analogWrite(11, b);
  }
}

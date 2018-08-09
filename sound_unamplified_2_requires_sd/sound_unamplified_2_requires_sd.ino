#include <PCM.h>

const unsigned char sample[] PROGMEM = {
  125, 119, 115, 115, 112, 116, 114, 113, 124, 126,
  136, 145, 139,
};

void setup() {
  startPlayback(sample, sizeof(sample));

}

void loop() {
  

}

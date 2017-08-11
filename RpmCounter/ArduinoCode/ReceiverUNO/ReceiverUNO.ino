#include "Wire.h"

void setup() {
  Serial.begin(9600);
  Wire.begin(1); 
  Wire.onReceive(receiveEvent);
}


void receiveEvent(int bytes) {  
  if (bytes != 2) return;
  int lower= Wire.read();
  int upper= Wire.read();
  
  Serial.println(lower | (upper <<8));
}


void loop() {
  
}

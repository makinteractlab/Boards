// RPM counter by Andrea BIanchi (Aug 2017)

int LED = 1;


#include <TinyWireM.h>

// Helper functions
void sendTwoBytes(long value)
{
  int lower = value & 0xFF;
  int upper = (value >> 8 ) & 0xFF;
  TinyWireM.beginTransmission(1);
  TinyWireM.send(lower);
  TinyWireM.send(upper);
  TinyWireM.endTransmission();
}


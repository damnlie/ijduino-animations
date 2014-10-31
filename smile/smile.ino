//Vcc=5v grd=grd din=12 cs=10 clk=11
#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=500;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,15);
  /* and clear the display */
  lc.clearDisplay(0);
}
void writeArduinoOnMatrix() {
  /* here is the data for the characters */ 
  byte smile[8]={B00111100,
                 B01000010,
                 B10100101,
                 B10000001,
                 B10100101,
                 B10011001,
                 B01000010,
                 B00111100};

  lc.setRow(0,0,smile[0]);
  lc.setRow(0,1,smile[1]);
  lc.setRow(0,2,smile[2]);
  lc.setRow(0,3,smile[3]);
  lc.setRow(0,4,smile[4]);
  lc.setRow(0,5,smile[5]);
  lc.setRow(0,6,smile[6]);
  lc.setRow(0,7,smile[7]);
  delay(delaytime);
}

void loop() { 
  writeArduinoOnMatrix();
}


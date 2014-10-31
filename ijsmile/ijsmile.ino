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
  byte ij[8]={B00000000,
              B01000010,
              B00000000,
              B01000000,
              B01000010,
              B01000010,
              B01111110,
              B00000000};

  lc.setRow(0,0,ij[0]);
  lc.setRow(0,1,ij[1]);
  lc.setRow(0,2,ij[2]);
  lc.setRow(0,3,ij[3]);
  lc.setRow(0,4,ij[4]);
  lc.setRow(0,5,ij[5]);
  lc.setRow(0,6,ij[6]);
  lc.setRow(0,7,ij[7]);
  delay(delaytime);
}

void loop() { 
  writeArduinoOnMatrix();
}


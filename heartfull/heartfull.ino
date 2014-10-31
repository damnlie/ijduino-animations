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
  byte heart[8]={B00000000,
                 B01100110,
                 B11111111,
                 B11111111,
                 B11111111,
                 B01111110,
                 B00111100,
                 B00011000};

  lc.setRow(0,0,heart[0]);
  lc.setRow(0,1,heart[1]);
  lc.setRow(0,2,heart[2]);
  lc.setRow(0,3,heart[3]);
  lc.setRow(0,4,heart[4]);
  lc.setRow(0,5,heart[5]);
  lc.setRow(0,6,heart[6]);
  lc.setRow(0,7,heart[7]);
  delay(delaytime);
}

void loop() { 
  writeArduinoOnMatrix();
}


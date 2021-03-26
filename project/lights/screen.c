#include <msp430.h>
#include "led.h"

unsigned char screen_change = 0;

void screen_init(){
  P1DIR |= SCREEN;
  screen_change = 1;
  screen_update();
}

void screen_update(){
  if(screen_change){
    int a = 1;
  }
}
    

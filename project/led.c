#include <msp430.h>
#include "led.h"
#include "button.h"

void led_init(){
  P1DIR |= LEDS;
  led_update(0);
}

void led_update(char ledFlags){
  P1OUT &= (0xff - LEDS) | ledFlags;
  P1OUT |= ledFlags;
}

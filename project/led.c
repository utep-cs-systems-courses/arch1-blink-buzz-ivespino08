#include <msp430.h>
#include "led.h"
#include "button.h"
#include "stateMachine.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init(){
  P1DIR |= LEDS;
  button_state_changed = 1;
  led_changed = 1;
  led_update();
}

void led_update(){
  if(button_state_changed){
    char ledFlags = 0;

    ledFlags |= state_main();
    
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  button_state_changed = 0;
}

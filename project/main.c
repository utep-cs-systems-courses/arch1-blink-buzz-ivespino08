#include <msp430.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"

void main(void){
  configureClocks();
  button_init();
  led_init();
  buzzer_init();

  or_sr(0x18);
}

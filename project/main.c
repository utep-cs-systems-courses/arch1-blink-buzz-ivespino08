#include <msp430.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"

int main(){
  configureClocks();
  led_init();
  button_init();
  buzzer_init();
}

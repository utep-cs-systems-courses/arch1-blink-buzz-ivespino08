#include <msp430.h>
#include "button.h"
#include "led.h"
#include "stateMachine.h"
#include "timerLib/libTimer.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & BUTTONS){
    configureClocks();
    button_interrupt_handler();
    P2IFG &= ~BUTTONS;
    enableWDTInterrupts();
  }
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
  }
}

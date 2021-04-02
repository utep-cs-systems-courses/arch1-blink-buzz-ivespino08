#include <msp430.h>
#include "button.h"
#include "led.h"
#include "stateMachine.h"
#include "timerLib/libTimer.h"

char button_state_down, button_state_changed;

static char button_update_interrupt_sense(){
  char p2val = P2IN;

  P2IES |= (p2val & BUTTONS);
  P2IES &= (p2val | ~BUTTONS);
  return p2val;
}

void button_init(){
  P2REN |= BUTTONS;
  P2IE |= BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;
  button_update_interrupt_sense();
  led_update(0);
}

void button_interrupt_handler(){
  char p2val = button_update_interrupt_sense();
  
  button_state_down |= (p2val & BT1) ? 0 : 1;
  button_state_down |= (p2val & BT2) ? 0 : 1;
  button_state_down |= (p2val & BT3) ? 0 : 1;
  button_state_down |= (p2val & BT4) ? 0 : 1;
  
  button_state_changed = 1;

  state_main();
}

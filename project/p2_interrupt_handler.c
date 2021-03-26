#include <msp430.h>
#include "button.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & BUTTONS){
    P2IFG &= ~BUTTONS;
    button_interrupt_handler();
  }
}

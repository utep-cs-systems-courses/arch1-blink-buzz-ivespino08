#include <msp430.h>
#include "button.h"
#include "led.h"
#include "timerLib/libTimer.h"

void button_1(){
  static char state = 0;
  char flags = 0;
  switch(state){
  case 0:
    flags = (LED_GREEN | LED_RED);
    state = 1;
    break;
  case 1:
    flags = 0;
    state = 0;
    break;
  }
  return flags;
}

void button_2(){

}

void button_3(){

}

void button_4(){

}

char state_main(){
  char flags = 0;
  if(P1IN & BT1){
    flags = button_1();
  }else if(P1IN & BT2){
    flags = button_2();
  }else if(P1IN & BT3){
    flags = button_3();
  }else if(P1IN & BT4){
    flags = button_4();
  }
  return flags;
}

#include <msp430.h>
#include "button.h"
#include "led.h"
#include "buzzer.h"
#include "timerLib/libTimer.h"

static int game = 0;
static char state = 0;

char button_1(){
  char flags = 0;
  switch(state){
  case 0:
    flags = LEDS;
    state = 1;
    buzzer_set_period(1000);
    break;
  case 1:
    flags = 0;
    state = 0;
    buzzer_set_period(0);
    break;
  }
  return flags;
}

char button_2(){
  char flags = 0;
  switch(state){
  case 0:
    flags = LED_RED;
    buzzer_set_period(1500);
    state = 1;
    break;
  case 1:
    flags = LED_GREEN;
    buzzer_set_period(500);
    state = 0;
    break;
  }
  return flags;
}

char button_3(){
  char flags = 0;
  switch(state){
  case 0:
    flags = LED_RED;
    buzzer_set_period(1500);
    state = 1;
    break;
  case 1:
    flags = LEDS;
    buzzer_set_period(1000);
    state = 2;
    break;
  case 2:
    flags = LED_GREEN;
    buzzer_set_period(1500);
    state = 3;
    break;
  case 3:
    flags = 0;
    buzzer_set_period(0);
    state = 0;
    break;
  }
  return flags;
}

char button_4(){
  char flags = 0;
  static char flip = 0;
  switch(state){
  case 0:
    flags = LED_GREEN;
    buzzer_set_period(400);
    state = 1;
    flip = 0;
    break;
  case 1:
    buzzer_set_period(600);
    if(flip){
      flags = LED_RED;
      state = 0;
    }else{
      state = 2;
      flags = LED_GREEN;
    }
    break;
  case 2:
    buzzer_set_period(800);
    if(flip){
      flags = LED_RED;
      state = 1;
    }else{
      state = 3;
      flags = LED_GREEN;
    }
    break;
  case 3:
    buzzer_set_period(1000);
    if(flip){
      flags = LED_RED;
      state = 2;
    }else{
      state = 4;
      flags = LED_GREEN;
    }
    break;
  case 4:
    buzzer_set_period(1200);
    if(flip){
      flags = LED_RED;
      state = 3;
    }else{
      state = 5;
      flags = LED_GREEN;
    }
    break;
  case 5:
    buzzer_set_period(1400);
    if(flip){
      flags = LED_RED;
      state = 4;
    }else{
      state = 6;
      flags = LED_GREEN;
    }
    break;
  case 6:
    buzzer_set_period(1600);
    if(flip){
      flags = LED_RED;
      state = 5;
    }else{
      flags = LED_GREEN;
      state = 7;
    }
    break;
  case 7:
    buzzer_set_period(1800);
    if(flip){
      flags = LED_RED;
      state = 6;
    }else{
      flags = LED_GREEN;
      state = 8;
    }
    break;
  case 8:
    flags = LED_RED;
    buzzer_set_period(2000);
    state = 7;
    flip = 1;
    break;
  }
  return flags;
}

void state_main(){
  if(button_state_down){
    if(P2IFG & BT1){
      game = 1;
    }else if(P2IFG & BT2){
      game = 2;
    }else if(P2IFG & BT3){
      game = 3;
    }else if(P2IFG & BT4){
      game = 4;
    }
    state = 0;
  }
}

char state_advance(){
  char flags = 0;
  switch(game){
  case 1:
    flags = button_1();
    break;
  case 2:
    flags = button_2();
    break;
  case 3:
    flags = button_3();
    break;
  case 4:
    flags = button_4();
    break;
  }
  led_update(flags);
}

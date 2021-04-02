#ifndef button_included
#define button_included

#include <msp430.h>

#define BT1 BIT0                /* button1 is p2.0 */
#define BT2 BIT1                /* button2 is p2.1 */
#define BT3 BIT2                /* button3 is p2.2 */
#define BT4 BIT3                /* button4 is p2.3 */
#define BUTTONS (BT1 | BT2 | BT3 | BT4) /* 4 buttons on this board */


void button_init();
void button_interrupt_handler();

extern char button_state_down, button_state_changed; /* effectively boolean */

#endif

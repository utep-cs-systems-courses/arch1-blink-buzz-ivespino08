#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 

#additional rules for files
toy.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o led.o button.o buzzer.o stateMachine.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

button.o: button.c button.h

buzzer.o: buzzer.c buzzer.h

stateMachine.o: stateMachine.c stateMachine.h

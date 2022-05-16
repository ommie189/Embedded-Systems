/*
 * EmbeddedLab4.c
 *
 * Created: 21/09/2020 13:57:46
 * Author : Ommie
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL //frequency of CPU
#include <util/delay.h>//delay library
#include <avr/interrupt.h>//interrupt library



int main(void)
{
	PORTD   = 0xFF;
	TCNT1  =  0x00;			//16-bit counter register
	TIMSK1 =  0x01;			//timer interrupt mask register//set to 1 to allow timer interrupt
	
	//counter control registers

	TCCR1B = 3; //Using 1024 prescaler
    sei();							//set global interrupt enable
					//enable output on PORTB
    while (1) {						//empty
   }
}

//interrupt routine
ISR(TIMER1_OVF_vect){
	DDRD ^= 0xFF; //toggle output pin
}
























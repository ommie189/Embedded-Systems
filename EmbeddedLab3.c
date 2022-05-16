/*
 * EmbeddedLab3.c
 *
 * Created: 15/09/2020 16:19:22
 * Author : Ommie
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL    //Define CPU clock as 16Mhz
#include <util/delay.h>		//library for delay function
#include <avr/interrupt.h>

int main(void)
{
	cli(); //clear all interrupts
	DDRD = 0b11111011;	//set input pin 2 to 0
	EIMSK = 0b00000001; //turns on INT0 to enable EIMSK
	EICRA =0b00000001; //set ISC00 to trigger ANY logic change
	sei();
   
   //LOOP
   while(1){
	   //Ist LED
	   PORTD =0b00001000;//set bit in pin no.3
	   _delay_ms(500);//half a second delay to turn on
	   
	   //2nd LED
	   PORTD =0b0010000;//pin no.4
	   _delay_ms(500);
	  
	   
	   //3rd LED
	    PORTD =0b00100000;//pin no.5
	   _delay_ms(500);
	   
	}
   
   //interrupt service routine
   ISR(INT0_vect){
	   int i = 0;
	   while(i<3){ // a loop to blink LEDs three times simultaneously rate on press of
		   //Button
		   _delay_ms(500);
		   PORTD|=(1<<3)|(1<<4)|(1<<5); // Toggling on all the LED pins at the same time
		   _delay_ms(500);
		   PORTD = 0; //Set PORTD to off
		   i++;
	   }
	  return 0;
}
	
	
	

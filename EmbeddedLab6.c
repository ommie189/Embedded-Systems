/*
 * EmbeddedLab6.c
 *
 * Created: 29/09/2020 14:33:46
 * Author : Ommie
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL 
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRB = 0xFF;
	DDRC = 0x00;
	//7-set ADEN, 6-set ADSC,5-trigger of ADC enabled, 3- ADC conversion complete interrupt activated, 2
	ADCSRA = 0b10001111; 
	//ADC conversion result in the Data Register
    ADMUX = (1<<REFS0) |(1<<ADLAR);
	sei();
	ADCSRA |= (1<<ADSC); 
    while (1) 
    { //to go on until interrupted
    }
	return 0;
}

//interrupt service routine for ADC routine
ISR(ADC_vect){
	PORTB = ADCH;//each has 8 bits //(1<<REFS0) |
				//Set output on PORTD equal to values in ADCH register's values based on the p.d. of values sent to the AREF pin converted to digital
	ADCSRA |= (1<<ADSC);  //start every single AD convert. This bit will be cleared after each conversion.
}


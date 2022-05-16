/*
 * EmbeddedLab5 final.c
 *
 * Created: 05/10/2020 14:47:59
 * Author : Ommie
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
/*
int main(void)
{
	DDRD =0xFF;
	PORTD = 0X00;
	ADMUX = (1<<REFS0)| (1<<ADLAR);
	ADCSRA = (1<<ADEN);
	ADCSRA =(1<<ADATE)| (1<<ADIE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADSC);
	sei();
    while (1) 
    {
    }
}
ISR(ADC_vect){
	PORTD=ADCH;
	ADCSRA = (1<<ADSC);
}
*/

//part 1
int main(void)
{
	cli();
	TIMSK1 =(1<OCIE1A);
	TCCR1B |=(1<WGM12);
	TCCR1B |=(1<CS10);
	
	OCR1A =100;
	//set output pin for LED
	DDRD|=(1<<PORTD7);
	
	//set registers
	sei();
	while(1)
	{
		PORTD |=(1<<PORTD7);
		
	}
	
	ISR(TIMER1_COMPA_vect){
		PORTD &=~(1<<PORTD7);
		_delay_ms(3);
		OCR1A+=100;
	}
}
//part 2
int main(void)
{
	
cli();
TIMSK1 =(1<OCIE1A);
TCCR1B |=(1<WGM12);
TCCR1B |=(1<CS10);

OCR1A =100;
//set output pin for LED
DDRD|=(1<<PORTD7);

//set registers
sei();

while(1){
	PORTD |=(1<<PORTD7);

}

ISR(TIMER1_COMPA_vect){
	PORTD &=~(1<<PORTD7);//OFF
	_delay_ms(3);
	OCR1A+=100;
}
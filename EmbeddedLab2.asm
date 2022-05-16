;
; EmbeddedLab2.asm
;
; Created: 15/09/2020 14:54:01
; Author : Ommie
;


; Replace with your application code
.org 0x0000
		rjmp EXINT0

.org 0x0002		;reserved interrupt program address for pin number 2(Pin 2&3 are input pins)

	; Set Interrupt to trigger when input is at low level
		ldi r16, low(RAMEND)
		sts EICRA, r16					

		;Enables INT1
		ldi r16, high(RAMEND)
		sts EIMSK, r16					

		ldi r16, 0xFF
		sts EIFR, r16  ;access I/O registers above these 64 I/O registers

		; Sets PORTB as output
		ldi r16, 0xFF
		out DDRB, r16

		; Sets PORTD as input
 		ldi r17
		out DDRD, r17

		;resets r18 and PORTB
		ldi r18
		out PORTB, r18

		;Global Enable Interrupt
		sei ;sets the I-bits to 1

;External Interrupt Routine

EXINT0:
	inc r18
	out PORTB, r18
	reti ;Each interrupt routine must end with the RETI instruction
	;After this it goes back to where you stop the program
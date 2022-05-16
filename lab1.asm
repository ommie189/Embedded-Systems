;
; AssemblerApplication1.asm
;
; Created: 07/09/2020 15:28:32
; Author : Ommie
;


; Replace with your application code
.include "m328def.inc" 
.org 0x0000
           RJMP begin; jump to begin  
.org 0x0034 
 begin:    CLI
           LDI    R16,low(RAMEND)		;set r16 to low
         OUT    SPL,R16					; 

           LDI     R16,high(RAMEND)
         OUT    SPH, R16  
		               
         LDI    R16,0xFF			;set r16 to the LED bit
         OUT    DDRD, R16			;set LED pin to output 
		   
 toggle: LDI     R16,0xFF			
         OUT    PORTD, R16

           RCALL  Delay
           LDI     R16,0x00
         OUT     PORTD, R16			;write register to PORTD

           RCALL  Delay
		   rjmp toggle

Delay:		LDI     R17, 0xFF
			LDI		R18, 0xFF
			LDI		R19, 0XFF


loop:    DEC     R17 
           BRNE    loop   
		   
		 DEC  R18
		   BRNE loop

		 DEC R19
		   BRNE loop		             
          RET     


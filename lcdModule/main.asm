;====================================================================
; Main.asm file generated by New Project wizard
;
; Created:   Thu Oct 27 2016
; Processor: PIC16F688
; Compiler:  MPASM (Proteus)
;====================================================================

;====================================================================
; DEFINITIONS
;====================================================================

#include p16f688.inc                ; Include register definition file
; CONFIG
; __config 0xFFD4
 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_OFF & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_ON & _FCMEN_ON

;====================================================================
; VARIABLES
;====================================================================
   x	EQU	0x21
   y	EQU	0x22
   hi	EQU	0x23
   lo	EQU	0x24
   
   #define	lcdPort	PORTC
   #define	rs	PORTA, 0
   #define	en	PORTA, 1
   ; RW is grounded
   ; D4 ----> RC0
   ; D5 ----> RC1
   ; D6 ----> RC2
   ; D7 ----> RC3


   
;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================     
      ; Reset Vector
      ORG	0x0000
      GOTO	setup
      
      ORG	0x0004
      RETFIE

;====================================================================
; CODE SEGMENT
;====================================================================
setup:
      ; PIC pre configurations
      BANKSEL	CMCON0
      MOVLW	0x07
      MOVWF	CMCON0
      BANKSEL	ANSEL
      CLRF	ANSEL
      CLRF	TRISC
      CLRF	TRISA
      
      BANKSEL	PORTC
      CLRF	PORTC	; Data purposes
      CLRF	PORTA	; Control purposes
      CALL	lcdInit
      
;====================================================================
; MAIN LOOP
;====================================================================
CALL	message
loop:
      GOTO	loop

;====================================================================
; CONTROL AND DATA FUNCTIONS
;====================================================================      
; Init sequence must be:
; RC3 2 1 0 - Registers from PORTC
;  D4 5 6 7 - Pins from LM016L
;   0 0 1 1
;   0 0 1 1
;   0 0 1 1
;   0 0 1 0 ; End of init sequence
;   0 0 1 0
;   1 0 0 0 ; End of 4 bit sequence
;   0 0 0 0
;   1 1 1 1 ; End of blinking cursor sequence
lcdInit:
      BANKSEL	PORTA
      ;Control bits already cleared at setup
      ;BCF	rs	; ControlMode=0, DataMode=1
      ;BCF	en	; Wait config=0, SendConfig=1
      MOVLW	B'0011'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'0011'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'0011'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'0010'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'0010'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'1000'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'0000'
      MOVWF	PORTC
      CALL	runCmd
      MOVLW	B'1111'
      MOVWF	PORTC
      CALL	runCmd
      RETURN

message:
      MOVLW	'A'
      CALL	writeByte
      MOVLW	'T'
      CALL	writeByte
      MOVLW	'T'
      CALL	writeByte
      MOVLW	'E'
      CALL	writeByte
      MOVLW	'N'
      CALL	writeByte
      MOVLW	'D'
      CALL	writeByte
      MOVLW	'A'
      CALL	writeByte
      MOVLW	'N'
      CALL	writeByte
      MOVLW	'T'
      CALL	writeByte
      MOVLW	'!'
      CALL	writeByte
      RETURN
      

runCmd:
      BSF	en	; E=1 (Connect to module), E=0(Disconnect)	
      CALL	delay
      BCF	en	; E=0
      CALL	delay
      CALL	delay
      RETURN
      
send:
      BSF	rs
      CALL	runCmd
      RETURN

writeByte:
      MOVWF	lo
      MOVWF	hi
      SWAPF	lo, W
      MOVWF	PORTC
      CALL	send
      
      MOVF	hi, W
      MOVWF	PORTC      
      CALL	send
      RETURN
      
delay:
      MOVLW	D'48'
      MOVWF	x
counterTwo:
      MOVLW	D'255'
      MOVWF	y
counterOne:
      DECFSZ	y, 1
      GOTO	counterOne
      DECFSZ	x, 1
      GOTO	counterTwo 
      RETURN

;====================================================================
   END
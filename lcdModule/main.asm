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

#include p16f688.inc                ; Include register definition file;; __config 0xFFD4
#include "C:\Users\Bruno\git\Attendant\lcdModule\lcdMacros.inc"

 __CONFIG _FOSC_INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_OFF & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_ON & _FCMEN_ON
;====================================================================
; VARIABLES
;====================================================================
; Definitions for LCD controls
lcdVar	 UDATA	0x20
i	 RES	1		; Index for loop
j	 RES	1		; Index for loop
hi	 RES	1		; Most  significant nibble from data/command
lo	 RES	1		; Least significant nibble from data/command

lcdPrt	 UDATA	0x05	
ctrlPort RES	1	; PORTA=0x05. rs=RA0, en=RA1
dataPort RES	1	; PORTC=0x06
	 GLOBAL i, j, hi, lo, dataPort, ctrlPort
      
;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================     
      ; Reset Vector
      ORG	0x0000
      GOTO	setup
      ; Interrupt Vector
      ORG	0x0004
      RETFIE

;====================================================================
; CODE SEGMENT
;====================================================================
#include "C:\Users\Bruno\git\Attendant\lcdModule\lcdFunctions.inc"

setup:  
      ; PIC pre configurations
      BANKSEL	CMCON0	 ; Bank 1
      MOVLW		0x07
      MOVWF		CMCON0	 ; Desativating comparators
      BANKSEL	ANSEL
      CLRF		ANSEL	 ; Desativating analog i/o
	  MOVLW		B'111000'; RA[0..2]=output, RA[3..5]=input
      MOVWF		TRISA	 
      MOVLW		B'110000'; RC[0..3]=output, RC[4..5]=input
      MOVWF		TRISC
      
      BANKSEL	PORTC	; Bank 0
      CLRF	PORTC		; Data purposes
      CLRF	PORTA		; Control purposes 
      CALL  lcdInit		; Send init sequence
      GOTO	loop
         
;====================================================================
; MAIN LOOP
;==================================================================== 
loop:
      CALL	message
      GOTO	loop
    
;====================================================================
   END

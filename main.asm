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
dataPort EQU	PORTC
ctrlPort EQU	PORTA
i	 	 EQU	0x20		; Index for loop
j	 	 EQU	0x21		; Index for loop
hi	 	 EQU	0x22		; Most  significant nibble from data/command
lo	 	 EQU	0x23		; Least significant nibble from data/command

; Define command lengths = (num of chars) + 3 (0x0D 0x0A 0x00)
ATCOM	 UDATA	0x24
command	 RES	D'1'		; command "AT+RST"
;ATCom02	 RES	D'14'		; command "AT+CIPMUX=1"
;ATCom03	 RES	D'34'		; command "AT+CWJAP="IC","icomputacaoufal""

#define	rs	ctrlPort, 0	; R/S (Data/Command)
#define	en	ctrlPort, 1	; Enable
#define	btn1 	ctrlPort, 4 ; Button 1
#define btn2 	ctrlPort, 5 ; Button 2


;lcdPrt	 UDATA	0x05	
;ctrlPort RES	1	; PORTA=0x05. rs=RA0, en=RA1
;dataPort RES	1	; PORTC=0x06
;	 GLOBAL i, j, hi, lo, dataPort, ctrlPort
      
;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================     
      ; Reset Vector
      ORG	0x0000
      GOTO	setup
      
      ; Interrupt Vector
      ORG	0x0004
      CALL	intExecute ; routine located at btnModule/btnFunctions
      RETFIE

;====================================================================
; CODE SEGMENT
;====================================================================
#include "C:\Users\Bruno\git\Attendant\lcdModule\lcdFunctions.inc"
#include "C:\Users\Bruno\git\Attendant\btnModule\btnFunctions.inc"
#include "C:\Users\Bruno\git\Attendant\serialModule\serialModule.inc"
#include "C:\Users\Bruno\git\Attendant\serialModule\commandModule.inc"

setup:  
      ; PIC pre configurations
      BANKSEL	CMCON0	 ; Bank 1 selction
      MOVLW	0x07
      MOVWF	CMCON0	 ; Disabling comparators
      
      BANKSEL	ANSEL
      CLRF	ANSEL	 ; Disabling analog I/O
      MOVLW	B'111000'; RA[0..2]=output, RA[3..5]=input
      MOVWF	TRISA	 
      MOVLW	B'110000'; RC[0..3]=output, RC[4..5]=input
      MOVWF	TRISC
      
      BCF	OPTION_REG,7; notRAPU = Activate internal pull-up from PORTA
      MOVLW	B'110000'
      MOVWF	WPUA		; Weak pullup for RA5 e RA4
     
      BANKSEL 	dataPort; Bank 0 selection
      CLRF	dataPort	; Data purposes
      CLRF	ctrlPort	; Control purposes
      CALL  lcdInit	; Execute LCD display init sequence
      BSF	INTCON, GIE	; Global Interrupt Enable Bit
      BANKSEL 	IOCA	; Bank 1 selection
      MOVLW	B'110000'
      MOVWF	IOCA		; Interrupt on change active on RA5 and RA4
      BSF	INTCON, RAIE; PORTA change interrupt Enable bit
      BCF	INTCON, RAIF; Clearing RAIF Flag
      MOVLW   	0x70
      MOVWF   	OSCCON  ; set for 8-MHz internal clock 
      BANKSEL 	ctrlPort
      
      ; Configuring USART
      
      MOVLW   d'12'           ;9600 baud
      MOVWF   SPBRG
      BCF     PIR1,  RCIF     ;clear RX interrupt
      BSF     RCSTA, SPEN     ;serial port enable
      BSF     RCSTA, CREN     ;continuous RX enable
      BCF     TXSTA, SYNC     ;asynchronous mode
      BSF     TXSTA, TXEN     ;enable transmitter
      
;     CALL    loadCommands
;     CALL    message
      CALL	connectWifi
;      CALL	requestTicket
;      CALL	informTicket
      
      GOTO	loop
         
;====================================================================
; MAIN LOOP
;==================================================================== 
      
loop:	
     CALL	delay
     GOTO	loop
    
;====================================================================
   END

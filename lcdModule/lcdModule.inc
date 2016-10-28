

; ========================================
; Display initialization sequence.
; Sequence:  H'33'  H'32'  H'28'  H'0F'
; ==========================================
lcdInit	MACRO
      BANKSEL	PORTA
      ;Control bits already cleared at setup
      writeCmd	H'33'
      writeCmd	H'32'
      writeCmd	H'28'
      writeCmd	H'0F'
      ENDM

; ========================================
; Execute communication with display.
; Can be used for both data and cmd purposes.
; ========================================
run MACRO
      BSF	PORTA, 1	; E=1 (Connect to module), E=0(Disconnect)	
      CALL	delay
      BCF	ctrlPort,1	; E=0
      CALL	delay
      CALL	delay
      ENDM

; ========================================
; Write and execute a two nibbles control 
; command.
; ========================================
writeCmd MACRO	cmd
      MOVLW	cmd
      getNibble
      MOVF	lo, W
      MOVWF	PORTC
      BCF	ctrlPort, 0
      run
      
      MOVF	hi, W
      MOVWF	PORTC      
      run
      ENDM
      
; ========================================
; Splite a byte into two nibbles and write
; it to LCD display
; ========================================
writeData MACRO byte
      MOVLW	byte
      getNibble
      MOVF	lo, W
      MOVWF	PORTC
      BSF	PORTA, 0
      run
      
      MOVF	hi, W
      MOVWF	PORTC      
      run
      ENDM
 
 ; ========================================
 ; Divide a byte into two nibbles, 
 ; storing them and "lo" and "hi" registers.
 ; ========================================
getNibble MACRO
      MOVWF	lo
      MOVWF	hi
      SWAPF	lo, 1
      ENDM
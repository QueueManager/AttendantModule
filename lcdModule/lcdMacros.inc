; ========================================
; Write and execute a two nibbles control 
; command.
; ========================================
writeCmd MACRO	cmd
      MOVLW	cmd
      CALL	getNibble
      MOVF	lo, W
      MOVWF	PORTC
      BCF	ctrlPort, 0
      CALL	run
      
      MOVF	hi, W
      MOVWF	PORTC      
      CALL	run
      ENDM
      
; ========================================
; Splite a byte into two nibbles and write
; it to LCD display
; ========================================
writeData MACRO byte
      MOVLW	byte
      CALL	getNibble
      MOVF	lo, W
      MOVWF	PORTC
      BSF	PORTA, 0
      CALL	run
      
      MOVF	hi, W
      MOVWF	PORTC      
      CALL	run
      ENDM
      

 

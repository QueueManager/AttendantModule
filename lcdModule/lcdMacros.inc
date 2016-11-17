; ========================================
; Write and execute a two nibbles control 
; command.
; ========================================
writeCmd MACRO	cmd
      MOVLW	cmd
      CALL	getNibble
      MOVF	lo, W
      MOVWF	dataPort
      BCF	rs
      CALL	run
      
      MOVF	hi, W
      MOVWF	dataPort      
      CALL	run
      ENDM
      
; ========================================
; Write and execute a two nibbles control 
; command.
; ========================================
writeCmdW MACRO
      CALL	getNibble
      MOVF	lo, W
      MOVWF	dataPort
      BCF	rs
      CALL	run
      
      MOVF	hi, W
      MOVWF	dataPort      
      CALL	run
      ENDM
      
; ========================================
; Split a byte into two nibbles and write
; it to LCD display
; ========================================
writeData MACRO byte
      MOVLW	byte
      CALL	getNibble
      MOVF	lo, W
      MOVWF	dataPort
      BSF	rs
      CALL	run
      
      MOVF	hi, W
      MOVWF	dataPort      
      CALL	run
      ENDM

; ========================================
; Same as before. But, data is at W.
; ========================================
writeDataW MACRO
      CALL	getNibble
      MOVF	lo, W
      MOVWF	dataPort
      BSF	rs
      CALL	run
      
      MOVF	hi, W
      MOVWF	dataPort      
      CALL	run
      ENDM

; ========================================
; Same as before. But, data is at fileRegister
; ========================================
writeDataF MACRO fileRegister
	  MOVF	fileRegister, W
      CALL	getNibble
      MOVF	lo, W
      MOVWF	dataPort
      BSF	rs
      CALL	run
      
      MOVF	hi, W
      MOVWF	dataPort      
      CALL	run
      ENDM
      

 

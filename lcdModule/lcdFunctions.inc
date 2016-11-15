; ========================================
; Delay function. Minimum time between two 
; consecutive commands. 'X' and 'Y' are
; used as indexes in FOR loops.
; ========================================
delay:
      MOVLW	D'6'
      MOVWF	i

      MOVLW	D'255'		; outter for loop
      MOVWF	j

      DECFSZ	j, 1	; inner for loop
      GOTO	$-1
      DECFSZ	i, 1
      GOTO	$-5
      RETURN 
      
; ========================================
; Display initialization sequence.
; Sequence:  H'33'  H'32'  H'28'  H'0F'
; ==========================================
lcdInit:
      BANKSEL	ctrlPort
      ;Control bits already cleared at setup
      writeCmd	H'33'
      writeCmd	H'32'
      writeCmd	H'28'
      writeCmd	H'0F'
      RETURN
      
; ========================================
; Divide a byte from W into two nibbles, 
; storing them and "lo" and "hi" registers.
; ========================================
getNibble:
      MOVWF	lo
      MOVWF	hi
      SWAPF	lo, 1
      RETURN
      
; ========================================
; Execute communication with display.
; Can be used for both data and cmd purposes.
; ========================================
run:
      BSF	en		; E=1 (Connect to module), E=0(Disconnect)	
      CALL	delay
      BCF	en		; E=0
      CALL	delay
      CALL	delay
      RETURN
    

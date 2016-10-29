; ========================================
; Delay function. Minimum time between two 
; consecutive commands. 'X' and 'Y' are
; used as indexes in FOR loops.
; ========================================
delay:
      MOVLW	D'1'
      MOVWF	i

      MOVLW	D'5'		; outter for loop
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
    
; =========================================
; Test message to be print at display.
; =========================================  
message:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'A'
      writeData	't'
      writeData	't'
      writeData	'e'
      writeData	'n'
      writeData	'd'
      writeData	'a'
      writeData	'n'
      writeData	't'
      writeData	' '
      writeData	'M'
      writeData	'o'
      writeData	'd'
      writeData	'u'
      writeData	'l'
      writeData	'e'
      writeCmd	H'C0'		; Second line command	
      CALL	delay			; Wait a little
      writeData	'M'
      writeData	'i'
      writeData	'c'
      writeData	'r'
      writeData	'o'
      writeData	'c'
      writeData	'o'
      writeData	'n'
      writeData	't'
      writeData	'r'
      writeData	'o'
      writeData	'l'
      writeData	'l'
      writeData	'e'
      writeData	'r'
      writeData	's'
      writeData	'!'
      CALL	delay
      RETURN

      
; =========================================
; Button1 was pressed.
; =========================================  
msgBtn1:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'B'
      writeData	'u'
      writeData	't'
      writeData	't'
      writeData	'o'
      writeData	'n'
      writeData	' '
      writeData	'1'
      writeData	' '
      writeData	'w'
      writeData	'a'
      writeData	's'
      writeCmd	H'C0'		; Second line command	
      writeData	'P'
      writeData	'r'
      writeData	'e'
      writeData	's'
      writeData	's'
      writeData	'e'
      writeData	'd'
      writeData	'.'
      writeData	'.'
      writeData	'.'
      CALL	delay
      RETURN

; =========================================
; Button2 was pressed.
; =========================================  
msgBtn2:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'B'
      writeData	'u'
      writeData	't'
      writeData	't'
      writeData	'o'
      writeData	'n'
      writeData	' '
      writeData	'2'
      writeData	' '
      writeData	'w'
      writeData	'a'
      writeData	's'
      writeCmd	H'C0'		; Second line command	
      writeData	'P'
      writeData	'r'
      writeData	'e'
      writeData	's'
      writeData	's'
      writeData	'e'
      writeData	'd'
      writeData	'.'
      writeData	'.'
      writeData	'.'
      CALL	delay
      RETURN


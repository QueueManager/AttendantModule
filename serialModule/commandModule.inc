; ========================================
; Responsible for loading commands into 
; microcontroller's RAM memomy.
; ========================================
loadCommands: 
	; ====================================
	; ATCom01. Size=6, "AT+RST"
	MOVLW	 ATCom01
	MOVWF    FSR
    MOVLW    'A'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW    'T'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '+'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW    'R'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW    'S'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW    'T'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   0x0D            ; Carriage return
    MOVWF   INDF
    INCF    FSR, F
    MOVLW   0x0A            ; Line feed
    MOVWF   INDF
    INCF    FSR, F
    MOVLW   0x00            ; Use as end of text marker
    MOVWF	INDF
	
	; ====================================
	; ATCom02. Size=11, "AT+CIPMUX=1"
	MOVLW	ATCom02
	MOVWF    FSR
	MOVLW   'A'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'T'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '+'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'C'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'I'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'P'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'M'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'U'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'X'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '='
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '1'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   0x0D            ; Carriage return
    MOVWF   INDF
    INCF    FSR, F
    MOVLW   0x0A            ; Line feed
    MOVWF   INDF
    INCF    FSR, F
    MOVLW   0x00            ; Use as end of text marker
	MOVWF	INDF
	
	; ====================================
	; ATCom03. Size=31, "AT+CWJAP="IC","icomputacaoufal""
	MOVLW	 ATCom03
	MOVWF    FSR
	MOVLW   'T'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '+'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'C'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'W'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'J'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'A'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'P'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '='
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '"'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'I'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'C'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '"'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   ','
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '"'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'i'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'c'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'o'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'm'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'p'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'u'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   't'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'a'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'c'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'a'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'o'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'u'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'f'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'a'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   'l'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   '"'
    MOVWF    INDF
    INCF     FSR, F
    MOVLW   0x0D            ; Carriage return
    MOVWF   INDF
    INCF    FSR, F
    MOVLW   0x0A            ; Line feed
    MOVWF   INDF
    INCF    FSR, F
    MOVLW   0x00            ; Use as end of text marker
	MOVWF	INDF
	
	RETURN
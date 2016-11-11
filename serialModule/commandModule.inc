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

connectWifi:
		MOVLW	d'0'
		MOVWF	command
		GOTO	atCommand

startServe:
		MOVLW	d'1'
		MOVWF	command
		GOTO	atCommand

callClient:
		MOVLW	d'2'
		MOVWF	command
		GOTO	atCommand

callPanel:
		MOVLW	d'3'
		MOVWF	command
		GOTO	atCommand

atCommand:
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F

		MOVF	    command,W
		ADDWF	    PCL,F
		GOTO	    connectWifi
		GOTO	    startServeI
		GOTO	    callClientI
		GOTO	    callPanelI

connectWifiI:
		; CWMODE=1
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'W'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'M'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'O'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'D'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		
		; AT+CWJAP_CUR="dlink",""
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'W'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'J'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '_'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'U'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'R'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'd'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'l'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'l'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'i'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'n'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'k'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    ','
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		RETURN

startServeI:
		; CIPMUX=1
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'M'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'U'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'X'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; AT+CIPSERVER=1,1000
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'R'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'V'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'R'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    ','
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		RETURN

callClientI:
		; CIPSTART=?TCP?,?192.168.0.100?,1000
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'R'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '9'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '2'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '.'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '6'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '8'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '.'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '.'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    ','
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; AT+CIPSEND=1
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'N'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'D'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; <guiche>
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; AT+CIPCLOSE
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'L'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'O'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		RETURN

callPanelI:
		; CIPSTART=?TCP?,?192.168.0.102?,1000
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'R'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '9'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '2'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '.'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '6'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '8'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '.'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '.'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '2'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '"'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    ','
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; AT+CIPSEND=3
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'N'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'D'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '='
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '3'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; <guiche>
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		; <ticket>
		MOVLW	    '0'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '1'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		; AT+CIPCLOSE
		MOVLW	    'A'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'T'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    '+'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'I'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'P'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'C'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'L'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'O'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'S'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    'E'
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0D	    ; Carriage return
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x0A	    ; Line feed
		MOVWF	    INDF
		INCF	    FSR, F
		MOVLW	    0x00	    ; Use as end of text marker
		MOVWF	    INDF
		RETURN
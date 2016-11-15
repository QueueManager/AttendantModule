newAtCom:
		MOVLW	    'A'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    '+'
		CALL	    TX_Serial		
		RETURN
		
connectWifi:
		CALL		newAtCom
		; CWMODE=1
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'W'
		CALL	    TX_Serial
		MOVLW	    'M'
		CALL	    TX_Serial
		MOVLW	    'O'
		CALL	    TX_Serial
		MOVLW	    'D'
		CALL	    TX_Serial
		MOVLW	    'E'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		
		; AT+CWJAP_CUR="dlink",""
		CALL		newAtCom
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'W'
		CALL	    TX_Serial
		MOVLW	    'J'
		CALL	    TX_Serial
		MOVLW	    'A'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    '_'
		CALL	    TX_Serial
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'U'
		CALL	    TX_Serial
		MOVLW	    'R'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    'd'
		CALL	    TX_Serial
		MOVLW	    'l'
		CALL	    TX_Serial
		MOVLW	    'i'
		CALL	    TX_Serial
		MOVLW	    'n'
		CALL	    TX_Serial
		MOVLW	    'k'
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    ','
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		RETURN

startServer:
		; CIPMUX=1
		CALL		newAtCom
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'I'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    'M'
		CALL	    TX_Serial
		MOVLW	    'U'
		CALL	    TX_Serial
		MOVLW	    'X'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		
		; AT+CIPSERVER=1,1000
		CALL		newAtCom
		CALL	    TX_Serial
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'I'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    'S'
		CALL	    TX_Serial
		MOVLW	    'E'
		CALL	    TX_Serial
		MOVLW	    'R'
		CALL	    TX_Serial
		MOVLW	    'V'
		CALL	    TX_Serial
		MOVLW	    'E'
		CALL	    TX_Serial
		MOVLW	    'R'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    ','
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		RETURN

;===========================================
; Start of a every new AT command
;===========================================
newAtCom:
		MOVLW	    'A'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    '+'
		CALL	    TX_Serial		
		RETURN

; ======================================	
; Connect to WIFI current network
; ======================================			
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

; ======================================	
; Request next ticket information to
; User Module
; ======================================	
requestTicket:
		; CIPSTART=?TCP?,?192.168.0.100?,1000
		CALL		newAtCom
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'I'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    'S'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    'A'
		CALL	    TX_Serial
		MOVLW	    'R'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '9'
		CALL	    TX_Serial
		MOVLW	    '2'
		CALL	    TX_Serial
		MOVLW	    '.'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '6'
		CALL	    TX_Serial
		MOVLW	    '8'
		CALL	    TX_Serial
		MOVLW	    '.'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '.'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '"'
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
		
		; AT+CIPSEND=1
		CALL		newAtCom
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
		MOVLW	    'N'
		CALL	    TX_Serial
		MOVLW	    'D'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		; <guiche>
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		
		; AT+CIPCLOSE
		CALL		newAtCom
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'I'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'L'
		CALL	    TX_Serial
		MOVLW	    'O'
		CALL	    TX_Serial
		MOVLW	    'S'
		CALL	    TX_Serial
		MOVLW	    'E'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		RETURN
	
; ======================================	
; Send ticket + guiche information to
; Panel module 
; ======================================	
informTicket:
		; CIPSTART=?TCP?,?192.168.0.102?,1000
		CALL		newAtCom
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'I'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    'S'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    'A'
		CALL	    TX_Serial
		MOVLW	    'R'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '9'
		CALL	    TX_Serial
		MOVLW	    '2'
		CALL	    TX_Serial
		MOVLW	    '.'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '6'
		CALL	    TX_Serial
		MOVLW	    '8'
		CALL	    TX_Serial
		MOVLW	    '.'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '.'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '2'
		CALL	    TX_Serial
		MOVLW	    '"'
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
		
		; AT+CIPSEND=3
		CALL		newAtCom
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
		MOVLW	    'N'
		CALL	    TX_Serial
		MOVLW	    'D'
		CALL	    TX_Serial
		MOVLW	    '='
		CALL	    TX_Serial
		MOVLW	    '3'
		CALL	    TX_Serial
		; <guiche>
		MOVLW	    '1'
		CALL	    TX_Serial
		; <ticket>
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    '1'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		
		; AT+CIPCLOSE
		CALL		newAtCom
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'I'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'L'
		CALL	    TX_Serial
		MOVLW	    'O'
		CALL	    TX_Serial
		MOVLW	    'S'
		CALL	    TX_Serial
		MOVLW	    'E'
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		RETURN

; ======================================	
; Command to start a server. Not used
; In this module. Just for reference 
; purposes.
; ======================================	
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


; ======================================	
; Request next ticket information to
; User Module
; ======================================	
requestTicket:
		; CIPSTART=0,"TCP","192.168.0.101",1000
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
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    ','
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    ','
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
		MOVLW	    '1'
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
		CALL		tcpStartMsg
		CALL		Wait_OK		
		CALL		tcpNextMsg	; ===> POINT NUMBER 1
		
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
		MOVLW	    '0'			; Connect ID (multiple conn enabled)
		CALL	    TX_Serial
		MOVLW	    ','
		CALL	    TX_Serial		
		MOVLW	    '1'			; Number of bytes to send
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		CALL		Wait_OK
		CALL		tcpNextMsg	; ===> POINT NUMBER 2
		MOVLW	    '0'			; DATA TO SEND <guiche>
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL		Wait_OK
		CALL		tcpNextMsg	; ===> POINT NUMBER 3
		
		; WAIT UNTIL WE RECEIVE SOME DATA
		CALL		Wait_IPD
		
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
		CALL		Wait_OK
		CALL		tcpNextMsg	; ===> POINT NUMBER 4
		RETURN
	
; ======================================	
; Send ticket + guiche information to
; Panel module 
; ======================================	
informTicket:
		; CIPSTART=0,"TCP","192.168.0.102",1000
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
		MOVLW	    '0'
		CALL	    TX_Serial
		MOVLW	    ','
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    'T'
		CALL	    TX_Serial
		MOVLW	    'C'
		CALL	    TX_Serial
		MOVLW	    'P'
		CALL	    TX_Serial
		MOVLW	    '"'
		CALL	    TX_Serial
		MOVLW	    ','
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
		CALL		tcpStartMsg
		CALL		Wait_OK		
		CALL		tcpNextMsg	; ===> POINT NUMBER 1
		
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
		MOVLW	    '0'			; Connect ID (multiple conn enabled)
		CALL	    TX_Serial
		MOVLW	    ','
		CALL	    TX_Serial		
		MOVLW	    '1'			; Number of bytes to send
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL	    TX_Serial
		CALL		Wait_OK
		CALL		tcpNextMsg	; ===> POINT NUMBER 2
		MOVLW	    '0'			; DATA TO SEND <guiche>
		CALL	    TX_Serial
		MOVLW	    0x0D		; Carriage Return
		CALL	    TX_Serial
		MOVLW	    0x0A		; Line feed
		CALL		Wait_OK
		CALL		tcpNextMsg	; ===> POINT NUMBER 3
		
		; WAIT UNTIL WE RECEIVE SOME DATA
		CALL		Wait_IPD
		
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
		CALL		Wait_OK
		CALL		tcpNextMsg	; ===> POINT NUMBER 4
		RETURN
		
		
; ======================================	
; Command to start a server. Not used
; In this module. Just for reference 
; purposes.
; ======================================	
;startServer:
;		; CIPMUX=1
;		CALL		newAtCom
;		MOVLW	    'C'
;		CALL	    TX_Serial
;		MOVLW	    'I'
;		CALL	    TX_Serial
;		MOVLW	    'P'
;		CALL	    TX_Serial
;		MOVLW	    'M'
;		CALL	    TX_Serial
;		MOVLW	    'U'
;		CALL	    TX_Serial
;		MOVLW	    'X'
;		CALL	    TX_Serial
;		MOVLW	    '='
;		CALL	    TX_Serial
;		MOVLW	    '1'
;		CALL	    TX_Serial
;		MOVLW	    0x0D		; Carriage Return
;		CALL	    TX_Serial
;		MOVLW	    0x0A		; Line feed
;		CALL	    TX_Serial
;		
;		; AT+CIPSERVER=1,1000
;		CALL		newAtCom
;		MOVLW	    'C'
;		CALL	    TX_Serial
;		MOVLW	    'I'
;		CALL	    TX_Serial
;		MOVLW	    'P'
;		CALL	    TX_Serial
;		MOVLW	    'S'
;		CALL	    TX_Serial
;		MOVLW	    'E'
;		CALL	    TX_Serial
;		MOVLW	    'R'
;		CALL	    TX_Serial
;		MOVLW	    'V'
;		CALL	    TX_Serial
;		MOVLW	    'E'
;		CALL	    TX_Serial
;		MOVLW	    'R'
;		CALL	    TX_Serial
;		MOVLW	    '='
;		CALL	    TX_Serial
;		MOVLW	    '1'
;		CALL	    TX_Serial
;		MOVLW	    ','
;		CALL	    TX_Serial
;		MOVLW	    '1'
;		CALL	    TX_Serial
;		MOVLW	    '0'
;		CALL	    TX_Serial
;		MOVLW	    '0'
;		CALL	    TX_Serial
;		MOVLW	    '0'
;		CALL	    TX_Serial
;		MOVLW	    0x0D		; Carriage Return
;		CALL	    TX_Serial
;		MOVLW	    0x0A		; Line feed
;		CALL	    TX_Serial
;		RETURN
;
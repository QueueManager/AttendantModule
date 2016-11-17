; ========================================
; Serial Routines. Got from: 
; http://www.instructables.com/id/Fun-With-PIC-Assembly-Episode-18/step5/Software/
; ========================================
; Wait for a received byte
RX_Serial:  BTFSC   RCSTA, OERR		; Overun. If any error occur, CLEAR and SET CREN.
	    CALL    Overflow
	    BTFSS   PIR1,  RCIF     ; RX interrupt (Set when the last bit was already received)
	    GOTO    RX_Serial
	    MOVFW   RCREG
	    RETURN

; Transmit a byte via serial			
TX_Serial:  ;BTFSS   PIR1,  TXIF    ;TX interrupt (set when free to send data)
	    BTFSS   TXSTA,  TRMT    ;Edited. Stop bit was already sent.
            GOTO    TX_Serial       ;not empty
            MOVWF   TXREG           ;ok to transmit
            RETURN

; Overflow at the receive buffer 			
Overflow:   BCF     RCSTA, CREN     ;clear overflow by disabling receiver
            BSF     RCSTA, CREN     ;re-enable receiver
            RETURN
						
; =========================================
; Wait for and OK from the AT connection
; =========================================
Wait_OK:
			CALL    RX_Serial
            SUBLW   'O'
            BTFSS   STATUS, Z
            GOTO    Wait_OK
            CALL    RX_Serial
            SUBLW   'K'
            BTFSS   STATUS, Z
            GOTO    Wait_OK
			CALL    RX_Serial
            SUBLW   0x0D
            BTFSS   STATUS, Z
            GOTO    Wait_OK
            RETURN
	
; =========================================
; Wait for and OK from the AT connection
; =========================================
Wait_IPD: 
			CALL    RX_Serial
            SUBLW   '+'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
            CALL    RX_Serial
            SUBLW   'I'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
			CALL    RX_Serial
            SUBLW   'P'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
			CALL    RX_Serial
            SUBLW   'D'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
			CALL    RX_Serial
            SUBLW   ','
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
            CALL    RX_Serial
            SUBLW   '0'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
			CALL    RX_Serial
            SUBLW   ','
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
			CALL    RX_Serial
            SUBLW   '5'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
			CALL    RX_Serial
            SUBLW   ':'
            BTFSS   STATUS, Z
            GOTO    Wait_IPD
	
	    CALL	RX_Serial	; Guichê		
	    CALL	RX_Serial	; TicketType
	    MOVWF	ticketType
	    CALL	RX_Serial	; TicketChar2
	    MOVWF	ticketChar2
	    CALL	RX_Serial	; TicketChar1
	    MOVWF	ticketChar1
	    CALL	RX_Serial	; TicketChar0
	    MOVWF	ticketChar0
	    CALL	ticketMsg		
            RETURN
	    
Wait_ESP    CALL    RX_Serial
            SUBLW   'G' 
            BTFSS   STATUS, Z
            GOTO    Wait_ESP
            CALL    RX_Serial
            SUBLW   'O'
            BTFSS   STATUS, Z
            GOTO    Wait_ESP
            CALL    RX_Serial
            SUBLW   'T'
            BTFSS   STATUS, Z
            GOTO    Wait_ESP
            CALL    RX_Serial
            SUBLW   ' '
            BTFSS   STATUS, Z
            GOTO    Wait_ESP
            CALL    RX_Serial
            SUBLW   'I'
            BTFSS   STATUS, Z
            GOTO    Wait_ESP
            CALL    RX_Serial
            SUBLW   'P'
            BTFSS   STATUS, Z
            GOTO    Wait_ESP
            RETURN

;==========================================
; Send one of the stored commands via serial.
; Not used anymore. Stayed here for info purposes.
;==========================================
;sendCommand:MOVWF   FSR
;nextChar:   MOVFW   INDF
;			writeDataW	; Write to LCD
;			MOVFW	INDF
;           BTFSC   STATUS, Z       ;end of text = 0
;           RETURN
;            CALL    TX_Serial	
;			CALL    delay
;            INCF    FSR
;            GOTO    nextChar

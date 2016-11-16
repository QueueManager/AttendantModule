; ========================================
; Serial Routines. Got from: 
; http://www.instructables.com/id/Fun-With-PIC-Assembly-Episode-18/step5/Software/
; ========================================
; Wait for a received byte
RX_Serial:  BTFSC   RCSTA, OERR		;Overun
            CALL    Overflow
            BTFSS   PIR1,  RCIF     ;RX interrupt
            GOTO    RX_Serial
			MOVFW   RCREG           ;read RX buffer (clears interrupt)
            RETURN

; Transmit a byte via serial			
TX_Serial:  BTFSS   PIR1,  TXIF     ;TX interrupt: 1 = TXREG is empty
            GOTO    TX_Serial       ;not empty
            MOVWF   TXREG           ;ok to transmit
            RETURN

; Overflow at the receive buffer 			
Overflow:   BCF     RCSTA, CREN     ;clear overflow by disabling receiver
            BSF     RCSTA, CREN     ;re-enable receiver
            RETURN
			
;==========================================
; Wait for a serial data and send to LCD
;==========================================
readSerial: 
			CALL	RX_Serial
			writeDataW
			;writeCmd	H'14'
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
			CALL	RX_Serial
			SUBLW	0x0D		; Carriage return
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
	
			CALL	guicheMsg
			CALL	RX_Serial	; Guichê
			writeDataW
			CALL	ticketMsg
			CALL	RX_Serial	; TicketType
			MOVWF	ticketType
			writeDataW
			CALL	RX_Serial	; TicketChar2
			MOVWF	ticketChar2
			writeDataW
			CALL	RX_Serial	; TicketChar1
			MOVWF	ticketChar1
			writeDataW
			CALL	RX_Serial	; TicketChar0
			MOVWF	ticketChar0
			writeDataW			
			
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

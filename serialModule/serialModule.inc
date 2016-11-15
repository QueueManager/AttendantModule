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
			writeDataW
			;writeCmd	H'14'
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
; Send one of the stored commands via serial
;==========================================
sendCommand:MOVWF   FSR
nextChar:   MOVFW   INDF
			writeDataW	; Write to LCD
			MOVFW	INDF
            BTFSC   STATUS, Z       ;end of text = 0
            RETURN
            CALL    TX_Serial	
			CALL    delay
            INCF    FSR
            GOTO    nextChar
			
;==========================================
; Wait for a serial data and send to LCD
;==========================================
readSerial: CALL	RX_Serial
			RETURN
			
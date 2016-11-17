; ========================================
; Button interrupt treatment routine.
; ========================================
intExecute:
	BTFSS	btn1
	GOTO	btn1Action
	BTFSS	btn2
	GOTO	btn2Action
;	BTFSC	PIR1, RCIF
;	GOTO	rxData

intEnd:
	BCF		PIR1, RCIF
	BCF		INTCON, RAIF
	RETURN

; ========================================
; When a new byte is read from RX
; ========================================
rxData:
;    MOVFW   RCREG
;    MOVWF   lastCharRX
;    INCF    lcdCursor
;    goto intEnd
	
; ========================================
; Button 1 pressed routine.
; ========================================
btn1Action:
	;CALL	msgBtn1
	writeCmd	H'80'
	writeCmd	H'01'
	CALL	requestTicket
	CALL	informTicket
	CALL	ticketMsg
	GOTO	intEnd

; ========================================
; Button 2 pressed routine.
; ========================================
btn2Action:
	;CALL	msgBtn2
	MOVFW	ticketChar0
	SUBLW	'Z'
	BTFSC   STATUS, Z
	GOTO	intEnd
	CALL	informTicket
	CALL	ticketMsg
	GOTO 	intEnd
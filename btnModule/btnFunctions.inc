; ========================================
; Button interrupt treatment routine.
; ========================================
intExecute:
	BTFSS	btn1
	GOTO	btn1Action
	BTFSS	btn2
	GOTO	btn2Action
intEnd:
    BCF		INTCON, RAIF
	RETURN

; ========================================
; Button 1 pressed routine.
; ========================================
btn1Action:
	CALL	msgBtn1
	GOTO	intEnd

; ========================================
; Button 2 pressed routine.
; ========================================
btn2Action:
	CALL	msgBtn2
	GOTO 	intEnd
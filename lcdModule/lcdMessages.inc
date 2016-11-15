; =========================================
; Test message to be print at display.
; =========================================  
helloMessage:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'A'
      writeData	't'
      writeData	't'
      writeData	'e'
      writeData	'n'
      writeData	'd'
      writeData	'a'
      writeData	'n'
      writeData	't'
      writeData	' '
      writeData	'M'
      writeData	'o'
      writeData	'd'
      writeData	'u'
      writeData	'l'
      writeData	'e'
      writeCmd	H'C0'		; Second line command	
      CALL	delay			; Wait a little
      writeData	'M'
      writeData	'i'
      writeData	'c'
      writeData	'r'
      writeData	'o'
      writeData	'c'
      writeData	'o'
      writeData	'n'
      writeData	't'
      writeData	'r'
      writeData	'o'
      writeData	'l'
      writeData	'l'
      writeData	'e'
      writeData	'r'
      writeData	's'
      writeData	'!'
      CALL	delay
      RETURN
 
; =========================================
; Button1 was pressed.
; =========================================  
msgBtn1:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'B'
      writeData	'u'
      writeData	't'
      writeData	't'
      writeData	'o'
      writeData	'n'
      writeData	' '
      writeData	'1'
      writeData	' '
      writeData	'w'
      writeData	'a'
      writeData	's'
      writeCmd	H'C0'		; Second line command	
      writeData	'P'
      writeData	'r'
      writeData	'e'
      writeData	's'
      writeData	's'
      writeData	'e'
      writeData	'd'
      writeData	'.'
      writeData	'.'
      writeData	'.'
      CALL	delay
      RETURN

; =========================================
; Button2 was pressed.
; =========================================  
msgBtn2:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'B'
      writeData	'u'
      writeData	't'
      writeData	't'
      writeData	'o'
      writeData	'n'
      writeData	' '
      writeData	'2'
      writeData	' '
      writeData	'w'
      writeData	'a'
      writeData	's'
      writeCmd	H'C0'		; Second line command	
      writeData	'P'
      writeData	'r'
      writeData	'e'
      writeData	's'
      writeData	's'
      writeData	'e'
      writeData	'd'
      writeData	'.'
      writeData	'.'
      writeData	'.'
      CALL	delay
      RETURN

; ========================================
; Waiting OK message
; ========================================
waitOkMsg:
      writeData	'W'
      writeData	'a'
      writeData	'i'
      writeData	't'
      writeData	'i'
      writeData	'n'
      writeData	'g'	  
      writeData	' '	  
      writeData	'O'	  
      writeData	'K'	
      writeData	'.'	  
      writeData	'.'	  
      writeData	'.'
	  RETURN
	  
; ==========================================
; Seting station mode at ESP8266
; ==========================================
conStaMsg:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'S'
      writeData	'e'
      writeData	't'
      writeData	' '
      writeData	'S'
      writeData	'T'
      writeData	'A'
      writeData	' '
      writeData	'm'
      writeData	'o'
      writeData	'd'
      writeData	'e'
      writeData	'!'
	  CALL	delay
      writeCmd	H'C0'		; Second line command
	  CALL	waitOkMsg
	  RETURN

; ==========================================
; Connecting to WIFI network
; ==========================================
conWifiMsg:
	  writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'W'
      writeData	'I'
      writeData	'F'
      writeData	'I'
      writeData	' '
      writeData	'c'
      writeData	'o'
      writeData	'n'
      writeData	'n'
      writeData	'e'
      writeData	'c'
      writeData	't'
      writeData	'i'
	  writeData	'n'
	  writeData	'g'
	  writeData	'!'
	  CALL	delay
      writeCmd	H'C0'		; Second line command
	  CALL	waitOkMsg
	  RETURN

; ==========================================
; Setting multiple connections
; ==========================================
conMultMsg:
	  writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'S'
      writeData	'e'
      writeData	't'
      writeData	' '
      writeData	'm'
      writeData	'u'
      writeData	'l'
      writeData	't'
      writeData	'i'
      writeData	' '
      writeData	'c'
      writeData	'o'
      writeData	'n'
	  writeData	's'
	  writeData	'!'
	  CALL	delay
      writeCmd	H'C0'		; Second line command
	  CALL	waitOkMsg
	  RETURN	  

; ==========================================
; Connection done successfully
; ==========================================
; conDone:
	  ;writeCmd	H'01'		; Clear screen
      ;writeCmd	H'80'		; First line command
      ;writeData	'C'
      ;writeData	'o'
      ;writeData	'n'
      ;writeData	'n'
      ;writeData	'e'
      ;writeData	'c'
      ;writeData	't'
      ;writeData	'i'
      ;writeData	'o'
      ;writeData	'n'
      ;writeData	' '
      ;writeData	'd'
      ;writeData	'o'
	  ;writeData	'n'
	  ;writeData	'e'
	  ;CALL	delay
      ;writeCmd	H'C0'		; Second line command
      ;writeData	's'
      ;writeData	'u'
      ;writeData	'c'
      ;writeData	'c'
      ;writeData	'e'
      ;writeData	's'
      ;writeData	's'
      ;writeData	'f'
      ;writeData	'u'
      ;writeData	'l'
      ;writeData	'l'
      ;writeData	'y'
      ;writeData	'!'
	  ;RETURN	

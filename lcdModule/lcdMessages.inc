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
      RETURN
 
; =========================================
; Button1 was pressed.
; =========================================  
msgBtn1:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'B'
      writeData	't'
      writeData	'n'
      writeData	'1'
      writeData	'.'
      writeData	'.'
      writeData	'.'
      RETURN

; =========================================
; Button2 was pressed.
; =========================================  
msgBtn2:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'B'
      writeData	't'
      writeData	'n'
      writeData	'2'
      writeData	'.'
      writeData	'.'
      writeData	'.'
;      writeCmd	H'C0'		; Second line command	
      RETURN
	  
; ==========================================
; Seting station mode at ESP8266
; ==========================================
conStaMsg:
      writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'S'
      writeData	'T'
      writeData	'A'
      writeData	' '
      writeData	'O'
      writeData	'K'
      writeData	'?'
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
      writeData	'O'
      writeData	'K'
      writeData	'?'
	  RETURN

; ==========================================
; Setting multiple connections
; ==========================================
conMultMsg:
	  writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'C'
      writeData	'P'
      writeData	'M'
      writeData	'U'
      writeData	'X'
      writeData	' '
      writeData	'O'
      writeData	'K'
      writeData	'?'
	  RETURN	  

; ==========================================
; Connection done successfully
; ==========================================
conDone:
	  writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'C'
      writeData	'o'
      writeData	'n'
      writeData	'n'
      writeData	' '
      writeData	'd'
      writeData	'o'
	  writeData	'n'
	  writeData	'e'
	  writeData	'!'
	  RETURN	
	  
; ==========================================
; Open TCP conection
; ==========================================
tcpStartMsg:
	  writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
      writeData	'T'
      writeData	'C'
      writeData	'P'
	  RETURN

; ==========================================
; Send data to User Module; Close connection.
; ==========================================
tcpNextMsg:
      writeData	'.'
	  RETURN

; ==========================================
; Show next guichet message
; ==========================================
guicheMsg:
	  writeCmd	H'01'		; Clear screen
      writeCmd	H'80'		; First line command
	  writeData 'G'
	  writeData 'u'
	  writeData 'i'
	  writeData 'c'
	  writeData 'h'
	  writeData 'e'
	  writeData ':'
	  writeData ' ' 
	  RETURN
	  
; ==========================================
; Show next ticket message
; ==========================================
ticketMsg:
	  writeCmd	H'C0'		; Second line command	 
	  writeData 'T'
	  writeData 'i'
	  writeData 'c'
	  writeData 'k'
	  writeData 'e'
	  writeData 't'
	  writeData ':'
	  writeData ' '
	  RETURN
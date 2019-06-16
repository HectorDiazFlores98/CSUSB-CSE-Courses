; Class CSE 313 : Machine Organization 
; Term :: Fall 2018 
; Name(s): Hector Diaz
; Lab#3: Days of the week
; Description: Write a program in LC-3 assembly language that keeps prompting for an integer in the range 0-6,
; and each time it outputs the corresponding name of the day.
; If a key other than ’0’ through ’6’ is pressed, the program exits.

	.ORIG x3100		;start at location x3100
	LEA R0, GREETING 	;Load the Address of 'greet' into R0
	PUTS			;Outputs our greeting message to the command prompt
    
	GETC			;Gets the users input SINGLE CHARACATER
    
	
	ADD R3, R0, #0
		;when the getc command is issued, whatever the user inputs is stored as the ASCII key   
	ADD R3, R3, #-16
 	;NOT the numeric value, so you subtract 16, 3 times to get the actual numeric value in 2s comp format
	ADD R3, R3, #-16
 	;(48 must be sbtracted but biggest number ADD supports is 5 bits big in 2s comp == -16)
	ADD R3, R3, #-16    	;EX: 5 key is pressed -> ASCII '5' == 53, so 53 - (16*3(48)) == 5  
	
				;R3 already contains the numerical code of the day i
	LEA R0, DAYS        	;Stores address of whatever day to R0
    
	ADD R3, R3, #0		;To be able to use condition codes
	
	;The loop (4 instructions ) implements R0 <- R0 + 10 * i
LOOP
    BRz DISPLAY
		
	ADD R0, R0, #10
    	
	ADD R3, R3, #-1
    
	BR LOOP 

DISPLAY PUTS
	HALT
	GREETING .STRINGZ "PLEASE ENTER A NUMBER:"
	DAYS  
        
		.STRINGZ "Sunday   "
        
		.STRINGZ "Monday   "
        
		.STRINGZ "Tuesday  "
       
		.STRINGZ "Wednesday"
        
		.STRINGZ "Thursday "
        
		.STRINGZ "Friday   "
        
		.STRINGZ "Saturday "
    
	.END
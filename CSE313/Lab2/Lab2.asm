; Class CSE 313 : Machine Organization 
; Term :: Fall 2018 
; Name(s): Hector Diaz
; Lab 2: Arithmatic Operations
; Description: We will be subtracting, converting numbers to absolute values and detecting which number is greater (x or y)  
	.ORIG x3000	;start at adress x3000

	;Loading to Registers (Set up)
	LDI R0, X 	;load the value located at the location x into R0 (x3120)
	LDI R1, Y 	;load the value located at the location x into R1 (x3121)

	;X-Y
	NOT R2, R1	;store (R1)' in R2 (get 2's compliment)
	ADD R2, R2, #1	;add 1 to R2 (assembly cant do negative or 2's comp) so take Y'+1 = 2's comp
	ADD R3, R0, R2	;R3 = R0 + R2(R2(Y) 2's comp)
	STI R3, x_y	;store the contents of R3(x-y) in lable x_y 

	;Absolute Val X
	ADD R4, R0, #0 	;R4 = R0 + 0
	BRzp zpX	;if above is (0 ||x > 0) run zp. if x < 0 run code below
	NOT R4, R4	;since this code is running, find the 1's compliment of neg #
	ADD R4, R4, #1	;1's comp of neg # + 1 = positive number
	zpX STI R4, absX ;stores abs value of R5 in label absX (Only runs if orig number is pos)

	;Absolute Val Y
	ADD R5, R1, #0 	;R5 = R1 + 0
	BRzp zpY	;if above is (0 ||x > 0) run zp. if x < 0 run code below
	NOT R5, R5	;since this code is running, find the 1's compliment of neg #
	ADD R5, R5, #1	;1's comp of neg # + 1 = positive number
	zpY STI R5, absY ;stores abs value of R5 in label absX (Only runs if orig number is pos)
	
	;|X| - |Y|
	NOT R5, R5 	;(R5(|Y|))'
	ADD R5, R5, #1	;(R5)' + 1)
	ADD R6, R4, R5	; R6 = R4 + R5
	BRn yBigger
	BRz Equal
	BRp xBigger
	
	yBigger	ADD R7, R7, #2	;will run if y is bigger than x
	STI R7, biggerResult	;display R7
	HALT 			;halt the program and begin to run code below

	Equal ADD R7, R7, #0	;will run if the result is 0
	STI R7, biggerResult	;display R7
	HALT			;halt the program and begin to run code below

	xBigger	ADD R7, R7, #1	;will run if x is bigger than y
	STI R7, biggerResult	;display R7
	HALT		;halt the program and begin to run code below
	
	HALT ;Halt the program
	X .FILL x3120 ;The following fills will put the value of the register indicated by the label in to the memory location
	Y .FILL x3121
	x_y .FILL x3122
	absX .FILL x3123
	absY .FILL x3124
	biggerResult .FILL x3125
.END			;end the program
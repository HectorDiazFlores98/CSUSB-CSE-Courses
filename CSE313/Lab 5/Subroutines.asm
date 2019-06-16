; Class CSE 313 : Machine Organization 
; Term :: Fall 2018 
; Name(s): Hector Diaz
; Lab 5: Subroutines: Multiplication, Division, and Modulus
; Description:  Given two integers X and Y compute the product XY (multiplication),the quotient X/Y (integer division), 
; and the modulus X (modY) (remainder).

.ORIG x3000 
					;load values.
	LDI R0, X		;load value from x3100 to R0 	
	LDI R1, Y 		;load value from x3101 to R1
	
	JSR MULT 		;jump to subroutine MULT
	STI R2, XY 		;store the value from R2 into x3102

   	JSR DIV  		;jump to subroutine div		
	STI R3, QUOT  	;store the value R4 holds into x3103 (quotiont)  						
	STI R4, MOD  	;store the value R5 holds into x3104 (remainder)		   			
	
HALT

MULT ST R0, SaveReg0 ; Multiplication subroutine begins
	 ST R1, SaveReg1 ; Save register 1 and 2 before they are destroyed by subroutine
	 
	 AND R2, R2, #0 	; Clear R2 to hold XY
	 AND R3, R3, #0		; Clear R3 to hold R0 sign
	 AND R4, R4, #0		; Clear R4 to hold R1 sign
	 AND R5, R5, #0		; Clear R5 to hold sign of XY
	 ADD R3, R3, #1		; Add 1 to make default positive
	 ADD R4, R4, #1		; Add 1 to make default positive
	 
CheckX	 ADD R0, R0, #0 ; If this is neg then X is neg, convert to +
	 BRn Xneg
CheckY	 ADD R1, R1, #0 ; IF this is neg then Y is neg, convert to +
	 BRn Yneg
	 ; Both x and Y should be positive by now
	 ; Multiplication algorithm = (x + x + x ..) as long as (Y - 1) > 0 for every loop
LOOP: 
	 ADD R2, R2, R0 ; Add R0 + R2 = R2 
	 ADD R1, R1, #-1 ; Add R1 - 1 = R1 
	 BRp LOOP
	 
	 ADD R5, R4, R3 ;Add R3 + R4 = R5, if NEG or ZERO make R3 NEG
	 BRz NegResult
	 
FinishedAll	 LD R0, SaveReg0
	 LD R1, SaveReg1
	 RET

Xneg NOT R0, R0 ;Negate R0
	ADD R0, R0, #1
	AND R3, R3, #0 ; Clear R3 
	ADD R3, R3, #-1	; Declare R0 as a negative number
	BRnzp CheckX

Yneg NOT R1, R1
	ADD R1, R1, #1
	 AND R4, R4, #0
	 ADD R4, R4, #-1
	BRnzp CheckY
	
NegResult NOT R2, R2
	ADD R2, R2, #1
	BRnzp FinishedAll
	
DIV AND R3, R3, #0 ; Will Store Quotient
	AND R4, R4, #0 ; Will Store Remainder
	AND R5, R5, #0 ; Will Store Validity
	AND R6, R6, #0 ; Will be used as temp
	
	ADD R0, R0, #0 ; Test to see if X is negative
	BRn STOP   ; if R0 is negative, jumpt to SaveReg0
	ADD R1, R1, #0 ; Test to see if Y is Negative or 0
	BRnz STOP  ; if R1 is 0 or negative jump to SaveReg0
	
	ADD R5, R5, #1 ; Add 1 to indicate it is valid
	ADD R6, R6, R0 ; R6(temp) = R6 + X
	
	NOT R1, R1	;Turn R1 into a negative number
	ADD R1, R1, #1
	
	LOOP2:
		ADD R6, R6, R1 ;Add R6 = R6 + R1
		BRn FinishDiv
		BRz FinishedNoRem
		ADD R3, R3, #1 ; Add 1 to quotient
		BRp LOOP2 

FinishDiv NOT R1, R1
	ADD R1, R1, #1
	ADD R6, R6, R1
	ADD R4, R4, R6 
	RET 

FinishedNoRem AND R4, R4, #0
	ADD R3, R3, #1
	RET 
		
STOP RET

X 	.FILL x3100
Y 	.FILL x3101
XY 	.FILL x3102
QUOT 	.FILL x3103
MOD 	.FILL x3104
SaveReg0 .FILL x0
SaveReg1 .FILL x0
.END 
	 
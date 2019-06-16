; Class CSE 313 : Machine Organization 
; Term :: Fall 2018 
; Name(s): Hector Diaz
; Lab 1: ALU Operations 
; Description: We will do the basic functions of adding, subtract, and NOT  & OR

.ORIG x3000 	;Start at the memory location x3000
LEA R2, xFF 	;Load the address of xFF (x3100) into R2
LDR R1, R2 x0 	;Load the value of memory location R2(x3100) + x0 = (x3100) into R1
LDR R3, R2 x1 	;Load the value of memory location R2(x3100) + x1 = (x3101) into R3
; X+Y 
ADD R4, R1, R3 	;R4 = R1 + R3 
STR R4, R2, x2 	;Store R4 in [R2 + X2] = x3102
; X AND Y 
AND R4, R1, R3 	;R4 = R1 AND R3 
STR R4, R2, x3 	;Store R4 in [R2 + x3] = x3103 
; X OR Y 
NOT R5, R1 		;R5 = X'
NOT R6, R3 		;R6 = Y'
AND R4, R5, R6  ;R4 = X' AND Y'
NOT R4, R4  	;R4 = (R1 + R3)'
STR R4, R2 x4 	;Store R4 in [R2+x4] = x3104 
; NOT (X)
NOT R4, R1 		;R4 = (R1)' 
STR R4, R2, x5	;Store R4 in [R2 + x5] = x3105 
;NOT(Y) 
NOT R4, R3 		;R4 = (R3)'
STR R4, R2, x6  ;Store R4 in [R2 + x6] = x3106
; X+3 
ADD R4, R1, x3	;R4 = [R1 + 3]
STR R4, R2, x7	;Store R4 in [R2 + x7]
;Y-3 
ADD R4, R3, x-3	;R4 = R3 - 3 
STR R4, R2, x8	;Store R4 in [R2 + x8] = x3108 
;x even or odd 
AND R4, R1, x1	; R4 = x AND 0001 
STR R4, R2, x9 	; Store R4 in [R2 + x9] = x3109 

HALT 			;Halt the program
.END 			;End the program 
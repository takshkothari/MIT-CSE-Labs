	AREA	RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x40001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA 	mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R4, #10
	MOV R6, #0
	LDR R0, =VALUES ; pointer to the first value
UP	LDR R1, [R0], #4
	ADD R6, R6, R1 ; adding first 2 numbers, storing in R6
	SUBS R4, #1
	BNE UP
	LDR R2,  =RESULT
	STR R6, [R2] ; store sum
STOP
	B STOP
VALUES DCD 1,2,3,4,5,6,7,8,9,10
	AREA data, DATA, READWRITE
RESULT DCD 0
	END
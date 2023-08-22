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
	LDR R0, =N1
	LDR R1, =N2
	LDR R2, [R0]
	LDR R3, [R1]
	LDR R4, = DST
	MOV R5, #4
	MOV R6, #0
UP	ADDS R2, R6
	MOV R6, #0
	;ADC R6, #0
	ADDS R2, R3
	ADC R6, #0
	STR R2, [R4], #4
	LDR R2, [R0, #4]!
	LDR R3, [R1, #4]!
	SUBS R5, #1
	BNE UP
	STR R6, [R4]
STOP 
	B STOP
N1 DCD 0x00000000, 0x00000000, 0x00000000, 0x12345678
N2 DCD 0x00000000, 0x11111111, 0x00001111, 0x00000000
	AREA data, DATA, READWRITE
DST DCD 0
	END
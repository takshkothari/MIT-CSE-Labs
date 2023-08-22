	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE,READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	
	LDR r0,=SRC
	LDR r1,=KEY
	LDR r4,=DST
	MOV r8,#10
	LDR r3,[r1]
UP	LDR r2,[r0],#4
	CMP r3,r2
	BEQ FOUND
	SUBS r8,#1
	CMP r8,#0
	BEQ DOWN
	BNE UP
DOWN MOV r9,#0
	STRB r9,[r4]
	B STOP
FOUND MOV r9,#1
	STRB r9,[r4]
STOP
	B STOP
SRC DCD 0,1,2,3,4,5,6,7,8,9
KEY DCD 3

	AREA mydata,DATA,READWRITE
DST DCD 0
	END
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x40001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA	mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R1,=VALUE1
	LDR R2,=VALUE2
	UMULL R3, R4, R2, R1
	LDR R2,=RESULT
	STR R4,[R2]
	ADD R2,#4
	STR R3,[R2]
STOP
	B STOP
VALUE1 DCD 0X54000000
VALUE2 DCD 0X10000002
	AREA	mydata,DATA,READWRITE
RESULT DCD 0
	END
	
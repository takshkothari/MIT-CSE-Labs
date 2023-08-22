	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC 
	LDR R1, =DST 
	LDR R2, [R0]
	STR R2, [R1] 
STOP
	B STOP ; Be there
	AREA mydata, DATA, READWRITE
SRC DCD 4 ;SRC location in data memory
DST DCD 2 ;DST location in data memory
	END

		AREA RESET,DATA,READONLY
		EXPORT __Vectors

__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler

Reset_Handler
		LDR R0, =N1
		LDR R1, =N2
		LDR R2 , =RES
		LDR R3,[R0]
		LDR R4,[R1]
		SUBS R5,R3,R4
		STR R5,[R2]
STOP	
		B STOP
N1 DCD 6
N2 DCD 4
		AREA mydata,DATA,READWRITE
RES DCD 0
		END
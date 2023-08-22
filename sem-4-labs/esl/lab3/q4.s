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
		LDR R0,=N
		LDR R1,[R0]
		LDR R6,=DST
		AND R1,#0xF0
		LSR R1,#4
		CMP R1,#0xA
		BCC AD1
		ADD R1,#0X07
AD1		ADD R1,#0x30
		STRB R1,[R6],#1
		LDR R1,[R0]
		AND R1,#0x0F
		CMP R1,#0xA
		BCC AD2
		ADD R1,#0X07
AD2		ADD R1,#0x30
		STRB R1,[R6]
STOP	
		B STOP
N DCD 0x4A
		AREA mydata,DATA,READWRITE
DST DCD 0
		END
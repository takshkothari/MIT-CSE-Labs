	AREA RESET, DATA, READONLY
	EXPORT __Vectors
		
__Vectors
	
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler

	LDR r0,=input
	LDR r1,=result
	LDR r2,[r0]
	BL fct
	STR r2,[r1]
HERE B HERE
fct PUSH{r3,LR}
	MOV r3,r2
	CMP r2,#0
	BNE dwn
	MOV r2,#1
	B dwn1
dwn SUB r2,#1
	BL fct
	MOV r4,r3
	MUL r2,r4
dwn1 POP{r3,LR}
	BX LR
	
input DCD 0x5
	AREA mydata, DATA, READWRITE
result DCD 0
	END
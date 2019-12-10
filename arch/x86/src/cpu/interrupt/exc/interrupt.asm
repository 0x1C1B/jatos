%macro EXC_CODELESS 1

	global isr%1
	
	isr%1:
	
		cli
		push 0x00   ; Dummy error code
		push %1     ; Interrupt number
		
		jmp isr_prehandler	; Call first stage interrupt handler
		
%endmacro

%macro EXC_CODE 1

	global isr%1
  
	isr%1:
	
		cli
                    ; Error code pushed automatically
		push %1     ; Interrupt number
		
		jmp isr_prehandler	; Call first stage interrupt handler
	
%endmacro

extern isr_prehandler

EXC_CODELESS 0
EXC_CODELESS 1
EXC_CODELESS 2
EXC_CODELESS 3
EXC_CODELESS 4
EXC_CODELESS 5
EXC_CODELESS 6
EXC_CODELESS 7
EXC_CODE 8
EXC_CODELESS 9
EXC_CODE 10
EXC_CODE 11
EXC_CODE 12
EXC_CODE 13
EXC_CODE 14
EXC_CODELESS 15
EXC_CODELESS 16
EXC_CODELESS 17
EXC_CODELESS 18
EXC_CODELESS 19
EXC_CODELESS 20
EXC_CODELESS 21
EXC_CODELESS 22
EXC_CODELESS 23
EXC_CODELESS 24
EXC_CODELESS 25
EXC_CODELESS 26
EXC_CODELESS 27
EXC_CODELESS 28
EXC_CODELESS 29
EXC_CODELESS 30
EXC_CODELESS 31
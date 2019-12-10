%macro IRQ 1

	global isr%1
  
	isr%1:
  
		cli
		push byte 0x00
		push byte %1
		
		jmp isr_prehandler	; Call first stage interrupt handler
		
%endmacro

extern isr_prehandler

IRQ 32
IRQ 33
IRQ 34
IRQ 35
IRQ 36
IRQ 37
IRQ 38
IRQ 39
IRQ 40
IRQ 41
IRQ 42
IRQ 43
IRQ 44
IRQ 45
IRQ 46
IRQ 47
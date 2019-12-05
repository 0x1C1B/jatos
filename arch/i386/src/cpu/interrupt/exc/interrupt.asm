%macro ISR_NON_CODE 1

	global isr%1
	
	isr%1:
	
		cli
		push byte 0x00  ; Dummy error code
		push byte %1    ; Interrupt number
		
		jmp isr_exc_handler
		
%endmacro

%macro ISR_CODE 1

	global isr%1
  
	isr%1:
	
		cli
                        ; Error code pushed automatically
		push byte %1    ; Interrupt number
		
		jmp isr_exc_handler
	
%endmacro

ISR_NON_CODE 0
ISR_NON_CODE 1
ISR_NON_CODE 2
ISR_NON_CODE 3
ISR_NON_CODE 4
ISR_NON_CODE 5
ISR_NON_CODE 6
ISR_NON_CODE 7
ISR_CODE 8
ISR_NON_CODE 9
ISR_CODE 10
ISR_CODE 11
ISR_CODE 12
ISR_CODE 13
ISR_CODE 14
ISR_NON_CODE 15
ISR_NON_CODE 16
ISR_NON_CODE 17
ISR_NON_CODE 18
ISR_NON_CODE 19
ISR_NON_CODE 20
ISR_NON_CODE 21
ISR_NON_CODE 22
ISR_NON_CODE 23
ISR_NON_CODE 24
ISR_NON_CODE 25
ISR_NON_CODE 26
ISR_NON_CODE 27
ISR_NON_CODE 28
ISR_NON_CODE 29
ISR_NON_CODE 30
ISR_NON_CODE 31

extern isr_handler

isr_exc_handler:

	; Save the current processor state

	pusha
    
    mov ax, ds
    push eax

	mov ax, 0x10 ; Load kernel data segment descriptor
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Push current stack pointer

    mov eax, esp
    push eax

    call isr_handler

    pop eax     ; Remove pushed stack pointer

    pop ebx     ; Restore original data segment descriptor
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx

    popa

    add esp, 0x08 ; Clean up pushed error code and ISR number
    sti
    
    iret
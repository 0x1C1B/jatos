bits 32
section .text

global isr_prehandler
extern isr_handler

; First stage ISR interrupt handler responsible for saving current processor state
isr_prehandler:

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

    call isr_handler    ; Calls second stage interrupt handler

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
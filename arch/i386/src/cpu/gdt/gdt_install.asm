bits 32
section .text

global gdt_install

gdt_install:

    mov eax, [esp + 0x04]   ; GDT pointer passed as a parameter
    lgdt [eax]              ; Load passed GDT

	mov ax, 0x10            ; Init offset of GDT kernel data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08:.flush

.flush:

    ret
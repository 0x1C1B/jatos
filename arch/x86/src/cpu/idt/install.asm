bits 32
section .text

global idt_install

idt_install:

    mov eax, [esp + 0x04]   ; IDT pointer passed as a parameter
    lidt [eax]              ; Load passed IDT
   
    ret
bits 32
section .text

global outb

outb:

    mov al, [esp + 8]   ; Move data to be sent to I/O port
    mov dx, [esp + 4]   ; Set I/O port address
    out dx, al          ; Send data to port
    ret
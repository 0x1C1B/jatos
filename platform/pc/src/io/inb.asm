bits 32
section .text

global inb

inb:

    mov dx, [esp + 4]   ; Set I/O port address
    in al, dx           ; Read a byte from port into register
    ret
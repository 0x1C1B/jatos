bits 32
section .text

global inb

inb:

    mov dx, [esp + 4]
    in al, dx
    ret
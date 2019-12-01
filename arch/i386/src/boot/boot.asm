MBOOT_PAGE_ALIGN	equ 0x01 << 0x00
MBOOT_MEM_INFO      equ 0x01 << 0x01
MBOOT_HEADER_MAGIC	equ 0x1BADB002
MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

bits 32
section .multiboot

kmultiboot:

	dd  MBOOT_HEADER_MAGIC
	dd  MBOOT_HEADER_FLAGS
	dd  MBOOT_CHECKSUM

bits 32
section .text

global kboot
extern kmain

kboot:

	; Setup tentative stack
	mov esp, kstack + KSTACK_SIZE

	push ebx	; Save multiboot header at stack

	cli
	call kmain
	hlt

section .bss

kstack:

	resb KSTACK_SIZE

KSTACK_SIZE equ 4096

/*
 * MIT License
 *
 * Copyright (c) 2019 0x1C1B
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <cpu/interrupt/exc/exc.h>

void exc_init() {

    idt_set_descriptor(0, (uint32_t) isr0, 0x08, 0x8E); // Division by zero exception
	idt_set_descriptor(1, (uint32_t) isr1, 0x08, 0x8E); // Debug exception
	idt_set_descriptor(2, (uint32_t) isr2, 0x08, 0x8E); // Non maskable interrupt
	idt_set_descriptor(3, (uint32_t) isr3, 0x08, 0x8E); // Breakpoint exception
	idt_set_descriptor(4, (uint32_t) isr4, 0x08, 0x8E); // Into detected overflow
	idt_set_descriptor(5, (uint32_t) isr5, 0x08, 0x8E); // Out of bounds exception
	idt_set_descriptor(6, (uint32_t) isr6, 0x08, 0x8E); // Invalid opcode exception
	idt_set_descriptor(7, (uint32_t) isr7, 0x08, 0x8E); // No coprocessor exception
	idt_set_descriptor(8, (uint32_t) isr8, 0x08, 0x8E); // Double fault
	idt_set_descriptor(9, (uint32_t) isr9, 0x08, 0x8E); // Coprocessor segment overrun
	idt_set_descriptor(10, (uint32_t) isr10, 0x08, 0x8E); // Bad TSS
	idt_set_descriptor(11, (uint32_t) isr11, 0x08, 0x8E); // Segment not present
	idt_set_descriptor(12, (uint32_t) isr12, 0x08, 0x8E); // Stack fault
	idt_set_descriptor(13, (uint32_t) isr13, 0x08, 0x8E); // General protection fault
	idt_set_descriptor(14, (uint32_t) isr14, 0x08, 0x8E); // Page fault
	idt_set_descriptor(15, (uint32_t) isr15, 0x08, 0x8E); // Unknown interrupt exception
	idt_set_descriptor(16, (uint32_t) isr16, 0x08, 0x8E); // Coprocessor fault
	idt_set_descriptor(17, (uint32_t) isr17, 0x08, 0x8E); // Alignment check exception
	idt_set_descriptor(18, (uint32_t) isr18, 0x08, 0x8E); // Machine check exception
	idt_set_descriptor(19, (uint32_t) isr19, 0x08, 0x8E); // Reserved
	idt_set_descriptor(20, (uint32_t) isr20, 0x08, 0x8E); // Reserved
	idt_set_descriptor(21, (uint32_t) isr21, 0x08, 0x8E); // Reserved
	idt_set_descriptor(22, (uint32_t) isr22, 0x08, 0x8E); // Reserved
	idt_set_descriptor(23, (uint32_t) isr23, 0x08, 0x8E); // Reserved
	idt_set_descriptor(24, (uint32_t) isr24, 0x08, 0x8E); // Reserved
	idt_set_descriptor(25, (uint32_t) isr25, 0x08, 0x8E); // Reserved
	idt_set_descriptor(26, (uint32_t) isr26, 0x08, 0x8E); // Reserved
	idt_set_descriptor(27, (uint32_t) isr27, 0x08, 0x8E); // Reserved
	idt_set_descriptor(28, (uint32_t) isr28, 0x08, 0x8E); // Reserved
	idt_set_descriptor(29, (uint32_t) isr29, 0x08, 0x8E); // Reserved
	idt_set_descriptor(30, (uint32_t) isr30, 0x08, 0x8E); // Reserved
	idt_set_descriptor(31, (uint32_t) isr31, 0x08, 0x8E); // Reserved
}
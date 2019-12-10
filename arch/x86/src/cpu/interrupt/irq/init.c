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

#include <cpu/interrupt/irq/irq.h>

void irq_init() {

	int_disable();	// Disable interrupts temporary

	/*
		In Real Mode IRQs 0 to 7 are mapped to IDT/IVT entries 8 to 15 normally. This results
		in double occupancy in Protected Mode. For preventing this, remapping the IRQs, by
		configuring the Programmable Interrupt Controller (PIC), is required.
	*/

	// Start IRQ0 (ISR32) - End IRQ15 (ISR47)
	pic_remap_irq(0x20, 0x28);

    idt_set_descriptor(32, (uint32_t) isr32, 0x08, 0x8E); // System timer
	idt_set_descriptor(33, (uint32_t) isr33, 0x08, 0x8E); // Keyboard controller
	idt_set_descriptor(34, (uint32_t) isr34, 0x08, 0x8E); // Cascade signal
	idt_set_descriptor(35, (uint32_t) isr35, 0x08, 0x8E); // Serial port controller 1
	idt_set_descriptor(36, (uint32_t) isr36, 0x08, 0x8E); // Serial port controller 2
	idt_set_descriptor(37, (uint32_t) isr37, 0x08, 0x8E); // Sound card
	idt_set_descriptor(38, (uint32_t) isr38, 0x08, 0x8E); // Floppy disk controller
	idt_set_descriptor(39, (uint32_t) isr39, 0x08, 0x8E); // Parallel port 1
	
	idt_set_descriptor(40, (uint32_t) isr40, 0x08, 0x8E); // Real time clock
	idt_set_descriptor(41, (uint32_t) isr41, 0x08, 0x8E); // Advanced Configuration and Power Interface (ACPI)
	idt_set_descriptor(42, (uint32_t) isr42, 0x08, 0x8E); // Peripheral
	idt_set_descriptor(43, (uint32_t) isr43, 0x08, 0x8E); // Peripheral
	idt_set_descriptor(44, (uint32_t) isr44, 0x08, 0x8E); // Mouse
	idt_set_descriptor(45, (uint32_t) isr45, 0x08, 0x8E); // CPU co-processor
	idt_set_descriptor(46, (uint32_t) isr46, 0x08, 0x8E); // Primary ATA channel
	idt_set_descriptor(47, (uint32_t) isr47, 0x08, 0x8E); // Secondary ATA channel

	// Enable all IRQs (total 16) for PIC
	for(uint8_t irq = 0; irq < 16; ++irq) {
		pic_enable_irq(irq);
	}

	int_enable();	// Enable interrupts again
}
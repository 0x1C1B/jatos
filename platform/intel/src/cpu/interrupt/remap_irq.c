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

#include <cpu/interrupt/pic.h>

void pic_remap_irq(uint8_t offset, uint8_t limit) {

    // Save PIC masks
    uint8_t mask1 = inb(PIC_MASTER_DATA_REG);
    uint8_t mask2 = inb(PIC_SLAVE_DATA_REG);

    // ICW1: Initialize remapping for maser + slave by sending ICW1 (Initialisation Command Word)
	outb(PIC_MASTER_COMMAND_REG, 0x11);
    outb(PIC_SLAVE_COMMAND_REG, 0x11);

	// ICW2: Set interrupts to remap
    outb(PIC_MASTER_DATA_REG, offset);  // Master PIC vector offset
    outb(PIC_SLAVE_DATA_REG, limit);    // Slave PIC vector offset

	// ICW3: Choose master and slave
    outb(PIC_MASTER_DATA_REG, 0x04);	// Set PIC1 as master
    outb(PIC_SLAVE_DATA_REG, 0x02);		// Set PIC2 as slave

	// ICW4: Set both 8259 PIC chips to x86 mode
    outb(PIC_MASTER_DATA_REG, 0x01);	// Set mode for PIC1
    outb(PIC_SLAVE_DATA_REG, 0x01);		// Set mode for PIC2

	// Restore saved masks
    outb(PIC_MASTER_DATA_REG, mask1);
    outb(PIC_SLAVE_DATA_REG, mask2);
}
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

#ifndef _ARCH_X86_IDT_H
#define _ARCH_X86_IDT_H

#include <stdint.h>
#include <string.h>

/*
    Descriptor shows processor which Interrupt Service Routine (ISR), in general which
    interrupt handler, to call to handle either an exception or an software/hardware interrupt.
*/

struct idt_descriptor
{
    uint16_t base_low;      // The 16 lowest bits of the 32 bits address in the segment
    uint16_t selector;      // 16 bit selector (index) must point to valid descriptor in GDT
    uint8_t reserved;       // Reserved (unused)
    uint8_t flags;          // Configuration flags (privileges, present, etc.)
    uint16_t base_high;     // The 16 highest bits of the 32 bit address in the segment
}
__attribute__ ((packed));

typedef struct idt_descriptor idt_descriptor_t;

/*
    IDT is the protected mode counterpart to the Real Mode Interrupt Vector Table (IVT).
*/

struct idt_table
{
	uint16_t limit;
	uint32_t base;
}
__attribute__ ((packed));

typedef struct idt_table idt_table_t;

void idt_init();

// Used for registering further interrupts with corresponding handler
void idt_set_descriptor(uint8_t index, uint32_t base, uint16_t selector, uint8_t flags);

#endif // _ARCH_X86_IDT_H
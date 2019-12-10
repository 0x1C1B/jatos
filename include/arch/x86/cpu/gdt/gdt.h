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

#ifndef _ARCH_X86_GDT_H
#define _ARCH_X86_GDT_H

#include <stdint.h>

/*
    Defines base access privileges for certain parts of memory, called segments
*/

struct gdt_descriptor
{
    uint16_t limit_low;     // Lower two bytes of limit (segment size)
    uint16_t base_low;      // Lower two bytes of the base address (segment start)
    uint8_t base_middle;    // Third byte of the base address
    uint8_t access;         // Access privileges and permissions
    uint8_t granularity;    // Configuration flags + Highest 4 bits of limit
    uint8_t base_high;      // Highest (4th) byte of the base address
}
__attribute__ ((packed));

typedef struct gdt_descriptor gdt_descriptor_t;

struct gdt_table
{
	uint16_t limit;
	uint32_t base;
}
__attribute__ ((packed));

typedef struct gdt_table gdt_table_t;

/*
    Specifies the position of the segment related descriptor inside of the GDT.
    Using this information it's also possible to calculate the descriptor's memory
    offset inside of the table.
*/

typedef enum {

    NULL_DESCRIPTOR_INDEX,          // Reserved segment (unused)
    KERNEL_CODE_DESCRIPTOR_INDEX,   // Offset 0x08
    KERNEL_DATA_DESCRIPTOR_INDEX,   // Offset 0x10
    USER_CODE_DESCRIPTOR_INDEX,     // Offset 0x18
    USER_DATA_DESCRIPTOR_INDEX,     // Offset 0x20
    TASK_STATE_DESCRIPTOR_INDEX     // Offset 0x28
}
gdt_selector_t;

void gdt_init();

#endif // _ARCH_X86_GDT_H
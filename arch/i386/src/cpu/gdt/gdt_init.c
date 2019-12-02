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

#include <cpu/gdt/gdt.h>

static gdt_table_t gdt;

// Omitted user + tss descriptors for now
static gdt_descriptor_t descriptors[3];

extern void gdt_install(uint32_t gdt_ptr);
static void gdt_setup_descriptor(gdt_selector_t selector, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);

void gdt_init() {

    gdt.limit = (sizeof(descriptors) - 1);
    gdt.base = (uint32_t) &descriptors;

    // NULL descriptor
    gdt_setup_descriptor(NULL_DESCRIPTOR_INDEX, 0x00, 0x00, 0x00, 0x00);

    // Kernel code descriptor
    gdt_setup_descriptor(KERNEL_CODE_DESCRIPTOR_INDEX, 0x00, 0xFFFFFFFF, 0x9A, 0xCF);

    // Kernel data descriptor
    gdt_setup_descriptor(KERNEL_DATA_DESCRIPTOR_INDEX, 0x00, 0xFFFFFFFF, 0x92, 0xCF);

    // Flush GDT and switch to Protected Mode (PM)
    gdt_install((uint32_t) &gdt);
}

static void gdt_setup_descriptor(gdt_selector_t selector, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {

    // Setup fractional base address (segment's start address)
    descriptors[selector].base_low = (base & 0xFFFF);
    descriptors[selector].base_middle = (base >> 16) & 0xFF;
    descriptors[selector].base_high  = (base >> 24) & 0xFF;

    // Setup fractional limit (segment's size)
    descriptors[selector].limit_low = (limit & 0xFFFF);
    descriptors[selector].granularity = (limit >> 16) & 0x0F;

    // Setup granularity + access flags
    descriptors[selector].granularity |= granularity & 0xF0;
    descriptors[selector].access = access;
} 
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

#include <driver/video/vga/vga.h>

extern uint8_t *const vga_modes[VGA_VIDEO_MODES];

static void vga_install(uint8_t *registers);

int32_t vga_init(vga_mode_t mode) {

    if(VGA_VIDEO_MODES <= mode || 0x00 == vga_modes[mode]) {
        return -1;
    }

    vga_install(vga_modes[mode]);
    return 0;
}

static void vga_install(uint8_t *registers) {

    // Initialize MISC controller
    outb(VGA_MISC_WRITE_PORT, *(registers++));
    
    // Initialize sequencer
    for(uint8_t index = 0; index < 5; ++index) {

        outb(VGA_SEQ_ADDRESS_PORT, index);
        outb(VGA_SEQ_DATA_PORT, *(registers++));
    }

    // Initialize CRT controller
    outb(VGA_CRTC_ADDRESS_PORT, 0x03);
    outb(VGA_CRTC_DATA_PORT, inb(VGA_CRTC_DATA_PORT) | 0x80);
    outb(VGA_CRTC_ADDRESS_PORT, 0x11);
    outb(VGA_CRTC_DATA_PORT, inb(VGA_CRTC_DATA_PORT) & ~0x80);
    
    registers[0x03] = registers[0x03] | 0x80;
    registers[0x11] = registers[0x11] & ~0x80;
    
    for(uint8_t index = 0; index < 25; ++index) {

        outb(VGA_CRTC_ADDRESS_PORT, index);
        outb(VGA_CRTC_DATA_PORT, *(registers++));
    }

    // Initialize graphics controller
    for(uint8_t index = 0; index < 9; ++index) {

        outb(VGA_GC_ADDRESS_PORT, index);
        outb(VGA_GC_DATA_PORT, *(registers++));
    }

    // Initialize attribute controller
    for(uint8_t index = 0; index < 21; ++index) {

        inb(VGA_AC_RESET_PORT);
        outb(VGA_AC_ADDRESS_PORT, index);
        outb(VGA_AC_WRITE_PORT, *(registers++));
    }
    
    inb(VGA_AC_RESET_PORT);
    outb(VGA_AC_ADDRESS_PORT, 0x20);
}
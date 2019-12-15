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

static uint8_t VGA_80X25X16_TEXT_MODE[] = {

    // MISC
	0x67,
    // SEQ
	0x03, 0x00, 0x03, 0x00, 0x02,
    // CRTC
	0x5F, 0x4F, 0x50, 0x82, 0x55, 0x81, 0xBF, 0x1F,
	0x00, 0x4F, 0x0D, 0x0E, 0x00, 0x00, 0x00, 0x50,
	0x9C, 0x0E, 0x8F, 0x28, 0x1F, 0x96, 0xB9, 0xA3,
	0xFF,
    // GC
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0E, 0x00,
	0xFF,
    // AC
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x14, 0x07,
	0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x0C, 0x00, 0x0F, 0x08, 0x00
};

static uint8_t VGA_320X200X256_GFX_MODE[] = {

    // MISC
	0x63,
    // SEQ
	0x03, 0x01, 0x0F, 0x00, 0x0E,
    // CRTC
	0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0xBF, 0x1F,
	0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x9C, 0x0E, 0x8F, 0x28,	0x40, 0x96, 0xB9, 0xA3,
	0xFF,
    // GC
	0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x0F,
	0xFF,
    // AC
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x41, 0x00, 0x0F, 0x00,	0x00
};

// VGA video modes table
uint8_t *const vga_modes[VGA_VIDEO_MODES] = {

    0x00,   // Mode 0 is unsupported
    0x00,   // Mode 1 is unsupported
    0x00,   // Mode 2 is unsupported
    VGA_80X25X16_TEXT_MODE,
    0x00,   // Mode 4 is unsupported
    0x00,   // Mode 5 is unsupported
    0x00,   // Mode 6 is unsupported
    0x00,   // Mode 7 is unsupported
    0x00,   // Mode 8 is unsupported
    0x00,   // Mode 9 is unsupported
    0x00,   // Mode 10 is unsupported
    0x00,   // Mode 11 is unsupported
    0x00,   // Mode 12 is unsupported
    0x00,   // Mode 13 is unsupported
    0x00,   // Mode 14 is unsupported
    0x00,   // Mode 15 is unsupported
    0x00,   // Mode 16 is unsupported
    0x00,   // Mode 17 is unsupported
    0x00,   // Mode 18 is unsupported
    VGA_320X200X256_GFX_MODE
};
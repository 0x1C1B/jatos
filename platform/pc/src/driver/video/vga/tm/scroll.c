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

#include <driver/video/vga/tm/vga_tm.h>

static uint16_t *video_memory = (uint16_t *) VGA_VIDEO_MEMORY;

void vga_tm_scroll(size_t rows) {

    uint8_t attribute = ((VGA_TM_BLACK & 0x0F) << 4) | (VGA_TM_WHITE & 0x0F);
	uint16_t value = 0x20 | (attribute << 8);

    size_t cells = (VGA_TM_ROWS - rows) * VGA_TM_COLUMNS;
    uint16_t offset = video_memory + rows * VGA_TM_COLUMNS;

    memcpy(video_memory, offset, cells * 2);
    memsetw(video_memory + cells, value, rows * VGA_TM_COLUMNS);
}
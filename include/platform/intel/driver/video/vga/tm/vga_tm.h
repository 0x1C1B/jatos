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

#ifndef _PLATFORM_DRIVER_VGA_TM_H
#define _PLATFORM_DRIVER_VGA_TM_H

#include <driver/video/vga/vga.h>
#include <io/ports.h>

#include <string.h>
#include <stdint.h>

/*
    Screen is divided into separate character cells that are organized in
    in rows and columns.
*/

#define VGA_TM_ROWS     (25)
#define VGA_TM_COLUMNS  (80)
#define VGA_TM_CELLS    (VGA_TM_ROWS * VGA_TM_COLUMNS)

// Colors supported by VGA 16-Color text mode
#define VGA_TM_BLACK			(0x00)
#define VGA_TM_BLUE             (0x01)
#define VGA_TM_GREEN			(0x02)
#define VGA_TM_CYAN             (0x03)
#define VGA_TM_RED				(0x04)
#define VGA_TM_MAGENTA			(0x05)
#define VGA_TM_BROWN			(0x06)
#define VGA_TM_LIGHT_GREY		(0x07)
#define VGA_TM_DARK_GREY		(0x08)
#define VGA_TM_LIGHT_BLUE		(0x09)
#define VGA_TM_DARK_GREEN		(0x0A)
#define VGA_TM_LIGHT_CYAN		(0x0B)
#define VGA_TM_LIGHT_RED		(0x0C)
#define VGA_TM_LIGHT_MAGENTA	(0x0D)
#define VGA_TM_LIGHT_BROWN		(0x0E)
#define VGA_TM_WHITE			(0x0F)

void vga_tm_init();

// Modifying screen's character cells
int32_t vga_tm_move(size_t cell, uint16_t *buf, size_t cells);
int32_t vga_tm_write(size_t cell, uint8_t c, uint8_t fg, uint8_t bg);
void vga_tm_clear();

int32_t vga_tm_scroll(size_t rows);

// Text mode cursor functionality
void vga_tm_disable_cursor();
void vga_tm_enable_cursor(uint8_t start, uint8_t end);
int32_t vga_tm_cursor(size_t cell);

#endif // _PLATFORM_DRIVER_VGA_TM_H
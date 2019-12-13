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

#ifndef _PLATFORM_IO_CLI_H
#define _PLATFORM_IO_CLI_H

#include <driver/video/vga/tm/vga_tm.h>
#include <driver/ps2/keyboard/keyboard.h>

#include <ctype.h>

// Colors supported by VGA 16-Color text mode
#define CLI_BLACK           (0x00)
#define CLI_BLUE            (0x01)
#define CLI_GREEN			(0x02)
#define CLI_CYAN            (0x03)
#define CLI_RED				(0x04)
#define CLI_MAGENTA			(0x05)
#define CLI_BROWN			(0x06)
#define CLI_LIGHT_GREY		(0x07)
#define CLI_DARK_GREY		(0x08)
#define CLI_LIGHT_BLUE		(0x09)
#define CLI_DARK_GREEN		(0x0A)
#define CLI_LIGHT_CYAN		(0x0B)
#define CLI_LIGHT_RED		(0x0C)
#define CLI_LIGHT_MAGENTA	(0x0D)
#define CLI_LIGHT_BROWN		(0x0E)
#define CLI_WHITE			(0x0F)

#define CLI_SUCCESS  (0x00)
#define CLI_FAILURE  (-0x01)

typedef struct cli {

    size_t rows;
    size_t columns;

    size_t cursor_x;
    size_t cursor_y;

    uint8_t fg;
    uint8_t bg;

} cli_t;

void cli_init();

void cli_putc(char c);
void cli_print(const char *str);

void cli_delc();
void cli_clear();
void cli_color(uint8_t fg, uint8_t bg);

char cli_getc();
void cli_scan(char *buf);

#endif // _PLATFORM_IO_CLI_H
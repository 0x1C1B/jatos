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

#include <io/cli/cli.h>

extern cli_t cli;

void cli_putc(char c) {

    switch(c) {

        case '\t': { // TAB

            cli.cursor_x = (cli.cursor_x + 8) & ~(8 - 1);
            break;
        }
        case '\n': { // Newline

            cli.cursor_x = 0;
		    ++cli.cursor_y;
            break;
        }
        default: {

            uint16_t cell = cli.cursor_x + (cli.columns * cli.cursor_y);
            vga_tm_write(cell, c, cli.fg, cli.bg);
            ++cli.cursor_x;
        }
    }

    // Check if end of line is reached
    if(cli.columns <= cli.cursor_x) {

		cli.cursor_x = 0;
		++cli.cursor_y;
	}

    // Check if end of screen is reached
    if(cli.rows <= cli.cursor_y) {

        vga_tm_scroll(1);
        cli.cursor_y = cli.rows - 1;
    }

    // Move cursor to calculated position
    uint16_t cell = cli.cursor_x + (cli.columns * cli.cursor_y);
    vga_tm_cursor(cell);
}
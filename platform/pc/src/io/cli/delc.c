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

cli_t cli;

void cli_delc() {

    if(0 != cli.cursor_x) {

        --cli.cursor_x;

        uint16_t cell = cli.cursor_x + (cli.columns * cli.cursor_y);
        vga_tm_write(cell, '\0', cli.fg, cli.bg);

    } else if(0 != cli.cursor_y) {

        cli.cursor_x = cli.columns - 1;
        --cli.cursor_y;

        uint16_t cell = cli.cursor_x + (cli.columns * cli.cursor_y);
        vga_tm_write(cell, '\0', cli.fg, cli.bg);
    }

    // Move cursor to calculated position
    uint16_t cell = cli.cursor_x + (cli.columns * cli.cursor_y);
    vga_tm_cursor(cell);
}
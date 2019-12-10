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
#include <driver/keyboard/layout/layout.h>

void cli_scan(char *buf) {

    uint8_t key = 0x00;
    char *ptr = buf;

    do {

        // Blocking input
        while(0 == keyboard_available());
        key = keyboard_getc();

        if(KEY_BACKSPACE == key || ASCII_BACKSPACE == key) {   // Backspace

            if(ptr - 1 >= buf) {    // Delete last inputted character

                cli_delc();
                *(--ptr) = '\0';
            }

        } else {

            *ptr++ = (char) key;
            cli_putc(key);
        }

    } while('\n' != key);

    *ptr = '\0';    // End read string
}
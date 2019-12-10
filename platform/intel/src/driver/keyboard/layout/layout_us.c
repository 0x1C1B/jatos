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

#include <driver/keyboard/layout/layout.h>

static const uint8_t SCANCODE_US[128] =
{
	ASCII_NULL, ASCII_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', ASCII_BACKSPACE,
	ASCII_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', ASCII_ENTER, 0x00,
	'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0x00, '\\', 'z',
	'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0x00, 0x00, 0x00, ' ', 0x00, KEY_F1,
	KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, 0x00, 0x00, KEY_HOME, KEY_UP, KEY_PGUP, '-',
	KEY_LEFT, '5', KEY_RIGHT, '+', KEY_END, KEY_DOWN, KEY_PGDN, KEY_INS, KEY_DEL, 0x00, 0x00, 0x00, KEY_F11, KEY_F12
};

static const uint8_t SCANCODE_US_SHIFTED[128] =
{
	ASCII_NULL, ASCII_ESC, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', ASCII_BACKSPACE,
	ASCII_TAB, 'Q', 'W',   'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',   '{', '}', ASCII_ENTER, 0x00,
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~', 0x00, '|', 'Z',
	'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0x00, 0x00, 0x00, ' ', 0x00, KEY_F1,
	KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, 0x00, 0x00, KEY_HOME, KEY_UP, KEY_PGUP, '-',
	KEY_LEFT, '5', KEY_RIGHT, '+', KEY_END, KEY_DOWN, KEY_PGDN, KEY_INS, KEY_DEL, 0x00, 0x00, 0x00, KEY_F11, KEY_F12
};

keyboard_layout_t layout_us = {

    .name = "us",
    .country = "United States",
    .keymap = SCANCODE_US,
    .shifted = SCANCODE_US_SHIFTED,
};
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

#ifndef _PLATFORM_DRIVER_KEYBOARD_LAYOUT_H
#define _PLATFORM_DRIVER_KEYBOARD_LAYOUT_H

#include <stdint.h>

#define ASCII_NULL          0x00
#define ASCII_ESC           0x1B
#define ASCII_BACKSPACE     '\b'
#define ASCII_TAB           '\t'
#define ASCII_ENTER         '\n'
#define ASCII_RETURN        '\r'
#define ASCII_NEWLINE       '\n'

#define KEY_ESC     0x01
#define KEY_F1      0x80
#define KEY_F2      (KEY_F1 + 0x01)
#define KEY_F3      (KEY_F2 + 0x01)
#define KEY_F4      (KEY_F3 + 0x01)
#define KEY_F5      (KEY_F4 + 0x01)
#define KEY_F6      (KEY_F5 + 0x01)
#define KEY_F7      (KEY_F6 + 0x01)
#define KEY_F8      (KEY_F7 + 0x01)
#define KEY_F9      (KEY_F8 + 0x01)
#define KEY_F10     (KEY_F9 + 0x01)
#define KEY_F11     (KEY_F10 + 0x01)
#define KEY_F12     (KEY_F11 + 0x01)

#define KEY_INS		0x90
#define KEY_DEL		0x91
#define KEY_HOME	0x92
#define KEY_END		0x93
#define KEY_PGUP	0x94
#define KEY_PGDN	0x95
#define KEY_LEFT	0x96
#define KEY_UP		0x97
#define KEY_DOWN	0x98
#define KEY_RIGHT	0x99

#define	KEY_BACKSPACE	0x0E
#define	KEY_ENTER		0x1C
#define	KEY_LCTRL		0x1D
#define	KEY_LSHIFT		0x2A
#define	KEY_RSHIFT		0x36
#define	KEY_LALT		0x38
#define	KEY_RALT		0x38
#define	KEY_CAPS		0x3A

typedef struct keyboard_layout {

    char *name;
    char *country;

    const uint8_t *const keymap;
    const uint8_t *const shifted;

} keyboard_layout_t;

extern keyboard_layout_t layout_us;

#endif // _PLATFORM_DRIVER_KEYBOARD_LAYOUT_H
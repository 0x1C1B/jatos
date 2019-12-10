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

#ifndef _PLATFORM_DRIVER_KEYBOARD_H
#define _PLATFORM_DRIVER_KEYBOARD_H

#include <io/ports.h>
#include <cpu/interrupt/isr.h>
#include <driver/keyboard/layout/layout.h>

#include <stdint.h>
#include <stdbool.h>

#define KEYBOARD_CONTROL_REG    0x64
#define KEYBOARD_DATA_REG       0x60

#define KEYBOARD_BUFFER_CAPACITY    256

typedef struct key_queue {

	uint8_t *write_ptr;
	uint8_t *read_ptr;
	volatile size_t available;

    uint8_t buffer[KEYBOARD_BUFFER_CAPACITY];

} key_queue_t;

void keyboard_init();
uint8_t keyboard_getc();
size_t keyboard_available();

uint8_t keyboard_decode();
uint32_t keyboard_enqueue(uint8_t key);
uint32_t keyboard_dequeue(uint8_t * const key);

#endif // _PLATFORM_DRIVER_KEYBOARD_H
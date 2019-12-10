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

#include <driver/keyboard/keyboard.h>

key_queue_t queue;
keyboard_layout_t *layout;

static void keyboard_handler(processor_state_t *state);

void keyboard_init() {

    // Initialize key circular buffer
    queue.write_ptr = queue.buffer;
    queue.read_ptr = queue.buffer;
    queue.available = 0;

    layout = &layout_us;    // Set a default keyboard layout

    isr_install_listener(KEYBOARD_INTERRUPT, keyboard_handler);
}

static void keyboard_handler(processor_state_t *state) {

    uint8_t key = keyboard_decode();

    if(0x00 != key) {

        keyboard_enqueue(key);
    }
}
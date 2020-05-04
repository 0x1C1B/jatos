/*
 * MIT License
 *
 * Copyright (c) 2020 0x1C1B
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

#include <driver/serial/serial.h>

void serial_init(uint16_t port) {

    outb(SERIAL_INTERRUPT_ENABLE_REGISTER(port), 0x00);             // Disable all interrupts
    outb(SERIAL_LINE_CONTROL_REGISTER(port), 0x80);                 // Enable DLAB (set baud rate divisor)
    outb(SERIAL_DLAB_LEAST_SIGNIFICANT_BYTE_REGISTER(port), 0x03);  // Set divisor to 3 (lo byte) 38400 baud
    outb(SERIAL_DLAB_MOST_SIGNIFICANT_BYTE_REGISTER(port), 0x00);   // Set divisor to 3 (hi byte) 38400 baud
    outb(SERIAL_LINE_CONTROL_REGISTER(port), 0x03);                 // 8 bits, no parity, one stop bit
    outb(SERIAL_INTERRUPT_IDENTIFICATION_REGISTER(port), 0xC7);     // Enable FIFO, clear them, with 14-byte threshold
    outb(SERIAL_MODEM_CONTROL_REGISTER(port), 0x0B);                // IRQs enabled, RTS/DSR set
}

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

#ifndef _PLATFORM_DRIVER_SERIAL_H
#define _PLATFORM_DRIVER_SERIAL_H

#include <stdint.h>
#include <io/ports.h>

#define SERIAL_COM1 0x3f8
#define SERIAL_COM2 0x2F8
#define SERIAL_COM3 0x3E8
#define SERIAL_COM4 0x2E8

#define SERIAL_DATA_REGISTER(port)                          (port + 0x00)
#define SERIAL_DLAB_LEAST_SIGNIFICANT_BYTE_REGISTER(port)   (port + 0x00)
#define SERIAL_INTERRUPT_ENABLE_REGISTER(port)              (port + 0x01)
#define SERIAL_DLAB_MOST_SIGNIFICANT_BYTE_REGISTER(port)    (port + 0x01)
#define SERIAL_INTERRUPT_IDENTIFICATION_REGISTER(port)      (port + 0x02)
#define SERIAL_LINE_CONTROL_REGISTER(port)                  (port + 0x03)
#define SERIAL_MODEM_CONTROL_REGISTER(port)                 (port + 0x04)
#define SERIAL_LINE_STATUS_REGISTER(port)                   (port + 0x05)
#define SERIAL_MODEM_STATUS_REGISTER(port)                  (port + 0x06)
#define SERIAL_SCRATCH_REGISTER(port)                       (port + 0x07)

void serial_init(uint16_t port);
uint8_t serial_read(uint16_t port);
void serial_write(uint16_t port, uint8_t data);

#endif // _PLATFORM_DRIVER_SERIAL_H

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

#ifndef _PLATFORM_DRIVER_PIT_H
#define _PLATFORM_DRIVER_PIT_H

#include <io/ports.h>
#include <cpu/interrupt/isr.h>

#define PIT_COUNTER_0_REG   0x40
#define PIT_COUNTER_1_REG   0x41
#define PIT_COUNTER_2_REG   0x42
#define PIT_COMMAND_REG     0x43

#define PIT_OSCILLATOR_FREQUENCY    (1193180)   // 1.19MHz
#define PIT_IRQ_SEC_HIT             (19)        // Timer fires 19 times per second

void pit_init();
void pit_phase(uint8_t counter, uint32_t frequency);
void pit_wait(size_t ticks);

#endif // _PLATFORM_DRIVER_PIT_H
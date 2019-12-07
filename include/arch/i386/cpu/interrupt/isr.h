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

#ifndef _I386_ISR_H
#define _I386_ISR_H

#include <stdint.h>
#include <string.h>

/*
    Current processor state before occurred interrupt. Required for restoring
    CPU state after interrupt handling procedure is finished.
*/

struct processor_state
{
    uint32_t ds; 
    
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    
    uint32_t interrupt_code;
    uint32_t error_code;

    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t useresp;
    uint32_t ss;
}
__attribute__ ((packed));

typedef struct processor_state processor_state_t;

typedef void (*isr_listener_t)(processor_state_t *state);

typedef enum {

    // CPU generated exceptions
    DIVISION_BY_ZERO_EXCEPTION,
    DEBUG_EXCEPTION,
    NON_MASKABLE_INTERRUPT_EXCEPTION,
    BREAKPOINT_EXCEPTION,
    INTO_DETECTED_OVERFLOW_EXCEPTION,
    OUT_OF_BOUNDS_EXCEPTION,
    INVALID_OPCODE_EXCEPTION,
    NO_COPROCESSOR_EXCEPTION,
    DOUBLE_FAULT_EXCEPTION,
    COPROCESSOR_SEGMENT_OVERRUN_EXCEPTION,
    BAD_TSS_EXCEPTION,
    SEGMENT_NOT_PRESENT_EXCEPTION,
    STACK_FAULT_EXCEPTION,
    GENERAL_PROTECTION_FAULT_EXCEPTION,
    PAGE_FAULT_EXCEPTION,
    UNKNOWN_INTERRUPT_EXCEPTION,
    COPROCESSOR_FAULT_EXCEPTION,
    ALIGNMENT_CHECK_EXCEPTION,
    MACHINE_CHECK_EXCEPTION,

    // Interrupt Request (IRQ)/Hardware interrupts
    PROGRAMMABLE_INTERRUPT_TIMER_INTERRUPT = 32,
    KEYBOARD_INTERRUPT,
    CASCADE_INTERRUPT,
    COM2_INTERRUPT,
    COM1_INTERRUPT,
    LPT2_INTERRUPT,
    FLOPPY_DISK_INTERRUPT,
    LPT1_INTERRUPT,
    CMOS_REAL_TIME_CLOCK_INTERRUPT,
    PERIPHERAL1_INTERRUPT,
    PERIPHERAL2_INTERRUPT,
    PERIPHERAL3_INTERRUPT,
    PS2_INTERRUPT,
    COPROCESSOR_INTERRUPT,
    PRIMARY_ATA_HARD_DISK_INTERRUPT,
    SECONDARY_ATA_HARD_DISK_INTERRUPT
}
isr_selector_t;

void isr_init();
void isr_notifier(processor_state_t *state);

void isr_install_default_listener(isr_listener_t listener);
void isr_install_listener(isr_selector_t selector, isr_listener_t listener);
void isr_uninstall_listener(isr_selector_t selector);

#endif // _I386_ISR_H
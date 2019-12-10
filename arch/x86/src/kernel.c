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

#include <boot/multiboot.h>
#include <cpu/cpu.h>

#include <driver/timer/pit.h>
#include <io/cli/cli.h>

#include <stdlib.h>

void kinterrupt_handler(processor_state_t *state);

void kmain(multiboot_header_t *mboot_ptr) {

    cpu_init(); // Initialize CPU (GDT + IDT + Interrupts)

    // Install a default interrupt handler
    isr_install_default_listener(&kinterrupt_handler);

    pit_init(); // Initialize programmable interrupt timer
    cli_init(); // Enable command line interface (Keyboard + VGA textmode)

    while(1);
}

void kinterrupt_handler(processor_state_t *state) {

    static const char *exc_messages[] = {

        "Division by zero",
        "Debug",
        "Non maskable interrupt",
        "Breakpoint",
        "Into detected overflow",
        "Out of bounds",
        "Invalid opcode",
        "No coprocessor",
        "Double fault",
        "Coprocessor segment overrun",
        "Bad TSS",
        "Segment not present",
        "Stack fault",
        "General protection fault",
        "Page fault",
        "Unknown interrupt",
        "Coprocessor fault"
        "Alignment check",
        "Machine check"
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception",
        "Intel reserved exception"
    };

    static const char *irq_messages[] = {

        "System timer",
        "Keyboard controller",
        "Cascade signal",
        "Serial port controller 1",
        "Serial port controller 2",
        "Sound card",
        "Floppy disk controller",
        "Parallel port 1",
        "Real time clock",
        "Advanced Configuration and Power Interface",
        "Peripheral",
        "Peripheral",
        "Mouse",
        "CPU co-processor",
        "Primary ATA channel",
        "Secondary ATA channel"
    };

    // Handle exceptions only
    if(32 > state->interrupt_code) {

        char int_code[4];
		
        cli_color(CLI_RED, CLI_BLACK);

        cli_print("Interrupt (Exception) ");
        cli_print(itoa(state->interrupt_code, int_code, 10));
        cli_print(": ");
        cli_print(exc_messages[state->interrupt_code]);
        cli_putc('\n');

        cli_color(CLI_WHITE, CLI_BLACK);

    } else if(32 <= state->interrupt_code && 47 >= state->interrupt_code) { // Handle IRQs

        char int_code[4];
		
        cli_color(CLI_GREEN, CLI_BLACK);

        cli_print("Interrupt (Hardware) ");
        cli_print(itoa(state->interrupt_code, int_code, 10));
        cli_print(": ");
        cli_print(irq_messages[state->interrupt_code - 32]);
        cli_putc('\n');

        cli_color(CLI_WHITE, CLI_BLACK);
    }
}
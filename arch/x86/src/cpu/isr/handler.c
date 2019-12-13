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

#include <cpu/isr/isr.h>

extern isr_listener_t listeners[ISR_LISTENER_LIMIT];

// Second stage ISR interrupt handler responsible for notifying observers about occurred interrupts
void isr_handler(processor_state_t *state) {

	// Call registered listener for actual handling implementation
    if(ISR_LISTENER_LIMIT > state->interrupt_code && 0x00 != listeners[state->interrupt_code]) {
		
		isr_listener_t listener = listeners[state->interrupt_code];
		listener(state);
	}

	// If IRQ8 (ISR40) - IRQ15 (ISR47) are invoked we nned to send an EOI to slave controller
	if(40 <= state->interrupt_code) {

        outb(PIC_SLAVE_COMMAND_REG, PIC_EOI);
    }

    // In either case we need to send an EOI to the master interrupt controller
    outb(PIC_MASTER_COMMAND_REG, PIC_EOI);
}
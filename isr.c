#include "io.h"
#include "fb.h"
#include "isr.h"
#include "libc/string.h"
#include "libc/stddef.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(uint8_t n, isr_t handler) {
	interrupt_handlers[n] = handler;
}

void isr_handler(registers_t regs) {
	char interrupt[3];
	fb_write_str("recieved interrupt: ");
	itoa(regs.int_no, interrupt, 10);
	fb_write_str(interrupt);
	//fb_write_str(regs.int_no);
	fb_write_str("\n");

	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}

void irq_handler(registers_t regs) {
	if (regs.int_no >= 40) {
		outb(0xA0, 0x20);
	}

	outb(0x20, 0x20);

	if (interrupt_handlers[regs.int_no] != 0) {
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}

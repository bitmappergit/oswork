#include "io.h"
#include "fb.h"
#include "libc/string.h"
#include "dt.h"
#include "timer.h"
#include "serial.h"

void kmain(struct multiboot *mboot_ptr) {
	init_dt();
	//asm volatile ("int $0x3");
	//asm volatile ("int $0x4");
	//int i = 0;
	//char snum[3];
	fb_init();
	fb_clear();
	/*while(i != 100) {
		itoa(i, snum, 10);
		fb_write_str("test ");
		fb_write_str(snum);
		fb_write_str("\n");
		i++;
	}*/
	fb_write_str("abcdefghijklmnopqrstuvwxyz\n");
	asm volatile ("int $0x3");
	asm volatile ("int $0x4");
	asm volatile("sti");
	//serial_configure_baud_rate(0x3F8, 2);
	//serial_configure_line(0x3F8);
	//outb(0x3F8, 'h');
	//outb(0x3F8, 'a');
	//outb(0x3F8, 'h');
	//outb(0x0F8, 'a');
	init_timer(1);
	char str[16];
	while(1 == 1) {
		if(get_timer_value() % 100 == 0) {
		itoa(get_timer_value() / 100, str, 10);
		//fb_write_str("hhhhhhhhhhhhhhh");
		fb_write_str(str);
		fb_write_str("\n");
		}
		//timer_tick();
	}
}

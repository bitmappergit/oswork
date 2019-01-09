#include "io.h"
#include "fb.h"
#include "libc/string.h"
#include "dt.h"
#include "timer.h"

void main(struct multiboot *mboot_ptr) {
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
	init_timer(1);
}

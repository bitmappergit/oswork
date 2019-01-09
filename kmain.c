#include "io.h"
#include "fb.h"

void main(struct multiboot *mboot_ptr) {
	fb_init();
	fb_clear();
	fb_write_str("you have gay\n");
}

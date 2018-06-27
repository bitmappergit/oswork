#include "fb.h"

void main() {
	fb_init();
	fb_clear();
	fb_write_str("huge brain\n");
	fb_write_str("haha yes\n");
	fb_write_cell(40, 11, '|', FB_WHITE, FB_BLACK);
	fb_write_cell(40, 12, '|', FB_WHITE, FB_BLACK);
	fb_write_cell(40, 13, 'v', FB_WHITE, FB_BLACK);
	fb_write_cell(40, 15, 'h', FB_WHITE, FB_BLACK);
	fb_write_cell(42, 16, 'e', FB_WHITE, FB_BLACK);
	fb_write_cell(44, 17, 'l', FB_WHITE, FB_BLACK);
	fb_write_cell(46, 18, 'l', FB_WHITE, FB_BLACK);
	fb_write_cell(48, 19, 'o', FB_WHITE, FB_BLACK);
}

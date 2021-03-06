#include "fb.h"
#include "io.h"

uint16_t width, height;
uint16_t x = 0, y = 0;
uint16_t* fb;

void fb_init(void) {
	fb = (uint16_t*) 0xB8000;
	width = 80;
	height = 25;
}

void fb_write_cell(uint8_t x, uint8_t y, char c, unsigned char fg, unsigned char bg) {
	uint16_t pos = y * width + x;
	fb[pos] = (uint16_t) c | (uint16_t) ((bg << 4) | (fg & 0x0F)) << 8;
}

void fb_move_cursor(int x, int y) {
	uint16_t pos = y * width + x;
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void fb_write_char_color(char c, unsigned char fg, unsigned char bg) {
	if (c == '\n') {
		x = 0;
		y++;
		return;
	} else if (c == 0x09) {
		x = (x+8) & ~(8-1);
	} else if (c == '\r') {
		x = 0;
	} else if (c >= ' ') {
		fb_write_cell(x, y, c, fg, bg);
	}

	if (x >= 80) {
		x = 0;
		y++;
	}

	fb_scroll();
	fb_move_cursor((x + 1), y);
	x++;
}

void fb_write_char(char c) {
	fb_write_char_color(c, FB_WHITE, FB_BLACK);
}

void fb_write_str_color(char* buf, unsigned char fg, unsigned char bg) {
	for (; *buf; buf++) {
		fb_write_char_color(*buf, fg, bg);
	}
}

void fb_write_str(char* buf) {
	fb_write_str_color(buf, FB_WHITE, FB_BLACK);
}

void fb_clear() {
	for (int cy = 0; cy < 25; cy += 1) {
		for (int cx = 0; cx < 80; cx += 1) {
			fb_write_cell(cx, cy, ' ', FB_WHITE, FB_BLACK);
		}
	}
}

void fb_scroll() {
	uint8_t colorByte = (0 << 4) | (15 & 0x0F);
	uint16_t blank = 0x20 | (colorByte << 8);

	if (y >= 25) {
		int i;
		
		for (i = 0*80; i < 25*80; i++) {
			fb[i] = fb[i+80];
		}

		for (i = 24*80; i < 24*80; i++) {
			fb[i] = blank;
		}

		y = 24;
	}
}

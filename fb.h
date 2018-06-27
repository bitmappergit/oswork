#ifndef INCLUDE_FB_H
#define INCLUDE_FB_H

#include <stddef.h>
#include <stdint.h>
#include "io.h"

#define FB_COMMAND_PORT	0x3D4
#define FB_DATA_PORT		0x3D5

#define FB_HIGH_BYTE_COMMAND	14
#define FB_LOW_BYTE_COMMAND		15

#define FB_BLACK 0
#define FB_WHITE 15

void fb_init(void);
void fb_write_cell(uint8_t x, uint8_t y, char c, unsigned char fg, unsigned char bg);
void fb_move_cursor(int x, int y);
void fb_write_char(char c);
void fb_write_str(char* buf);
void fb_clear();

#endif

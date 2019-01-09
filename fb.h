#ifndef INCLUDE_FB_H
#define INCLUDE_FB_H

#include "io.h"

#define FB_COMMAND_PORT		0x3D4
#define FB_DATA_PORT		0x3D5

#define FB_HIGH_BYTE_COMMAND	14
#define FB_LOW_BYTE_COMMAND	15

#define FB_BLACK          0
#define FB_BLUE           1
#define FB_GREEN          2
#define FB_CYAN           3
#define FB_RED            4
#define FB_MAGENTA        5
#define FB_BROWN          6
#define FB_LIGHT_GREY     7
#define FB_DARK_GREY      8
#define FB_LIGHT_BLUE     9
#define FB_LIGHT_GREEN    10
#define FB_LIGHT_CYAN     11
#define FB_LIGHT_RED      12
#define FB_LIGHT_MAGENTA  13
#define FB_LIGHT_BROWN    14
#define FB_WHITE          15

void fb_init(void);
void fb_write_cell(u8int x, u8int y, char c, unsigned char fg, unsigned char bg);
void fb_move_cursor(int x, int y);
void fb_write_char_color(char c, unsigned char fg, unsigned char bg);
void fb_write_char(char c);
void fb_write_str_color(char* buf, unsigned char fg, unsigned char bg);
void fb_write_str(char* buf);
void fb_clear();
void fb_scroll();

#endif

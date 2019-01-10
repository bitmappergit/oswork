#include "paging.h"

extern void load_page_directory(uint32_t*);
extern void enable_paging();

static void create_blank_page_directory() {
	for(int32_t i = 0; i < 1024; i++) {
		page_directory[i] = 0x00000002;
	}
}

static void create_first_page_table() {
	for(int32_t i = 0; i < 1024; i++) {
		first_page_table[i] = (i * 0x1000) | 3;
	}
	page_directory[0] = ((uint32_t)first_page_table) | 3;
}

//page_directory[0] = ((uint32_t)first_page_table) | 3;

void init_paging() {
	create_blank_page_directory();
	create_first_page_table();
	load_page_directory(page_directory);
	enable_paging();
}

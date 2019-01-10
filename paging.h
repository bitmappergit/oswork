#include "libc/stddef.h"

#ifndef INCLUDE_PAGING_H
#define INCLUDE_PAGING_H

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

static void create_blank_page_directory();
static void create_first_page_table();
void init_paging();

#endif

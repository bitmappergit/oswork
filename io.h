#include "libc/stddef.h"

#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

void outb(uint16_t port, uint8_t data);
uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);

#endif

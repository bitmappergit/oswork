#include "typedefs.h"

#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

void outb(u16int port, u8int data);
u8int inb(u16int port);
u16int inw(u16int port);

#endif

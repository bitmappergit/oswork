#include "libc/stddef.h"
#include "io.h"

void outb(uint16_t port, uint8_t value) {
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

uint16_t inw(uint16_t port) {
	uint16_t ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len) {
    const uint8_t *sp = (const uint8_t *)src;
    uint8_t *dp = (uint8_t *)dest;
    for(; len != 0; len--) *dp++ = *sp++;
}

void memset(uint8_t *dest, uint8_t val, uint32_t len) {
    uint8_t *temp = (uint8_t *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

int strcmp(char *str1, char *str2) {
      int i = 0;
      int failed = 0;
      while(str1[i] != '\0' && str2[i] != '\0'){
          if(str1[i] != str2[i]) {
              failed = 1;
              break;
          }
          i++;
      }

      if( (str1[i] == '\0' && str2[i] != '\0') || (str1[i] != '\0' && str2[i] == '\0') )
          failed = 1;
  
      return failed;
}

char *strcpy(char *dest, const char *src) {
    do {
      *dest++ = *src++;
    }
    while (*src != 0);
}

char *strcat(char *dest, const char *src) {
    while (*dest != 0) {
        *dest = *dest++;
    }

    do {
        *dest++ = *src++;
    }
    while (*src != 0);
    return dest;
}

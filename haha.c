#include <stdio.h>

int main() {
	int i = 0;
	while(i != 32) {
		printf("idt_set_gate( %d, (u32int)isr%d , 0x08, 0x8E);\n", i, i);
		i++;
	}
}

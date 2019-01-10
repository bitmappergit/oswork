OBJECTS = multiload.o fb.o io.o kmain.o libc/string.o dt.o isr.o gdt.o timer.o interrupt.o serial.o
CC = gcc
CFLAGS = -m32 -nostdinc -nostdlib -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -c -ffreestanding
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os -input-charset utf8 -quiet -boot-info-table -o os.iso iso

run: os.iso
	qemu-system-i386 -cdrom os.iso -enable-kvm

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

libc/%.o: libc/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso

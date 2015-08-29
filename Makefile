CXX=i686-elf-g++
CXXFLAGS=-std=c++1z -Wall -Wextra -pedantic -O2 -ffreestanding -fno-exceptions -fno-rtti

AS=i686-elf-as

KERNEL_OBJ=kernel/obj/kernel.o
OS_OBJ=obj/boot.o $(KERNEL_OBJ)

OSNAME=schluOS
OS_BIN=bin/$(OSNAME).bin

ISODIR=bin/iso

all: iso

os: $(OS_OBJ)
	mkdir -p bin
	$(CXX) -T src/linker.ld -O2 -ffreestanding -nostdlib -o $(OS_BIN) $(OS_OBJ) -lgcc

iso: os
	mkdir -p $(ISODIR)/boot
	cp $(OS_BIN) $(ISODIR)/boot/$(OSNAME).bin 
	mkdir -p $(ISODIR)/boot/grub
	printf "menuentry \"$(OSNAME)\" {\n\tmultiboot /boot/$(OSNAME).bin\n}\n" > $(ISODIR)/boot/grub/grub.cfg
	grub-mkrescue -o bin/$(OSNAME).iso $(ISODIR)

run_iso: iso
	qemu-system-i386 -cdrom bin/$(OSNAME).iso

run: os
	qemu-system-i386 -kernel $(OS_BIN)

obj/boot.o: src/boot.s
	mkdir -p obj
	$(AS) src/boot.s -o obj/boot.o

kernel/obj/kernel.o: kernel/src/kernel.cpp
	mkdir -p kernel/obj
	$(CXX) $(CXXFLAGS) -c kernel/src/kernel.cpp -o kernel/obj/kernel.o

clean:
	rm -rf bin
	rm -rf obj
	rm -rf kernel/bin
	rm -rf kernel/obj
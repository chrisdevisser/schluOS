CXX=i686-elf-g++
CXXFLAGS=-std=c++1z -Wall -Wextra -pedantic -O2 -ffreestanding -fno-exceptions -fno-rtti

AS=i686-elf-as

KERNEL_OBJ=kernel/obj/kernel.o
OS_OBJ=obj/boot.o $(KERNEL_OBJ)

CRTI_OBJ=obj/crti.o
CRTBEGIN_OBJ:=$(shell $(CXX) $(CXXFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CXX) $(CXXFLAGS) -print-file-name=crtend.o)
CRTN_OBJ=obj/crtn.o

OS_AUG_OBJ:=$(CRTI_OBJ) $(CRTBEGIN_OBJ) $(OS_OBJ) $(CRTEND_OBJ) $(CRTN_OBJ)

OSNAME=schluOS
OS_BIN=bin/$(OSNAME).bin

ISODIR=bin/iso

all: iso

os: $(OS_AUG_OBJ)
	mkdir -p bin
	$(CXX) -T src/linker.ld -O2 -ffreestanding -nostdlib -o $(OS_BIN) $(OS_AUG_OBJ) -lgcc

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

obj/%.o: src/%.s
	mkdir -p obj
	$(AS) $< -o $@

kernel/obj/kernel.o: kernel/src/kernel.cpp
	mkdir -p kernel/obj
	$(CXX) $(CXXFLAGS) -c kernel/src/kernel.cpp -o kernel/obj/kernel.o

clean:
	rm -rf bin
	rm -rf obj
	rm -rf kernel/bin
	rm -rf kernel/obj
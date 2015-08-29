#set default host and host architecture
HOST?=$(shell ../default-host.sh)
HOSTARCH:=$(shell ../target-triplet-to-arch.sh $(HOST))

#set default flags and libs
CXXFLAGS?=-O2 -g -Werror
CPPFLAGS?=
LDFLAGS?=
LIBS?=

#more defaults
DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

#update flags and libs with mandatory options
CXXFLAGS:=$(CXXFLAGS) -Wall -Wextra -pedantic -ffreestanding -fbuiltin
CPPFLAGS:=$(CPPFLAGS) -D__schluOS_kernel -Iinclude
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

ARCHDIR:=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

#update flags and libs with kernel architecture flags and libs
CXXFLAGS:=$(CXXFLAGS) $(KERNEL_ARCH_CXXFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

OBJS:=$(KERNEL_ARCH_OBJS) src/kernel.o

CRTI_OBJ:=$(ARCHDIR)/crti.o
CRTBEGIN_OBJ:=$(shell $(CXX) $(CXXFLAGS) $(LDFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CXX) $(CXXFLAGS) $(LDFLAGS) -print-file-name=crtend.o)
CRTN_OBJ:=$(ARCHDIR)/crtn.o

ALL_OUR_OBJS:=$(CRTI_OBJ) $(OBJS) $(CRTN_OBJ)
ALL_OBJS:=$(CRTI_OBJ) $(CRTBEGIN_OBJ) $(OBJS) $(CRTEND_OBJ) $(CRTN_OBJ)

all: schluOS.kernel

.PHONY: all clean install install-headers install-kernel

schluOS.kernel: $(ALL_OBJS) $(ARCHDIR)/linker.ld 
	$(CXX) -T $(ARCHDIR)/linker.ld -o $@ $(CXXFLAGS) $(ALL_OBJS) $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ -std=c++1z $(CXXFLAGS) $(CPPFLAGS)

%.o: %.s
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

clean:
	rm -f schluOS.kernel $(ALL_OUR_OBJS) *.o */*.o */*/*.o 

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTv include $(DESTDIR)$(INCLUDEDIR)

install-kernel: schluOS.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp schluOS.kernel $(DESTDIR)$(BOOTDIR)
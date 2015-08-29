HOST?=$(shell ../default-host.sh)
HOSTARCH:=$(shell ../target-triplet-to-arch.sh $(HOST))

CXXFLAGS=-O2 -g -Werror
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CXXFLAGS:=$(CXXFLAGS) -Wall -Wextra -pedantic
CPPFLAGS:=$(CPPFLAGS) -D__schluOS_libc -Iinclude
LIBK_CXXFLAGS:=$(CXXFLAGS) -ffreestanding -fbuiltin
LIBK_CPPFLAGS:=$(CPPFLAGS) -D__schluOS_kernel

ARCHDIR:=arch/$(HOSTARCH)
KERNEL_ARCHDIR:=../kernel/arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CXXFLAGS:=$(CXXFLAGS) $(ARCH_CXXFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBK_CXXFLAGS:=$(LIBK_CXXFLAGS) $(KERNEL_ARCH_CXXFLAGS)
LIBK_CPPFLAGS:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)

FREEOBJS:=\
$(ARCH_FREEOBJS) \
src/stdio/printf.o \
src/stdio/putchar.o \
src/stdio/puts.o \
src/stdlib/abort.o \
src/string/memcmp.o \
src/string/memcpy.o \
src/string/memmove.o \
src/string/memset.o \
src/string/strlen.o

HOSTEDOBJS:=$(ARCH_HOSTEDOBJS)
OBJS:=$(FREEOBJS) $(HOSTEDOBJS)
LIBK_OBJS:=$(FREEOBJS:.o=.libk.o) $(KERNEL_ARCH_FREEOBJS:.o=.libk.o)

BINS=libc.a libg.a libk.a

all: $(BINS)

.PHONY: all clean install install-headers install-libs

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libg.a:
	$(AR) rcs $@

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

%.o: %.cpp
	$(CXX) -c $< -o $@ -std=c++1z $(CXXFLAGS) $(CPPFLAGS)

%.o: %.s
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(CPPFLAGS)

%.libk.o: %.cpp
	$(CXX) -c $< -o $@ -std=c++1z $(LIBK_CXXFLAGS) $(LIBK_CPPFLAGS)

%.libk.o: %.s
	$(CXX) -c $< -o $@ $(LIBK_CXXFLAGS) $(LIBK_CPPFLAGS)

clean:
	rm -f $(BINS) $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -RTv include $(DESTDIR)$(INCLUDEDIR)

install-libs: $(BINS)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINS) $(DESTDIR)$(LIBDIR)
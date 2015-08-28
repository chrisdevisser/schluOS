This is the result of me following the tutorials on http://wiki.osdev.org/.
So far, I've had no luck getting the freestanding C++ headers to work, which is really unfortunate.

Current build instructions are manual using a cross compiled GCC 6.0 for i686-elf. The last step requires qemu.

1. Assemble src/boot.s to bin/boot.o.
2. Compile kernel/src/kernel.cpp to kernel/bin/kernel.o.
3. Use g++ with src/linker.ld to combine bin/boot.o and kernel/bin/kernel.o into bin/schluOS.bin.
4. Run make_iso.sh.
5. Run launch_iso.sh or launch_kernel.sh. 
This is the result of me following the tutorials on http://wiki.osdev.org/.
So far, I've had no luck getting the freestanding C++ headers to work, which is really unfortunate. Everything is rather messy and squished into kernel.cpp right now, but that's due to change.

There's a really poor makefile to use with a cross compiled GCC 6.0 for i686-elf:

- Build OS: make os
- Build ISO: make/make iso
- Run kernel in qemu: make run
- Run ISO in qemu: make run_iso
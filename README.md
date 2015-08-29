This is the result of me following the tutorials on http://wiki.osdev.org/.
So far, I've had no luck getting the freestanding C++ headers to work, which is really unfortunate.

Requires a GCC 6.0 cross compiler targetting i686-elf. 

- clean.sh: Removes built things.
- qemu.sh: Builds and runs the kernel in qemu.
- qemu-iso.sh: Builds and runs an ISO of schluOS in qemu.

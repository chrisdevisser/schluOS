#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir/boot/grub
cp sysroot/boot/schluOS.kernel isodir/boot/schluOS.kernel

cat > isodir/boot/grub/grub.cfg << EOF
menuentry "schluOS" {
	multiboot /boot/schluOS.kernel
}
EOF

grub-mkrescue -o schluOS.iso isodir
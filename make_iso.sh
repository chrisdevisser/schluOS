mkdir -p bin/iso/boot
cp bin/schluOS.bin bin/iso/boot/schluOS.bin
mkdir -p bin/iso/boot/grub
cp src/grub.cfg bin/iso/boot/grub/grub.cfg
grub-mkrescue -o bin/schluOS.iso bin/iso
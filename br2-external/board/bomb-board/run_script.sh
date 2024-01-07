#!/usr/bin/env bash

linux_kernel=zImage
rootfs=rootfs.ext2

# Start qemu with the desired parameters
qemu-system-arm -M virt -cpu cortex-a15 -m 256 \
    -kernel $linux_kernel -append "root=/dev/vda console=null" \
    -drive file=$rootfs,format=raw,index=0,media=disk \
    -chardev pty,id=gdb \
    -device pci-serial,chardev=gdb \
    -serial stdio \
    -serial chardev:gdb \
    -nographic -monitor none

cmd_/home/dts/code/linux/hello_mod.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /home/dts/code/linux/hello_mod.ko /home/dts/code/linux/hello_mod.o /home/dts/code/linux/hello_mod.mod.o

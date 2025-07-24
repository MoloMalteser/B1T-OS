CROSS=aarch64-none-elf
CFLAGS=-Wall -O2 -nostdlib -ffreestanding -Iinclude

OBJS=src/framebuffer.o src/gui_bootloader.o src/neuron.o

kernel8.img: $(OBJS)
	$(CROSS)-ld -T linker.ld -o kernel.elf $(OBJS)
	$(CROSS)-objcopy kernel.elf -O binary kernel8.img

%.o: %.c
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o *.img *.elf

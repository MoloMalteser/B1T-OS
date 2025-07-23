CROSS_COMPILE=arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
OBJCOPY=$(CROSS_COMPILE)objcopy

CFLAGS=-Wall -O2 -nostdlib -ffreestanding -mcpu=cortex-a53 -march=armv8-a
LDFLAGS=-T linker.ld

SRCS=src/bootloader.S src/kernel.c src/gpio.c
OBJS=$(SRCS:.c=.o)
OBJS:=$(OBJS:.S=.o)

all: b1tos.img

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

b1tos.elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

b1tos.img: b1tos.elf
	$(OBJCOPY) -O binary $< $@

clean:
	rm -f $(OBJS) b1tos.elf b1tos.img

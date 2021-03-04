CC=m68k-elf-gcc
AS=m68k-elf-as
LD=m68k-elf-ld
SIZE=m68k-elf-size
OBJCOPY=m68k-elf-objcopy
OBJDUMP=m68k-elf-objdump

CPUFLAGS = -m68040
ASFLAGS  = $(CPUFLAGS)
CFLAGS   = $(CPUFLAGS) -Os -std=c99 -ffreestanding -I src/include -flto
LDFLAGS  = -nostdlib -lgcc

SRCS  = $(wildcard src/*.c)

OBJS  = $(SRCS:.c=.o)
OBJS += src/start.o

FNAME=boot

OUTPUT=$(FNAME).elf $(FNAME).lst $(FNAME).bin $(FNAME).mem

all : $(OUTPUT) size

size : $(FNAME).elf
	$(SIZE) $<

$(FNAME).elf: $(OBJS)
	$(CC) -T src/linker.ld $(CFLAGS) $(LDFLAGS) -o $@ $^

src/main.o: force

%.lst : %.elf
	$(OBJDUMP) -D $< > $@

%.bin : %.elf
	$(OBJCOPY) -O binary $< $@

%.mem : %.bin
	$(OBJCOPY) -I binary -O verilog --verilog-data-width=4 $< $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o : %.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(OUTPUT)

force:

.PHONY: clean all force

PROJ = main
CPU ?= cortex-m4
BOARD ?= stm32f407discovery
LINKER_SCRIPT ?= start.ld
INC_PATH = ./include
CONFIG_FILE = stm.cfg
TARGET ?= light

INC = -I$(INC_PATH)/
CFLAGS = -g -mcpu=$(CPU) -mthumb -mtune=$(CPU) -fbuiltin -ffreestanding -nostdlib

OBJ = $(TARGET).o \
	$(INC_PATH)/stm32f407.o \
	$(INC_PATH)/stm32f407_adc.o \
	$(INC_PATH)/stm32f407_pwm.o \
	$(INC_PATH)/stm32f407_dac.o \
	$(INC_PATH)/stm32f407_gpio.o \
	$(INC_PATH)/stm32f407_usart.o

.PHONY: all
all: $(PROJ).elf

%.o: %.c
	arm-none-eabi-gcc $(INC) $(CFLAGS) -c $^ -o $@

$(PROJ).elf: $(OBJ)
	arm-none-eabi-ld -T$(LINKER_SCRIPT) $^ -o $@
	arm-none-eabi-objdump -D -S $@ > $@.lst
	arm-none-eabi-readelf -a $@ > $@.debug

run:
	sudo openocd --file $(CONFIG_FILE) -c "program $(PROJ).elf verify reset exit"

debug:
	openocd --file $(CONFIG_FILE)

gdb:
	arm-none-eabi-gdb $(PROJ).elf

clean:
	rm -f *.out *.elf *.lst *.debug *.o *.obj
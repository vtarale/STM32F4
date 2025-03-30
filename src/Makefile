PROJ = main
CPU ?= cortex-m4
BOARD ?= stm32f407discovery
LINKER_SCRIPT = start.ld
INC_PATH = ./include
CONFIG_FILE = stm.cfg

INC = -I$(INC_PATH)/include/
CFLAGS = -g -T$(LINKER_SCRIPT) -mcpu=$(CPU) -mthumb -mtune=$(CPU) -fbuiltin -ffreestanding -nostdlib

.PHONY: all
all: $(PROJ).elf

OBJ = $(TARGET).o \
				$(INC_PATH)/stm32f407_adc.o
				$(INC_PATH)/stm32f407_pwm.o
				$(INC_PATH)/stm32f407_dac.o
				$(INC_PATH)/stm32f407_gpio.o
				$(INC_PATH)/stm32f407_usart.o

%.o: %.c
	arm-none-eabi-gcc $(INC) -mthumb -mcpu=$(CPU) -g -c $^ -o $@

$(PROJ).elf: $(OBJ)
	arm-none-eabi-ld -Tmap.ld $^ -o $@
	arm-none-eabi-objdump -D -S $@ > $@.lst
	arm-none-eabi-readelf -a $@ > $@.debug

arm-none-eabi-gcc $(CFLAGS) $(TARGET).c $(COMMON_FILES) -o $(PROJ).elf

run:
	sudo openocd --file $(CONFIG_FILE) -c "program $(PROJ).elf verify reset exit"

debug:
	openocd --file $(CONFIG_FILE)

read:
	readelf -a $(PROJ).elf

clean:
	rm -rf *.out *.elf *.lst *.debug *.o *.obj
compile_light:
	arm-none-eabi-gcc -g -Tstart.ld -mcpu=cortex-m4 -mthumb -mtune=cortex-m4 -fbuiltin -ffreestanding -nostdlib light.c include/stm32f407_gpio.c -o main.elf
compile_adc:
	arm-none-eabi-gcc -g -Tstart.ld -mcpu=cortex-m4 -mthumb -mtune=cortex-m4 -fbuiltin -ffreestanding -nostdlib adc.c include/stm32f407_gpio.c include/stm32f407_adc.c -o main.elf
run:
	openocd --file stm.cfg -c "program main.elf verify reset exit" 
debug:
	openocd --file stm.cfg
read:
	readelf -a main.elf
clean:
	rm *.elf
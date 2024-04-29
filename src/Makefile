compile_light:
	arm-none-eabi-gcc -Tstart.ld -mcpu=cortex-m4 -mthumb -mtune=cortex-m4 -fbuiltin -ffreestanding -nostdlib light.c include/stm32f407_gpio.c -o main.elf
run:
	openocd --file stm.cfg -c "program main.elf verify reset exit" 
debug:
	openocd --file stm.cfg
read:
	readelf -a main.elf
clean:
	rm *.elf
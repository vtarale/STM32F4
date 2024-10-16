# STM32F4
* Using the `stm32f407-discovery` board.
* Making PID Controller

## Current Status
* `stm32f407_gpio.h` complete (now can be used !!). 
* `stm32f407_usart.h` complete (now can be used !!). 
* `stm32f407_adc.h` complete (now can be used !!).
* `stm32f407_dac.h` complete (now can be used !!). 
* `light.c` complete.
* `ADC` complete.
* `USART` complete.
* `DAC` complete.
* `PWM` fixing bugs

**Under Development:**
* Make `README` better
* `PID controller` : the next thing after `PWM`

## Prequistes
* To flash code on board - `openocd`
* Arm `32 bit` compiler - `arm-none-eabi-gcc`
* `nostdlib`
* For checking code and debugging - `readelf`
* For debugging - `gdb`, `lldb` (for mac)
* For `usart` - `qemu`

## Using the Library
**Caution**: while using library `global variables` can't be used.
* While using the library `main()` function has to be replaced by `start()`
```
int start() {                   // has to be always int
  ...
}
```

## Running the Code !
1. To compile `light.c`:
```
$ make compile_light
```
2. To compile `adc.c`:
```
$ make compile_adc
```
3. To compile `usart.c`:
```
$ make compile_usart
```
4. To compile `dac.c`:
```
$ make compile_dac
```
5. To `flash` the code onto the board:
```
$ make run
```
6. To `debug`:
```
$ make debug
```
7. To analyze(recheck) the code and see the memory (`readelf`):
```
$ make read
```
8. To clean (clear `object files`):
```
$ make clean
```

## References
[RM0090 Reference manual](https://github.com/vtarale/STM32F4/blob/main/Datasheets/reference_manual.pdf)
[STM32F407 Datasheet](https://github.com/vtarale/STM32F4/blob/main/Datasheets/datasheet.pdf)

## Lisence
[MIT](https://github.com/vtarale/STM32F4/blob/main/LICENSE)

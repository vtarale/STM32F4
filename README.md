# STM32F4
* Using the `stm32f407-discovery` board.
* Making PID Controller

## Current Status
* `stm32f407_gpio.h` complete (now can be used !!). 
* `light.c` complete.
* `ADC` complete.
* `USART` complete.

**Under Development:**
* `DAC` implementation left.

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
4. To `flash` the code onto the board:
```
$ make run
```
5. To `debug`:
```
$ make debug
```
6. To analyze(recheck) the code and see the memory (`readelf`):
```
$ make read
```
7. To clean (clear `object files`):
```
$ make clean
```

## References
[RM0090 Reference manual](https://www.st.com/resource/en/reference_manual/rm0090-stm32f405415-stm32f407417-stm32f427437-and-stm32f429439-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Lisence
[MIT](https://github.com/vtarale/STM32F4/blob/main/LICENSE)

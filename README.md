# STM32F4
* Using the `stm32f407-discovery` board.
* Demo projects.
* Currently, learning the board.
* Coding it in `c`.
* Will make a pid controller with it in future.

## Current Status
* `stm32f407_gpio.h` complete (now can be used !!). 
* `light.c` complete.

**Under Development:**
* `ADC` implementation left.
* `DAC` implementation left.

## Prequistes
* To flash code on board - `openocd`
* Arm `32 bit` compiler - `arm-none-eabi-gcc`
* `nostdlib`
* For checking code and debugging - `readelf`
* For debugging - `gdb`, `lldb` (for mac)

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
2. To flash the code onto the board:
```
$ make run
```
3. To `debug`:
```
$ make debug
```
4. To analyze(recheck) the code and see the memory (`readelf`):
```
$ make read
```
5. To clean (clear `object files`):
```
$ make clean
```

## References
[RM0090 Reference manual](https://www.st.com/resource/en/reference_manual/rm0090-stm32f405415-stm32f407417-stm32f427437-and-stm32f429439-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Lisence
[MIT](https://github.com/vtarale/STM32F4/blob/main/LICENSE)

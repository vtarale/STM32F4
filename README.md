# STM32F4
* Using the `stm32f4-discovery` board
* Demo projects
* Currently, learning the board
* Coding it in `c`
* Will make a pid controller with it in future

## Prequistes
* To flash code on board - `openocd`
* Arm `32 bit` compiler - `arm-none-eabi-gcc`
* `nostdlib`
* For checking code and debugging - `readelf`
* For debugging - `gdb`

## Running the Code !
* Currently the code is not complete
* `openocd` commands left to add in `Makefile`

To compile light.c(not yet completed):
```
$ make compile_light
```
To analyze(recheck) the code and see the memory(`readelf`):
```
$ make read
```
To clean:
```
$ make clean
```

## References
[RM0090 Reference manual](https://www.st.com/resource/en/reference_manual/rm0090-stm32f405415-stm32f407417-stm32f427437-and-stm32f429439-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Lisence
[MIT](https://opensource.org/license/mit)

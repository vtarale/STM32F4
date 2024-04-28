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

## Using the Library
* While using the library `main()` function has to be replaced by `start()`
```
int start() {                   // has to be always int
  ...
}
```
* Using `reset_gpio` and `reset_gpio_all`
```
void reset_gpio(int x) {
  ...
}
void reset_gpio_all() {
  ...
}
```
1. Resets all the GPIOs to reset value.
2. *int x*: Specify GPIO val. Use the macro `GPIOx_VAL`
* Using `set_moder()`:
```
  void set_moder(GPIO *x, int state, int pin, int bit_0, int bit_1) {
          ...
  }
```
1. *GPIO *x**: Use the macro `GPIOx`
2. *int state*: Configure the register(input, output, alternate function, analog). Use the macro `MODER_INPUT`, `MODER_OUTPUT`, `MODER_AF`, `MODER_ANALOG`
3. *int pin*: Specify which GPIO Pin you are using(A0 .. A15). Use the macro. `PIN_x`
4. *int bit_0*: Use the macro `PIN_x_BIT_0`
5. *int bit_1*: Use the macro `PIN_x_BIT_1`

* Using `set_otyper()`:
```
  void set_otyper(GPIO *x, int state, int pin, int bit_0, int bit_1) {
          ...
  }
```
1. *GPIO *x**: Use the macro `GPIOx`
2. *int state*: Configure the output. Use the macro `OTYPER_PUSH_PULL`, `OTYPER_OPEN_DRAIN`
3. *int pin*: Specify which GPIO Pin you are using(A0 .. A15). Use the macro. `PIN_x`
4. *int bit_0*: Use the macro `PIN_x_BIT_0`
5. *int bit_1*: Use the macro `PIN_x_BIT_1`
  
## Running the Code !
* Currently the code is not complete
* `openocd` commands left to add in `Makefile`
1. To compile light.c(not yet completed):
```
$ make compile_light
```
2. To analyze(recheck) the code and see the memory(`readelf`):
```
$ make read
```
3. To clean:
```
$ make clean
```

## References
[RM0090 Reference manual](https://www.st.com/resource/en/reference_manual/rm0090-stm32f405415-stm32f407417-stm32f427437-and-stm32f429439-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Lisence
[MIT](https://github.com/vtarale/STM32F4/blob/main/LICENSE)

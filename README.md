# STM32F4
Creating custom header files for the `stm32f4`. Aim to create a pid controller at last. 
The `stm32f4` is development board with `Arm Cortex-M4` arhitecture. It is `32 bit` a proccesor. The STM32F4 has multiple `adcs`,  `timers`, `clocks`, a `dac`, and much more.

## Current Status
* Mostly all neccessary header files done except `stm32f407_pwm.h`
* **Under Development:** debbuging the `PWM`
* `PID controller` : the next thing after `PWM`

## Prequistes
* To flash code on board - `openocd`
* Arm `32 bit` compiler - `arm-none-eabi-gcc`
* `nostdlib`
* For checking code and debugging - `readelf`
* For debugging - `arm-none-eabi-gdb`
* For `usart` - `coolTerm`(for mac), `minicom`
* Can be downloaded for `linux` and mac from [HomeBrew](brew.sh)

## Using the Library
**Caution**: while using library `global variables` can't be used.
* While using the library `main()` function has to be replaced by `start()`
```
int start() {                   // has to be always int
  ...
}
```
**Will write the documentation for each library soon**

## Running the Code !
* Compiling
```
 make TARGET=<filename>
```
* Running
```
  make run
```
* Debugging
```
  make debug
  make gdb(seperate terminal)
```
* Clean
```
  make clean
  cd include/
  make clean
```

## References
[RM0090 Reference manual](https://github.com/vtarale/STM32F4/blob/main/Datasheets/reference_manual.pdf) <br/>
[STM32F407 Datasheet](https://github.com/vtarale/STM32F4/blob/main/Datasheets/datasheet.pdf) <br/>
[Fundamentals of System-on-Chip Design on Arm Cortex-M Microcontrollers](https://www.arm.com/resources/education/books/fundamentals-soc)

## Lisence
[MIT](https://github.com/vtarale/STM32F4/blob/main/LICENSE)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 64K
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 112K
}

ENTRY(reset_handler)

SECTIONS
{
    .text : {
      _start_text = .;
      *(.vec*)
      *(.text)
      _end_text = .;
    } > FLASH AT > FLASH

    .data : {
      _start_data = .;
      KEEP(*(.data*))
      _end_data = .;
    } > RAM AT> FLASH

    .rodata : {
      KEEP(*(.rodata*))
    } > FLASH AT> FLASH

    .bss : {
      _start_bss = .;
      KEEP(*(.bss*))
      _end_bss = .;
    } > RAM AT > RAM
}

__stack_top__ = ORIGIN(RAM) + LENGTH(RAM) - 4;
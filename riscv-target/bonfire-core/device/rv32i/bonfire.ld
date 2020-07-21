
ENTRY(_start)


SECTIONS
{


  . = 0x00000000;
  .text : { *(.text) }

  . = ALIGN(0x1000);
  .data : { *(.data) }
  .data.string : { *(.data.string)}
  _edata = .;

  .bss : { *(.bss) }
  _end = .;
  . = _end + 256;
  . = ALIGN(256);
  stack = .;
}

monitor = 0x10000000;

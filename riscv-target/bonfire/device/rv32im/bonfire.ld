MEMORY
{
	RAM (rwx)    : ORIGIN = 0x00000000, LENGTH = 32768 
}


ENTRY(_start)


SECTIONS
{


  . = 0x00000000;
  .text.init : { *(.text.init) }
  . = 0x00000080;
  .text.trap : { *(.text.trap) }


  . = ALIGN(0x1000);
  .tohost : { *(.tohost) }

  . = ALIGN(0x1000);
  .text : { *(.text) }
  _etext = .;

  . = ALIGN(0x1000);
  .data : { *(.data) }
  .data.string : { *(.data.string)}
  _edata = .;

  .bss : { *(.bss) }
  _end = .;
}


monitor = 0x10000000;
signature_dump_port =0x1ffffffc;
uart =  0x20000000;

mtime   = 0x0FFFF0000;

ENTRY(_start)


SECTIONS
{


  . = 0x00000000;
  .text.init : { *(.text.init) }
  . = ALIGN(64);
  .text.trap : { *(.text.trap) }

  . = ALIGN(4);
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
trap_dump = monitor + 0x1000;
signature_dump_port =0x1ffffffc;
/* uart =  0x20000000;

mtime   = 0x0FFFF0000; */
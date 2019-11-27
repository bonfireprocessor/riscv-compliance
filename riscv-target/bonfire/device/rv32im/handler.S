

.global dump_signature

.section .text.trap;
.align  4;

_trap_start:
    j _trap_exception
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc
    j _int_exc



// This could be exception or user interrupt
// 0xb is the environment call to indicate the end
_trap_exception:
    csrr a0, mcause;
    addi a1, zero, 0xb
    beq a0, a1, 1f
    la a1, begin_signature
    sw a0, 0(a1);
1:
    la a1, monitor;
    sw a0, 0(a1)  

_int_exc:
    la a1, monitor;
    sw x0, 0(a1)  

dump_signature:
    la a0, signature_dump_port
    la a1, begin_signature
    la a2, end_signature
l2:
    lw t1,0(a1)
    sw t1,0(a0)
    addi a1,a1,4
    blt a1,a2, l2 
    ret     
    
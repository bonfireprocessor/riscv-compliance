

.global dump_signature

.section .text.trap;
.align  4;

_trap_start:
    j _trap_exception
   



// This could be exception or user interrupt
// 0xb is the environment call to indicate the end
_trap_exception:
    csrr a0, mcause;
    addi a1, zero, 0xb
    beq a0, a1, 1f // check for ecall 
    addi a1, zero, 0x6
    beq a0,a1, 1f  // check for misalign 
    la a1, begin_signature
    sw a0, 0(a1);
1:
    call dump_signature
    la a1, (monitor+0x1000) // Trap output area 
    csrr a0, mcause 
    sw a0,0(a1) 
    csrr t1, mepc
    sw t1,4(a1)
    csrr t1,mbadaddr
    sw t1,8(a1)
    csrr t1,mstatus 
    sw t1,12(a1)  
    
    la a1, monitor // Termination/result address 
    sw a0, 0(a1) // write mcause  

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
    
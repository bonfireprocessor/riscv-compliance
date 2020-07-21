

.section .text.trap;


_trap_start:

// This could be exception or user interrupt
// 0xb is the environment call to indicate the end
  
    la a1, trap_dump // Trap output area 
    csrr a0, mcause 
    sw a0,0(a1) 
    csrr t1, mepc
    sw t1,4(a1)
    csrr t1,mbadaddr
    sw t1,8(a1)
    csrr t1,mstatus 
    sw t1,12(a1)  
    
    la a1, monitor // Termination/result address 
    sw x31, 0(a1) // write x31 register 

    
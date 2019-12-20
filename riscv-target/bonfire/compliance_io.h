// RISC-V Compliance Test Header File
// Copyright (c) 2017, Codasip Ltd. All Rights Reserved.
// See LICENSE for license details.
//
// Description: Common header file for RV32I tests


#ifndef _COMPLIANCE_IO_H
#define _COMPLIANCE_IO_H

//-----------------------------------------------------------------------
// RV IO Macros
//-----------------------------------------------------------------------

#define RVTEST_IO_INIT
#define RVTEST_IO_PUTC(_R)
#define RVTEST_IO_WRITE_STR(_SP, _STR)


// _SP = (volatile register)
// _R = GPR
// _I = Immediate
#define RVTEST_IO_ASSERT_GPR_EQ(_SP, _R, _I) \
//    li _SP, _I; \
//    beq _SP,_R, 20002f; \
//    mv x31,_R; \
//    ecall; \
//    la _SP, monitor; \
//    sw _R, 0(_SP); \
// 20002:          \

#define RVTEST_IO_CHECK()

#endif // _COMPLIANCE_IO_H

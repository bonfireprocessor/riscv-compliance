// RISC-V Compliance Test Header File
// Copyright (c) 2017, Codasip Ltd. All Rights Reserved.
// See LICENSE for license details.
//
// Description: Common header file for RV32I tests

#ifndef _COMPLIANCE_TEST_H
#define _COMPLIANCE_TEST_H

#include "riscv_test.h"

//-----------------------------------------------------------------------
// RV Compliance Macros
//-----------------------------------------------------------------------

#define TESTUTIL_BASE monitor
#define TESTUTIL_ADDR_HALT (TESTUTIL_BASE)
//#define TESTUTIL_ADDR_BEGIN_SIGNATURE (TESTUTIL_BASE + 0x8)
//#define TESTUTIL_ADDR_END_SIGNATURE (TESTUTIL_BASE + 0xc)

#undef RVTEST_PASS
#define RVTEST_PASS \
        li t0, 1;       \
        la t1, TESTUTIL_ADDR_HALT;  \
        sw t0, 0(t1);    \
        _endless: \
        j _endless; \

#undef RVTEST_FAIL
#define RVTEST_FAIL \
        li t0, -1;   \
        la t1, TESTUTIL_ADDR_HALT;  \
        sw t0, 0(t1);    \
        j _endless; \


#define RV_COMPLIANCE_HALT          \
        dump_signature: \
        la a0, signature_dump_port; \
        la a1, begin_signature; \
        la a2, end_signature; \
        _l2:  \
        lw t1,0(a1); \
        sw t1,0(a0); \
        addi a1,a1,4;  \
        blt a1,a2, _l2;  \
        RVTEST_PASS       \


#define RV_COMPLIANCE_RV32M   \
        .section .text.init; \
        .global _start;       \
        _start:              \
        la a1, _trap_start;  \
        csrw mtvec, a1;      \
        j begin_testcode; \


#define RV_COMPLIANCE_CODE_BEGIN     \
        .section .text;              \
        .align  4;                   \
        .global begin_testcode;      \
         begin_testcode:


#define RV_COMPLIANCE_CODE_END    \
        RVTEST_CODE_END           \

#define RV_COMPLIANCE_DATA_BEGIN \
       .align 4; .global begin_signature; begin_signature: \

#define RV_COMPLIANCE_DATA_END           \
         RVTEST_DATA_END    \

#endif


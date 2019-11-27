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

#define TESTUTIL_BASE 0x10000000
#define TESTUTIL_ADDR_HALT (TESTUTIL_BASE)
#define TESTUTIL_ADDR_BEGIN_SIGNATURE (TESTUTIL_BASE + 0x8)
#define TESTUTIL_ADDR_END_SIGNATURE (TESTUTIL_BASE + 0xc)

#undef RVTEST_PASS
#define RVTEST_PASS \
        li t0, 1;                                                             \
        li t1, TESTUTIL_ADDR_HALT;                                            \
        sw t0, 0(t1);    \
        _endless: \
        j _endless; \

#undef RVTEST_FAIL
#define RVTEST_FAIL \
        li t0, -1;                                                             \
        li t1, TESTUTIL_ADDR_HALT;                                            \
        sw t0, 0(t1);    \
        j _endless; \


#define RV_COMPLIANCE_HALT                                                    \
        /* tell simulation about location of begin_signature */               \
        la t0, begin_signature;                                               \
        li t1, TESTUTIL_ADDR_BEGIN_SIGNATURE;                                 \
        sw t0, 0(t1);                                                         \
        /* tell simulation about location of end_signature */                 \
        la t0, end_signature;                                                 \
        li t1, TESTUTIL_ADDR_END_SIGNATURE;                                   \
        sw t0, 0(t1);                                                         \
        RVTEST_PASS                                                           \


#define RV_COMPLIANCE_RV32M   \
        .section .text.init; \
        .global _start;       \
        _start:              \
        li sp,0x7ff0;        \
        la a1, _trap_start;  \
        csrw mtvec, a1;      \
        j begin_testcode; \


#define RV_COMPLIANCE_CODE_BEGIN                                              \
        .section .text;                                                  \
        .align  4;                                                            \
        .global begin_testcode;                                                        \
         begin_testcode:



#define RV_COMPLIANCE_CODE_END                                                \
                                                                              \

#define RV_COMPLIANCE_DATA_BEGIN
        .section .data;                                          \
        .align 4;                                                             \
        .global begin_signature;                                      \
        begin_signature:

#define RV_COMPLIANCE_DATA_END                                               \
        .align 4;                                                             \
        .global end_signature;                                        \
        end_signature:

#endif


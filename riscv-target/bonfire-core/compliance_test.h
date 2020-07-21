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

//#define TESTUTIL_BASE monitor
#define TESTUTIL_ADDR_HALT monitor


#undef RVTEST_PASS
#define RVTEST_PASS \
        li t0, 1;    \
        la t1, TESTUTIL_ADDR_HALT; \
        sw t0, 0(t1);    \
        _endless: \
        j _endless; \

#undef RVTEST_FAIL
#define RVTEST_FAIL \
        li t0, -1;      \
        la t1, TESTUTIL_ADDR_HALT;  \
        sw t0, 0(t1);    \
        j _endless; \


#define RV_COMPLIANCE_HALT   \
        RVTEST_PASS          \


#define RV_COMPLIANCE_RV32M   \
       

#define RV_COMPLIANCE_CODE_BEGIN   \
        .section .text;            \
        .global _start;            \
        _start:                    \
        begin_testcode:



#define RV_COMPLIANCE_CODE_END          \
        RVTEST_CODE_END                 \

#define RV_COMPLIANCE_DATA_BEGIN        \
        .align 4; .global begin_signature; begin_signature:

#define RV_COMPLIANCE_DATA_END           \
        RVTEST_DATA_END 

#endif


# Running the compliance tests on Bonfire Core (MyHDL based RISC-V implementation)



## Dependencies

### [Bonfire-core](https://github.com/bonfireprocessor/bonfire-core)
Bonfire Core is an implementation of a RISC-V processor in MyHDL. This Target is intended for running the RISC-V compliance suite on it. It is intended to run the Python code directly, not the generated VHDL or Verilog. Prerequisties for running the simulation should be in the README of the bonfire-core repo. 


### RISC-V Toolchain e.g. [https://github.com/riscv/riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain)
There are different possiblties to get a RISC-V toolchain. Aside from building from source, also precompiled toolchains work, also [GNU RISC-V Embedded GCC](https://xpack.github.io/riscv-none-embed-gcc/install/).

However, the RISC-V toolchain must be found by the compliance suite. The envrionment variable RISCV_PREFIX defines the prefix (with our without path...) for invoking gcc and other tools from the chain.


If all prerequistes are met, the Tests can be invoked with

    make RISCV_TARGET=bonfire-core BONFIRE_CORE_ROOT<path to bonfire-core repo>

It will run the following test suites:

    rv32i 

### Result:
Because bonfire-core currenlty has no privilege mode tests that rely on it are ignored:

```
Check                 I-ADD-01 ... OK
Check                I-ADDI-01 ... OK
Check                 I-AND-01 ... OK
Check                I-ANDI-01 ... OK
Check               I-AUIPC-01 ... OK
Check                 I-BEQ-01 ... OK
Check                 I-BGE-01 ... OK
Check                I-BGEU-01 ... OK
Check                 I-BLT-01 ... OK
Check                I-BLTU-01 ... OK
Check                 I-BNE-01 ... OK
Check         I-DELAY_SLOTS-01 ... OK
Check              I-EBREAK-01 ... IGNORE
Check               I-ECALL-01 ... IGNORE
Check           I-ENDIANESS-01 ... OK
Check                  I-IO-01 ... OK
Check                 I-JAL-01 ... OK
Check                I-JALR-01 ... OK
Check                  I-LB-01 ... OK
Check                 I-LBU-01 ... OK
Check                  I-LH-01 ... OK
Check                 I-LHU-01 ... OK
Check                 I-LUI-01 ... OK
Check                  I-LW-01 ... OK
Check        I-MISALIGN_JMP-01 ... IGNORE
Check       I-MISALIGN_LDST-01 ... IGNORE
Check                 I-NOP-01 ... OK
Check                  I-OR-01 ... OK
Check                 I-ORI-01 ... OK
Check             I-RF_size-01 ... OK
Check            I-RF_width-01 ... OK
Check               I-RF_x0-01 ... OK
Check                  I-SB-01 ... OK
Check                  I-SH-01 ... OK
Check                 I-SLL-01 ... OK
Check                I-SLLI-01 ... OK
Check                 I-SLT-01 ... OK
Check                I-SLTI-01 ... OK
Check               I-SLTIU-01 ... OK
Check                I-SLTU-01 ... OK
Check                 I-SRA-01 ... OK
Check                I-SRAI-01 ... OK
Check                 I-SRL-01 ... OK
Check                I-SRLI-01 ... OK
Check                 I-SUB-01 ... OK
Check                  I-SW-01 ... OK
Check                 I-XOR-01 ... OK
Check                I-XORI-01 ... OK
--------------------------------
OK: 48/48 RISCV_TARGET=bonfire-core RISCV_DEVICE=rv32i RISCV_ISA=rv32i
```

### Additional parameters:
The Target supports paralell execution of the test, which speeds up execution a lot.
E.g. adding 

    PARALLEL=1 JOBS="-j8"

to the command line will run 8 paralell processes.
# Running the compliance tests on bonfire-cpu



## Dependencies
### [FuseSoC](https://github.com/olofk/fusesoc)
Because bonfire-cpu used FuseSoC is build environment, also the verifcation makefile uses FuseSoc to invoke ghdl and pass all parameters. Install FuseSoC as described in the Readme. More information about FuseSoC can be found here: https://fusesoc.readthedocs.io/

### [GHDL](https://github.com/ghdl/ghdl)
GHDL >= 0.36 is required. 
Because the Suite  elaborate/compile the Bonfire-CPU from source for every test, it is best to use GHDL with the "mcode" backend. 
Compilation with mcode is very fast (1-2 seconds ), so the time to run the whole suite is reasonable. 
GHDL must be found in the path. 


### RISC-V Toolchain e.g. [https://github.com/riscv/riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain)
There are different possiblties to get a RISC-V toolchain. Aside from building from source, also precompiled toolchains work, also [GNU RISC-V Embedded GCC ] (https://xpack.github.io/riscv-none-embed-gcc/install/).

However, the RISC-V toolchain must be found by the compliance suite. The envrionment variable RISCV_PREFIX defines the prefix (with our without path...) for invoking gcc and other tools from the chain. 

### The bonfire-cpu VHDL sources
By default the bonfire-cpu source is autmatically fetched from Github [https://github.com/bonfireprocessor/bonfire-cpu](https://github.com/bonfireprocessor/bonfire-cpu), using the "compliance" branch in the Bonfire-CPU repo. 
This can be overwritten by passing a different directory with the parameter BONFIRE_CORESROOT.


If all prerequistes are met, the Tests can be invoked with 

    make RISCV_TARGET=bonfire

This will automatically fetch the latest bonfire-cpu from GitHub and run the following test suites:

    rv32i rv32im rv32Zicsr rv32Zifencei

### Supported parameters:

In addtition to the standard parameters of the RISCV Compliance suite the following parameters are supported:


| Parameter | Description  |
|-----------|--------------|
|BONFIRE_CORESROOT| Set the --cores-root directory for FuseSoC. Use it, to run the suite on a local source code|
|BONFIRE_CONF | Allow to pass generics to FuseSoC/ GHDL. |

For a list of supported generics in BONFIRE_CONF invoke

    fusesoc --cores-root=riscv-target/bonfire/device/rv32i core-info bonfire-cpu


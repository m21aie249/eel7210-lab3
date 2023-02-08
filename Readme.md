Project name: Complex Design in SystemC
===========================================================================================================================
This branch implements Lab3 Item (a): Implement a memory of 8KB, connect it to the bus and simulate “load” and “store” instructions.

To run, execute the following commands on the system prompt, modify the SystemC folder locations as applicable:

(Code uses -std=c++11, will not work with -std=c++98) 

Compile:
g++ -std=c++11 -I. -o sim_design main.cpp -I$SYSTEMC_HOME/include -L$SYSTEMC_HOME/lib -lsystemc -lm

Run:    
./sim_design

=========================================================================================================================

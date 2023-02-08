Project name: Complex Design in SystemC
===========================================================================================================================
This branch implements Lab3 Item (b): By writing a testbench, simulate a real algorithm on an accelerator (by writing any one accelerator code in C++ e.g- FFT, FIR, RSA) etc.

This branch demonstrates RSA code present in the original database

To run, execute the following commands on the system prompt, modify the SystemC folder locations as applicable:

(Code uses -std=c++11, will not work with -std=c++98) 

Change directory:
cd rsa

Compile:
g++ -std=c++11 -I. -o sim_rsa tb_rsa.cpp main.cpp rsa.cpp -I$SYSTEMC_HOME/include -L$SYSTEMC_HOME/lib -lsystemc -lm

Run:    
./sim_rsa

=========================================================================================================================

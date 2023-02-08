/*
 * @ASCK
 * M21AIE249: Modified for Item (a)
 */

#include <systemc.h>

SC_MODULE (IR) {
 
    sc_in <sc_uint<14>> addr; 
    sc_out <sc_uint<20>> inst;


    /*
    ** module global variables 
    */

    sc_uint<20> mem[819]; // 819 rows and 819*20=16380 bits = (16KB - 4bits) ~= 16KB

    int instNum = 22;
    sc_uint<20> instruction[22] = {
     // 0b01234567890123456789
        0b00000000000000000000,
        0b00100000000000000111,  // transfer (r0 <- 7): 7
        0b00010010010000000000,  // inc (r1++): 1

        //stall for achieving the correct register data - sub
        0b11110000000000000000, //stall
        0b11110000000000000000, //stall
        0b11110000000000000000, //stall

        0b01010000000000000101, // stroe (mem[5] <= r0) : 7
        0b01001010000000000101, // load  (r5 <= mem[5]) : 7

        0b11110000000000000000, //nop
        0b11110000000000000000, //nop
        0b11110000000000000000, //nop
   };

    SC_CTOR (IR){
        SC_METHOD (process);
        sensitive << addr;

        for(int i=0; i<instNum; i++){
            mem[i] = instruction[i];
        }

        // filling out other rows with a nop opcode
        for(int i=instNum; i<819; i++){
            mem[i] = 0b11110000000000000000;
        }
    }
    
    void process () {
        if(addr.read() < 819){
            inst.write(mem[addr.read()]);
        }
        else{
            inst.write(0);
        }
    }
    
    
};
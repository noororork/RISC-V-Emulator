// assembler.cpp    
// Takes parsed instructions then assembles them into binary machine code

#include "../include/memory.h"
#include "../include/parser.h"
#include "../include/registers.h"
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Assembler{
    private:
        map<string, uint8_t> opcodes = {{"lw", 0b0000011}, {"sw", 0b0100011}};
        Registers r;

    public:
        void assemble(string op, string arg1, string arg2){
            uint8_t rd = r.getRegVal(arg1);
            // next is to sort out encoding types and parsing arg2
        }
};
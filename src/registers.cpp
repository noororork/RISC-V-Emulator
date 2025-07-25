// registers.cpp
// Declares registers

#include "../include/memory.h"
#include "../include/parser.h"
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <utility> // For pair type
using namespace std;

class Registers{
    private:
        pair<string, uint32_t> regs[32];

    public:
        Registers(){
            regs[0] = {"zero", 0};
            regs[1] = {"ra", 0};
            regs[2] = {"sp", 0};
            regs[3] = {"gp", 0};
            regs[4] = {"tp", 0};
            regs[5] = {"t0", 0};
            regs[6] = {"t1", 0};
            regs[7] = {"t2", 0};
            regs[8] = {"s0", 0};
            regs[9] = {"s1", 0};
            regs[10] = {"a0", 0};
            regs[11] = {"a1", 0};
            regs[12] = {"a2", 0};
            regs[13] = {"a3", 0};
            regs[14] = {"a4", 0};
            regs[15] = {"a5", 0};
            regs[16] = {"a6", 0};
            regs[17] = {"a7", 0};
            regs[18] = {"s2", 0};
            regs[19] = {"s3", 0};
            regs[20] = {"s4", 0};
            regs[21] = {"s5", 0};
            regs[22] = {"s6", 0};
            regs[23] = {"s7", 0};
            regs[24] = {"s8", 0};
            regs[25] = {"s9", 0};
            regs[26] = {"s10", 0};
            regs[27] = {"s11", 0};
            regs[28] = {"t3", 0};
            regs[29] = {"t4", 0};
            regs[30] = {"t5", 0};
            regs[31] = {"t6", 0};
        }
        int getRegVal(const string& regName){ // Using pass-by ref doesn't copy data so faster and const means no mutation
            int index = 0;
            for(const auto& pair : regs){ // Auto is unspecified type
                if(pair.first == regName){
                    return index;
                }
            }
            index++;
        }

};

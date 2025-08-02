// i_imm.cpp
// executes i immediate type instructions

#include "instructions/i_imm.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

string I_imm::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint8_t imm11_0, uint8_t imm5_11){
    string instructionName;
    if (func3 == 0x5){
        if (imm5_11 == 0x00){
            instructionName = "srli";
        }else if (imm5_11 == 0x20){
            instructionName = "srai";
        }else{
            cerr << "Invalid instruction\n";
        }
    }else {
        instructionName = iImmInstructions.at(func3);
    }
    return instructionName;
}

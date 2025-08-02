// b.cpp
// executes b type instructions

#include "instructions/b.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

string B::findInstruction(uint8_t imm11, uint8_t imm4_1, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t imm10_5, uint8_t imm12){
    string instructionName;
    instructionName = bInstructions.at(func3);
    return instructionName;
}
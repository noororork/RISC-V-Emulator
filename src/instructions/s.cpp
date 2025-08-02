// s.cpp
// executes s type instructions

#include "instructions/s.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

string S::findInstruction(uint8_t imm4_0, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t imm11_5){
    string instructionName;
    instructionName = sInstructions.at(func3);
    return instructionName;
}
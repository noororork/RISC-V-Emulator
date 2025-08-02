// i.cpp
// executes i type instructions

#include "instructions/i.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

string I::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint8_t imm11_0){
    string instructionName;
    instructionName = iInstructions.at(func3);
    return instructionName;
}

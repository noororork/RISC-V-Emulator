// i.cpp
// executes i type instructions

#include "instructions/i.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

I::I(){
    // Constructor to initialise map
    iInstructions = {
        {{0x0, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_lb(rd, rs1, rs2); }}, 
        {0x1, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_lh(rd, rs1, rs2); }}, 
        {0x2, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_lw(rd, rs1, rs2); }}, 
        {0x4, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_lbu(rd, rs1, rs2); }}, 
        {0x5, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_lhu(rd, rs1, rs2); }}
        }
    };
}

void I::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint8_t imm11_0){
    iInstructions.at(func3);
}

// s.cpp
// executes s type instructions

#include "instructions/s.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

S::S()
    :registers(reg.getRegs()), // Registers must be initialised int he constructor as it is a reference
    // Constructor to initialise map
    sInstructions{
        {{0x0, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_sb(imm, rs1, rs2); }}, 
        {0x1, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_sh(imm, rs1, rs2); }}, 
        {0x2, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_sw(imm, rs1, rs2); }}
        }
    }
{}

int32_t S::findInstruction(uint8_t imm4_0, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t imm11_5){
    int32_t unsignedImm = (imm11_5 << 5) | imm4_0;
    int32_t imm = (static_cast<int32_t>(unsignedImm << 20)) >> 20; // Does left shift to become 32 bits then arithmetic right shift to sign extend
    offset = sInstructions.at(func3)(imm, rs1, rs2);
    return offset;
}

int32_t S::execute_sb(int32_t imm, uint8_t rs1, uint8_t rs2){
    uint32_t address = registers[rs1] + imm;
    memory.writeByte(address, rs2);
    return 4;
}

int32_t S::execute_sh(int32_t imm, uint8_t rs1, uint8_t rs2){
    uint32_t address = registers[rs1] + imm;
    memory.writeHalf(address, rs2);
    return 4;
}

int32_t S::execute_sw(int32_t imm, uint8_t rs1, uint8_t rs2){
    uint32_t address = registers[rs1] + imm;
    memory.writeWord(address, rs2);
    return 4;
}
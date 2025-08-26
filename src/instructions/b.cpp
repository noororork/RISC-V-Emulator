// b.cpp
// executes b type instructions

#include "instructions/b.h"
#include "cpu.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

B::B()
    :registers(reg.getRegs()),  // Registers must be initialised int he constructor as it is a reference
    // Constructor to initialise map
    bInstructions{
        {{0x0, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_beq(imm, rs1, rs2); }}, 
        {0x1, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_bne(imm, rs1, rs2); }}, 
        {0x4, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_blt(imm, rs1, rs2); }},
        {0x5, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_bge(imm, rs1, rs2); }},
        {0x6, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_bltu(imm, rs1, rs2); }},
        {0x7, [this](int32_t imm, uint8_t rs1, uint8_t rs2){return execute_bgeu(imm, rs1, rs2); }},
        }
    }
{}

int32_t B::findInstruction(uint8_t imm11, uint8_t imm4_1, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t imm10_5, uint8_t imm12){
    int32_t unsignedImm = ((imm12 << 12) | (imm11 << 11) | (imm10_5) << 5) | (imm4_1 << 1);
    int32_t imm = (static_cast<int32_t>(unsignedImm << 19)) >> 19; // Does left shift to become 32 bits then arithmetic right shift to sign extend
    offset = bInstructions.at(func3)(imm, rs1, rs2);
    return offset;
}

int32_t B::execute_beq(int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 == rs2){
        return imm;
    }
    return 4;
}

int32_t B::execute_bne(int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 != rs2){
        return imm;
    }
    return 4;
}

int32_t B::execute_blt(int32_t imm, uint8_t rs1, uint8_t rs2){
    int8_t signedRs1 = rs1;
    int8_t signedRs2 = rs2;
    if (signedRs1 < signedRs2){
        return imm;
    }
    return 4;
}

int32_t B::execute_bge(int32_t imm, uint8_t rs1, uint8_t rs2){
    int8_t signedRs1 = rs1;
    int8_t signedRs2 = rs2;
    if (signedRs1 >= signedRs2){
        return imm;
    }
    return 4;
}

int32_t B::execute_bltu(int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 < rs2){
        return imm;
    }
    return 4;
}

int32_t B::execute_bgeu(int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 >= rs2){
        return imm;
    }
    return 4;
}

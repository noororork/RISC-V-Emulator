// b.cpp
// executes b type instructions

#include "instructions/b.h"
#include "cpu.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

B::B()
    :registers(reg.getRegs()){  // Registers must be initialised int he constructor as it is a reference
    // Constructor to initialise map
    bInstructions = {
        {{0x0, [this](CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){execute_beq(cpu, imm, rs1, rs2); }}, 
        {0x1, [this](CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){execute_bne(cpu, imm, rs1, rs2); }}, 
        {0x4, [this](CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){execute_blt(cpu, imm, rs1, rs2); }},
        {0x5, [this](CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){execute_bge(cpu, imm, rs1, rs2); }},
        {0x6, [this](CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){execute_bltu(cpu, imm, rs1, rs2); }},
        {0x7, [this](CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){execute_bgeu(cpu, imm, rs1, rs2); }},
        }
    };
}

void B::findInstruction(uint8_t imm11, uint8_t imm4_1, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t imm10_5, uint8_t imm12){
    int32_t unsignedImm = ((imm12 << 12) | (imm11 << 11) | (imm10_5) << 5) | (imm4_1 << 1);
    int32_t imm = (static_cast<int32_t>(unsignedImm << 19)) >> 19; // Does left shift to become 32 bits then arithmetic right shift to sign extend
    bInstructions.at(func3);
}

void B::execute_beq(CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 == rs2){
        cpu.incrementPc(imm);
    }
}

void B::execute_bne(CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 != rs2){
        cpu.incrementPc(imm);
    }
}

void B::execute_blt(CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){
    int8_t signedRs1 = rs1;
    int8_t signedRs2 = rs2;
    if (signedRs1 < signedRs2){
        cpu.incrementPc(imm);
    }
}

void B::execute_bge(CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){
    int8_t signedRs1 = rs1;
    int8_t signedRs2 = rs2;
    if (signedRs1 >= signedRs2){
        cpu.incrementPc(imm);
    }
}

void B::execute_bltu(CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 < rs2){
        cpu.incrementPc(imm);
    }
}

void B::execute_bgeu(CPU& cpu, int32_t imm, uint8_t rs1, uint8_t rs2){
    if (rs1 >= rs2){
        cpu.incrementPc(imm);
    }
}

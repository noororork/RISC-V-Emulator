// i.cpp
// executes i type instructions

#include "instructions/i.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

I::I()
    :registers(reg.getRegs()){  // Registers must be initialised int he constructor as it is a reference
    // Constructor to initialise map
    iInstructions = {
        {{0x0, [this](uint8_t rd, uint8_t rs1, uint16_t imm){execute_lb(rd, rs1, imm); }}, 
        {0x1, [this](uint8_t rd, uint8_t rs1, uint16_t imm){execute_lh(rd, rs1, imm); }}, 
        {0x2, [this](uint8_t rd, uint8_t rs1, uint16_t imm){execute_lw(rd, rs1, imm); }}, 
        {0x4, [this](uint8_t rd, uint8_t rs1, uint16_t imm){execute_lbu(rd, rs1, imm); }}, 
        {0x5, [this](uint8_t rd, uint8_t rs1, uint16_t imm){execute_lhu(rd, rs1, imm); }}
        }
    };
}

void I::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint16_t imm){
    iInstructions.at(func3);
}

void I::execute_lb(uint8_t rd, uint8_t rs1, uint16_t imm){
    uint32_t address = registers[rs1] + imm;
    int8_t byte = memory.readByte(address);
    int32_t extended_byte = byte; // Sign-extended
    registers[rd] = extended_byte;
}

void I::execute_lh(uint8_t rd, uint8_t rs1, uint16_t imm){
    uint32_t address = registers[rs1] + imm;
    int16_t half = memory.readHalf(address);
    int32_t extended_half = half; // Sign-extended
    registers[rd] = extended_half;
}

void I::execute_lw(uint8_t rd, uint8_t rs1, uint16_t imm){
    uint32_t address = registers[rs1] + imm;
    int32_t word = memory.readWord(address);
    registers[rd] = word;
}

void I::execute_lbu(uint8_t rd, uint8_t rs1, uint16_t imm){
    uint32_t address = registers[rs1] + imm;
    uint8_t byte = static_cast<int8_t>(memory.readByte(address));
    uint32_t extended_byte = byte; // Zero-extended
    registers[rd] = extended_byte;
}

void I::execute_lhu(uint8_t rd, uint8_t rs1, uint16_t imm){
    uint32_t address = registers[rs1] + imm;
    uint16_t half = static_cast<int8_t>(memory.readHalf(address));
    uint32_t extended_half = half; // Zero-extended
    registers[rd] = extended_half;
}

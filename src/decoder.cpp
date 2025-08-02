// Decoder.cpp
// Instructions are passed into here from cpu.cpp and decoded

#include "decoder.h"
#include <string>
#include <iostream>
#include <bitset>
using namespace std;

void Decoder::decode(uint32_t& instruction){
    // Decoding instruction from 32-bits into each component
    string encodingType = getEncodingType(instruction);
    cout << encodingType << "\n";
    string instructionName;
    if ((encodingType == "r") || (encodingType == "i-imm") || (encodingType == "i") || (encodingType == "s") || (encodingType == "b")){
        uint8_t func3 = getFunc3(instruction);
        uint8_t rs1 = getRs1(instruction);

        // Decoding r-type instructions
        if (encodingType == "r"){
            uint8_t func7 = getFunc7(instruction);
            uint8_t rd = getRd(instruction);
            uint8_t rs2 = getRs2(instruction);
            r.findInstruction(rd, func3, rs1, rs2, func7);

        // Decoding i-immediate-type instructions
        } else if (encodingType == "i-imm"){
            uint8_t imm5_11 = getFunc7(instruction);
            uint8_t rd = getRd(instruction);
            uint8_t imm11_0 = getImm11_0(instruction);
            i_imm.findInstruction(rd, func3, rs1, imm11_0, imm5_11);

        // Decoding i-type instructions
        } else if (encodingType == "i"){
            uint8_t rd = getRd(instruction);
            uint8_t imm11_0 = getImm11_0(instruction);
            i.findInstruction(rd, func3, rs1, imm11_0);

        // Decoding s-type instructions
        } else if (encodingType == "s"){
            uint8_t imm11_5 = getFunc7(instruction);
            uint8_t imm4_0 = getRd(instruction);
            uint8_t rs2 = getRs2(instruction);
            s.findInstruction(imm4_0, func3, rs1, rs2, imm11_5);

        // Decoding b-type instructions
        } else if (encodingType == "b"){
            uint8_t rs2 = getRs2(instruction);
            uint8_t imm12 = getImm12(instruction);
            uint8_t imm10_5 = getImm10_5(instruction);
            uint8_t imm11 = getImm11(instruction);
            uint8_t imm4_1 = getImm4_1(instruction);
            b.findInstruction(imm11, imm4_1, func3, rs1, rs2, imm10_5, imm12);
        }
    }else{
        cout << "nono" << "\n";
    }
}

string Decoder::getEncodingType(uint32_t instruction){
    // Extracting 7 bits for opcode [6:0]
    string encodingType = "\0";
    uint8_t opcode = ((1 << 7) - 1) & instruction; // Extracts opcodes

    if (opcodes.count(opcode)) {
        encodingType = opcodes.at(opcode);
    } else {
        std::cerr << "Unknown opcode: " << opcode << '\n';
    // handle error or assign a default
    }
    return encodingType;
}

uint8_t Decoder::getFunc3(uint32_t instruction){
    // Extracting 3 bits for func3 [14:12]
    instruction = instruction >> 12;
    uint8_t func3 = ((1 << 3) - 1) & instruction;
    return func3;
}

uint8_t Decoder::getRs1(uint32_t instruction){
    // Extracting 5 bits for rs1 [19:15]
    instruction = instruction >> 15;
    uint8_t rs1 = ((1 << 5) - 1) & instruction;
    return rs1;
}

uint8_t Decoder::getFunc7(uint32_t instruction){
    // Extracting 7 bits for func7 [31:25]
    instruction = instruction >> 25;
    uint8_t func7 = ((1 << 7) - 1) & instruction;
    return func7;
}

uint8_t Decoder::getRd(uint32_t instruction){
    // Extracting 5 bits for destination register [11:7]
    instruction = instruction >> 7;
    uint8_t rd = ((1 << 5) - 1) & instruction;
    return rd;
}

uint8_t Decoder::getRs2(uint32_t instruction){
    // Extracting 5 bits for rs1 [24:20]
    instruction = instruction >> 20;
    uint8_t rs2 = ((1 << 5) - 1) & instruction;
    return rs2;
}

uint8_t Decoder::getImm12(uint32_t instruction){
    // Extracting 1 bit for imm[12] [31]
    instruction = instruction >> 30;
    uint8_t imm12 = ((1 << 1) - 1) & instruction;
    return imm12;
}

uint8_t Decoder::getImm10_5(uint32_t instruction){
    // Extracting 6 bits for imm[10:5] [30:25]
    instruction = instruction >> 25;
    uint8_t imm10_5 = ((1 << 6) - 1) & instruction;
    return imm10_5;
}

uint8_t Decoder::getImm11(uint32_t instruction){
    // Extracting 1 bit for imm[11] [7]
    instruction = instruction >> 7;
    uint8_t imm11 = ((1 << 1) - 1) & instruction;
    return imm11;
}

uint8_t Decoder::getImm4_1(uint32_t instruction){
    // Extracting 5 bits for imm[4:1] [11:8]
    instruction = instruction >> 8;
    uint8_t imm4_1 = ((1 << 4) - 1) & instruction;
    return imm4_1;
}

uint8_t Decoder::getImm11_0(uint32_t instruction){
    // Extracting 12 bits for imm[11:0] [31:20]
    instruction = instruction >> 20;
    uint8_t imm11_0 = ((1 << 12) - 1) & instruction;
    return imm11_0;
}
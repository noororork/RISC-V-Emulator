// Decoder.cpp
// Instructions are passed into here from cpu and decoded

#include "../include/decoder.h"

void Decoder::decode(uint32_t instruction){
    char encodingType = getEncodingType(instruction, 7);
}

char Decoder::getEncodingType(uint32_t instruction, int bits){
    // Extracting 7 bits for opcode
    unsigned int opcode = ((1 << bits) - 1) & instruction; // Extracts opcodes
    char encodingType = opcodes.at(opcode);
    return encodingType;
}


// Decoder.cpp
// Instructions are passed into here from cpu and decoded
// Currently not decoding immediates

#include "../include/decoder.h"
#include <string>
#include <iostream>
#include <bitset>
using namespace std;

void Decoder::decode(uint32_t& instruction){
    char encodingType = getEncodingType(instruction);
    cout << encodingType << "\n";
    string instructionName;
    if ((encodingType == 'r') || (encodingType == 'i') || (encodingType == 's') || (encodingType == 'b')){
        uint8_t func3 = getFunc3(instruction);

        // Using ifelse instead of switch for flexibilty when introducing more types in the future- eg imm types
        if (encodingType == 'r'){
            uint8_t func7 = getFunc7(instruction);
            instructionName = findInstructionR(func7, func3);

        } else if (encodingType == 'i'){
            uint8_t imm511 = getImm511(instruction);
            instructionName = findInstructionR(imm511, func3);

        } else if (encodingType == 's'){
            uint8_t func7 = getFunc7(instruction);
            //findInstructionR(func7);

        } else if (encodingType == 'b'){
            uint8_t func7 = getFunc7(instruction);
            //findInstructionR(func7);
        } 
        //uint8_t rs1 = getRs1(instruction);
    }else{
        cout << "nono" << "\n";
    }
}

char Decoder::getEncodingType(uint32_t instruction){
    // Extracting 7 bits for opcode
    char encodingType = '\0';
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
    // Extracting 3 bits for func3
    instruction = instruction >> 12;
    uint8_t func3 = ((1 << 3) - 1) & instruction;
    return func3;
}

uint8_t Decoder::getFunc7(uint32_t instruction){
    // Extracting 7 bits for func7
    instruction = instruction >> 25;
    uint8_t func7 = ((1 << 7) - 1) & instruction;
    return func7;
}

uint8_t Decoder::getImm511(uint32_t instruction){
    // Extracting 7 bits for imm[11:5]
    instruction = instruction >> 25;
    uint8_t func7 = ((1 << 7) - 1) & instruction;
    return func7;
}

string Decoder::findInstructionR(uint8_t func7, uint8_t func3){
    string instructionName;
    if (func3 == 0x0){
        if (func7 == 0x00){
            instructionName = "add";
        }else if (func7 == 0x20){
            instructionName = "sub";
        }else{
            cerr << "Invalid instruction\n";
        }
    }else if (func3 == 0x5){
        if (func7 == 0x00){
            instructionName = "srl";
        }else if (func7 == 0x20){
            instructionName = "sra";
        }else{
            cerr << "Invalid instruction\n";
        }
    }else {
        instructionName = rInstructions.at(func3);
    }
    return instructionName;
}

string Decoder::findInstructionI(uint8_t imm511, uint8_t func3){

}


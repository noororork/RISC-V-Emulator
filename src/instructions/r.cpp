// r.cpp
// executes r type instructions

#include "instructions/r.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

string R::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t func7){
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
    cout << instructionName << "\n";
    return instructionName;
}
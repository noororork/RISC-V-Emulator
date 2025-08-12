// r.cpp
// executes r type instructions

#include "instructions/r.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

R::R(){
    // Constructor to initialise map
    rInstructions = {
        {{0x4, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_xor(rd, rs1, rs2); }}, 
        {0x6, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_or(rd, rs1, rs2); }}, 
        {0x7, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_and(rd, rs1, rs2); }}, 
        {0x2, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_slt(rd, rs1, rs2); }}, 
        {0x3, [this](uint8_t rd, uint8_t rs1, uint8_t rs2){execute_sltu(rd, rs1, rs2); }}
        }
    };
}

void R::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint8_t rs2, uint8_t func7){
    if (func3 == 0x0){
        if (func7 == 0x00){
            execute_add(rd, rs1, rs2);
        }else if (func7 == 0x20){
            execute_sub(rd, rs1, rs2);
        }else{
            cerr << "Invalid instruction\n";
        }
    }else if (func3 == 0x5){
        if (func7 == 0x00){
            execute_srl(rd, rs1, rs2);;
        }else if (func7 == 0x20){
            execute_sra(rd, rs1, rs2);;
        }else{
            cerr << "Invalid instruction\n";
        }
    }else {
        rInstructions.at(func3);
    }
}

void R::execute_add(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "add\n";
}

void R::execute_sub(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "sub\n";
}

void R::execute_srl(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "srl\n";
}

void R::execute_sra(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "sra\n";
}

void R::execute_xor(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "xor\n";
}

void R::execute_or(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "or\n";
}

void R::execute_and(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "and\n";
}

void R::execute_sll(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "sll\n";
}

void R::execute_slt(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "slt\n";
}

void R::execute_sltu(uint8_t rd, uint8_t rs1, uint8_t rs2){
    cout << "sltu\n";
}
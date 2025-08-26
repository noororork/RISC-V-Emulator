// i_imm.cpp
// executes i immediate type instructions

#include "instructions/i_imm.h"
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

I_imm::I_imm()
    :registers(reg.getRegs()),  // Registers must be initialised in the constructor as it is a reference
    // Constructor to initialise map
    i_immInstructions{
        {{0x0, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_addi(rd, rs1, imm11_0); }}, 
        {0x4, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_xori(rd, rs1, imm11_0); }}, 
        {0x6, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_ori(rd, rs1, imm11_0); }}, 
        {0x7, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_andi(rd, rs1, imm11_0); }}, 
        {0x1, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_slli(rd, rs1, imm11_0); }},
        {0x2, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_slti(rd, rs1, imm11_0); }},
        {0x3, [this](uint8_t rd, uint8_t rs1, uint16_t imm11_0){return execute_sltiu(rd, rs1, imm11_0); }}
        }
    }
{}

int32_t I_imm::findInstruction(uint8_t rd, uint8_t func3, uint8_t rs1, uint16_t imm11_0, uint8_t imm5_11, uint8_t imm0_4){
    if (func3 == 0x5){
        if (imm5_11 == 0x00){
            offset = execute_srli(rd, rs1, imm0_4);
        }else if (imm5_11 == 0x20){
            offset = execute_srai(rd, rs1, imm0_4);
        }else{
            cerr << "Invalid instruction\n";
        }
    }else if ((func3 == 0x1) && (imm5_11 == 0x00)){
        offset = execute_slli(rd, rs1, imm0_4);
    }else{
        offset = i_immInstructions.at(func3)(rd, rs1, imm11_0);
    }
    return offset;
}

int32_t I_imm::execute_addi(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "add\n";
    registers[rd] = registers[rs1] + registers[imm];
    return 4;
}

int32_t I_imm::execute_subi(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "sub\n";
    registers[rd] = registers[rs1] - registers[imm];
    return 4;
}

int32_t I_imm::execute_srli(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "srli\n";
    registers[rd] = registers[rs1] >> registers[imm];
    return 4;
}

int32_t I_imm::execute_srai(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "srai\n";
    int8_t signed_rs1 = static_cast<int8_t>(registers[rs1]); // Casts it to a signed type for sign extension
    registers[rd] = signed_rs1 >> registers[imm]; 
    return 4;
}

int32_t I_imm::execute_xori(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "xori\n";
    registers[rd] = registers[rs1] ^ registers[imm];
    return 4;
}

int32_t I_imm::execute_ori(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "ori\n";
    registers[rd] = registers[rs1] | registers[imm];
    return 4;
}

int32_t I_imm::execute_andi(uint8_t rd, uint8_t rs1, uint16_t imm){
    cout << "andi\n";
    registers[rd] = registers[rs1] & registers[imm];
    return 4;
}

int32_t I_imm::execute_slli(uint8_t rd, uint8_t rs1, uint8_t imm){
    cout << "slli\n";
    registers[rd] = registers[rs1] << registers[imm];
    return 4;
}

int32_t I_imm::execute_slti(uint8_t rd, uint8_t rs1, uint8_t imm){
    cout << "slti\n";
    int8_t signed_rs1 = static_cast<int8_t>(registers[rs1]);
    int8_t signed_imm = static_cast<int8_t>(registers[imm]);
    if (signed_rs1 < signed_imm){
        registers[rd] = 1;
    }else{
        registers[rd] = 0;
    }
    return 4;
}

int32_t I_imm::execute_sltiu(uint8_t rd, uint8_t rs1, uint8_t imm){
    cout << "sltiu\n";
    if (registers[rs1] < registers[imm]){
        registers[rd] = 1;
    }else{
        registers[rd] = 0;
    }
    return 4;
}

#ifndef I_IMM_H
#define I_IMM_H

#include <cstdint>
#include <map>
#include <unordered_map>
#include <array>
#include <string>
#include <utility>
#include <any>
#include <functional>
#include "registers.h"

class I_imm{
    private:
        int32_t offset;
        using func = std::function<int32_t(uint8_t, uint8_t, uint16_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> i_immInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
    public:
        I_imm();
        int32_t findInstruction(uint8_t, uint8_t, uint8_t, uint16_t, uint8_t, uint8_t);
        int32_t execute_addi(uint8_t, uint8_t, uint16_t);
        int32_t execute_subi(uint8_t, uint8_t, uint16_t);
        int32_t execute_srli(uint8_t, uint8_t, uint16_t);
        int32_t execute_srai(uint8_t, uint8_t, uint16_t);
        int32_t execute_xori(uint8_t, uint8_t, uint16_t);
        int32_t execute_ori(uint8_t, uint8_t, uint16_t);
        int32_t execute_andi(uint8_t, uint8_t, uint16_t);
        int32_t execute_slli(uint8_t, uint8_t, uint8_t);
        int32_t execute_slti(uint8_t, uint8_t, uint8_t);
        int32_t execute_sltiu(uint8_t, uint8_t, uint8_t);
};

#endif
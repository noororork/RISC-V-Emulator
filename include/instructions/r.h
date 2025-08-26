#ifndef R_H
#define R_H

#include <cstdint>
#include <map>
#include <unordered_map>
#include <array>
#include <string>
#include <utility>
#include <any>
#include <functional>
#include "registers.h"

class R{
    private:
        int32_t offset;
        using func = std::function<int32_t(uint8_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> rInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;

    public:
        R();
        int32_t findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        int32_t execute_add(uint8_t, uint8_t, uint8_t);
        int32_t execute_sub(uint8_t, uint8_t, uint8_t);
        int32_t execute_srl(uint8_t, uint8_t, uint8_t);
        int32_t execute_sra(uint8_t, uint8_t, uint8_t);
        int32_t execute_xor(uint8_t, uint8_t, uint8_t);
        int32_t execute_or(uint8_t, uint8_t, uint8_t);
        int32_t execute_and(uint8_t, uint8_t, uint8_t);
        int32_t execute_sll(uint8_t, uint8_t, uint8_t);
        int32_t execute_slt(uint8_t, uint8_t, uint8_t);
        int32_t execute_sltu(uint8_t, uint8_t, uint8_t);
};

#endif
#ifndef I_H
#define I_H

#include <cstdint>
#include <map>
#include <unordered_map>
#include <array>
#include <string>
#include <utility>
#include <any>
#include <functional>
#include "registers.h"
#include "memory.h"

class I{
    private:
        int32_t offset;
        using func = std::function<int32_t(uint8_t, uint8_t, uint16_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> iInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
        Memory memory;

    public:
        I();
        int32_t findInstruction(uint8_t, uint8_t, uint8_t, uint16_t);
        int32_t execute_lb(uint8_t, uint8_t, uint16_t);
        int32_t execute_lh(uint8_t, uint8_t, uint16_t);
        int32_t execute_lw(uint8_t, uint8_t, uint16_t);
        int32_t execute_lbu(uint8_t, uint8_t, uint16_t);
        int32_t execute_lhu(uint8_t, uint8_t, uint16_t);
};

#endif
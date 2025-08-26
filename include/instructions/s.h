#ifndef S_H
#define S_H

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

class S{
    private:
        int32_t offset;
        using func = std::function<int32_t(int32_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> sInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
        Memory memory;

    public:
        S();
        int32_t findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        int32_t execute_sb(int32_t, uint8_t, uint8_t);
        int32_t execute_sh(int32_t, uint8_t, uint8_t);
        int32_t execute_sw(int32_t, uint8_t, uint8_t);
};

#endif
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
        using func = std::function<void(uint16_t, uint8_t, uint16_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> sInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
        Memory memory;

    public:
        S();
        void findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        void execute_sb(uint16_t, uint8_t, uint8_t);
        void execute_sh(uint16_t, uint8_t, uint8_t);
        void execute_sw(uint16_t, uint8_t, uint8_t);
};

#endif
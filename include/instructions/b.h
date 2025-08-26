#ifndef B_H
#define B_H

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

class B{
    private:
        using func = std::function<void(int32_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> bInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
        Memory memory;

    public:
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        void execute_beq(int32_t, uint8_t, uint8_t);
        void execute_bne(int32_t, uint8_t, uint8_t);
        void execute_blt(int32_t, uint8_t, uint8_t);
        void execute_bge(int32_t, uint8_t, uint8_t);
        void execute_bltu(int32_t, uint8_t, uint8_t);
        void execute_bgeu(int32_t, uint8_t, uint8_t);
};

#endif
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

class CPU; // Forward declaration prevents circular includes 

class B{
    private:
        int32_t offset;
        using func = std::function<int32_t(int32_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> bInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
        Memory memory;

    public:
        B();
        int32_t findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        int32_t execute_beq(int32_t, uint8_t, uint8_t);
        int32_t execute_bne(int32_t, uint8_t, uint8_t);
        int32_t execute_blt(int32_t, uint8_t, uint8_t);
        int32_t execute_bge(int32_t, uint8_t, uint8_t);
        int32_t execute_bltu(int32_t, uint8_t, uint8_t);
        int32_t execute_bgeu(int32_t, uint8_t, uint8_t);
};

#endif
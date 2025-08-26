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
        using func = std::function<void(CPU&, int32_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> bInstructions;
        Registers reg;
        std::array<uint32_t, 32>& registers;
        Memory memory;

    public:
        B();
        void findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        void execute_beq(CPU&, int32_t, uint8_t, uint8_t);
        void execute_bne(CPU&, int32_t, uint8_t, uint8_t);
        void execute_blt(CPU&, int32_t, uint8_t, uint8_t);
        void execute_bge(CPU&, int32_t, uint8_t, uint8_t);
        void execute_bltu(CPU&, int32_t, uint8_t, uint8_t);
        void execute_bgeu(CPU&, int32_t, uint8_t, uint8_t);
};

#endif
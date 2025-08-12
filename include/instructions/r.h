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
        using func = std::function<void(uint8_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> rInstructions;
        Registers reg;
        std::array<uint8_t, 32>& registers = reg.getRegs();

    public:
        R();
        void findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        void execute_add(uint8_t, uint8_t, uint8_t);
        void execute_sub(uint8_t, uint8_t, uint8_t);
        void execute_srl(uint8_t, uint8_t, uint8_t);
        void execute_sra(uint8_t, uint8_t, uint8_t);
        void execute_xor(uint8_t, uint8_t, uint8_t);
        void execute_or(uint8_t, uint8_t, uint8_t);
        void execute_and(uint8_t, uint8_t, uint8_t);
        void execute_sll(uint8_t, uint8_t, uint8_t);
        void execute_slt(uint8_t, uint8_t, uint8_t);
        void execute_sltu(uint8_t, uint8_t, uint8_t);
};

#endif
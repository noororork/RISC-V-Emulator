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

class I{
    private:
        using func = std::function<void(uint8_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> iInstructions;
        Registers reg;
        std::array<uint8_t, 32>& registers = reg.getRegs();

    public:
        void findInstruction(uint8_t, uint8_t, uint8_t, uint8_t);
        void execute_lb(uint8_t, uint8_t, uint8_t);
        void execute_lh(uint8_t, uint8_t, uint8_t);
        void execute_lw(uint8_t, uint8_t, uint8_t);
        void execute_lbu(uint8_t, uint8_t, uint8_t);
        void execute_lhu(uint8_t, uint8_t, uint8_t);
};

#endif
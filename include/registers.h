#ifndef REGISTERS_H
#define REGISTERS_H

#include <string>
#include <utility> // For pair type
#include <cstdint>
#include <array>

class Registers{
    private:
        std::array<uint32_t, 32> regs;

    public:
        std::array<uint32_t, 32>& getRegs();
};

#endif
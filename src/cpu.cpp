// cpu.cpp
// holds registers and the pc

#include "../include/emulator.h"
#include <cstdint>

class CPU{
    private:
        uint32_t regs[32];
        uint32_t pc;
};
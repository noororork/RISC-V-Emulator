// cpu.cpp
// Holds registers and the pc and simulates Fetch Execute

#include "../include/emulator.h"
#include <vector>
#include <cstdint>
using namespace std;

class CPU{
    private:
        uint32_t regs[32];
        uint32_t pc;   
};
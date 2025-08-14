// registers.cpp
// Declares registers

#include "registers.h"
#include <cstdint>
#include <vector>
#include <array>
#include <string>
#include <iostream>
using namespace std;


array<uint32_t, 32>& Registers::getRegs(){ // Using pass-by ref doesn't copy data so faster and const means no mutation
    return regs;
}



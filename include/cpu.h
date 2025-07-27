#ifndef CPU_H
#define CPU_H
#include "../include/memory.h"
#include <string>

class CPU{
    private:
        uint32_t pc;
        Memory memory;
    public:
        int loadProgram(std::string fileName);  
};

#endif
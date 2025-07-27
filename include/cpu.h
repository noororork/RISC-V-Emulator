#ifndef CPU_H
#define CPU_H
#include "../include/memory.h"
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

class CPU{
    private:
        Memory memory;
        std::vector<uint8_t> mem = memory.getMemory();
    public:
        void loadProgram(std::string);
        void initalisePC(std::vector<uint8_t>);
        void fetchInstruction(std::vector<uint8_t>);
};

#endif
#ifndef CPU_H
#define CPU_H

#include "memory.h"
#include "decoder.h"
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

class CPU{
    private:
        bool running = true;
        Memory memory;
        std::vector<uint8_t>& memVec = memory.getMemory(); // & ensures that memVec is a reference and not a copy- so when memory updates memVec points to the new vector
        Decoder decoder;

    public:
        void loadProgram(std::string);
        void initalisePC(std::vector<uint8_t>&);
        void fetchInstruction(std::vector<uint8_t>&, uint32_t);
};

#endif
// memory.cpp
// Defines memory structure

#include "memory.h"
#include <cstdint>
#include <vector>
using namespace std;

Memory::Memory(): memory(MEMORY_SIZE) {}  // Constructor

vector<uint8_t>& Memory::getMemory(){
    return memory;
}

int8_t Memory::readByte(uint32_t address){
    return memory[address];
}

int16_t Memory::readHalf(uint32_t address){
    return memory[address + 1] << 8 | memory[address];
}

int32_t Memory::readWord(uint32_t address){
    return memory[address + 3] << 24 | memory[address + 2] << 16 | memory[address + 1] << 8 | memory[address];
}

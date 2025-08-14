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
    return memory[]
}

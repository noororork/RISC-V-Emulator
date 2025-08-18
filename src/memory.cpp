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

void Memory::writeByte(uint32_t address, uint8_t rs2){
    memory[address] = rs2;
}

void Memory::writeHalf(uint32_t address, uint16_t rs2){
    uint8_t byte1 = rs2 & 0xFF;
    uint8_t byte2 = (rs2 >> 8) & 0xFF;
    memory[address] = byte1;
    memory[address + 1] = byte2;
}

void Memory::writeWord(uint32_t address, uint32_t rs2){
    uint8_t byte1 = rs2 & 0xFF;
    uint8_t byte2 = (rs2 >> 8) & 0xFF;
    uint8_t byte3 = (rs2 >> 16) & 0xFF;
    uint8_t byte4 = (rs2 >> 24) & 0xFF;
    memory[address] = byte1;
    memory[address + 1] = byte2;
    memory[address + 2] = byte3;
    memory[address + 3] = byte4;
}

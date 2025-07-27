// memory.cpp
// Defines memory structure

#include "../include/memory.h"
#include <cstdint>
#include <vector>
using namespace std;


Memory::Memory(): memory(MEMORY_SIZE) {}  // Constructor

vector<uint8_t>& Memory::getMemory(){
    return memory;
}

// assembler.cpp    
// Takes parsed instructions then assembles them into binary machine code

#include "../include/memory.h"
#include "../include/parser.h"
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Assembler{
    private:
        map<string, uint8_t> opcodes = {{"lw", 0b0000011}, {"sw", 0b0100011}};
};
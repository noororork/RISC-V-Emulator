#ifndef B_H
#define B_H

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class B{
    private:
        std::map<uint8_t, std::string> bInstructions = {{0x0, "beq"}, {0x1, "bne"}, {0x4, "blt"}, {0x5, "bge"}, {0x6, "bltu"}, {0x7, "bgeu"}};

    public:
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
};

#endif
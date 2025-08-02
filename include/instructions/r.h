#ifndef R_H
#define R_H

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class R{
    private:
        std::map<uint8_t, std::string> rInstructions = {{0x4, "xor"}, {0x6, "or"}, {0x7, "and"}, {0x1, "sll"}, {0x2, "slt"}, {0x3, "sltu"}};

    public:
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);

};

#endif
#ifndef I_IMM_H
#define I_IMM_H

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class I_imm{
    private:
        std::map<uint8_t, std::string> iImmInstructions = {{0x0, "addi"}, {0x4, "xori"}, {0x6, "ori"}, {0x7, "andi"}, {0x1, "slli"}, {0x2, "slti"}, {0x3, "sltiu"}};

    public:
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
};

#endif
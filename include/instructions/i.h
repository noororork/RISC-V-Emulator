#ifndef I_H
#define I_H

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class I{
    private:
        std::map<uint8_t, std::string> iInstructions = {{0x0, "lb"}, {0x1, "lh"}, {0x2, "lw"}, {0x4, "lbu"}, {0x5, "lhu"}};

    public:
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t);
};

#endif
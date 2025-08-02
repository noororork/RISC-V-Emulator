#ifndef S_H
#define S_H

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class S{
    private:
        std::map<uint8_t, std::string> sInstructions = {{0x0, "sb"}, {0x1, "sh"}, {0x2, "sw"}};

    public:
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
};

#endif
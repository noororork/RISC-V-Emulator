#ifndef DECODER_H
#define DECODER_H

#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class Decoder{
    private:
        std::map<uint8_t, char> opcodes = {{0b0110011, 'r'}, {0b0010011, 'i'}, {0b0000011, 'i'}, {0b0100011, 's'}, {0b1100011, 'b'}};
        std::map<uint8_t, std::string> rInstructions = {{0x4, "xor"}, {0x6, "or"}, {0x7, "and"}, {0x1, "sll"}, {0x2, "slt"}, {0x3, "sltu"}};
    public:
        void decode(uint32_t&);
        char getEncodingType(uint32_t);
        uint8_t getFunc3(uint32_t);
        uint8_t getFunc7(uint32_t);
        uint8_t getRs1(uint32_t);
        std::string findInstructionR(uint8_t, uint8_t);
};

#endif

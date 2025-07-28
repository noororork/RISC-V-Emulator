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
        std::map<uint8_t, char> opcodes = {{0110011, 'r'}, {0010011, 'i'}, {0000011, 'i'}, {0100011, 's'}, {1100011, 'b'}};
    public:
        void decode(uint32_t);
        char getEncodingType(uint32_t, int);
};

#endif

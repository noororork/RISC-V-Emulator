#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>

class Memory{
    private:
        const size_t MEMORY_SIZE = 64 * 1024;  // size_t is safer than int to define uints since there is no overflow
        std::vector<uint8_t> memory;  // This shows there are 64 kilobytes of 8-bit memory

    public:
        Memory();
        std::vector<uint8_t>& getMemory();
};

#endif
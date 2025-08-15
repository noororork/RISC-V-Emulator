#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>
#include <cstddef> // For size_t

class Memory{
    private:
        static const size_t MEMORY_SIZE = 64 * 1024;  // size_t is safer than int to define uints since there is no overflow + static so it exists at compile time
        std::vector<uint8_t> memory;  // This shows there are 64 kilobytes of 8-bit memory

    public:
        Memory();
        std::vector<uint8_t>& getMemory();

        // Load instructions
        int8_t readByte(uint32_t);
        int16_t readHalf(uint32_t);
        int32_t readWord(uint32_t);

        // Store instructions
        void writeByte(uint32_t, uint8_t);
        void writeHalf(uint32_t, uint16_t);
        void writeWord(uint32_t, uint32_t);
};

#endif
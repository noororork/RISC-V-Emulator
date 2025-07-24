// memory.cpp
// Defines memory structure

#include <cstdint>
#include <vector>
using namespace std;

class Memory{
    private:
        const size_t MEMORY_SIZE = 64 * 1024;  // size_t is safer than int to define uints since there is no overflow
        vector<uint8_t> memory;  // This shows there are 64 kilobytes of 8-bit memory

    public:
        Memory(): memory(MEMORY_SIZE) {}  // Constructor
};
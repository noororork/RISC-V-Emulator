#ifndef REGISTERS_H
#define REGISTERS_H

#include <string>
#include <utility> // For pair type
#include <cstdint>

class Registers{
    private:
        private:
        std::pair<std::string, uint32_t> regs[32];
    public:
        Registers();
        int getRegVal(const std::string&);
};

#endif
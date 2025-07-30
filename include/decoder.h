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
        std::map<uint8_t, std::string> opcodes = {{0b0110011, "r"}, {0b0010011, "i-imm"}, {0b0000011, "i"}, {0b0100011, "s"}, {0b1100011, "b"}};
        std::map<uint8_t, std::string> rInstructions = {{0x4, "xor"}, {0x6, "or"}, {0x7, "and"}, {0x1, "sll"}, {0x2, "slt"}, {0x3, "sltu"}};
        std::map<uint8_t, std::string> iImmInstructions = {{0x0, "addi"}, {0x4, "xori"}, {0x6, "ori"}, {0x7, "andi"}, {0x1, "slli"}, {0x2, "slti"}, {0x3, "sltiu"}};
        std::map<uint8_t, std::string> iInstructions = {{0x0, "lb"}, {0x1, "lh"}, {0x2, "lw"}, {0x4, "lbu"}, {0x5, "lhu"}};
        std::map<uint8_t, std::string> sInstructions = {{0x0, "sb"}, {0x1, "sh"}, {0x2, "sw"}};
        std::map<uint8_t, std::string> bInstructions = {{0x0, "beq"}, {0x1, "bne"}, {0x4, "blt"}, {0x5, "bge"}, {0x6, "bltu"}, {0x7, "bgeu"}};
    public:
        void decode(uint32_t&);
        std::string getEncodingType(uint32_t);
        uint8_t getFunc3(uint32_t);
        uint8_t getFunc7(uint32_t);
        uint8_t getImm511(uint32_t);
        uint8_t getRs1(uint32_t);
        std::string findInstructionR(uint8_t, uint8_t);
        std::string findInstructionIImm(uint8_t, uint8_t);
        std::string findInstructionI(uint8_t);
        std::string findInstructionS(uint8_t);
        std::string findInstructionB(uint8_t);
};

#endif

#ifndef DECODER_H
#define DECODER_H

#include "instructions/r.h"
#include "instructions/i_imm.h"
#include "instructions/i.h"
#include "instructions/s.h"
#include "instructions/b.h"
#include <cstdint>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <any>

class Decoder{
    private:
        // Instruction type objects
        R r;
        I i;
        I_imm i_imm;
        S s;
        B b;
        std::map<uint8_t, std::string> opcodes = {{0b0110011, "r"}, {0b0010011, "i-imm"}, {0b0000011, "i"}, {0b0100011, "s"}, {0b1100011, "b"}};
        int32_t offset;

    public:
        int32_t decode(uint32_t&);
        std::string getEncodingType(uint32_t);
        uint8_t getFunc3(uint32_t);
        uint8_t getFunc7(uint32_t);
        uint8_t getRs1(uint32_t);
        uint8_t getRs2(uint32_t);
        uint8_t getRd(uint32_t);
        uint8_t getImm12(uint32_t);
        uint8_t getImm10_5(uint32_t);
        uint8_t getImm11(uint32_t);
        uint8_t getImm4_1(uint32_t);
        uint16_t getImm11_0(uint32_t);
        std::string findInstructionR(uint8_t, uint8_t);
        std::string findInstructionIImm(uint8_t, uint8_t);
        std::string findInstructionI(uint8_t);
        std::string findInstructionS(uint8_t);
        std::string findInstructionB(uint8_t);
};

#endif

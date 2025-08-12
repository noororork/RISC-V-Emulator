#ifndef R_H
#define R_H

#include <cstdint>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <any>
#include <functional>

class R{
    private:
        using func = std::function<void(uint8_t, uint8_t, uint8_t)>; //<returnType(params)>
        std::unordered_map<uint8_t, func> rInstructions;

    public:
        R();
        std::string findInstruction(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
        void execute_add(uint8_t, uint8_t, uint8_t);
        void execute_sub(uint8_t, uint8_t, uint8_t);
        void execute_srl(uint8_t, uint8_t, uint8_t);
        void execute_sra(uint8_t, uint8_t, uint8_t);
        void execute_xor(uint8_t, uint8_t, uint8_t);
        void execute_or(uint8_t, uint8_t, uint8_t);
        void execute_and(uint8_t, uint8_t, uint8_t);
        void execute_sll(uint8_t, uint8_t, uint8_t);
        void execute_slt(uint8_t, uint8_t, uint8_t);
        void execute_sltu(uint8_t, uint8_t, uint8_t);
};

#endif
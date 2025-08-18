// cpu.cpp
// Holds registers and the pc and simulates Fetch Execute

#include "cpu.h"
#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <fstream>  // File stream library
using namespace std;


void CPU::loadProgram(string fileName){ // CPU:: = Scope resolution operator- shows it belongs to CPU class
    // Finding the size of the file
    long size;
    ifstream binaryFile(fileName, ios::binary | ios::in);
    if (!binaryFile.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
    }
    binaryFile.seekg(0, ios::end); // Seekg allows us to find arbitrary position in file- in this case the end
    size = binaryFile.tellg();
    binaryFile.seekg(0, ios::beg); // 0 is offset
    // Read the bytes from the file into the memory vector, and case uint8_t* to char* as required by read()
    if (size > 1024 * 60){ // Leaving stack space
        binaryFile.read(reinterpret_cast<char*>(memVec.data()), size);
    } else{
        cerr << "File size is too large" << endl;
    }

    for (uint8_t byte : memVec) {
        if (byte != 0) {
            cout << static_cast<int>(byte) << "\n";
        }
    }
    initalisePC(memVec);
}

void CPU::initalisePC(vector<uint8_t>& memVec){
    uint32_t pc = 0x00000000;
    std::cout << pc << "\n";
    fetchInstruction(memVec, pc);
}

void CPU::fetchInstruction(vector<uint8_t>& memVec, uint32_t pc){
    // Arranging 4 bytes to make a word based on little-endianness : first address memVec[pc] is lsb
    while (running){
        if (pc + 3 > 60 * 1024){ // Leaving stack space
            break;
        }
        uint32_t instruction;
        instruction = memVec[pc] | memVec[pc + 1] << 8 | memVec[pc + 2] << 16 | memVec[pc + 3] << 24; 
        cout << instruction << "\n";
        decoder.decode(instruction);
        pc += 4; // Incrementing pc
    }
}

// cpu.cpp
// Holds registers and the pc and simulates Fetch Execute

#include "../include/cpu.h"
#include "../include/memory.h"
#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <fstream>  // File stream library
using namespace std;


int CPU::loadProgram(string fileName){ // CPU:: = Scope resolution operator- shows it belongs to CPU class
    vector<uint8_t> memVec = memory.getMemory();

    // Finding the size of the file
    long size;
    ifstream binary_file(fileName, ios::binary | ios::in);
    if (!binary_file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return 1;
    }
    binary_file.seekg(0, ios::end); // Seekg allows us to find arbitrary position in file- in this case the end
    size = binary_file.tellg();
    binary_file.seekg(0, ios::beg); // 0 is offset
    // Read the bytes from the file into the memory vector, and case uint8_t* to char* as required by read()
    binary_file.read(reinterpret_cast<char*>(memVec.data()), size);

    for (uint8_t byte : memVec) {
        if (byte != 0) {
            cout << static_cast<int>(byte) << "\n";
        }
    }
    return 0;
}

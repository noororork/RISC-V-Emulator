#include <ios>
#include <fstream>
#include "../include/cpu.h"

int main(){
    // This array represents raw bytes
    uint8_t rawData[] = { 0xB3, 0x02, 0xE3, 0x40 };

    // Open a file in binary write mode
    std::ofstream outFile("program.bin", std::ios::binary);

    // Write the raw bytes into the file
    outFile.write(reinterpret_cast<char*>(rawData), sizeof(rawData));

    outFile.close();
    CPU cpu;
    cpu.loadProgram("program.bin");
    return 0;
}
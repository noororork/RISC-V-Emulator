// cpu.cpp
// Holds registers and the pc and simulates Fetch Execute

#include "../include/memory.h"
#include "../include/parser.h"
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <fstream>  // File stream library
using namespace std;

class CPU{
    private:
        uint32_t pc;
        Memory memory;
        Parser parser;

    public:
        int loadProgram(string fileName){
            ifstream f(fileName);

            if(!f.is_open()){
                cerr << "Error opening file";
                return 0;
            }
            string s;
            while(getline(f,s)){
                parser.parse(s);
                return 1;
            }
        }
        
};
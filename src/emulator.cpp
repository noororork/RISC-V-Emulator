// emulator.cpp
// holds main program for running instructions

#include "../include/cpu.h"
#include "../include/memory.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>  // File stream library
using namespace std;

class Emulator{
    private: 
        CPU cpu;
        Memory memory;
    public:
        int loadProgram(string fileName){
            ifstream f(fileName);

            if(!f.is_open()){
                cerr << "Error opening file";
            }
            string s;
            while (getline(f,s)){
                parse(s);
            }
        }
        
};
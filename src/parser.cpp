// parser.cpp
// Parses lines that have been passed through and sends them to execute

#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype> // For isspace
using namespace std;

class Parser{
    public:
        void parse(string s){
            s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end()); // Removes whitespace
            
            istringstream iss(s);
            string op, arg1, arg2;
            iss >> op >> arg1 >> arg2; // Seperating line into address and operation
            
            arg1.erase(remove_if(arg1.begin(), arg1.end(), ','), arg1.end()); // Removes comma after first address
        }
};
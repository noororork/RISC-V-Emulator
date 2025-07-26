// parser.cpp
// Parses lines that have been passed through and sends them to execute

#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <cctype> // For isspace
using namespace std;

class Parser{
    private:
        map<string, char> encodingTypes = {{"lw", 'i'}, {"sw", 's'}};
    public:
        void parse(string s){
            s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end()); // Removes whitespace
            
            istringstream iss(s);
            string op;
            iss >> op; // Seperating operation

            char type = encodingTypes.at(op);
            seperate(s, type);
            
            //arg1.erase(remove_if(arg1.begin(), arg1.end(), ','), arg1.end()); // Removes comma after first address 
        }
        void seperate(string s, char type){
            istringstream iss(s);
            switch (type){
                case 'i': 
                    string op, arg
            }
        }
};
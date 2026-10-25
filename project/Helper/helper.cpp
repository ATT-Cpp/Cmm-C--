#include<iostream>
#include<vector>
#include<string>

class HelperFunctions { //add this to Helpers/helpers.h
    public:
        bool FindKeyword(int& i, std::string expected) { //add this 
            if(tokens[i].keywords != expected) {
                return false;
            }
            ++i;
            return true;  
        }
                    
        bool FindType(int& i, std::string expected) {
            if(tokens[i].type != expected) {
                return false; 
            }
            ++i
            return true;
        }
};

#include<iostream>
#include<vector>
#include<string>
#include "helper.h"
class HelperFunctions { //add this to Helpers/helpers.h
    public:
        bool FindKeyword(int& i, std::string expected) { //add this 
            if(tokens[i].keywords != expected) {
                return false;
            }
            return true;  
        }
                    
        bool FindType(int& i, TokenType expected) {
            if(tokens[i].type != expected) {
                return false; 
            }
            return true;
        }
        bool FindCharSymbols(char expected) {
            if (expected == '=' || expected == '!' ||
            expected == '>' || expected == '<' ||
            expected == ';' || expected == '[' ||
            expected == ']' || expected == '(' ||
            expected == ')') {
            return true;
        }
            return false;
        }
                
};

#include<iostream>
#include<vector>
#include<string>
#include "helper.h"
class HelperFunctions { //add this to Helpers/helpers.h
    public:
        bool FindKeyword(int& i, std::string expected) { //add this 
            if(tokens[i].keywords != expected) {
                ++i;
                return false;
            }
            ++i;
            return true;  
        }
                    
        bool FindType(int& i, TokenType expected) {
            if(tokens[i].type != expected) {
                ++i;
                return false; 
            }
            ++i;
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

          void parseCondition(int& i) {
            if(FindType(i, LPARENTHESES)) {
                while(!FindType(i, RPARENTHESES)) {
                    if(FindType(i, IDENTIFIER)) { }
                    if(FindType(i, SYMBOL)) { }
                    if(FindType(i, IDENTIFIER)) { }
                    while(FindType(i, AND) || FindType(i,OR))  { 
                         if(FindType(i, IDENTIFIER)) { }
                         if(FindType(i, SYMBOL)) { }
                         if(FindType(i, IDENTIFIER)) { }
                    }
                }
            }
        }

        void parseBlock(int& i) { 
            parseCondition(i);
            if(FindType(i, LBRACKET)) {
                while(!FindType(i, RBRACKET)) { 
                    if(FindKeyword(i, "if")) {
                        parseCondition(i);
                    }
                    else if(FindKeyword(i, "while")) {
                        parseCondition();
                    } 
                    else if(FindKeyword(i, "for")) {
                        parseCondition();
                    }
                    // placeholder for more loops or others that have [ ];
                    else {
                        break;
                    }
                        
                }
            }
        }

                
};

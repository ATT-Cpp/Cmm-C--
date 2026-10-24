#include "lexer.h"
#include "parser.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
class Ifstatement
{
    public:
        bool Consume(std::vector<Tokens> tokens, int& i,  std::string expected) { // in parser.h change the arguments
                if(tokens[i].keywords != expected) {
                    return false;
                
            }
            ++i;
            return true;
            
                
        } 

        void ParseIfStatement() { // in parser.h change the return type to void
            for(int i = 0; i < tokens.size(); ++i) {                    
                    if(Consume(tokens, i, "if")) {
                        if(tokens[i].type == LPARENTHESES) {
                            ++i;
                            if(tokens[i].type == IDENTIFIER) {
                                ++i;
                                if(tokens[i].type == EQUALTO || tokens[i].type == ASSIGNMENTOP || tokens[i].type == NOT || tokens[i].type == ||) { //add OR in lexer.cpp 
                                    ++i; 
                                    if(tokens[i].type == IDENTIFIER) {
                                        ++i;
                                        if(tokens[i].type == RPARENTHESES) {
                                        ++i;
                                        if(tokens[i].type == LBRACKET) {
                                            ++i;
                                            while(tokens[i].type != RBRACKET) {
                                                if(Consume(tokens, i , "if")) {
                                                }
                                                //do pending while, for etc statements here and write like parseWhileSt() so becomes easy
                                            }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
            }
        }
};
        

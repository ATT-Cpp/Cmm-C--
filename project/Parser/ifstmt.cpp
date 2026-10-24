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
                            if(tokens[i].type != NOT) {
                                ++i;
                                if(tokens[i].type == IDENTIFIER) {
                                    ++i;
                                if(tokens[i].type == EQUALTO) { //add logic in lexer.cpp like > < etc.
                                    ++i; 
                                    if(tokens[i].type == IDENTIFIER) {
                                        ++i;
                                        
                                        if(tokens[i].type == RPARENTHESES) {
                                        ++i;
                                        if(tokens[i].type == LBRACKET) {
                                            ++i;
                                                while(tokens[i].type != RBRACKET) {
                                                    if(tokens[i].keywords == "if")
                                                    {
                                                        // parse inner if here
                                                     }
                                                    else if(tokens[i].keywords == "while") {
                                                         //parse inner while here
                                                    }
    
                                                    else if(tokens[i].keywords == "for") {
                                                        //parse inner for herec
                                                    }
                                                    ++i;
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
        

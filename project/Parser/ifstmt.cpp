#include "lexer.h"
#include "parser.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
class Ifstatement
{
    public:
        bool Consume(std::vector<Tokens> tokens, int& i,  std::string expected) {
                if(tokens[i].keywords != expected) {
                    return false;
                
            }
            ++i;
            return true;
            
                
        } 
};
        

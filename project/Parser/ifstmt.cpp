#include"Lexer/lexer.h"
#include"Helper/helper.h"
#include"parser.h"
#include<iostream>
#include<vector>
#include<string>

class IfStatement { 
    public:
        void parseIfStatement(int& i) { 
            if(FindKeyword(i, "if")) {
                ++i;
                parseCondition(i);
                parseBlock(i);
            } 
        }
}

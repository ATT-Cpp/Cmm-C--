#include"Lexer/lexer.h"
#include"Helper/helper.h"
#include"parser.h"
#include<iostream>
#include<vector>
#include<string>
 void IfStatement::parseIfStatement(int& i) { 
    if(FindKeyword(i, "if")) {
        ++i;
        parseCondition(i);
        parseBlock(i);
    } 
 }

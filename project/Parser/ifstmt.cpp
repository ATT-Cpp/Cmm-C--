#include"Lexer/lexer.h"
#include"Helper/helper.h"
#include"parser.h"
#include<iostream>
#include<vector>
#include<string>
        using TokenType = type;
ifstmt if;
        bool FindKeyword(int& i, std::string expected) { //add this 
            if(tokens[i].Value != expected) {
                ++i;
                return false;
            }
            ++i;
            return true;  
        }
                    
        bool FindType(int& i, TokenType expected) {
            if(tokens[i]. != expected) {
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
 void IfStatement::parseIfStatement(int& i) { 
    if(FindKeyword(i, "if")) {
        parseCondition(i);
        parseBlock(i);
    } 
 }

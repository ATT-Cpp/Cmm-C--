#include"Lexer/lexer.h"
#include"Helper/helper.h"
#include"parser.h"
#include<iostream>
#include<vector>
#include<string>

        void parseCondition(int& i) {
            if(FindType(i, LPARENTHESES)) {
                while(!FindType(i, RPARENTHESES)) {
                    if(FindType(i, IDENTIFIER)) { }
                    if(FindType(i, SYMBOL)) { }
                    if(FindType(i, IDENTIFIER)) { }
                    while(FindType(i, AND) || FindType(i,OR))  { 
                         ++i;
                         if(FindType(i, IDENTIFIER)) { }
                         if(FindType(i, SYMBOL)) { }
                         if(FindType(i, IDENTIFIER)) { }
                    }
                }
            }
        }

        void parseBlock(int& i) { 
            parseCondition(i);
            if(Findtype(i, LBRACKET)) {
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

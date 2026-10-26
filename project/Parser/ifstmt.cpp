#include"Lexer/lexer.h"
#include"Helper/helper.h"
#include"parser.h"
#include<iostream>
#include<vector>
#include<string>

class IfStatement {
    public:
        void parseIfStatement(int& i) {
            if(FindKeyword(i, "if") && FindType(i, KEYWORD)) {
                ++i;
                if(FindType(i,LPARENTHESES)) {
                    ++i;
                    while(FindType(i,LPARENTHESES)) {
                        ++i;
                        if(FindType(i, IDENTIFIER)) {
                            ++i;
                            if(FindType(i,SYMBOLS)) {
                                ++i;
                                if(FindType(i,IDENTIFIER)) {
                                    ++i;
                                    while(FindType(i,AND) || FindType(i,OR)) {
                                        ++i;
                                        if(FindType(i, IDENTIFIER)) {
                                            ++i;
                                            if(FindType(i,SYMBOLS)) {
                                                ++i;
                                                if(FindType(i, IDENTIFIER)) {
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
        }
};

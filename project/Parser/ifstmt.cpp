    #include "lexer.h"
    #include "parser.h"
    #include<iostream>
    #include<vector>
    #include<string>
    #include<algorithm>
    class Ifstatement
    {
        public:    
            bool Parseifstmt(int& i) {
                if(tokens[i].type != KEYWORD || tokens[i].keywords != "if") {
                    return false;
                }
                ++i;

                if(tokens[i].type != LPARENTHESES) {
                    return false;
                }
                ++i;

                if(tokens[i].type == NOT)
               {
                       ++i;
                }



                if(tokens[i].type != INDENTIFIER) {
                    return false;
                }
                ++i;

                if(tokens[i].type != EQUALTO && tokens[i].type != NOTEQUALTO && tokens[i].type != GREATERTHEN && tokens[i].type != GREATERTHENOREQUALTO && tokens[i].type != LESSTHEN && tokens[i].type != LESSTHENOREQUALTO) {
                    return false;
                }
                ++i;
                if(tokens[i].type != INDENTIFIER) {
                    return false;
                }
                ++i;

                while(tokens[i].type == AND || tokens[i].type == OR) {
                    ++i;
                    if(tokens[i].type == NOT) {
                        ++i;
                    }

                    if(tokens[i].type != IDENTIFIER) {
                        return false;
                    }
                    ++i;

                    if(tokens[i].type != EQUALTO && tokens[i].type != NOTEQUALTO && tokens[i].type != GREATERTHEN && tokens[i].type != GREATERTHENOREQUALTO && tokens[i].type != LESSTHEN && tokens[i].type != LESSTHENOREQUALTO) {
                        return false;
                    }
                    ++i;
                    
                    if(tokens[i].type != IDENTIFIER) {
                        return false;
                    }
                    ++i;
                }
                if(tokens[i].type != RPARENTHESES) {
                    return false;
                }
                ++i;
                return true;
            }
    };
            

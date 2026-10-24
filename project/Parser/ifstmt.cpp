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
    
            void parseExpression(int& i) {
                if(tokens[i].type == LPARENTHESES) {
                    ++i;
                    while(tokens[i].type != RPARENTHESES) {
                        
                        if(tokens[i].type == NOT) {
                            ++i;
                            if(tokens[i].type == IDENTIFIER) {
                                ++i;
                                if(tokens[i].type == EQUALTO || tokens[i].type == GREATERTHEN || tokens[i].type == GREATERTHENOREQUALTO || tokens[i].type == LESSTHEN || tokens[i].type == LESSTHENOREQUALTO) {
                                    ++i;
                                    if(tokens[i].type == IDENTIFIER) {
                                        ++i;
                                        while(tokens[i].type == AND || tokens[i].type == OR ) {
                                            ++i;
                                            if(tokens[i].type == IDENTIFIER) {
                                            ++i;
                                                if(tokens[i].type == EQUALTO || tokens[i].type == GREATERTHEN || tokens[i].type == GREATERTHENOREQUALTO || tokens[i].type == LESSTHEN || tokens[i].type == LESSTHENOREQUALTO) {
                                                    ++i
                                                    if(tokens[i].type == IDENTIFIER) {
                                                    ++i;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                             if(tokens[i].type == IDENTIFIER) {
                                ++i;
                                if(tokens[i].type == EQUALTO || tokens[i].type == GREATERTHEN || tokens[i].type == GREATERTHENOREQUALTO || tokens[i].type == LESSTHEN || tokens[i].type == LESSTHENOREQUALTO) {
                                    ++i
                                    if(tokens[i].type == IDENTIFIER) {
                                        ++i;
                                        while(tokens[i].type == AND || tokens[i].type == OR ) {
                                            ++i;
                                            if(tokens[i].type == IDENTIFIER) {
                                            ++i;
                                                if(tokens[i].type == EQUALTO || tokens[i].type == GREATERTHEN || tokens[i].type == GREATERTHENOREQUALTO || tokens[i].type == LESSTHEN || tokens[i].type == LESSTHENOREQUALTO) {
                                                    ++i
                                                    if(tokens[i].type == IDENTIFIER) {
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
            

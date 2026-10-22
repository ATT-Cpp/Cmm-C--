#include "parser.h"
#include<iostream>
#include<vector>
#include<string>

class Ifstatement
{
    public:
      void advance()
      {
          ++current
      }

      Ifstatement ParseIfStatement()
      {
          Token TokenType;
              for(int i = 0; i < T.size(); i ++)
              {
                  if(Tokens == TokenType::KEYWORD)
                  {
                      ++i;
                    Tokens[i];
                     if(Tokens == TokenType::LPARENTHESES)
                     {
                         ++i;
                         Tokens[i];
                         while(T != TokenType::RPARENTHESES)
                         {
                             if(Tokens == TokenType::IDENTIFIER)
                             {
                                 ++i;
                                 Tokens[i];
                                 if(Tokens == TokenType::ASSIGNMENTOP || T == TokenType::EQUALTO || T == TokenType::NOT )
                                 {
                                     ++i;
                        Tokens[i];
                                     if(Tokens == TokenType::LBRACKET)
                                     {
                                         ++i;
                      Tokens[i];
                                         if(Tokens == TokenType::RBRACKET)
                                         {
                                          ++i;
                     Tokens[i];
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
                                          
            
            
    
        

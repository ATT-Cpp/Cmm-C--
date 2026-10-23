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
          for(auto& ai : tokens)
          {
              for(auto i = 0; i < tokens.size(); ++i)
              {
                  ai = tokens[i];
                  if(tokens.type == KEYWORDS) {
                      ++i;
                      ai = tokens[i];
                      if(tokens.keywords == "if") {
                          ++i;
                          ai = tokens[i];
                          if(tokens.type == LPARENTHESES) {
                              ++i;
                              ai = tokens[i];
                              if(tokens.type == KEYWORDS) {
                                  ++i;
                                  ai = tokens[i];
                                  if(tokens.type == IDENTIFIER) {
                                      ++i;
                                      ai = tokens[i];
                                      if(tokens.type == ASSIGNMENTOP || tokens.type == EQUALTO || tokens.type == NOT) {
                                          ++i;
                                          ai = tokens[i];
                                          if(tokens.type == IDENTIFIER) {
                                              ++i;
                                              ai = tokens[i];
                                              if(tokens.type == RPARENTHESES) {
                                                  ++i;
                                                  ai = tokens[i];
                                                  if(tokens.type == LBRACKET) {
                                                      ++i;
                                                      ai = tokens[i];
                                                      if(tokens.type == RBRACKET) {
                                                          ++i;
                                                          ai = tokens[i];
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
          }
      }

}; 
                                          
            
            
    
        

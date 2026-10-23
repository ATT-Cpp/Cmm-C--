#include "lexer.h"
#include "parser.h"
#include<iostream>
#include<vector>
#include<string>

class Ifstatement
{
    public:

       bool consume(std::vector<Tokens>& tokens, int& i, std::string& expected) {
           Token T;
           if(tokens[i] != expected) {
               return false;
           }
           ++i
               
           return true;
       }

      void ParseIfStatement()
      {      
          for(int i = 0; i < input.size(); ++i) {
              if(consume(tokens, i, "if")
      }

}; 
                                          
            
            
    
        

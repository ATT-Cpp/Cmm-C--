#include "lexer.h"
#include<vector>
#include<iostream>
#include<string>

void Compiler::Lexer(std::string input)
{
  std::string currentWord;

  for(int i = 0; i < input.size(); ++i)
  {
    if(isspace(currentWord) {
    
      ++i;
      currentWord += input[i];
  }
    }

    for(auto&AI : Keywords)
    {
      if(currentWord == AI)
      {
        Tokens.push_back( Compiler { TokenType::KEYWORD } );
        ++i;
        currentWord += input[i];
      }

      if(currentWord != AI) {
          Tokens.push_back( Compiler { TokenType::IDENTIFIER } );
          ++i;
          currentWord+=input[i];

     }
      if(currentWord == "=")
      {
        Tokens.push_back( Compiler { TokenType::ASSIGNMENTOP } );
        ++i;
        currentWord+=input[i];
      }

      if(currentWord == "==")
      {
        Tokens.push_back( Compiler { TokenType::EQUALTO } );
        ++i;
        currentWord+=input[i]
      }

      if(currentWord == "!")
      {
        Tokens.push_back( Compiler { TokenType::NOT } );
        ++i;
        currentWord+=input[i];
      }

      if(currentWord == ";")
      {
        Tokens.push_back( Compiler { TokenType::SEMICOLON } );
        ++i;
        currentWord+=input[i];
      }

      

    }
      
}


    

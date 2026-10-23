#include "lexer.h"
#include<vector>
#include<iostream>
#include<string>
#include<cctype>
#include<locales>
void Compiler::Lexer(std::string input)
{
  std::string currentWord;
  char currentSchar;
  for(int i = 0; i < input.size(); ++i)
  {
    if(isspace(currentSchar)) {
    
      ++i;
      currentWord += input[i];
      currentSchar += input[i];
      
      if(currentWord == "if") {
        Tokens.push_back( Compiler { TokenType::KEYWORD } );
        Syntax.push_back(currentWord);
        ++i;
        currentWord+=input[i];
        currentSchar+=input[i];
      }
      if(currentWord == "fn") {
        Tokens.push_back( Compiler { TokenType::KEYWORD } );
          Syntax.push_back(currentWord);
        ++i;
        currentWord+=input[i];
        currentSchar+=input[i];
      }

      if(currentWord == "return") {
        Tokens.push_back( Compiler { TokenType::KEYWORD } );
        Syntax.push_back(currentWord);
        ++i;
        currentWord+=input[i];
        currentSchar+=input[i];
      }
      if(currentWord == "import") {
        Tokens.push_back( Compiler { TokenType::KEYWORD } );
        Syntax.push_back(currentWord);
        ++i;
        currentWord+=input[i];
        currentSchar+=input[i];
      }
      if(currentWord == "else") {
        Tokens.push_back( Compiler { TokenType::KEYWORD } );
        Syntax.push_back(currentWord);
        ++i;
        currentWord+=input[i];
        currentSchar+=input[i];
      }
      
      if(currentWord != AI) {   //create identifier vec
          Tokens.push_back( Compiler { TokenType::IDENTIFIER } );
          ++i;
          currentWord+=input[i];
          currentSchar+=input[i];
      }

       if(currentWord == "==")
       {
         Tokens.push_back( Compiler { TokenType::EQUALTO } );
         Syntax.push_back(currentWord);
         ++i;
         currentWord+=input[i];
         currentSchar+=input[i];
       }
      
      if(isalpha(currentSchar))
      {
        
        if(currentSchar == '=')
        {
          Tokens.push_back( Compiler { TokenType::ASSIGNMENTOP } );
          ++i;
          currentSchar+=input[i];
        }

        if(currentSchar == '!')
        {
          Tokens.push_back( Compiler { TokenType::NOT } );
          ++i;
          currentSchar+=input[i];
        }

        if(currentSchar == ';')
        {
          Tokens.push_back( Compiler { TokenType::SEMICOLON } );
          ++i;
          currentSchar+=input[i];
        }

        if(currentSchar == '[')
        {
          Tokens.push_back( Compiler { TokenType::LBRACKET } );
          ++i;
          currentSchar+=input[i];
        }

        if(currentSchar == ']')
        {
          Tokens.push_back( Compiler { TokenType::RBRACKET } );
          ++i;
          currentSchar+=input[i];
        }

        if(currentSchar == '(')
        {
          Tokens.push_back( Compiler { TokenType::LPARENTHESES } );
          ++i;
          currentSchar+=input[i];
        }

        if(currentSchar == ')')
        {
          Tokens.push_back( Compiler { TokenType::RPARENTHESES } );
          ++i;
          currentSchar+=input[i];
        }

    }

    }
}
      

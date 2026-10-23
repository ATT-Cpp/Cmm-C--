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
  for(int i = 0; i + 1 < input.size();i++ )
  {
     currentSchar = input[i];
      if(!isspace(currentSchar)) {
        currentWord+=input[i];
        currentSchar=input[i];
      }
      if(currentWord == "if") {
        tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }
      if(currentWord == "fn") {
        tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "return") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }
      if(currentWord == "import") {
        tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }
      if(currentWord == "else") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }
      if(currentWord == "for") {
      tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "while") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "switch") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "case") {
      tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "break") {
        tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "int") {
      tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "float") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "bool") {
         tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "char") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "string") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "void") {
tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "var")
      {
         tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "auto") {
       tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }

      if(currentWord == "const")
      {
         tokens.push_back({
    TokenType::KEYWORD,
    currentWord
});
        ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      }
      
      if(std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end())
      {
         ++i;
        currentWord+=input[i];
        currentSchar=input[i];
      } else {
        tokens.push_back({TokenType::IDENTIFIER, currentWord});

      }
        
       if(currentWord == "==")
       {
         tokens.push_back(  { TokenType::EQUALTO, currentWord });
         ++i;
         currentWord+=input[i];
         currentSchar=input[i];
       }
      
        
        if(currentSchar == '=')
        {
          tokens.push_back( { TokenType::ASSIGNMENTOP } );
          Symbols.push_back(currentSchar);
          ++i;
          currentSchar=input[i];
        }

        if(currentSchar == '!')
        {
          tokens.push_back(  { TokenType::NOT } );
          Symbols.push_back(currentSchar);
          ++i;
          currentSchar=input[i];
        }

        if(currentSchar == ';')
        {
          tokens.push_back(  { TokenType::SEMICOLON } );
          Symbols.push_back(currentSchar);
          ++i;
          currentSchar=input[i];
        }

        if(currentSchar == '[')
        {
          tokens.push_back(  { TokenType::LBRACKET } );
 
          ++i;
          currentSchar=input[i];
        }

        if(currentSchar == ']')
        {
          tokens.push_back(  { TokenType::RBRACKET } );
        
          ++i;
          currentSchar=input[i];
        }

        if(currentSchar == '(')
        {
          tokens.push_back(  { TokenType::LPARENTHESES } );
          
          ++i;
          currentSchar=input[i];
        }

        if(currentSchar == ')')
        {
          tokens.push_back( { TokenType::RPARENTHESES } );
          
          ++i;
          currentSchar=input[i];
        }
      }

    }

    }

      

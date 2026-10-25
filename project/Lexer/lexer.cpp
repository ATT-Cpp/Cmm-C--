#include "lexer.h"
#include "Helper/helper.h"
#include<vector>
#include<iostream>
#include<cctype>
#include<locales>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

void Compiler::Lexer(std::string& input)
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
      if(std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end())
      {
        tokens.push_back({ TokenType::KEYWORDS, currentWord });
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
      
        
        if(FindCharSymbol('='))
        {
          tokens.push_back( { TokenType::ASSIGNMENTOP } );
          ++i;
          currentSchar=input[i];
        }

        if(FindCharSymbol('!'))
        {
          tokens.push_back(  { TokenType::NOT } );
          ++i;
          currentSchar=input[i];
        }
        if(FindCharSymbol('>')) {
          tokens.push_back( { TokenType::GREATERTHEN } );
          ++i;
          currentSchar = input[i];
        }
        if(FindCharSymbol('<')) {
          tokens.push_back ( { TokenType::LESSTHEN } );
          ++i;
          currentSchar = input[i];
        }
        if(currentWord == ">=") {
          tokens.push_back({TokenType::GREATERTHENOREQUALTO});
          ++i;
          currentWord += input[i];
          currentSchar = input[i];
        }
        if(currentWord == "<=") {
          tokens.push_back({TokenType::LESSTHENOREQUALTO});
          ++i;
          currentWord +=input[i];
          currentSchar = input[i];
        }

        if(FindCharSymbol(';'))
        {
          tokens.push_back(  { TokenType::SEMICOLON } );
          ++i;
          currentSchar=input[i];
        }

        if(FindCharSymbol('['))
        {
          tokens.push_back(  { TokenType::LBRACKET } );
 
          ++i;
          currentSchar=input[i];
        }

        if(FindCharSymbol(']'))
        {
          tokens.push_back(  { TokenType::RBRACKET } );
        
          ++i;
          currentSchar=input[i];
        }

        if(FindCharSymbol('('))
        {
          tokens.push_back(  { TokenType::LPARENTHESES } );
          
          ++i;
          currentSchar=input[i];
        }

        if(FindCharSymbol(')'))
        {
          tokens.push_back( { TokenType::RPARENTHESES } );
          
          ++i;
          currentSchar=input[i];
        }

        if(currentWord == "||") {
          tokens.push_back({TokenType::OR});
          ++i;
          currentSchar = input[i];
        }
       if (std::isdigit(currentSchar))
{
    std::string number;

    while (i < input.size() &&
           std::isdigit(input[i]))
    {
        number += input[i];
        ++i;
    }

    --i;

    tokens.push_back(
    {
        TokenType::NUMERICAL,
        number
    });
}

if (currentSchar == '"')
{
    std::string str;

    ++i;

    while (i < input.size() &&
           input[i] != '"')
    {
        str += input[i];
        ++i;
    }

    tokens.push_back(
    {
        TokenType::STRING_LITERAL,
        str
    });
}

if (currentSchar == '\'')
{
    std::string ch;

    ++i;

    if (i < input.size())
    {
        ch += input[i];
        ++i;
    }

    tokens.push_back(
    {
        TokenType::CHAR_LITERAL,
        ch
    });
}
  }
            

};


      

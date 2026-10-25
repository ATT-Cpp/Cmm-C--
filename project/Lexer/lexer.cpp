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
        if(tokens[i].type != Symbols) {
          
        tokens.push_back({TokenType::IDENTIFIER, currentWord});
        }
      ++i;

      }
        if(std::find(Symbol.begin(), Symbol.end(), currentWord) != Symbol.end()) {
          tokens.push_back({ TokenType::Symbols });
          ++i;
          currentWord+=input[i];
          currentSchar=input[i];
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


      

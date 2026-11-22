#include "../../Include/includes.h"

void Lexer::keywords(const std::string &input, size_t &i)
{
    if (i >= input.size())
    {
        std::cerr << "Error Tokenizing";
        return;
    }
    const size_t start = i;
    while (i < input.size() && (std::isalnum(static_cast<unsigned char>(input[i])) || input[i] == '_'))
    {
        ++i;
    }
    const std::string currentWord = input.substr(start, i - start);

    if (!currentWord.empty())
    {
        if (currentWord == "int")
        {
            Lexer::tokens.push_back({Lexer::INT, currentWord});
        }
        else if (currentWord == "double")
        {
            Lexer::tokens.push_back({Lexer::DOUBLE, currentWord});
        }
        else if (currentWord == "bool")
        {
            Lexer::tokens.push_back({Lexer::BOOL, currentWord});
        }
        else if (currentWord == "char")
        {
            Lexer::tokens.push_back({Lexer::CHAR, currentWord});
        }
        else if (currentWord == "void")
        {
            Lexer::tokens.push_back({Lexer::VOID, currentWord});
        }
        else if (currentWord == "string")
        {
            Lexer::tokens.push_back({Lexer::STRING, currentWord});
        }
        else if (currentWord == "auto")
        {
            Lexer::tokens.push_back({Lexer::AUTO, currentWord});
        }
        else if (currentWord == "true" || currentWord == "false")
        {
            Lexer::tokens.push_back({Lexer::BOOL, currentWord});
        }
        else if (std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end())
        {
            Lexer::tokens.push_back({KEYWORD, currentWord});
        }
        else
        {
            Lexer::tokens.push_back({Lexer::IDENTIFIER, currentWord});
        }
    }
}
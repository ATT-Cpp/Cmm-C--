#include "../../Include/includes.h"

void Compiler::keywords(const std::string &input, size_t &i)
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
        if (std::find(Compiler::datatype.begin(), Compiler::datatype.end(), currentWord) != Compiler::datatype.end())
        {
            Compiler::Token tokenType;
            if (currentWord == "int")
            {
                tokenType = Compiler::INT;
            }
            else if (currentWord == "double")
            {
                tokenType = Compiler::DOUBLE;
            }
            else if (currentWord == "bool")
            {
                tokenType = Compiler::BOOL;
            }
            else if (currentWord == "char")
            {
                tokenType = Compiler::CHAR;
            }
            else if (currentWord == "void")
            {
                tokenType = Compiler::VOID;
            }
            else
            {
                tokenType = Compiler::STRING;
            }
            Compiler::tokens.push_back({tokenType, currentWord});
        }
        else if (std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end())
        {
            Compiler::tokens.push_back({KEYWORD, currentWord});
        }
        else
        {
            Compiler::tokens.push_back({Compiler::IDENTIFIER, currentWord});
        }
    }
}
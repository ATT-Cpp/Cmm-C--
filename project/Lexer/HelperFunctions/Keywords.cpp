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
        if (std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end())
        {
            Compiler::tokens.push_back({KEYWORD, currentWord});
        }
        else
        {
            Compiler::tokens.push_back({Compiler::IDENTIFIER, currentWord});
        }
    }
}
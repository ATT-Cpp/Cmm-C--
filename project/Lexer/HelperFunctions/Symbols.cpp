#include "../../Include/includes.h"

void Compiler::Symbols(const std::string &input, std::size_t &i)
{
    if (i >= input.size())
    {
        return;
    }

    std::string currentWord(1, input[i]);
    if (std::find(Compiler::Symbol.begin(), Compiler::Symbol.end(), currentWord) != Compiler::Symbol.end())
    {
        Compiler::tokens.push_back({Compiler::SYMBOLS, currentWord});
        ++i;
    }
}
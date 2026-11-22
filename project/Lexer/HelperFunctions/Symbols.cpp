#include "../../Include/includes.h"

void Lexer::Symbols(const std::string &input, std::size_t &i)
{
    if (i >= input.size())
    {
        return;
    }

    const std::string *matchedSymbol = nullptr;
    for (const std::string &symbol : Lexer::Symbol)
    {
        if (input.compare(i, symbol.size(), symbol) == 0 &&
            (matchedSymbol == nullptr || symbol.size() > matchedSymbol->size()))
        {
            matchedSymbol = &symbol;
        }
    }
    if (matchedSymbol != nullptr)
    {
        Lexer::tokens.push_back({Lexer::SYMBOLS, *matchedSymbol});
        i += matchedSymbol->size();
    }
}
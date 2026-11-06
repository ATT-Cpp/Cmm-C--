#include "../../Include/includes.h"

void Compiler::Symbols(const std::string &input, std::size_t &i)
{
    if (i >= input.size())
    {
        return;
    }

    const std::string *matchedSymbol = nullptr;
    for (const std::string &symbol : Compiler::Symbol)
    {
        if (input.compare(i, symbol.size(), symbol) == 0 &&
            (matchedSymbol == nullptr || symbol.size() > matchedSymbol->size()))
        {
            matchedSymbol = &symbol;
        }
    }
    if (matchedSymbol != nullptr)
    {
        Compiler::tokens.push_back({Compiler::SYMBOLS, *matchedSymbol});
        i += matchedSymbol->size();
    }
}
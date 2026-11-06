#include "../../Include/includes.h"

Compiler c;
void Compiler::Lexer(const std::string &input, size_t &i)
{

    char currentSchar;

    if (i >= input.size())
    {
        return;
    }

    while (i < input.size())
    {
        currentSchar = input[i];

        if (std::isspace(static_cast<unsigned char>(currentSchar)))
        {
            ++i;
            continue;
        }

        if (std::isdigit(static_cast<unsigned char>(currentSchar)))
        {
            c.ParseInt(input, i);
            continue;
        }
        if (std::isalnum(static_cast<unsigned char>(currentSchar)) || currentSchar == '_')
        {
            c.keywords(input, i);
            continue;
        }

        size_t previousIndex = i;
        c.Symbols(input, i);
        if (i != previousIndex)
        {
            continue;
        }
        if (currentSchar == '"')
        {
            c.ParseString(input, i);
        }
        else if (currentSchar == '\'')
        {
            c.ParseChar(input, i);
        }
        else
        {
            ++i;
        }
    }
}
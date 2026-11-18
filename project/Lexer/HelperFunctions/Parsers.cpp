#include "../../Include/includes.h"

void Compiler::ParseString(const std::string &input, size_t &i)
{
    if (i >= input.size() || input[i] != '"')
    {
        return;
    }

    ++i;
    const size_t start = i;

    while (i < input.size() && input[i] != '"')
    {
        ++i;
    }

    if (i < input.size())
    {
        Compiler::tokens.push_back({Compiler::STRING, input.substr(start, i - start)});
        ++i;
    }
}

void Compiler::ParseInt(const std::string &input, size_t &i)
{
    if (i >= input.size() || !std::isdigit(static_cast<unsigned char>(input[i])))
    {
        return;
    }

    const size_t start = i;

    while (i < input.size() && std::isdigit(static_cast<unsigned char>(input[i])))
    {
        ++i;
    }

    Compiler::tokens.push_back({Compiler::INT, input.substr(start, i - start)});
}

void Compiler::ParseChar(const std::string &input, size_t &i)
{
    if (i >= input.size() || input[i] != '\'')
    {
        return;
    }

    ++i;

    if (i >= input.size())
    {
        return;
    }

    char ch = input[i];
    ++i;

    if (i < input.size() && input[i] == '\'')
    {
        Compiler::tokens.push_back({Compiler::CHAR, std::string(1, ch)});
        ++i;
    }
}

void Compiler::ParseBool(const std::string &input, size_t &i)
{
    if (i >= input.size())
    {
        return;
    }

    const size_t start = i;

    while (i < input.size() && std::isalpha(static_cast<unsigned char>(input[i])))
    {
        ++i;
    }

    const std::string currentWord = input.substr(start, i - start);
    if (currentWord == "true" || currentWord == "false")
    {
        Compiler::tokens.push_back({Compiler::BOOL, currentWord});
    }
}
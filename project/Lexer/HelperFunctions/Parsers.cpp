#include "../../Include/includes.h"

void Lexer::ParseString(const std::string &input, size_t &i)
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
        Lexer::tokens.push_back({Lexer::STRING, input.substr(start, i - start)});
        ++i;
    }
}

void Lexer::ParseInt(const std::string &input, size_t &i)
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

    Lexer::tokens.push_back({Lexer::INT, input.substr(start, i - start)});
}

void Lexer::ParseDouble(const std::string &input, size_t &i)
{
    if (i >= input.size() || !std::isdigit(static_cast<unsigned char>(input[i])))
    {
        return;
    }

    size_t end = i;
    while (end < input.size() && std::isdigit(static_cast<unsigned char>(input[end])))
    {
        ++end;
    }

    if (end >= input.size() || input[end] != '.' ||
        end + 1 >= input.size() ||
        !std::isdigit(static_cast<unsigned char>(input[end + 1])))
    {
        return;
    }

    ++end;
    while (end < input.size() && std::isdigit(static_cast<unsigned char>(input[end])))
    {
        ++end;
    }

    Lexer::tokens.push_back({Lexer::DOUBLE, input.substr(i, end - i)});
    i = end;
}

void Lexer::ParseChar(const std::string &input, size_t &i)
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
        Lexer::tokens.push_back({Lexer::CHAR, std::string(1, ch)});
        ++i;
    }
}

void Lexer::ParseBool(const std::string &input, size_t &i)
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
        Lexer::tokens.push_back({Lexer::BOOL, currentWord});
    }
}
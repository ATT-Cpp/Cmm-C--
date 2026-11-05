#include "../../Include/includes.h"

int main()
{
    const std::string input = R"(var int hp = 100
var auto player = "Avyu"
var auto rank = 'S'

var int coins = 99999
var auto title = "Compiler Builder")";
    Compiler compiler;
    size_t i = 0;
    compiler.Lexer(input, i);

    for (const Compiler::Tokens &token : Compiler::tokens)
    {
        std::cout << token.TokenType << ": " << token.Value << '\n';
    }
}
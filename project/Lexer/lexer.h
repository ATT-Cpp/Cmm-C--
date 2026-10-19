#pragma once
#include <iostream>
#include <vector>
#include <string>

class Compiler
{
    private:
        enum Token {

        KEYWORD,
        IDENTIFIER,

        LPARENTHESES,
        RPARENTHESES,

        LBRACKET,
        RBRACKET,

        } TokenType

        std::vector <std::string> Keywords { "fn", "if", "else", "for", "while", "switch", "case", "break", "continue", "int", "float", "double", "bool", "char", "void", "string", "const", "global", "var", "auto", "return", "import" };
        std::vector <Token> Tokens;

    public:
        void Lexer(std::string input);
};
        

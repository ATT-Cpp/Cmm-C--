#pragma once
#include <iostream>
#include <vector>
#include <string>

class Compiler
{
    public:
        enum Token {

        KEYWORD,
        IDENTIFIER,

        SYMBOLS, //like ; [] ()
        STRING,
        INT,
        CHAR,
        BOOL,
        

        };
        struct Tokens {
            Token TokenType;
            std::string Value;
        };

        inline static std::vector<std::string> Symbol { "<", ">", "==", "=", "!=", ">=", "<=", "[", "]", "(", ")", "||", "!", "&&", ";" };
        inline static std::vector<std::string> Keywords { "fn", "if", "else", "for", "while", "switch", "case", "break", "continue", "int", "float", "double", "bool", "char", "void", "string", "const", "global", "var", "auto", "return", "import", "else if" };
        inline static std::vector<Tokens> tokens;

    public:
        void Lexer(std::string input);
};

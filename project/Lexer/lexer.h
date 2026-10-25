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

        SYMBOLS, //like ; [] ()
        AND,
        OR,
        NOT,
        STRING,
        INT,
        CHAR,
        BOOL,
        

        };
        struct Tokens {
            Token TokenType;
            std::string Value;
        };
        extern std::vector <std::string> Symbol { "<", ">", "==", "=", "!=", ">=", "<=", "[", "]", "(", ")", "||", "!", "&&" };
        extern std::vector <std::string> Keywords { "fn", "if", "else", "for", "while", "switch", "case", "break", "continue", "int", "float", "double", "bool", "char", "void", "string", "const", "global", "var", "auto", "return", "import" };
        extern std::vector <Tokens> tokens;

    public:
        void Lexer(std::string input);
};

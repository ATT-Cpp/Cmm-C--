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

        };
        struct Tokens {
            Token TokenType;
            std::string Value;
        };
        std::vector <std::string> Symbol { "<", ">", "==", "=", "!=", ">=", "<=", "[", "]", "(", ")", "||", "!", "&&" };
        std::vector <std::string> Keywords { "fn", "if", "else", "for", "while", "switch", "case", "break", "continue", "int", "float", "double", "bool", "char", "void", "string", "const", "global", "var", "auto", "return", "import" };
        std::vector <Tokens> tokens;

    public:
        void Lexer(std::string input);
};
        
extern std::vector <std::string> Keywords;
extern std::vector <Tokens> tokens;

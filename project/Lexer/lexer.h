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

        ASSIGNMENTOP,
        EQUALTO,
        NOT,
        SEMICOLON,
        OR,
        GREATERTHEN,
        GREATERTHENOREQUALTO,
        LESSTHEN,
        LESSTHENOREQUALTO,

        } TokenType
        struct Tokens {
            Token TokenType;
            std::string keywords;
        }

        std::vector <std::string> Keywords { "fn", "if", "else", "for", "while", "switch", "case", "break", "continue", "int", "float", "double", "bool", "char", "void", "string", "const", "global", "var", "auto", "return", "import" };
        std::vector <Tokens> tokens;

    public:
        void Lexer(std::string input);
};
        
extern std::vector <std::string> Keywords;
extern std::vector <Token> Tokens;

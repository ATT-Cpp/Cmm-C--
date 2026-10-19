#pragma once
#include <iostream>

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

        

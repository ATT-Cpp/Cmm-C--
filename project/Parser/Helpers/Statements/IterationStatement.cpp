#include "../../../Helper/helper.h"
#include "../../../Lexer/Core/lexer.h"
#include "../../Core/parser.h"
#include <iostream>
#include <string>
#include <vector>
Helper help;
void IterationStatement::ParseWhileStatement(int &i, int &b)
{
    if (Compiler::tokens[i].Value == "while")
    {
        help.parseCondition(i);
        help.parseBlock(i);
    }
}

void IterationStatement::ParseForStatement(int &i, int &b)
{
    if (Compiler::tokens[i].Value == "for")
    {
        help.parseBlock(i);
    }
}

void IterationStatement::ParseForCondition(int &i, int &b)
{
}

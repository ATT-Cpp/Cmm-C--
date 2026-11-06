#include "../../../Helper/helper.h"
#include "../../../Lexer/Core/lexer.h"
#include "../../Core/parser.h"
#include <iostream>
#include <string>
#include <vector>
Helper help;
VariableDeclaration vd;
IterationStatement is;
void IterationStatement::ParseWhileStatement(int &i, int &b)
{
    if (Compiler::tokens[i].Value == "while")
    {
        help.parseCondition(i);
        help.parseBlock(i);
    }
}

void IterationStatement::ParseForCondition(int &i, std::string input)
{
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() || Compiler::tokens[i].Value != "(")
    {
        return;
    }

    ++i;
    while (i >= 0 && static_cast<size_t>(i) < Compiler::tokens.size() && Compiler::tokens[i].Value != ")")
    {
        vd.ParseVarDecl(i);
        if (i >= 0 && static_cast<size_t>(i) < Compiler::tokens.size() && Compiler::tokens[i].Value == ";")
        {
            ++i;
            help.parseCondition(i);
            if (i >= 0 && static_cast<size_t>(i) < Compiler::tokens.size() && Compiler::tokens[i].Value == ";")
            {
                ++i;
                if (i >= 0 && static_cast<size_t>(i) < Compiler::tokens.size() && Compiler::tokens[i].Value == "++")
                {
                    ++i;
                    if (i >= 0 && static_cast<size_t>(i) < Compiler::tokens.size() &&
                        Compiler::tokens[i].Value == vd.VariableName.Value)
                    {
                        ++i;
                    }
                }
            }
        }
    }
}

#include "../../../Include/includes.h"
Helper help;
VariableDeclaration vd;
IterationStatement is;
void IterationStatement::ParseWhileStatement(int &i, int &b)
{
    if(i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }
    
    if (Compiler::tokens[static_cast<size_t> (i)].Value != "while")
    {
        return;
    }
    help.parseCondition(i);
    help.parseBlock(i);
}

void IterationStatement::ParseForCondition(int &i, std::string input)
{
    (void)input;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    if (!help.FindKeywords(i, "for")) {
        return;
    }
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    if (!help.FindKeywords(i, "(")) {
        return;
    }
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    vd.ParseVarDecl(i);
    ForStatementNode.Children.push_back(vd.VariableDeclarationNode);

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        !help.FindKeywords(i, ";")) {
        return;
    }

    ForStatementNode.Children.push_back(help.parseCondition(i));

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        !help.FindKeywords(i, ";")) {
        return;
    }

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        !help.FindKeywords(i, "++")) {
        return;
    }
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }
    increment.Children.push_back(ASTnode::MakeNode(ASTnode::IDENTIFIER, Compiler::tokens[static_cast<size_t> (i)].Value));
    ForStatementNode.Children.push_back(increment);
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        !help.FindKeywords(i, ")")) {
        return;
    }
}

#include "../../../Include/includes.h"
Helper help;
VariableDeclaration vd;
IterationStatement is;
void IterationStatement::ParseWhileStatement(int &i, int &b)
{
    WhileStatementNode = ASTnode::MakeNode(ASTnode::WHILE_STATEMENT, "");
    if(i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }
    
    if (Lexer::tokens[static_cast<size_t> (i)].Value != "while")
    {
        return;
    }
    WhileStatementNode.Value = "while";
    WhileStatementNode.Children.push_back(help.parseCondition(i));
    help.parseBlock(i);
}

void IterationStatement::ParseForCondition(int &i, std::string input)
{
    (void)input;
    ForStatementNode = ASTnode::MakeNode(ASTnode::FOR_STATEMENT, "");
    increment = ASTnode::MakeNode(ASTnode::OPERATOR, "++");

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }

    if (!help.FindKeywords(i, "for")) {
        return;
    }
    ForStatementNode.Value = "for";
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }

    if (!help.FindKeywords(i, "(")) {
        return;
    }
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }

    vd.ParseVarDecl(i);
    ForStatementNode.Children.push_back(vd.VariableDeclarationNode);

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        !help.FindKeywords(i, ";")) {
        return;
    }

    ForStatementNode.Children.push_back(help.parseCondition(i));

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        !help.FindKeywords(i, ";")) {
        return;
    }

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        !help.FindKeywords(i, "++")) {
        return;
    }
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }
    increment.Children.push_back(ASTnode::MakeNode(ASTnode::IDENTIFIER, Lexer::tokens[static_cast<size_t> (i)].Value));
    ForStatementNode.Children.push_back(increment);
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        !help.FindKeywords(i, ")")) {
        return;
    }
}

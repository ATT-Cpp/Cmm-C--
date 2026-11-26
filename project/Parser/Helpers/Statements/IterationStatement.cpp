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
    ++i;
    if (!help.Universal(i, {true, true, true, "("}))
    {
        return;
    }
    ASTnode::Node condition = help.parseCondition(i);
    if (condition.Children.size() != 4 ||
        !help.Universal(i, {true, true, true, "["}))
    {
        return;
    }
    WhileStatementNode.Children.push_back(condition);
    WhileStatementNode.Children.push_back(help.parseBlock(i));
    WhileStatementNode.Value = "while";
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
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }

    if (!help.FindKeywords(i, "(")) {
        return;
    }
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }

    VariableDeclaration declaration;
    declaration.ParseVarDecl(i);
    if (declaration.VariableDeclarationNode.Children.size() != 3) {
        return;
    }
    ForStatementNode.Children.push_back(declaration.VariableDeclarationNode);

    ASTnode::Node condition = help.parseCondition(i);
    if (condition.Children.size() != 4) {
        return;
    }
    ForStatementNode.Children.push_back(condition);

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        !help.FindKeywords(i, ";")) {
        return;
    }

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t>(i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    increment.Children.push_back(
        ASTnode::MakeNode(ASTnode::IDENTIFIER, Lexer::tokens[static_cast<size_t>(i)].Value));
    ++i;
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }
    if (!help.FindKeywords(i, "++")) {
        return;
    }
    ForStatementNode.Children.push_back(increment);

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        !help.FindKeywords(i, ")")) {
        return;
    }
    if (!help.Universal(i, {true, true, true, "["})) {
        return;
    }
    ForStatementNode.Children.push_back(help.parseBlock(i));
    ForStatementNode.Value = "for";
}

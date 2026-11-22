#include "../../../Include/includes.h"

Helper help;
void ControlFlowStatement::ParseIfStatement(int &i)
{
    ControlFlowStatementNode = ASTnode::MakeNode(ASTnode::IF_STATEMENT, "");
    if (help.FindKeywords(i, "if"))
    {
        ControlFlowStatementNode.Value = "if";
        ControlFlowStatementNode.Children.push_back(help.parseCondition(i));
        help.parseBlock(i);
    }
}

void ControlFlowStatement::ParseElseStatement(int &i)
{
    ControlFlowStatementNode = ASTnode::MakeNode(ASTnode::IF_STATEMENT, "");
    if (help.FindKeywords(i, "else"))
    {
        ControlFlowStatementNode.Value = "else";
        help.parseBlock(i);
    }
}

void ControlFlowStatement::ParseElseIfStatement(int &i)
{
    ControlFlowStatementNode = ASTnode::MakeNode(ASTnode::IF_STATEMENT, "");
    if (help.FindKeywords(i, "else if"))
    {
        ControlFlowStatementNode.Value = "else if";
        ControlFlowStatementNode.Children.push_back(help.parseCondition(i));
        help.parseBlock(i);
    }
}
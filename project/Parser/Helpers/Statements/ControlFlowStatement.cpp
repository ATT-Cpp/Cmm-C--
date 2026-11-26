#include "../../../Include/includes.h"

Helper help;
void ControlFlowStatement::ParseIfStatement(int &i)
{
    ControlFlowStatementNode = ASTnode::MakeNode(ASTnode::IF_STATEMENT, "");
    if (help.FindKeywords(i, "if"))
    {
        if (!help.Universal(i, {true, true, true, "("}))
        {
            return;
        }
        ASTnode::Node condition = help.parseCondition(i);
        if (condition.Children.size() != 4)
        {
            return;
        }
        ControlFlowStatementNode.Value = "if";
        ControlFlowStatementNode.Children.push_back(condition);
        ControlFlowStatementNode.Children.push_back(help.parseBlock(i));
    }
}

void ControlFlowStatement::ParseElseStatement(int &i)
{
    ControlFlowStatementNode = ASTnode::MakeNode(ASTnode::IF_STATEMENT, "");
    if (help.FindKeywords(i, "else"))
    {
        ControlFlowStatementNode.Value = "else";
        ControlFlowStatementNode.Children.push_back(help.parseBlock(i));
    }
}

void ControlFlowStatement::ParseElseIfStatement(int &i)
{
    ControlFlowStatementNode = ASTnode::MakeNode(ASTnode::IF_STATEMENT, "");
    if (help.FindKeywords(i, "else if"))
    {
        if (!help.Universal(i, {true, true, true, "("}))
        {
            return;
        }
        ASTnode::Node condition = help.parseCondition(i);
        if (condition.Children.size() != 4)
        {
            return;
        }
        ControlFlowStatementNode.Value = "else if";
        ControlFlowStatementNode.Children.push_back(condition);
        ControlFlowStatementNode.Children.push_back(help.parseBlock(i));
    }
}
#include "../../../Include/includes.h"

Helper help;
void ControlFlowStatement::ParseIfStatement(int &i)
{
    if (help.FindKeywords(i, "if"))
    {
        help.parseCondition(i);
        help.parseBlock(i);
    }
}

void ControlFlowStatement::ParseElseStatement(int &i)
{
    if (help.FindKeywords(i, "else"))
    {
        help.parseBlock(i);
    }
}

void ControlFlowStatement::ParseElseIfStatement(int &i)
{
    if (help.FindKeywords(i, "else if"))
    {
        help.parseCondition(i);
        help.parseBlock(i);
    }
}
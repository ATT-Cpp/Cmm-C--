#include "helper.h"
#include "../Lexer/Core/lexer.h"
#include <iostream>
#include <string>
#include <vector>
Helper help {};
bool Helper::FindType(int &i, Compiler::Token type)
{
    if (Compiler::tokens[i].TokenType != type)
    {
        return false;
    }
    ++i;
    return true;
}

bool Helper::FindKeywords(int &i, std::string expected)
{
    if (Compiler::tokens[i].Value != expected)
    {
        return false;
    }
    ++i;
    return true;
}
ASTnode::Node Helper::parseCondition(int &i)
{
    bool hasParentheses = Compiler::tokens[i].Value == "(";
    if (hasParentheses || Compiler::tokens[i].Value != ";")
    {
        while (static_cast<size_t>(i) < Compiler::tokens.size() &&
               Compiler::tokens[i].Value != (hasParentheses ? ")" : ";"))
        {
            if (hasParentheses)
            {
                ++i;
            }
            const std::string tokenValue = Compiler::tokens[i].Value;
            if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                FindType(i, Compiler::IDENTIFIER))
            { 
                Left = ASTnode::MakeNode(ASTnode::DATA_TYPES, tokenValue);
            }
            const std::string operatorValue = Compiler::tokens[i].Value;
            if (FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") ||
                FindKeywords(i, "==") || FindKeywords(i, "!=")) //test
            {
                Operator = ASTnode::MakeNode(ASTnode::OPERATOR, operatorValue);
            }
            const std::string rightValue = Compiler::tokens[i].Value;
            if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                FindType(i, Compiler::IDENTIFIER))
            {
                Right = ASTnode::MakeNode(ASTnode::DATA_TYPES, rightValue);
            }
            if (Compiler::tokens[i].Value == "&&" || Compiler::tokens[i].Value == "||")
            {
                LogicGates = ASTnode::MakeNode(ASTnode::ANDOR, Compiler::tokens[i].Value);
            }
            while (Compiler::tokens[i].Value == "&&" || Compiler::tokens[i].Value == "||")
            {
                ++i;
                const std::string tokenValue = Compiler::tokens[i].Value;
                if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                    FindType(i, Compiler::IDENTIFIER))
                {
                    Left = ASTnode::MakeNode(ASTnode::DATA_TYPES, tokenValue);
                }
                const std::string operatorValue = Compiler::tokens[i].Value;
                if (FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") ||
                    FindKeywords(i, "==") || FindKeywords(i, "!="))
                {
                    Operator = ASTnode::MakeNode(ASTnode::OPERATOR, operatorValue);
                }
                const std::string rightValue = Compiler::tokens[i].Value;
                if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                    FindType(i, Compiler::IDENTIFIER))
                {
                    Right = ASTnode::MakeNode(ASTnode::DATA_TYPES, rightValue);
                }
            }
        }
    }
    ConditionNode.Children.push_back(Left);
    ConditionNode.Children.push_back(Operator);
    ConditionNode.Children.push_back(Right);
    ConditionNode.Children.push_back(LogicGates);
    return ConditionNode;
}

void Helper::parseBlock(int &i)
{

    if (Compiler::tokens[i].Value == "[")
    {

        while (Compiler::tokens[i].Value != "]")
        {

            ++i;
            if (Compiler::tokens[i].Value == "if")
            {
                help.parseCondition(i);
            }
            if (Compiler::tokens[i].Value == "while") {
            
                help.parseCondition(i);
            }
        }
    }
}

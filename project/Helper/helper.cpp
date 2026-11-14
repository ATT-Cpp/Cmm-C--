#include "helper.h"
#include "../Lexer/Core/lexer.h"
#include <iostream>
#include <string>
#include <vector>
Helper help {};
bool Helper::FindType(int &i, Compiler::Token type)
{
    if (!Universal(i, {true, true})) {
        return false;
    }

    if (Compiler::tokens[i].TokenType != type)
    {
        return false;
    }
    ++i;
    return true;
}

bool Helper::FindKeywords(int &i, std::string expected)
{
    if (!Universal(i, {true, true, true, expected})) {
        return false;
    }
    ++i;
    return true;
}

bool Helper::Universal(int& i, options opt) {
    if (opt.inrange_i && i < 0) {
        return false;
    }

    if ((opt.inrange_i_tokens || opt.Value_) &&
        (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())) {
        return false;
    }

    if (opt.Value_) {
        if (Compiler::tokens[i].Value != opt.Value) {
            return false;
        }
    }

    return opt.inrange_i || opt.inrange_i_tokens || opt.Value_;
}
ASTnode::Node Helper::parseCondition(int &i)
{
    if (!Universal(i, {true, true})) {
        return ConditionNode;
    }

    bool hasParentheses = Universal(i, {true, true, true, "("});
    if (hasParentheses || !Universal(i, {true, true, true, ";"}))
    {
        const std::string terminator = hasParentheses ? ")" : ";";
        while (Universal(i, {true, true}) &&
               !Universal(i, {true, true, true, terminator}))
        {
            if (hasParentheses)
            {
                ++i;
            }
            if (!Universal(i, {true, true})) {
                return ConditionNode;
            }
            const std::string tokenValue = Compiler::tokens[i].Value;
            if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                FindType(i, Compiler::IDENTIFIER))
            { 
                Left = ASTnode::MakeNode(ASTnode::DATA_TYPES, tokenValue);
            }
            if (!Universal(i, {true, true})) {
                return ConditionNode;
            }
            const std::string operatorValue = Compiler::tokens[i].Value;
            if (FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") ||
                FindKeywords(i, "==") || FindKeywords(i, "!=")) //test
            {
                Operator = ASTnode::MakeNode(ASTnode::OPERATOR, operatorValue);
            }
            if (!Universal(i, {true, true})) {
                return ConditionNode;
            }
            const std::string rightValue = Compiler::tokens[i].Value;
            if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                FindType(i, Compiler::IDENTIFIER))
            {
                Right = ASTnode::MakeNode(ASTnode::DATA_TYPES, rightValue);
            }
            if (!Universal(i, {true, true})) {
                return ConditionNode;
            }
            if (Universal(i, {true, true, true, "&&"}) ||
                Universal(i, {true, true, true, "||"}))
            {
                LogicGates = ASTnode::MakeNode(ASTnode::ANDOR, Compiler::tokens[i].Value);
            }
            while (Universal(i, {true, true}) &&
                   (Universal(i, {true, true, true, "&&"}) ||
                    Universal(i, {true, true, true, "||"})))
            {
                ++i;
                if (!Universal(i, {true, true})) {
                    return ConditionNode;
                }
                const std::string tokenValue = Compiler::tokens[i].Value;
                if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                    FindType(i, Compiler::IDENTIFIER))
                {
                    Left = ASTnode::MakeNode(ASTnode::DATA_TYPES, tokenValue);
                }
                if (!Universal(i, {true, true})) {
                    return ConditionNode;
                }
                const std::string operatorValue = Compiler::tokens[i].Value;
                if (FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") ||
                    FindKeywords(i, "==") || FindKeywords(i, "!="))
                {
                    Operator = ASTnode::MakeNode(ASTnode::OPERATOR, operatorValue);
                }
                if (!Universal(i, {true, true})) {
                    return ConditionNode;
                }
                const std::string rightValue = Compiler::tokens[i].Value;
                if (FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) ||
                    FindType(i, Compiler::IDENTIFIER))
                {
                    Right = ASTnode::MakeNode(ASTnode::DATA_TYPES, rightValue);
                }
                if (!Universal(i, {true, true})) {
                    return ConditionNode;
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
    if (!Universal(i, {true, true})) {
        return;
    }

    if (Universal(i, {true, true, true, "["}))
    {

        while (Universal(i, {true, true}) &&
               !Universal(i, {true, true, true, "]"}))
        {

            ++i;
            if (!Universal(i, {true, true})) {
                return;
            }
            if (Universal(i, {true, true, true, "if"}))
            {
                help.parseCondition(i);
            }
            if (!Universal(i, {true, true})) {
                return;
            }
            if (Universal(i, {true, true, true, "while"})) {
            
                help.parseCondition(i);
            }
        }
    }
}

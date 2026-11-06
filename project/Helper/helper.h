#pragma once

#include "../AST/ASTnode.h"
#include "../Lexer/Core/lexer.h"

class Helper
{
  public:
    bool FindKeywords(int &i, std::string expected);
    bool FindType(int &i, Compiler::Token expected);
    bool find(int &i);
    void parseBlock(int &i);
    ASTnode::Node parseCondition(int &i);
    ASTnode::Node ConditionNode = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node Left = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node Operator = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node Right = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node LogicGates = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
};

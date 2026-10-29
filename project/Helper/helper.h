#pragma once

#include "../AST/ASTnode.h"
#include "../Lexer/lexer.h"

class Helper {
    public:
        bool FindKeywords(int& i, std::string expected);
        bool FindType(int& i, Compiler::Token expected);
        ASTnode::Node parseBlock(int& i);
        ASTnode::Node parseCondition(int& i);
        ASTnode::Node ParseForStatement(int& i);
};

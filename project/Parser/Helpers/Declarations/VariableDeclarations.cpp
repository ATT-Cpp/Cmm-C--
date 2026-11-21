#include "../../../Include/includes.h"

Helper help;
VariableDeclaration vd;
FunctionDeclaration fd;

void VariableDeclaration::ParseVarDecl(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if (Compiler::tokens[static_cast<size_t>(i)].Value != "var")
    {
        return;
    }
    ++i;

    ParseDataType(i);
    ParseIdentifier(i);

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if (Compiler::tokens[i].Value != "=")
    {
        return;
    }
    ++i;
    ParseValue(i);

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if(Compiler::tokens[i].Value != ";") {
        return;
    }
    ++i;

}

void VariableDeclaration::ParseIdentifier(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if (Compiler::tokens[i].TokenType == Compiler::IDENTIFIER)
    {
        Identifier = ASTnode::MakeNode(ASTnode::IDENTIFIER, Compiler::tokens[i].Value);
        ++i;
    }
}

void VariableDeclaration::ParseDataType(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if (Compiler::tokens[i].TokenType == Compiler::INT)
    {
        DataType = ASTnode::MakeNode(ASTnode::INT, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::STRING)
    {
        DataType = ASTnode::MakeNode(ASTnode::STRING, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::DOUBLE)
    {
        DataType = ASTnode::MakeNode(ASTnode::DOUBLE, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::BOOL)
    {
        DataType = ASTnode::MakeNode(ASTnode::BOOL, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::CHAR)
    {
        DataType = ASTnode::MakeNode(ASTnode::CHAR, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::AUTO)
    {
        DataType = ASTnode::MakeNode(ASTnode::AUTO, Compiler::tokens[i].Value);
        ++i;
    }
}

void VariableDeclaration::ParseValue(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if (Compiler::tokens[i].TokenType == Compiler::INT)
    {
        Value = ASTnode::MakeNode(ASTnode::INT, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::STRING)
    {
        Value = ASTnode::MakeNode(ASTnode::STRING, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::DOUBLE)
    {
        Value = ASTnode::MakeNode(ASTnode::DOUBLE, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::BOOL)
    {
        Value = ASTnode::MakeNode(ASTnode::BOOL, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::CHAR)
    {
        Value = ASTnode::MakeNode(ASTnode::CHAR, Compiler::tokens[i].Value);
        ++i;
    }
    else if (Compiler::tokens[i].TokenType == Compiler::AUTO)
    {
        Value = ASTnode::MakeNode(ASTnode::AUTO, Compiler::tokens[i].Value);
        ++i;
    }

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size())
    {
        return;
    }

    if (Compiler::tokens[i].Value == fd.FunctionName.Value)
    {
        Value = ASTnode::MakeNode(ASTnode::STRING, Compiler::tokens[i].Value);
        ++i;
    }

    if (Compiler::tokens[i].Value == Identifier.Value)
    {
        Value = ASTnode::MakeNode(ASTnode::STRING, Compiler::tokens[i].Value);
        ++i;
    }
}

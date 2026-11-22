#include "../../../Include/includes.h"

Helper help;
VariableDeclaration vd;
FunctionDeclaration fd;

void VariableDeclaration::ParseVarDecl(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size())
    {
        return;
    }

    if (Lexer::tokens[static_cast<size_t>(i)].Value != "var")
    {
        return;
    }
    ++i;

    ParseDataType(i);
    if (VariableDeclarationNode.Children.empty())
    {
        std::cerr << "Parse error: expected a variable type after 'var'.\n";
        return;
    }

    ParseIdentifier(i);
    if (VariableDeclarationNode.Children.size() != 2)
    {
        std::cerr << "Parse error: expected a variable name.\n";
        return;
    }

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[i].Value != "=")
    {
        std::cerr << "Parse error: expected '=' after the variable name.\n";
        return;
    }

    ++i;
    ParseValue(i);
    if (VariableDeclarationNode.Children.size() != 3)
    {
        std::cerr << "Parse error: expected a variable value after '='.\n";
        return;
    }

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[i].Value != ";")
    {
        VariableDeclarationNode.Children.clear();
        std::cerr << "Parse error: expected ';' after the variable declaration.\n";
        return;
    }

    ++i;
}

void VariableDeclaration::ParseIdentifier(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size())
    {
        return;
    }

    if (Lexer::tokens[i].TokenType != Lexer::IDENTIFIER)
    {
        return;
    }

    Identifier = ASTnode::MakeNode(ASTnode::IDENTIFIER, Lexer::tokens[i].Value);
    ++i;
    VariableDeclarationNode.Children.push_back(Identifier);
}

void VariableDeclaration::ParseDataType(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size())
    {
        return;
    }

    if (Lexer::tokens[i].TokenType == Lexer::INT)
    {
        DataType = ASTnode::MakeNode(ASTnode::TYPE, "INT");
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::STRING)
    {
        DataType = ASTnode::MakeNode(ASTnode::TYPE, "STRING");
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::DOUBLE)
    {
        DataType = ASTnode::MakeNode(ASTnode::TYPE, "DOUBLE");
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::BOOL)
    {
        DataType = ASTnode::MakeNode(ASTnode::TYPE, "BOOL");
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::CHAR)
    {
        DataType = ASTnode::MakeNode(ASTnode::TYPE, "CHAR");
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::AUTO)
    {
        DataType = ASTnode::MakeNode(ASTnode::TYPE, "AUTO");
        ++i;
    }
    else {
        return;
    }

    VariableDeclarationNode.Children.push_back(DataType);
}

void VariableDeclaration::ParseValue(int &i)
{
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size())
    {
        return;
    }

    if (Lexer::tokens[i].TokenType == Lexer::INT)
    {
        Value = ASTnode::MakeNode(ASTnode::INT, Lexer::tokens[i].Value);
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::STRING)
    {
        Value = ASTnode::MakeNode(ASTnode::STRING, Lexer::tokens[i].Value);
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::DOUBLE)
    {
        Value = ASTnode::MakeNode(ASTnode::DOUBLE, Lexer::tokens[i].Value);
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::BOOL)
    {
        Value = ASTnode::MakeNode(ASTnode::BOOL, Lexer::tokens[i].Value);
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::CHAR)
    {
        Value = ASTnode::MakeNode(ASTnode::CHAR, Lexer::tokens[i].Value);
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::AUTO)
    {
        Value = ASTnode::MakeNode(ASTnode::AUTO, Lexer::tokens[i].Value);
        ++i;
    }
    else if (Lexer::tokens[i].TokenType == Lexer::IDENTIFIER)
    {
        Value = ASTnode::MakeNode(
            ASTnode::IDENTIFIER,
            Lexer::tokens[i].Value
        );
        ++i;
    }
    else
    {
        return;
    }

    VariableDeclarationNode.Children.push_back(Value);
}

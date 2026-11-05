#include "../../../Include/includes.h"
Helper help;
ASTnode::Node VariableDeclarationNode = ASTnode::MakeNode(ASTnode::VARIABLE_DECL, "");
ASTnode::Node VariableValue = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
ASTnode::Node VariableName = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
void VariableDeclaration::ParseVarDecl(int &i)
{

    if (help.FindKeywords(i, "var"))
    {
        VariableValue = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
        VariableName = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
        if (help.FindKeywords(i, "auto"))
        {
            const std::string text = Compiler::tokens[i].Value;
            if (help.FindType(i, Compiler::IDENTIFIER))
            {
                VariableName = ASTnode::MakeNode(ASTnode::IDENTIFIER, text);
            }
            if (help.FindKeywords(i, "="))
            {
                ParseDataTypes(i);
            }
        }
        else if (help.FindKeywords(i, "string") || help.FindKeywords(i, "int") || help.FindKeywords(i, "char") ||
                 help.FindKeywords(i, "bool"))
        {
            const std::string text = Compiler::tokens[i].Value;
            if (help.FindType(i, Compiler::IDENTIFIER))
            {
                VariableName = ASTnode::MakeNode(ASTnode::IDENTIFIER, text);
                if (help.FindKeywords(i, "="))
                {
                    ParseDataTypes(i);
                }
            }
        }
    }
}

void VariableDeclaration::ParseDataTypes(int &i)
{
    const std::string text = Compiler::tokens[i].Value;

    if (help.FindType(i, Compiler::STRING))
    {
        VariableValue = ASTnode::MakeNode(ASTnode::STRING, text);
        VariableName = ASTnode::MakeNode(ASTnode::STRING, VariableName.Value);
    }
    else if (help.FindType(i, Compiler::INT))
    {
        VariableValue = ASTnode::MakeNode(ASTnode::INT, text);
        VariableName = ASTnode::MakeNode(ASTnode::INT, VariableName.Value);
    }
    else if (help.FindType(i, Compiler::BOOL))
    {
        VariableValue = ASTnode::MakeNode(ASTnode::BOOL, text);
        VariableName = ASTnode::MakeNode(ASTnode::BOOL, VariableName.Value);
    }
    else if (help.FindType(i, Compiler::CHAR))
    {
        VariableValue = ASTnode::MakeNode(ASTnode::CHAR, text);
        VariableName = ASTnode::MakeNode(ASTnode::CHAR, VariableName.Value);
    }
    VariableDeclarationNode.Children.push_back(VariableValue);
    VariableDeclarationNode.Children.push_back(VariableName);
}
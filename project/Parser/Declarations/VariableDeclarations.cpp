#include"../../Include/includes.h"
Helper help;
ASTnode::Node VariableDeclarationNode;
ASTnode::Node VariableValue {};
ASTnode::Node VariableName{};
void VariableDeclaration::ParseVarDecl(int& i) {

    if(help.FindKeywords(i, "var")) {
        VariableValue = {};
        VariableName = {};
        if(help.FindKeywords(i, "auto")) {
                const std::string text = Compiler::tokens[i].Value;
            if(help.FindType(i, Compiler::IDENTIFIER)) {
                VariableName.Value = text;
            }
            if(help.FindKeywords(i, "=")) {
                ParseDataTypes(i);
            }
        }
        else if(help.FindKeywords(i, "string") || help.FindKeywords(i, "int") || help.FindKeywords(i, "char") || help.FindKeywords(i, "bool")) {
                const std::string text = Compiler::tokens[i].Value;
            if(help.FindType(i, Compiler::IDENTIFIER)) {
                VariableName.Value = text;
                if(help.FindKeywords(i, "=")) {
                    ParseDataTypes(i);
                }
            }
        }
    }
    
}

void VariableDeclaration::ParseDataTypes(int& i) {
    const std::string text = Compiler::tokens[i].Value;

    if(help.FindType(i, Compiler::STRING)) {
        VariableValue.Type = ASTnode::STRING;
        VariableValue.Value = text;
        VariableName.Type = ASTnode::STRING;
    }
    else if(help.FindType(i, Compiler::INT)) {
        VariableValue.Type = ASTnode::INT;
        VariableValue.Value = text;
        VariableName.Type = ASTnode::INT;
    }
    else if(help.FindType(i, Compiler::BOOL)) {
        VariableValue.Value = text;
        VariableValue.Type = ASTnode::BOOL;
        VariableName.Type = ASTnode::BOOL;
    }
    else if(help.FindType(i, Compiler::CHAR)) {
        VariableValue.Value = text;
        VariableValue.Type = ASTnode::CHAR;
        VariableName.Type = ASTnode::CHAR;
    }
    VariableDeclarationNode.Children.push_back(VariableValue);
    VariableDeclarationNode.Children.push_back(VariableName);

}
#include "../../../Include/includes.h"

ASTnode::Node EnumNode = ASTnode::MakeNode(ASTnode::ENUM_DECL, "");


void Enum::ParseEnumDeclaration(int& i) {

    ASTnode::Node EnumName = ASTnode::MakeNode(ASTnode::ENUM_DECL, "");

    if(i < 0 || static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t>(i)].Value != "enum") {
        return;
    }
    ++i;

    if(i < 0 || static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t> (i)].TokenType != Compiler::IDENTIFIER) {
        return;
    }
    EnumName.Value = Compiler::tokens[static_cast<size_t> (i)].Value;
    ++i;
    
    if(i < 0 || static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t> (i)].Value != "[") {
        return;
    }
    ++i;

    if(i < 0 || static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }

    EnumNode.Children.push_back(EnumName);

    while(i >= 0 &&
          static_cast<size_t>(i) < Compiler::tokens.size() &&
          Compiler::tokens[static_cast<size_t>(i)].Value != "]") {
        if(Compiler::tokens[static_cast<size_t>(i)].TokenType != Compiler::IDENTIFIER) {
            return;
        }
        ParseEnumBody(i);
    }
    if(i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }
    ++i;
}

void Enum::ParseEnumBody(int& i) {
    ASTnode::Node EnumBodyNames = ASTnode::MakeNode(ASTnode::IDENTIFIER, "");

    if(i < 0 || static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t> (i)].TokenType != Compiler::IDENTIFIER) {
        return;
    }
    EnumBodyNames.Value = Compiler::tokens[static_cast<size_t> (i)].Value;
    ++i;
    EnumNode.Children.push_back(EnumBodyNames);

    if(i < 0 || static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t> (i)].Value == ",") {
        ++i;
    }
}
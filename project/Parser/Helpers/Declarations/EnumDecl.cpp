#include "../../../Include/includes.h"

void Enum::ParseEnumDeclaration(int& i) {
    EnumNode = ASTnode::MakeNode(ASTnode::ENUM_DECL, "");
    ASTnode::Node EnumName = ASTnode::MakeNode(ASTnode::ENUM_NAME, "");

    if(i < 0 || static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }
    if(Lexer::tokens[static_cast<size_t>(i)].Value != "enum") {
        return;
    }
    ++i;

    if(i < 0 || static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }
    if(Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    EnumName.Value = Lexer::tokens[static_cast<size_t> (i)].Value;
    ++i;
    
    if(i < 0 || static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }
    if(Lexer::tokens[static_cast<size_t> (i)].Value != "[") {
        return;
    }
    ++i;

    if(i < 0 || static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }

    EnumNode.Children.push_back(EnumName);

    while(i >= 0 &&
          static_cast<size_t>(i) < Lexer::tokens.size() &&
          Lexer::tokens[static_cast<size_t>(i)].Value != "]") {
        if(Lexer::tokens[static_cast<size_t>(i)].TokenType != Lexer::IDENTIFIER) {
            return;
        }
        const int previousIndex = i;
        ParseEnumBody(i);
        if (i <= previousIndex) {
            return;
        }
    }
    if(i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }
    ++i;
}

void Enum::ParseEnumBody(int& i) {
    ASTnode::Node EnumBodyNames = ASTnode::MakeNode(ASTnode::ENUM_VALUE, "");

    if(i < 0 || static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }
    if(Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    EnumBodyNames.Value = Lexer::tokens[static_cast<size_t> (i)].Value;
    ++i;
    EnumNode.Children.push_back(EnumBodyNames);

    if(i < 0 || static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }
    if(Lexer::tokens[static_cast<size_t> (i)].Value == ",") {
        ++i;
    }
}
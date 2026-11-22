#include "../../../Include/includes.h"
Helper help;

void ImportDeclaration::ParseImportDeclaration(int& i,const std::string& input) {
    ImportDeclarationNode = ASTnode::MakeNode(ASTnode::IMPORT, "");
    std::string currentToken;
    if(static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }
    currentToken += Lexer::tokens[static_cast<size_t> (i)].Value;
    
    if(Lexer::tokens[static_cast<size_t> (i)].Value != "import") {
        return;
    }
    ++i;
    currentToken.clear();
    currentToken += Lexer::tokens[static_cast<size_t> (i)].Value;

    if(static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }

    if(Lexer::tokens[static_cast<size_t> (i)].Value != "\"") {
        return;
    }
    ++i;
    currentToken.clear();
    currentToken += Lexer::tokens[static_cast<size_t> (i)].Value;

    if(static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }

    while(Lexer::tokens[static_cast<size_t> (i)].Value != "\"")
    {
        LibraryName = ASTnode::MakeNode(ASTnode::STRING, currentToken);

        ++i;

        currentToken.clear();
        currentToken += Lexer::tokens[static_cast<size_t> (i)].Value;
    }

    if(static_cast<size_t> (i) >= Lexer::tokens.size()) {
        return;
    }

    if(Lexer::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ImportDeclarationNode.Children.push_back(LibraryName);
    ++i;
    currentToken.clear();
    currentToken += Lexer::tokens[static_cast<size_t> (i)].Value;
    
}

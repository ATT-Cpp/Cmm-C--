#include "../../../Include/includes.h"
Helper help;

void ImportDeclaration::ParseImportDeclaration(int& i,const std::string& input) {
    std::string currentToken;
    if(static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }
    currentToken += Compiler::tokens[static_cast<size_t> (i)].Value;
    
    if(Compiler::tokens[static_cast<size_t> (i)].Value != "import") {
        return;
    }
    ++i;
    currentToken.clear();
    currentToken += Compiler::tokens[static_cast<size_t> (i)].Value;

    if(static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }

    if(Compiler::tokens[static_cast<size_t> (i)].Value != "\"") {
        return;
    }
    ++i;
    currentToken.clear();
    currentToken += Compiler::tokens[static_cast<size_t> (i)].Value;

    if(static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }

    while(Compiler::tokens[static_cast<size_t> (i)].Value != "\"")
    {
        LibraryName = ASTnode::MakeNode(ASTnode::STRING, currentToken);

        ++i;

        currentToken.clear();
        currentToken += Compiler::tokens[static_cast<size_t> (i)].Value;
    }

    if(static_cast<size_t> (i) >= Compiler::tokens.size()) {
        return;
    }

    if(Compiler::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
    currentToken.clear();
    currentToken += Compiler::tokens[static_cast<size_t> (i)].Value;
    
}

#include "../../../Include/includes.h"
Helper help;

void ImportDeclaration::ParseImportDeclaration(int& i,const std::string& input) {
    (void)input;
    ImportDeclarationNode = ASTnode::MakeNode(ASTnode::IMPORT, "");
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t>(i)].Value != "import") {
        return;
    }
    ++i;
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t>(i)].TokenType != Lexer::STRING) {
        return;
    }

    LibraryName = ASTnode::MakeNode(
        ASTnode::STRING, Lexer::tokens[static_cast<size_t>(i)].Value);
    ++i;
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t>(i)].Value != ";") {
        return;
    }
    ImportDeclarationNode.Children.push_back(LibraryName);
    ++i;
}

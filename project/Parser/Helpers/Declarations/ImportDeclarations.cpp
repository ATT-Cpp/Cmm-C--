#include "../../../Include/includes.h"
Helper help;

void ImportDeclaration::ParseImportDeclaration(int& i, const std::string& input) {
    (void)input;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    if (!help.FindKeywords(i, "import")) {
        return;
    }

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    const bool isValidImportTarget = Compiler::tokens[i].TokenType == Compiler::STRING || Compiler::tokens[i].Value == "\"\"";
    if (!isValidImportTarget) {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    if (Compiler::tokens[i].Value != ";") {
        return;
    }
    ++i;
}
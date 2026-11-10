#include "../../../Include/includes.h"

void JumpBasedStatements::ParseBreakStatement(int &i) {
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[i].Value != "break") {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[i].Value != ";") {
        return;
    }
    ++i;
}

void JumpBasedStatements::ParseReturnStatement(int &i) {
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[i].Value != "return") {
        return;
    }

    ++i;
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    const bool isValid = Compiler::tokens[i].TokenType == Compiler::STRING ||
                         Compiler::tokens[i].TokenType == Compiler::BOOL ||
                         Compiler::tokens[i].TokenType == Compiler::CHAR ||
                         Compiler::tokens[i].TokenType == Compiler::INT;
    if (!isValid) {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[i].Value != ";") {
        return;
    }
    ++i;
}

void JumpBasedStatements::ParseContinueStatement(int &i) {
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[i].Value != "continue") {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[i].Value != ";") {
        return;
    }
    ++i;
}
